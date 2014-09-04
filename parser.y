%{
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symbol.h"

extern int lineno;
void yyerror (const char *msg);
Type global_type,function_type;
SymbolEntry *p,*f,*next_parameter;
bool evaluate_constant,l_value_flag,we_define_globals = 1,got_lvalue_from_table,function_is_defined = false,found_return_statement = false;
char *global_type_string;
int parameter_counter,total_parameters,loop_counter,count_lvalue_dimensions = 0,dimensions_in_expressions;



%}


%code requires {

#include "symbol.h"
typedef union a 
{ RepInteger x;				
  RepBoolean y;
  RepChar z;
  RepReal w;
  RepString q; } expression_value;
typedef struct expr 
{ 
  Type type;
  expression_value value; 
  bool is_constant ;} Expression;

void makeReal(Expression e1,Expression e2,Expression * e3,int operator);
void makeInteger(Expression e1,Expression e2,Expression * e3,int operator);
void makeComparison(Expression e1,Expression e2,Expression * e3,int operator);
void makeLogical(Expression e1,Expression e2,Expression * e3,int operator);
void setConstant(Expression e,const char * name);
bool assignmentEvaluation(Type t1,Type t2);
bool check_array_dimension(Expression e);
bool check_array_dimension_for_function(Expression e);
Type makeArray(Expression e,Type t);
Expression checkForArrayLvalue (const char * variable);
Expression checkForLvalue(const char * variable);
int countParameters(SymbolEntry *temp);
bool valid_loop_variable(SymbolEntry *loop_var);
void validateParameter(Expression e,SymbolEntry *parameter);
char * getType(Type type);
void operationAndAssignment(Expression e1,Expression e2,int operator);
Expression typeInference(Expression e1,Expression e2,int operator,bool two_expressions);
void validate_range_and_step(Expression e1,Expression e2,Expression step,bool has_step);
void validate_return(Type return_type);
void validate_Constant (const char * variable, Expression e);
void validate_Variable (const char * variable, Type type);
void validate_Routine (const char *routine_name, Type type);
void validate_Variable_with_assignment (const char *variable, Type type, Expression e);
void validate_print_expression (Expression x,Expression y,Expression w,int how_many);
Expression unit_expression;

}


%union {
RepInteger integer_value;
RepBoolean boolean_value;
RepChar character_value;
RepReal real_value;
RepString string_value;
Expression expression;
Type type;
}


/* Bison generates numerical codes for 
*  tokes on its own
*  The %union declaration specifies the entire collection of possible data types for semantic
*  values. The keyword %union is followed by braced code containing the same thing that goes
*  inside a union in C.

*/

/* YYSTYPE is the type for semantic values of our program,
 * int by default in bison 
 * 
 * $n is the semantic value of n-th component in rule ,$$ is the semantic value of
 * grouping.
 * If you don’t specify an action for a rule, Bison supplies a default: $$ = $1.
 * 
 */



%start module

%token T_bool "bool"
%token T_and "and"
%token T_break "break"
%token T_case "case"
%token<int_num> T_char "char"
%token T_const "const"
%token T_cont "continue"
%token T_def "default"
%token T_do "do"
%token T_DOWNTO "DOWNTO"
%token T_else "else"
%token T_false "false"
%token T_FOR "FOR"
%token T_FORM "FORM"
%token T_FUNC "FUNC"
%token T_if "if"
%token T_int "int"
%token T_MOD "MOD"
%token T_NEXT "NEXT"
%token T_not "not"
%token T_or "or"
%token T_PROC "PROC"
%token T_PROGRAM "PROGRAM"
%token T_REAL "REAL"
%token T_return "return"
%token T_STEP "STEP"
%token T_switch "switch"
%token T_TO "TO"
%token T_true "true"
%token T_while "while"
%token T_WRITE "WRITE"
%token T_WRITELN "WRITELN"
%token T_WRITESP "WRITESP"
%token T_WRITESPLN "WRITESPLN"
%token T_const_int 		/**Εγιναν κάποιες αλλαγές εδώ **/
%token T_const_real 
%token T_id
%token T_const_char 
%token T_string 
%token T_equal "=="
%token T_greater ">"
%token T_less "<"
%token T_nequal "!="
%token T_egreater ">="
%token T_lequal "<="
%token T_plus "+"
%token T_minus "-"
%token T_mult "*"
%token T_div "/"
%token T_mod "%"
%token T_notb "!"
%token T_AND "AND"
%token T_OR "OR"
%token T_pp "++"
%token T_mm "--"
%token T_assign "="
%token T_plusassign "+="
%token T_minusassign "-="
%token T_multassign "*="
%token T_divassign "/="
%token T_modassign "%="
%token T_ampersand "&"
%token T_mark ";"
%token T_dot "."
%token T_lpar "("
%token T_rpar ")"
%token T_2dots ":"
%token T_coma ","
%token T_lbracket "["
%token T_rbracket "]"
%token T_lhook "{"
%token T_rhook "}"

%token T_eof

%left T_or T_OR
%left T_AND T_and
%left T_equal T_nequal 
%left T_less T_greater T_lequal T_egreater
%left T_minus T_plus 
%left T_mult T_div T_MOD T_mod
%left T_not T_notb

%type<string_value> type T_id
%type<expression> const_expr expr l_value
%type<type> var_init_list  formal_list call


%%

/* Grammar starts here 
 * Basic declarations that make up a program
 */
module : declaration_list {  closeScope(); };

declaration_list : declaration declaration_list { } 
				   | /*nothing*/{ } ;

declaration : const_def { }
		    | var_def { }
		    | routine { we_define_globals = 1;}
		    | program { we_define_globals = 1;} ;


/* Constants definition.
 */
const_def  : T_const type T_id T_assign const_expr const_def_list T_mark { 	validate_Constant($3,$5); };


const_def_list : T_coma T_id T_assign const_expr const_def_list { 	validate_Constant($2,$4); }
			   | /****nothing***/ {  };


/* Variables definition.
 */

//must take the variables into consideration with the right order example : int x,y,z,x the last x has the problem
var_def : type T_id { validate_Variable($2,global_type); } 
		  var_def_list T_mark { }
		| type T_id T_assign expr { validate_Variable_with_assignment($2,global_type,$4); } var_def_list T_mark { }
	    | type T_id var_init_list { validate_Variable($2,$3); } var_def_list T_mark { };

var_def_list :   T_coma T_id {  validate_Variable($2,global_type);  } 
				 var_def_list  { }
 			   | T_coma T_id T_assign expr { validate_Variable_with_assignment($2,global_type,$4); } var_def_list { }
 			   | T_coma T_id var_init_list { validate_Variable($2,$3); } var_def_list { }
 			   | /***nothing***/ {  };

var_init_list : T_lbracket const_expr T_rbracket {  if ((!$2.is_constant)||check_array_dimension($2)) 
												   		fatal("Expression in array dimension is not a possitive integer constant. Line = %d\n",lineno); } 
			    var_init_list { $$=makeArray($2,$5); }
			  | T_lbracket const_expr T_rbracket {  if ((!$2.is_constant)||check_array_dimension($2)) 
			  									   		fatal("Expression in array dimension is not a possitive integer constant. Line = %d\n",lineno); 
			  									    else 
			  									    	$$=makeArray($2,global_type); };




/*** ROUTINES DECLARATIONS ***/
routine_header: choose T_lpar routine_header_if T_rpar { endFunctionHeader(p,function_type); } ;
	       
choose : T_PROC T_id {  validate_Routine($2,typeVoid); }
	   | T_FUNC type T_id { validate_Routine($3,global_type); };
routine_header_if : type formal routine_header_if_list { }
				  | /***nothing***/    {   } ;
routine_header_if_list : T_coma type formal routine_header_if_list{  }   
			| /***nothing***/ { } ;
formal : T_ampersand T_id { newParameter($2, global_type, PASS_BY_REFERENCE, p); }
	   | T_id  { newParameter($1, global_type, PASS_BY_VALUE, p); }
       | T_id formal_list { newParameter($1,$2,PASS_BY_REFERENCE,p); };
formal_if2 : const_expr { }
		   | /***nothing***/ { };
formal_list : T_lbracket formal_if2 T_rbracket formal_list { $$ = typeArray(1,$4); }
			| T_lbracket formal_if2 T_rbracket  { $$ = typeArray(1,global_type); };
routine : routine_header T_mark  { forwardFunction(p); 
								   closeScope(); 
								 } 	
	    | routine_header block { if ((!found_return_statement)&&(function_type != typeVoid))
	    						 	fatal("Function '%s' does not return aprropriate value\n",p->id);
	    						 we_define_globals = 1; 
	    						 function_is_defined = false; 
	    						 found_return_statement = false;
	    						 closeScope(); 
	    					   };


program_header : T_PROGRAM T_id T_lpar T_rpar { if (lookupEntry($2,LOOKUP_CURRENT_SCOPE,0))
	   												fatal("Can not declare main program with name '%s',name already used. Line = %d\n",$2,lineno);
	   											p = newFunction($2); 
												openScope(); 
												endFunctionHeader(p,typeVoid); 
											  };

program : program_header { we_define_globals = 0; } block {   closeScope(); };





/* Types
 */
type : T_int  { $$=strdup("Integer"); global_type=typeInteger; global_type_string=strdup("Integer"); }
	 | T_bool { $$=strdup("Boolean"); global_type=typeBoolean; global_type_string=strdup("Boolean"); }
	 | T_char { $$=strdup("Character");    global_type=typeChar; global_type_string=strdup("Character"); }
	 | T_REAL { $$=strdup("Real");    global_type=typeReal; global_type_string=strdup("Real"); } ;





/* Expressions.
 */

const_expr : { evaluate_constant=1; } expr { $$=$2; } ;

expr : T_const_int  { $$.type=typeInteger; $$.is_constant=1;  l_value_flag=0; }
	 | T_const_real { $$.type=typeReal; $$.is_constant=1;  l_value_flag=0;   }
	 | T_const_char { $$.type=typeChar; $$.is_constant=1;  l_value_flag=0;   }
	 | T_string 	{  $$.type=typeArray(strlen($$.value.q)+1,typeChar); $$.is_constant=1; l_value_flag=0;}
	 | T_true		{ $$.type=typeBoolean; $$.is_constant=1; l_value_flag=0;}
	 | T_false		{ $$.type=typeBoolean; $$.is_constant=1; l_value_flag=0;}
 	 | T_lpar expr T_rpar { $$=$2; l_value_flag=0;} 
	 | l_value	      { $$=$1;  }
	 | call		      { $$.is_constant=0; $$.type=$1;l_value_flag=0; }
	 | T_plus expr 	        { $$=typeInference($2,$2,T_plus,0); l_value_flag=0;}
	 | T_not expr 	        { $$=typeInference($2,$2,T_not,0);l_value_flag=0; }
	 | T_notb expr 	        { $$=typeInference($2,$2,T_notb,0); l_value_flag=0;}
	 | T_minus expr         { $$=typeInference($2,$2,T_minus,0);l_value_flag=0;}
	 | expr T_plus expr     { $$=typeInference($1,$3,T_plus,1);l_value_flag=0;}
	 | expr T_minus expr    { $$=typeInference($1,$3,T_minus,1);l_value_flag=0;}
	 | expr T_mult expr     { $$=typeInference($1,$3,T_mult,1);l_value_flag=0;}
	 | expr T_div expr      { $$=typeInference($1,$3,T_div,1);l_value_flag=0;}
	 | expr T_mod expr      { $$=typeInference($1,$3,T_mod,1);l_value_flag=0;}
	 | expr T_MOD expr      { $$=typeInference($1,$3,T_MOD,1);l_value_flag=0;}
	 | expr T_equal expr    { $$=typeInference($1,$3,T_equal,1);l_value_flag=0;}
	 | expr T_nequal expr   { $$=typeInference($1,$3,T_nequal,1);l_value_flag=0;}
	 | expr T_less expr     { $$=typeInference($1,$3,T_less,1);l_value_flag=0;}
	 | expr T_greater expr  { $$=typeInference($1,$3,T_greater,1);l_value_flag=0;}
	 | expr T_lequal expr   { $$=typeInference($1,$3,T_lequal,1);l_value_flag=0;}
	 | expr T_egreater expr { $$=typeInference($1,$3,T_egreater,1);l_value_flag=0;}
	 | expr T_AND expr      { $$=typeInference($1,$3,T_AND,1);l_value_flag=0;}
	 | expr T_and expr      { $$=typeInference($1,$3,T_and,1);l_value_flag=0;}
	 | expr T_OR expr       { $$=typeInference($1,$3,T_OR,1);l_value_flag=0;}
	 | expr T_or expr       { $$=typeInference($1,$3,T_or,1);l_value_flag=0;} ;




 

/* lvalue explanation.
 * lvalue returns an expression struct.type may be an arrrayType.
 * in case of array expression must be valid in brackets
 */

l_value : T_id { $$ = checkForLvalue($1);  };
		| T_id T_lbracket expr T_rbracket  l_value_list {   if ($3.is_constant) 
		     													if (check_array_dimension($3)) 
		     														fatal("Array subscript is not an integer. Line = %d",lineno);
		     												dimensions_in_expressions++;
		     												$$ = checkForArrayLvalue($1);
		     												dimensions_in_expressions = 0;
		     											};

l_value_list :   /***nothing***/ { }
		     | T_lbracket expr T_rbracket l_value_list { dimensions_in_expressions++;
		     											 if ($2.is_constant) 
		     											 	if (check_array_dimension($2)) 
		     													fatal("Array subscript is not an integer. Line = %d",lineno);
		     										   } ;
	 		





/* FUNCTION CALLS */

call :  T_id {  f = lookupEntry($1,LOOKUP_ALL_SCOPES,0);
		        if ((!f)||(f->entryType!=ENTRY_FUNCTION))
		       		fatal("Function '%s' is not declared. Line = %d\n",$1,lineno);
                next_parameter = f->u.eFunction.firstArgument; 
                parameter_counter = 0;; 
                total_parameters = countParameters(f) ;
              } 
        T_lpar call_if T_rpar { $$=f->u.eFunction.resultType; }; 
call_if :{ l_value_flag = 1; } expr {  validateParameter($2,next_parameter);  } call_if_list { }
		| /***nothing***/ { if (next_parameter) 
								fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno);
						  };
call_if_list :  T_coma { l_value_flag = 1; } expr {  validateParameter($3,next_parameter); } call_if_list { }
			 | /***nothing***/ { if (next_parameter) 
									fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno); 
							   };






block : T_lhook block_list T_rhook { };
block_list : local_def block_list {  }
		   | stmt block_list {  }
		   | /***nothing***/ {  } ;

local_def : const_def { }
		  | var_def { };







/* STATEMENTS */

stmt : T_mark { /* empty statement */ }
     | l_value T_assign expr T_mark {   if ($1.is_constant) 
     								  		fatal("Cannot change constant value. Line = %d\n",lineno);
     								  	else if (!assignmentEvaluation($1.type,$3.type))
     								  		fatal("Invalid assignment.Cannot assign %s to %s. Line = %d\n",getType($3.type),getType($1.type),lineno);
     								}
     | l_value T_plusassign expr T_mark  {  operationAndAssignment($1,$3,T_plus);   }
     | l_value T_minusassign expr T_mark {  operationAndAssignment($1,$3,T_minus);  }
     | l_value T_multassign expr T_mark  {  operationAndAssignment($1,$3,T_mult);   }
     | l_value T_divassign expr T_mark   {  operationAndAssignment($1,$3,T_div);    }
     | l_value T_modassign expr T_mark   {  operationAndAssignment($1,$3,T_mod);    }
     | l_value T_pp  T_mark { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     						  operationAndAssignment($1,unit_expression,T_plus); 
     						}
     | l_value T_mm T_mark  { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     						  operationAndAssignment($1,unit_expression,T_minus);   
     						} 
     | call T_mark { }
     | T_if T_lpar expr T_rpar stmt {   if (!equalType($3.type,typeBoolean)) 
											fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     													
     								}
     | T_if T_lpar expr T_rpar stmt T_else stmt {   if (!equalType($3.type,typeBoolean)) 
														fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     													
     								  }
     | T_while { loop_counter++; } T_lpar expr T_rpar stmt {    if (!equalType($4.type,typeBoolean)) 
															    	fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     													
																loop_counter--;     								   						
     								   						}
     | T_FOR { loop_counter++; } T_lpar T_id T_coma range T_rpar stmt {  p = lookupEntry($4,LOOKUP_ALL_SCOPES,0);
     																	if (!p) 
     																		fatal("Variable '%s' in for loop does not exist. Line = %d\n",$4,lineno);
     																	else if (!valid_loop_variable(p))
	   																		fatal("Variable '%s' in for loop is not an integer. Line = %d\n");
    																	loop_counter--;
     																  }
     | T_do T_while { loop_counter++; } T_lpar expr T_rpar T_mark {    if (!equalType($5.type,typeBoolean)) 
													  							fatal("Expression in while statement not boolean. Line = %d\n",lineno);	     													
     								  							   	   		loop_counter--;
     								  							   	   }
     | T_switch T_lpar expr T_rpar T_lhook switch_cases T_rhook  {    if ($3.type!=typeInteger)
     																	fatal("Expression in switch statement is not integer. Line = %d\n",lineno);
     															}
     | T_break T_mark { if (loop_counter==0) 
     						fatal("Break statement is not in a loop. Line = %d\n",lineno);
     				   }
     | T_cont T_mark  { if (loop_counter==0)
     						fatal("Continue statement is not in a loop. Line =%d\n",lineno);
     				  }
     | T_return expr T_mark { validate_return($2.type); found_return_statement = true; }
     | T_return T_mark 		{ validate_return(typeVoid); }
     | block { }
     | write T_lpar T_rpar T_mark { }
     | write T_lpar format format_more T_rpar T_mark {  };




switch_cases : switch_cases choose_case   { }
		   | /***nothing***/ {} ;

choose_case : T_case expr T_2dots statement_list T_break T_mark {   if (!equalType(typeInteger,$2.type)) 
																		fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
																}
		    | T_case expr T_2dots statement_list T_NEXT T_mark {   if (!equalType(typeInteger,$2.type)) 
																		fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
																}
		    | T_def T_2dots statement_list T_break T_mark { } 
		    | T_def T_2dots statement_list T_NEXT T_mark { };
statement_list : statement_list  stmt { }
			   | { /*nothing*/ };


range : expr range_choose expr { validate_range_and_step($1,$3,$1,0);; }
	  | expr range_choose expr T_STEP expr{ validate_range_and_step($1,$3,$5,1); }
range_choose : T_TO {  }
			 | T_DOWNTO {  };


/* FIX ME */
format_more : T_coma format format_more { }
		      | /***nothing***/     {  };
format : expr { validate_print_expression($1,$1,$1,1); }
       | T_FORM T_lpar expr T_coma expr T_coma expr T_rpar {  validate_print_expression($3,$5,$7,2);
       													   };
       | T_FORM T_lpar expr T_coma expr T_rpar { validate_print_expression($3,$5,$5,3);
       											};
write : T_WRITE { }
     | T_WRITELN { }
     | T_WRITESP { }
     | T_WRITESPLN { };




%%

/* validates the declaration of a constant 
 * and creates that constant 
 */

void validate_Constant (const char * variable, Expression e) {

	if (lookupEntry(variable,LOOKUP_CURRENT_SCOPE,0))
		fatal("Cannot define constant,name already in use Line = %d\n",lineno);
	else if (!assignmentEvaluation(global_type,e.type))  
		fatal("Type mismatch in constant %s definition. Line = %d\n",variable,lineno); 
	else if (!e.is_constant) 
		fatal("Can not evaluate constant %s in compile time. Line = %d\n",variable,lineno);
   	else 
		setConstant(e,variable); 

}

/* validates the declaration of a variable 
 * and creates that variable 
 */

 void validate_Variable(const char *variable, Type type) {
 	
 	if (lookupEntry(variable,LOOKUP_CURRENT_SCOPE,0)) 
		fatal("Can not declare variable with name '%s', name already used. Line = %d\n",variable,lineno); 
	else 
		newVariable(variable,type); 


 }

/* validates the declaration of a function
 * and creates that function 
 * p is a global symbol table variable that changes every time we declare a function,and function_type a type variable that changes at every declaration too
 */

void validate_Routine (const char *routine_name, Type type) {
	
	if (lookupEntry(routine_name,LOOKUP_CURRENT_SCOPE,0))
		fatal("Can not declare function with name '%s',name already used. Line = %d\n",routine_name,lineno);
	p = newFunction(routine_name); 
	function_type = type; 
	/* open the scope of the function here
	 */

	openScope();

	/* we_define_globals is a flag used for the initialiasation of global variables
	 * function_is_defined is a flag used for the validation of 'return ;' statements
	 */

	we_define_globals = 0; 
	function_is_defined = true; 
}

/* validate the declaration of a variable WITH assignment
 */

 void validate_Variable_with_assignment (const char *variable, Type type, Expression e) {

 	if (lookupEntry(variable,LOOKUP_CURRENT_SCOPE,0)) 
		fatal("Can not declare variable with name '%s', name already used. Line = %d\n",variable,lineno); 
	else 
		newVariable(variable,type); 
 
	if (!assignmentEvaluation(type,e.type)) 
		fatal("Type of expression in assignment of variable %s is not compatible with type %s. Line = %d\n",variable,getType(type),lineno); 
	if  ((we_define_globals)&&(!e.is_constant)) 
 		fatal("Global variable assignment '%s' is not a constant expression. Line = %d\n",variable,lineno); 

 }


// validates a print expression 



void validate_print_expression (Expression x,Expression y,Expression w,int how_many) {


	if (how_many==3) {
		if ((x.type!=typeReal)||(y.type!=typeInteger)||(w.type!=typeInteger))
			fatal("Expressions in FORM (x,w,d) must have types real,int and int accordingly. Line = %d\n",lineno);
		return ;
	}

	if ((x.type!=typeInteger)&&(x.type!=typeReal)&&(x.type!=typeChar)&&(x.type!=typeBoolean)&&(x.type->refType!=typeChar)&&(x.type->refType->refType!=NULL))
		fatal("Expression x in FORM (x,w) must be of basic type or string. Line = %d\n",lineno);
	
	if (how_many == 2)
		if (y.type != typeInteger)
			fatal("Expression w in FORM (x,w) must be of integer type. Line = %d\n"); 

	return;

}
void validate_return(Type return_type) {

	if (!function_is_defined)
		fatal("Return statement outside of a routine body. Line = %d\n",lineno);

	if (!equalType(function_type,return_type))
		if (function_type == typeVoid)
			fatal("Procedure '%s' does not have a type. Line = %d",p->id,lineno);
		else
			fatal("Function %s has type %s, expression in return statement has different type. Line = %d",p->id,getType(function_type),lineno);
	return ;
}

/* function thath validates the expressions in range 
 * and step of a loop 
 */
void validate_range_and_step(Expression e1,Expression e2,Expression step,bool has_step){

	if (e1.type!=typeInteger)
		fatal("Expression in first limit at range of loop not an integer. Line = %d\n",lineno);
	if (e2.type!=typeInteger)
		fatal("Expression in second limit at range of loop not an integer. Line = %d\n",lineno);
	if (has_step&&(step.type!=typeInteger))
		fatal("Expression in step of loop not an integer. Line = %d\n",lineno);
	
	return;
}


bool valid_loop_variable(SymbolEntry *loop_var){

	bool f = false;

	switch(loop_var->entryType){
		case(ENTRY_PARAMETER):
			if (loop_var->u.eParameter.type==typeInteger)
				return true;
			else return false;
		case(ENTRY_VARIABLE):
			if (loop_var->u.eVariable.type==typeInteger)
				return true;
			else return false;
	}

	return false;
}

/* function that perfomrs the validation of *=,+= etc */

void operationAndAssignment(Expression e1,Expression e2,int operator) {

	Type temporary_type = typeInference(e1,e2,operator,1).type;
    
    if (e1.is_constant) 
     	fatal("Cannot change constant value. Line = %d\n",lineno);
    else if (!assignmentEvaluation(e1.type,temporary_type))
     	fatal("Invalid assignment.Cannot assign %s to %s. Line = %d\n",getType(temporary_type),getType(e1.type),lineno); 
     								  
     return;
}


/* returns a string typeInteger,typeReal etc from Type */
char * getType(Type type){

	char *s;
	s = malloc(16);

	if (type==typeReal)
		strcpy(s,"Real");
	else if (type==typeInteger)
		strcpy(s,"Integer");
	else if (type==typeBoolean)
		strcpy(s,"Boolean");
	else if (type==typeChar)
		strcpy(s,"Character");
	
	return s;

}

/* validates a parameter with an expression
 * if parameter is NULL pointer then more parameters in
 * function call 
 */

void validateParameter(Expression e,SymbolEntry *parameter) {

	Type type,t2;
	bool assignment;	
	int count_parameter =0,count_expression = 0;

	if (!parameter)
		fatal("Function '%s' declared with %d argument(s). Line = %d",f->id,total_parameters,lineno);

	t2 = parameter->u.eParameter.type;
	type = e.type;

	next_parameter = parameter->u.eParameter.next;
	parameter_counter++;
	/* if parameter argument is typeArray then expression must be of the same type */
	
	if ((t2!=typeInteger)&&(t2!=typeReal)&&(t2!=typeBoolean)&&(t2!=typeChar)) {
		//printf("argument is of type array for sure \n");
		if ((type==typeInteger)||(type==typeReal)||(type==typeBoolean)||(type==typeChar)) 
			fatal("Argument %d of function '%s' is of type Array. Line = %d",parameter_counter,f->id,lineno);

		while ((t2!=typeInteger)&&(t2!=typeReal)&&(t2!=typeBoolean)&&(t2!=typeChar)) {
			t2 = t2->refType;
			count_parameter++;
		}
		while ((type!=typeInteger)&&(type!=typeReal)&&(type!=typeBoolean)&&(type!=typeChar)) {
			type = type->refType;
			count_expression++;
		}

		if (count_parameter != count_expression)
			fatal("Argument %d of function '%s' is a %d-dimension array,parameter is a %d-dimension array. Line = %d\n",parameter_counter,f->id,count_expression,count_parameter);

		if (t2!=type)
			fatal("Argument %d of function '%s' is a %s array,parameter is a %s array. Line = %d\n",parameter_counter,f->id,getType(t2),getType(type));


		return;
	}
	

	/* if expression is not an l-value and the paramater has been passed BY_REFERENCE,report error*/
	//printf("argument is NOT of type array\n");

	if ((parameter->u.eParameter.mode==PASS_BY_REFERENCE)&&(!l_value_flag))
		fatal("Cannot pass '%d' argument by reference, in function %s. Line = %d\n",parameter_counter,f->id,lineno);

	assignment = assignmentEvaluation(parameter->u.eParameter.type,type);
	if (!assignment)
		fatal("Argument %d of function '%s' is not valid. Line = %d\n",parameter_counter,f->id,lineno);
	
	


	return;
}


/* returns the number of parameters in a function
 * argument is the symbol table entry of the function 
 */

int countParameters(SymbolEntry *temp) {

	int count=0,i;
	SymbolEntry *first,*temporary,*last;

	temporary=temp->u.eFunction.firstArgument;
	last=temp->u.eFunction.lastArgument;
	while (temporary!=last){
		count++;
		temporary=temporary->u.eParameter.next;
	}
	count++;

	return count;
}


Expression checkForArrayLvalue (const char * variable){

	Expression expr ;
	SymbolEntry *symbol_table_entry;
	Type type;
	int count,dimensions = dimensions_in_expressions;


	if (l_value_flag) 
		l_value_flag = 0; 
	else 
		l_value_flag = 1; 	
	
	symbol_table_entry = lookupEntry(variable,LOOKUP_ALL_SCOPES,0);


	if (!symbol_table_entry)
		fatal("'%s' does not exist . Line = %d\n",variable,lineno);


	if (symbol_table_entry->entryType==ENTRY_FUNCTION)
		fatal("Missing parameters after %s function. Line = %d\n",variable,lineno);


	if (symbol_table_entry->entryType==ENTRY_CONSTANT) {
		if ((symbol_table_entry->u.eConstant.type == typeBoolean)||(symbol_table_entry->u.eConstant.type == typeReal)||(symbol_table_entry->u.eConstant.type == typeChar)||(symbol_table_entry->u.eConstant.type == typeInteger))
			fatal(" '%s' is not an array. Line = %d\n",variable,lineno);
		if (dimensions_in_expressions>1)
			fatal("String '%s' is a one dimensional array of characters. Line = %d\n",variable,lineno);
		expr.type = typeChar;
		expr.is_constant = 0;
		return expr;
	}


	type = symbol_table_entry->u.eVariable.type;

	if ((symbol_table_entry->u.eConstant.type == typeBoolean)||(symbol_table_entry->u.eConstant.type == typeReal)||(symbol_table_entry->u.eConstant.type == typeChar)||(symbol_table_entry->u.eConstant.type == typeInteger))
				fatal(" '%s' is not an array. Line = %d\n",variable,lineno);

	while (dimensions > 0) {
		type = type->refType;
		if (!type)
			fatal("Array '%s' has %d dimensions.Line = %d",variable,dimensions_in_expressions,lineno);
		dimensions--;
	}

	expr.type = type;
	expr.is_constant = 0;
	return expr;
}

Expression checkForLvalue (const char * variable) {

	Expression expr ;
	SymbolEntry *symbol_table_entry;
	Type type;

	/* check for lvalue existance */ 

	symbol_table_entry = lookupEntry(variable,LOOKUP_ALL_SCOPES,0);
	if (!symbol_table_entry)
		fatal("'%s' does not exist . Line = %d\n",variable,lineno);

	/* if lvalue is a function fatal : error with parameters */

	if (symbol_table_entry->entryType==ENTRY_FUNCTION)
		fatal("Missing parameters after %s function. Line = %d\n",variable,lineno);

	/* if lvalue is a constant we return expression with that constant */

	if (symbol_table_entry->entryType==ENTRY_CONSTANT) {
		expr.is_constant = 1;
		type = symbol_table_entry->u.eConstant.type;
		if (type==typeInteger) 
			expr.value.x = symbol_table_entry->u.eConstant.value.vInteger;
		else if (type==typeBoolean) 
			expr.value.y = symbol_table_entry->u.eConstant.value.vBoolean;
		else if (type==typeChar) 
			expr.value.z = symbol_table_entry->u.eConstant.value.vChar;
		else if (type==typeReal) 
			expr.value.w = symbol_table_entry->u.eConstant.value.vReal;
		else {
			expr.value.q = strdup(symbol_table_entry->u.eConstant.value.vString);
			type = typeArray(strlen(expr.value.q)+1,typeChar);
		}
		
		expr.type = type;
		return expr;
	}

	
	
	// returns the actual type of varialbe or parameter
	// it may return arrayType

	if (symbol_table_entry->entryType==ENTRY_PARAMETER)
		type = symbol_table_entry->u.eParameter.type;
	else
		type = symbol_table_entry->u.eVariable.type;
		
	/* l_value_flag is used in routine calls in pass by reference mode
	 * in order to determine if we give a PROPER lvalue
	 */

	if (l_value_flag) 
	 	l_value_flag = 0; 
	 else 
	 	l_value_flag = 1; 


	expr.is_constant = 0;
	expr.type = type;
	return expr;


}


/* returns a Type Array according 
 * to the value of the
 * consant expression in the Expression struct
 */

Type makeArray(Expression e,Type t){


	if (t==typeReal)
		return typeArray(e.value.w,t);
	else 
		return typeArray(e.value.x,t);

}

/* function that returns true if 
 * array dimension is not a constant (known at compile time)
 * integer non-zero expression
 */

bool check_array_dimension(Expression e) {

	return ( (e.type==typeBoolean) || ((e.type==typeInteger)&&(e.value.x<=0)&&(e.is_constant)) || (e.type==typeChar) || ((e.is_constant)&&(e.type==typeReal)&&( (e.value.w<=0)||(floor(e.value.w)<e.value.w)) ) ) ;

}




/* function that evaluates if an assignment is corretct, Xt1 = Yt2 
 * returns false if assignment is not possible by the specifications of pazcal
 */

bool assignmentEvaluation(Type t1,Type t2){

	if ((t2!=typeInteger)&&(t2!=typeReal)&&(t2!=typeBoolean)&&(t2!=typeChar))
		return false;

	if ((t1==typeBoolean)&&(t2==typeBoolean))
		return true;
	if (t1==typeReal)
		if (t2==typeBoolean)
			return false;
		else
			return true;
	
	if (t1==typeInteger) 
		if ((t2==typeBoolean)||(t2==typeReal))
			return false;
		else
			return true;
	
	if (t1==typeChar)
		if ((t2==typeBoolean)||(t2==typeReal))
			return false;
		return true;

}

/* function that sets a new constant based on type 
 * and value of the Expression structure 
 */

void setConstant(Expression e,const char *name) {

	if (e.type==typeInteger)
	    newConstant(name,e.type,e.value.x);
	if (e.type==typeBoolean)
	    newConstant(name,e.type,e.value.y);
	if (e.type==typeChar)
		newConstant(name,e.type,e.value.z);
	if (e.type==typeReal)
		newConstant(name,e.type,e.value.w);
}

/*
int get_parameters(SymbolEntry *temp) {

	int count=0,i;
	SymbolEntry *first,*temporary,*last;

	temporary=temp->u.eFunction.firstArgument;
	last=temp->u.eFunction.lastArgument;
	while (temporary!=last){
		count++;
		temporary=temporary->u.eParameter.next;
	}
	count++;

	return count;
}
*/


 
void makeReal(Expression e1,Expression e2,Expression * e3,int operator) {


	switch(operator){
		case(T_plus):
			if (e1.type==typeReal) {
				if (e2.type==typeChar) 
					e3->value.w=e1.value.w+e2.value.z;
				else if (e2.type==typeReal)
					e3->value.w=e1.value.w+e2.value.w;
				else
				    e3->value.w=e1.value.w+e2.value.x;
			}
			else if (e1.type==typeChar)
				e3->value.w=e1.value.z+e2.value.w;
			else 
				e3->value.w=e1.value.x+e2.value.w;
			
			return;
		case(T_minus):
			if (e1.type==typeReal) {
				if (e2.type==typeChar) 
					e3->value.w=e1.value.w-e2.value.z;
				else if (e2.type==typeReal)
					e3->value.w=e1.value.w-e2.value.w;
				else
				    e3->value.w=e1.value.w-e2.value.x;
			}
			else if (e1.type==typeChar)
				e3->value.w=e1.value.z-e2.value.w;
			else 
				e3->value.w=e1.value.x-e2.value.w;
			
			return;
		case(T_mult):
			if (e1.type==typeReal) {
				if (e2.type==typeChar) 
					e3->value.w=e1.value.w*e2.value.z;
				else if (e2.type==typeReal)
					e3->value.w=e1.value.w*e2.value.w;
				else
				    e3->value.w=e1.value.w*e2.value.x;
			}
			else if (e1.type==typeChar)
				e3->value.w=e1.value.z*e2.value.w;
			else 
				e3->value.w=e1.value.x*e2.value.w;
			
			return;
		case(T_div):
			if (e1.type==typeReal) {
				if (e2.type==typeChar) 
					e3->value.w=e1.value.w/e2.value.z;
				else if (e2.type==typeReal)
					e3->value.w=e1.value.w/e2.value.w;
				else
				    e3->value.w=e1.value.w/e2.value.x;
			}
			else if (e1.type==typeChar)
				e3->value.w=e1.value.z/e2.value.w;
			else 
				e3->value.w=e1.value.x/e2.value.w;
			
			return;
	
	}

}


void makeInteger(Expression e1,Expression e2,Expression * e3,int operator) {


	switch(operator){
		case(T_plus):
			if (e1.type==typeChar) {
				if (e2.type==typeChar) 
					e3->value.x=e1.value.z+e2.value.z;
				else
				    e3->value.x=e1.value.z+e2.value.x;
			}
			else if (e2.type==typeChar)
				e3->value.x=e1.value.x+e2.value.z;
			else 
				e3->value.x=e1.value.x+e2.value.x;
		
			return;
		case(T_minus):
			if (e1.type==typeChar) {
				if (e2.type==typeChar) 
					e3->value.x=e1.value.z-e2.value.z;
				else
				    e3->value.x=e1.value.z-e2.value.x;
			}
			else if (e2.type==typeChar)
				e3->value.x=e1.value.x-e2.value.z;
			else 
				e3->value.x=e1.value.x-e2.value.x;
			
			return;
		case(T_mult):
			if (e1.type==typeChar) {
				if (e2.type==typeChar) 
					e3->value.x=e1.value.z*e2.value.z;
				else
				    e3->value.x=e1.value.z*e2.value.x;
			}
			else if (e2.type==typeChar)
				e3->value.x=e1.value.x*e2.value.z;
			else 
				e3->value.x=e1.value.x*e2.value.x;
			
			return;
		case(T_div):
			if (e1.type==typeChar) {
				if (e2.type==typeChar) 
					e3->value.x=e1.value.z/e2.value.z;
				else
				    e3->value.x=e1.value.z/e2.value.x;
			}
			else if (e2.type==typeChar)
				e3->value.x=e1.value.x/e2.value.z;
			else 
				e3->value.x=e1.value.x/e2.value.x;
			
			return;
	}


		
	if (e1.type==typeChar) {
		if (e2.type==typeChar) 
			e3->value.x=e1.value.z%e2.value.z;
		else
			e3->value.x=e1.value.z%e2.value.x;
	}
	else if (e2.type==typeChar)
		e3->value.x=e1.value.x%e2.value.z;
	else 
		e3->value.x=e1.value.x%e2.value.x;
	
	return;
}


void makeComparison(Expression e1,Expression e2,Expression * e3,int operator) {

	switch(operator){
		case(T_equal):
			if ((e1.type==typeInteger)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.x==e2.value.x);
			if ((e1.type==typeInteger)&&(e1.type==typeReal))
				e3->value.y=(e1.value.x==e2.value.w);
			if ((e1.type==typeInteger)&&(e1.type==typeChar))
				e3->value.y=(e1.value.x==e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.w==e2.value.x);
			if ((e1.type==typeReal)&&(e1.type==typeChar))
				e3->value.y=(e1.value.w==e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeReal))
				e3->value.y=(e1.value.w==e2.value.w);
			if ((e1.type==typeChar)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.z==e2.value.x);
			if ((e1.type==typeChar)&&(e1.type==typeChar))
				e3->value.y=(e1.value.z==e2.value.z);
			if ((e1.type==typeChar)&&(e1.type==typeReal))
				e3->value.y=(e1.value.z==e2.value.w);
			return;
		case(T_nequal):
			if ((e1.type==typeInteger)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.x!=e2.value.x);
			if ((e1.type==typeInteger)&&(e1.type==typeReal))
				e3->value.y=(e1.value.x!=e2.value.w);
			if ((e1.type==typeInteger)&&(e1.type==typeChar))
				e3->value.y=(e1.value.x!=e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.w!=e2.value.x);
			if ((e1.type==typeReal)&&(e1.type==typeChar))
				e3->value.y=(e1.value.w!=e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeReal))
				e3->value.y=(e1.value.w!=e2.value.w);
			if ((e1.type==typeChar)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.z!=e2.value.x);
			if ((e1.type==typeChar)&&(e1.type==typeChar))
				e3->value.y=(e1.value.z!=e2.value.z);
			if ((e1.type==typeChar)&&(e1.type==typeReal))
				e3->value.y=(e1.value.z!=e2.value.w);
			return;
		case(T_greater):
			if ((e1.type==typeInteger)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.x>e2.value.x);
			if ((e1.type==typeInteger)&&(e1.type==typeReal))
				e3->value.y=(e1.value.x>e2.value.w);
			if ((e1.type==typeInteger)&&(e1.type==typeChar))
				e3->value.y=(e1.value.x>e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.w>e2.value.x);
			if ((e1.type==typeReal)&&(e1.type==typeChar))
				e3->value.y=(e1.value.w>e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeReal))
				e3->value.y=(e1.value.w>e2.value.w);
			if ((e1.type==typeChar)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.z>e2.value.x);
			if ((e1.type==typeChar)&&(e1.type==typeChar))
				e3->value.y=(e1.value.z>e2.value.z);
			if ((e1.type==typeChar)&&(e1.type==typeReal))
				e3->value.y=(e1.value.z>e2.value.w);
			return;
		case(T_lequal):
			if ((e1.type==typeInteger)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.x<=e2.value.x);
			if ((e1.type==typeInteger)&&(e1.type==typeReal))
				e3->value.y=(e1.value.x<=e2.value.w);
			if ((e1.type==typeInteger)&&(e1.type==typeChar))
				e3->value.y=(e1.value.x<=e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.w<=e2.value.x);
			if ((e1.type==typeReal)&&(e1.type==typeChar))
				e3->value.y=(e1.value.w<=e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeReal))
				e3->value.y=(e1.value.w<=e2.value.w);
			if ((e1.type==typeChar)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.z<=e2.value.x);
			if ((e1.type==typeChar)&&(e1.type==typeChar))
				e3->value.y=(e1.value.z<=e2.value.z);
			if ((e1.type==typeChar)&&(e1.type==typeReal))
				e3->value.y=(e1.value.z<=e2.value.w);
			return;
		case(T_egreater):
			if ((e1.type==typeInteger)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.x>=e2.value.x);
			if ((e1.type==typeInteger)&&(e1.type==typeReal))
				e3->value.y=(e1.value.x>=e2.value.w);
			if ((e1.type==typeInteger)&&(e1.type==typeChar))
				e3->value.y=(e1.value.x>=e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.w>=e2.value.x);
			if ((e1.type==typeReal)&&(e1.type==typeChar))
				e3->value.y=(e1.value.w>=e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeReal))
				e3->value.y=(e1.value.w>=e2.value.w);
			if ((e1.type==typeChar)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.z>=e2.value.x);
			if ((e1.type==typeChar)&&(e1.type==typeChar))
				e3->value.y=(e1.value.z>=e2.value.z);
			if ((e1.type==typeChar)&&(e1.type==typeReal))
				e3->value.y=(e1.value.z>=e2.value.w);
			return;
		case(T_less):
			if ((e1.type==typeInteger)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.x<e2.value.x);
			if ((e1.type==typeInteger)&&(e1.type==typeReal))
				e3->value.y=(e1.value.x<e2.value.w);
			if ((e1.type==typeInteger)&&(e1.type==typeChar))
				e3->value.y=(e1.value.x<e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.w<e2.value.x);
			if ((e1.type==typeReal)&&(e1.type==typeChar))
				e3->value.y=(e1.value.w<e2.value.z);
			if ((e1.type==typeReal)&&(e1.type==typeReal))
				e3->value.y=(e1.value.w<e2.value.w);
			if ((e1.type==typeChar)&&(e1.type==typeInteger))
				e3->value.y=(e1.value.z<e2.value.x);
			if ((e1.type==typeChar)&&(e1.type==typeChar))
				e3->value.y=(e1.value.z<e2.value.z);
			if ((e1.type==typeChar)&&(e1.type==typeReal))
				e3->value.y=(e1.value.z<e2.value.w);
			return;
	}
}

void makeLogical(Expression e1,Expression e2,Expression * e3,int operator){

	if ((operator==T_and)||(operator==T_AND))
		e3->value.y=e1.value.y&&e2.value.y;
	else
		e3->value.y=e1.value.y||e2.value.y;
	
}
Expression typeInference(Expression e1,Expression e2,int operator,bool two_expressions) {

	
	Expression e3;

	if (two_expressions)
        e3.is_constant=e1.is_constant&&e2.is_constant;
    else 
    	e3.is_constant=e1.is_constant;

	if ((operator==T_plus)||(operator==T_minus)||(operator==T_mult)||(operator==T_div)||(operator==T_MOD)||(operator==T_mod)&&(two_expressions)) {
		
		if ((e1.type==typeBoolean)||(e2.type==typeBoolean))
			fatal("Expression in operator not of arithmetic type . Line = %d\n",lineno);
		
		if ((operator==T_MOD)||(operator==T_mod)) {
			if ((e1.type==typeReal)||(e2.type==typeReal))
				fatal("Expression in modulo not of integer types. Line = %d\n",lineno);
            e3.type=typeInteger;
            if (e3.is_constant) makeInteger(e1,e2,&e3,operator);
            	
        }
        else {
            if ((e1.type==typeReal)||(e2.type==typeReal)) {
            	e3.type=typeReal;
            	if (e3.is_constant) makeReal(e1,e2,&e3,operator);
            }
            else {
            	e3.type=typeInteger;
            	if (e3.is_constant) makeInteger(e1,e2,&e3,operator);
            }
		}
	}

	if ((operator==T_equal)||(operator==T_nequal)||(operator==T_greater)||(operator==T_lequal)||(operator==T_egreater)||(operator==T_less)) {
		if ((e1.type==typeBoolean)||(e2.type==typeBoolean))
			fatal("Expression in comparison not of arithmetic type. Line = %d\n",lineno);
		e3.type=typeBoolean;
		if (e3.is_constant)
			makeComparison(e1,e2,&e3,operator);
    }

    if ((operator==T_and)||(operator==T_AND)||(operator==T_or)||(operator==T_OR)) {
    	if ((e1.type!=typeBoolean)||(e2.type!=typeBoolean))
    		fatal("Expression in logical operator not of boolean type. Line = %d\n",lineno);
    	e3.type=typeBoolean;
    	if (e3.is_constant)
    		makeLogical(e1,e2,&e3,operator);
    }

    if ((operator==T_not)||(operator==T_notb)) {
    	if ((e1.type!=typeBoolean)||(e2.type!=typeBoolean))
    		fatal("Expression in logical ΝΟΤ , not of arithmetic type. Line = %d\n",lineno);
    	e3.type=typeBoolean;
    	if (e3.is_constant)
    		e3.value.y= !e1.value.y;

    }

    if (((operator==T_plus)||(operator==T_minus))&&(!two_expressions)) {
    	if ((e1.type==typeBoolean)||(e2.type==typeBoolean))
    		fatal("Expression in sign relative operator must be of arithmetic type . Line = %d\n",lineno);
    	e3.type=e1.type;
    	if (e3.is_constant) {
    		if (e1.type==typeReal)
    			e3.value.w= -e1.value.w;
    		else if (e1.type==typeInteger)
    			e1.value.x= -e1.value.x;
    		else 
    			e3.value.z= -e1.value.z;
    	}
    }

    return e3;



}

void yyerror(const char *msg)
{
	extern int lineno;
	extern char *yytext;

	printf("ERROR: %s at symbol \" %s",msg,yytext);
	printf(" \" on line %d \n",lineno);
	exit(0);
}

int main(){

	/* initialize symbol table and open the global scope */
	initSymbolTable(256);
	//printSymbolTable();
	openScope();
	//printSymbolTable();

	int result = yyparse();

	if (!result) 
		printf("Parsing was complete\n");
	return 1;
}

