%{
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symbol.h"
#include "quadruples.h"


extern int lineno;
extern unsigned int   tempNumber;
void yyerror (const char *msg);
Type global_type,function_type;
SymbolEntry *p,*f,*next_parameter;
bool evaluate_constant,l_value_flag,we_define_globals = 1,got_lvalue_from_table,function_is_defined = false,found_return_statement = false;
char *global_type_string,*global_routine_name;
int parameter_counter,total_parameters,loop_counter,count_lvalue_dimensions = 0,dimensions_in_expressions,Q,count_lvalues;
SymbolEntry *W,*W1,*W2,*W3,*Wq;
char temp_name1[5],temp_name2[5],temp_name3[5];
int temp,N;
loop_stack *loop_seq;
switch_stack *switch_seq;
char *array_result_name;
int array_dimensions=0,counter=0,min_expr;
FILE *fp;
Type t; 
quad_node *L,*L1,*L2,*L3;

%}


%code requires {

#include "symbol.h"
#include "quadruples.h"
}


%union {
RepInteger integer_value;
RepBoolean boolean_value;
RepChar character_value;
RepReal real_value;
RepString string_value;
Expression expression;
Type type;
Statement statement;
Routine routine;
Range range;
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
%token T_do 
%token T_DOWNTO "DOWNTO"
%token T_else "else"
%token T_false "false"
%token T_FOR 
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
%token T_while 
%token T_WRITE "WRITE"
%token T_WRITELN "WRITELN"
%token T_WRITESP "WRITESP"
%token T_WRITESPLN "WRITESPLN"
%token T_const_int 
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

%type<string_value> type T_id range_choose
%type<expression> const_expr expr l_value cond call T_const_int T_const_real T_const_char T_string T_true T_false 
%type<type> var_init_list  formal_list 
%type<statement>  block stmt block_list choose_case switch_cases T_while T_do T_FOR
%type<routine> routine routine_header choose program_header
%type<range> range


%%

/* Grammar starts here 
 * Basic declarations that make up a program
 */
module : {fp = fopen("quads.txt","w+");printf("file opened"); } declaration_list {  closeScope();printf("program finished\n"); };

declaration_list : declaration declaration_list { } 
				   | /*nothing*/{ } ;

declaration : const_def { }
		    | var_def { }
		    | routine { we_define_globals = 1;}
		    | program { we_define_globals = 1;} ;


/* Constants definition.
 */
const_def  : T_const type T_id T_assign const_expr const_def_list T_mark { 	validate_Constant($3,$5); /*quad*/ GENQUAD(":=",$5.name,"-",strdup($3));};


const_def_list : T_coma T_id T_assign const_expr const_def_list { 	validate_Constant(strdup($2),$4); /*quad*/ GENQUAD(":=",$4.name,"-",strdup($2));}
			   | /****nothing***/ {  };


/* Variables definition.
 */

//must take the variables into consideration with the right order example : int x,y,z,x the last x has the problem
var_def : type T_id { validate_Variable($2,global_type); } 
		  var_def_list T_mark { }
		| type T_id T_assign expr { validate_Variable_with_assignment(strdup($2),global_type,$4); /*quad*/ GENQUAD(":=",$4.name,"-",strdup($2));printf("expression passed to temp var\n");} var_def_list T_mark { }
	    | type T_id var_init_list { validate_Variable($2,$3); } var_def_list T_mark { };

var_def_list :   T_coma T_id {  validate_Variable($2,global_type);  } 
				 var_def_list  { }
 			   | T_coma T_id T_assign expr { validate_Variable_with_assignment(strdup($2),global_type,$4); /*quad*/ GENQUAD(":=",$4.name,"-",strdup($2));} var_def_list { }
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
routine_header: choose T_lpar routine_header_if T_rpar { endFunctionHeader(p,function_type); /*quad*/$$.name = $1.name;} ;
	       
choose : T_PROC T_id {  validate_Routine($2,typeVoid); /*quad*/$$.name = strdup($2);}
	   | T_FUNC type T_id { validate_Routine($3,global_type); /*quad*/ $$.name = strdup($3);};
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
	    | routine_header {/*quad*/printf("before routine header\n");
	    			      GENQUAD("unit",$1.name,"-","-");
	    			      printf("after routine header\n");} block { if ((!found_return_statement)&&(function_type != typeVoid))
	    						 	fatal("Function '%s' does not return aprropriate value\n",p->id);
	    						 we_define_globals = 1; 
	    						 function_is_defined = false; 
	    						 found_return_statement = false;
	    						 closeScope(); 
	    						 
	    						 /*quad*/
	    						 printf("before whole program block\n");
	    						 sprintf(temp_name1,"%d",NEXTQUAD());
	    						 BACKPATCH(fp,$3.NEXT,temp_name1);GENQUAD("endu",$1.name,"-","-");
	    						 if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
	    						 printf("after whole program block\n");
	    						 
	    					   };


program_header : T_PROGRAM T_id T_lpar T_rpar { if (lookupEntry($2,LOOKUP_CURRENT_SCOPE,0))
	   						fatal("Can not declare main program with name '%s',name already used. Line = %d\n",$2,lineno);
	   					p = newFunction($2); 
						openScope(); 
						endFunctionHeader(p,typeVoid);
						/*quad*/ $$.name = strdup($2); 
						};

program : program_header { we_define_globals = 0; /*quad*/ GENQUAD("unit",$1.name,"-","-");printf("program unit created\n");} block {   printf("before whole program block\n");sprintf(temp_name1,"%d",NEXTQUAD());printf("inside whole program block 1\n");print_list($3.NEXT);BACKPATCH(fp,$3.NEXT,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("inside whole program block 2\n");printf("program name: %s\n",$1.name);GENQUAD("endu",$1.name,"-","-");printf("after whole program block\n"); /*quad*/ closeScope(); };





/* Types
 */
type : T_int  { $$=strdup("Integer"); global_type=typeInteger; global_type_string=strdup("Integer"); }
	 | T_bool { $$=strdup("Boolean"); global_type=typeBoolean; global_type_string=strdup("Boolean"); }
	 | T_char { $$=strdup("Character");    global_type=typeChar; global_type_string=strdup("Character"); }
	 | T_REAL { $$=strdup("Real");    global_type=typeReal; global_type_string=strdup("Real"); } ;


 

/* lvalue explanation.
 * lvalue returns an expression struct.type may be an arrrayType.
 * in case of array expression must be valid in brackets
 */

l_value : T_id { $$ = checkForLvalue($1);  /*quad*/$$.name = strdup($1);};
		| T_id {printf("writing array name\n");array_result_name = strdup($1);min_expr = tempNumber;} T_lbracket expr T_rbracket  l_value_list {   if ($4.is_constant) 
		     							if (check_array_dimension($4)) 
		     								fatal("Array subscript is not an integer. Line = %d",lineno);
		     						dimensions_in_expressions++;
		     						$$ = checkForArrayLvalue($1);
		     						dimensions_in_expressions = 0;
		     				       /*quad*/ printf("before array\n");
		     						W = newTemporary($$.type);
		     						$$.name = strdup(W->id);
		     						printf("array 3\n");    
		     						   
		     						printf("array 4\n");
		     						if(array_dimensions == 0){
		     							t = (Type) new(sizeof(struct Type_tag));
		     							printf("array 6a\n");
		     							t->kind = TYPE_INTEGER;
		     							printf("array 7a\n");
		     							t->refCount=0;
		     							printf("array 8a\n");
		     							W1 = newTemporary(t);
		     							printf("array 9a\n");
		     							sprintf(temp_name3,"$%d",(min_expr+array_dimensions));
		     							GENQUAD("array",strdup($1),temp_name3,strdup(W1->id));
		     													}
		     						else {
		     							printf("array 5b\n");
		     							sprintf(temp_name1,"$%d",(tempNumber-2));
		     							printf("array 7b\n");
		     							t->kind = TYPE_INTEGER;
		     							t->refCount=0;
		     							printf("array 8b\n");
		     							W1 = newTemporary(t);
		     							printf("array 9b\n");
		     							sprintf(temp_name3,"$%d",(min_expr+array_dimensions));
		     							GENQUAD("array",temp_name1,temp_name3,strdup(W1->id));
		     													}
		     						array_dimensions=0;
		     						printf("after array\n");
		     						sprintf(temp_name1,"$%d",(tempNumber-1));
		     						GENQUAD(":=",strdup(W1->id),"-",strdup(W->id));
		     						counter = 0;
		     									};

l_value_list :   /***nothing***/ { }
		     | T_lbracket expr T_rbracket l_value_list { dimensions_in_expressions++;
		     						if ($2.is_constant) 
		     							if (check_array_dimension($2)) 
		     								fatal("Array subscript is not an integer. Line = %d",lineno);
		     				       /*quad*/ printf("before array more dim\n");
		     				       		t = (Type) new(sizeof(struct Type_tag));
		     				       		if(array_dimensions == 0){
		     				       				
		     							printf("array 6a\n");
		     							t->kind = TYPE_INTEGER;
		     							printf("array 7a\n");
		     							t->refCount=0;
		     							printf("array 8a\n");
		     							W1 = newTemporary(t);
		     							printf("array 9a\n");
		     							sprintf(temp_name3,"$%d",(min_expr+array_dimensions));
		     							GENQUAD("array",array_result_name,temp_name3,strdup(W1->id));
		     						}
		     						else {
		     							
		     							printf("array 5b\n");
		     							sprintf(temp_name1,"$%d",(tempNumber-1));
		     							printf("array 6b\n");
		     							sprintf(temp_name2,"$%d",tempNumber);
		     							printf("array 7b\n");
		     							t->kind = TYPE_INTEGER;
		     							t->refCount=0;
		     							printf("array 8b\n");
		     							W1 = newTemporary(t);
		     							printf("array 9b\n");
		     							sprintf(temp_name3,"$%d",(min_expr+array_dimensions));
		     							GENQUAD("array",temp_name1,temp_name3,temp_name2);
		     						}
		     						array_dimensions++;
		     						printf("after array more dim\n");
		     				} ;
	 		





/* FUNCTION CALLS */

call :  T_id {  f = lookupEntry($1,LOOKUP_ALL_SCOPES,0);
		if ((!f)||(f->entryType!=ENTRY_FUNCTION))
		       	fatal("Function '%s' is not declared. Line = %d\n",$1,lineno);
                next_parameter = f->u.eFunction.firstArgument; 
                parameter_counter = 0;; 
                total_parameters = countParameters(f) ;
                /*quad*/ global_routine_name = strdup($1);
                				  } 
        T_lpar {/*quad*/  N = 1;} call_if T_rpar { $$.type=f->u.eFunction.resultType; /*quad*/ if ( ISFUNCTION(strdup($1)) ){$$.temp = tempNumber;W = newTemporary(FUNCRESULT(strdup($1)));$$.name = strdup(W->id);GENQUAD("par","RET",strdup(W->id),"-");}GENQUAD("call","-","-",strdup($1));}; 
call_if :{ l_value_flag = 1; } expr {  validateParameter($2,next_parameter);
		  	      /*quad*/ if ( PARAMMODE(global_routine_name,N) == "V" && ($2.type != PARAMTYPE(global_routine_name,N) ) )
						{GENQUAD("par",$2.name,PARAMMODE(global_routine_name,N),"-");}
					else
						{
						exit(0);
						GENQUAD("par",$2.name,PARAMMODE(global_routine_name,N),"-");}
					N = N+1;} call_if_list { }
		| /***nothing***/ { if (next_parameter) 
					fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno);
						  };
call_if_list :  T_coma { l_value_flag = 1; } expr {  validateParameter($3,next_parameter);
				/*quad*/ if ( PARAMMODE(global_routine_name,N) == "V" && ($3.type != PARAMTYPE(global_routine_name,N) ) )
						{GENQUAD("par",$3.name,PARAMMODE(global_routine_name,N),"-");}
					else
						{GENQUAD("par",$3.name,PARAMMODE(global_routine_name,N),"-");}
					N = N+1; } call_if_list { }
			 | /***nothing***/ { if (next_parameter) 
						fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno); 
							   };






block : T_lhook block_list T_rhook { /*quad*/ printf("open hook-block\n");$$.NEXT = $2.NEXT;printf("close hook-block\n");};
block_list : local_def block_list {  /*quad*/ printf("first local_def of block list\n");$$.NEXT = $2.NEXT;printf("rest local_defs of block list\n");}
		   | stmt {/*quad*/ printf("first stmt of block list\n");L = $1.NEXT; printf("first stmt of block list 1\n");sprintf(temp_name1,"%d",NEXTQUAD());printf("first stmt of block list 2\n");print_list(L);printf("   fp =  %d \n",fileno(fp));BACKPATCH(fp,L,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("   fp =  %d \n",fileno(fp));printf("after first stmt of block list\n");} block_list { /*quad*/ printf("rest stmts of block list\n");$$.NEXT = $3.NEXT;printf("after rest stmts of block list\n"); }
		   | /***nothing***/ { /*quad*/ printf("no other stmts-defs in block\n");$$.NEXT = NULL;} ;

local_def : const_def { }
		  | var_def { };







/* STATEMENTS */

stmt : T_mark { /*quad*/  $$.NEXT = EMPTYLIST();}
     | l_value T_assign expr T_mark {   if ($1.is_constant) 
     						fatal("Cannot change constant value. Line = %d\n",lineno);
     					else if (!assignmentEvaluation($1.type,$3.type))
     						fatal("Invalid assignment.Cannot assign %s to %s. Line = %d\n",getType($3.type),getType($1.type),lineno);
     					/*quad*/  
     					printf("before assign statement\n");
     					GENQUAD(":=",$3.name,"-",$1.name);
     					$$.NEXT = EMPTYLIST();
     					printf("after assign statement\n");
     					
     									}
     | l_value T_plusassign expr T_mark  {  operationAndAssignment($1,$3,T_plus);  /*quad*/  printf("before plusassign\n");GENQUAD("+",$3.name,$1.name,$1.name);$$.NEXT = EMPTYLIST();printf("after plusassign\n"); }
     | l_value T_minusassign expr T_mark {  operationAndAssignment($1,$3,T_minus);  /*quad*/   printf("before minusassign\n");GENQUAD("-",$3.name,$1.name,$1.name);$$.NEXT = EMPTYLIST();printf("after minusassign\n");}
     | l_value T_multassign expr T_mark  {  operationAndAssignment($1,$3,T_mult);   /*quad*/   printf("before multassign\n");GENQUAD("*",$3.name,$1.name,$1.name);$$.NEXT = EMPTYLIST();printf("after multassign\n");}
     | l_value T_divassign expr T_mark   {  operationAndAssignment($1,$3,T_div);    /*quad*/   printf("before divassign\n");GENQUAD("/",$3.name,$1.name,$1.name);$$.NEXT = EMPTYLIST();printf("after divassign\n");}
     | l_value T_modassign expr T_mark   {  operationAndAssignment($1,$3,T_mod);    /*quad*/   printf("before modassign\n");GENQUAD("%",$3.name,$1.name,$1.name);$$.NEXT = EMPTYLIST();printf("after modassign\n");}
     | l_value T_pp  T_mark { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     				operationAndAssignment($1,unit_expression,T_plus); 
     			/*quad*/   printf("before ++\n");GENQUAD("+",$1.name,"1",$1.name);$$.NEXT = EMPTYLIST();printf("after ++\n");
     						}
     | l_value T_mm T_mark  { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     					operationAndAssignment($1,unit_expression,T_minus);   
     					/*quad*/   printf("before --\n");GENQUAD("-",$1.name,"1",$1.name);$$.NEXT = EMPTYLIST();printf("after --\n");
     													} 
     | call T_mark { /*quad*/ $$.NEXT = EMPTYLIST();}
     | T_if T_lpar cond T_rpar {/*quad*/ printf("before if cond\n");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,$3._TRUE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");L1 = $3._FALSE_; L2 = EMPTYLIST();printf("after if cond\n");}
     	 stmt {   if (!equalType($3.type,typeBoolean)) 
			fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     			
		/*quad*/ printf("before if stmt\n");
			L3 = MERGE($6.NEXT,L2);
			printf("if stmt 1 \n");
			$$.NEXT = MERGE(L1,L3);
			printf("after if stmt\n");							
     								}
     | T_if T_lpar cond T_rpar {/*quad*/ printf("before if-else cond\n");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,$3._TRUE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");L1 = $3._FALSE_; L2 = EMPTYLIST();printf("after if-else cond\n");} 
     	stmt T_else {/*quad*/printf("before if-else stmt\n");L1 = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,$3._FALSE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("after if-else stmt\n");} 
     	stmt {  if (!equalType($3.type,typeBoolean)) 
			fatal("Expression in if statement not boolean. Line = %d\n",lineno);
		/*quad*/ 
		printf("before if-else\n"); 
		L2 = $9.NEXT;
		L3 = MERGE($6.NEXT,L2);
		$$.NEXT = MERGE(L1,L3);	
		printf("after if-else\n"); 
     					}
     | T_while { loop_counter++; 
     		/*quad*/ 
     		printf("entered while\n");
     		$1.NEXT = EMPTYLIST();
     		Q = NEXTQUAD();
     		if(loop_seq == NULL)
     			loop_seq = makeLoopStack(&($1),Q);
     		else 
     			loop_seq = LoopPush(loop_seq,Q,&($1));
     		printf("after word while\n");
     						} 
       T_lpar cond T_rpar {/*quad*/ printf("enter after cond\n");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,$4._TRUE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("leave after cond\n");} 
       stmt {    if (!equalType($4.type,typeBoolean)) 
			fatal("Expression in if statement not boolean. Line = %d\n",lineno);	
		loop_counter--; 
	/*quad*/
		printf("enter after stmt\n");
		sprintf(temp_name1,"%d",loop_seq->start);
		printf("while 1\n");
		BACKPATCH(fp,$7.NEXT,temp_name1);
		if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
		printf("while 2\n");
		sprintf(temp_name1,"%d",loop_seq->start);
		printf("while 3\n");
		GENQUAD("jump","-","-",temp_name1);
		printf("while 4\n");
		loop_seq = LoopPop(loop_seq);
		printf("while 5\n");
		//$$.NEXT = $4.NEXT;
		$$.NEXT = MERGE($1.NEXT,$4._FALSE_);
		printf("leave after stmt\n");}
     | T_FOR { loop_counter++; 
               /*quad*/ Q = NEXTQUAD()+4; 
               if(loop_seq == NULL)
              		loop_seq = makeLoopStack(&($1),Q);
              	else 
              		loop_seq = LoopPush(loop_seq,Q,&($1));
              						} 
       T_lpar T_id T_coma range {/*quad*/ 
       				  t = (Type) new(sizeof(struct Type_tag));
				  printf("FOR2\n");
				  t->kind = TYPE_INTEGER;
				  printf("FOR3\n");
				  t->refCount = 0;
			          printf("FOR4\n");
				  W3 = newTemporary(t);
				  printf("FOR5\n");
       				  GENQUAD(":=",$6.first,"-",strdup(W3->id));
       				  printf("FOR6\n");
       				  GENQUAD(":=",strdup(W3->id),"-",strdup($4)); 
       				  printf("FOR7\n");
       				  
       				  if($6.counting == 1) 
       				  	{ $1.NEXT = MAKELIST(NEXTQUAD());GENQUAD(">",strdup($4),$6.last,"*"); } 
       				  else if($6.counting == 2) 
       				  	{ $1.NEXT = MAKELIST(NEXTQUAD());GENQUAD("<",strdup($4),$6.last,"*");}
       				  									}
       T_rpar stmt {  	p = lookupEntry($4,LOOKUP_ALL_SCOPES,0);
     			if (!p) 
     				fatal("Variable '%s' in for loop does not exist. Line = %d\n",$4,lineno);
     			else if (!valid_loop_variable(p))
	   			fatal("Variable '%s' in for loop is not an integer. Line = %d\n");
    			loop_counter--;
    			/*quad*/ 
    			printf("FOR8\n");
    			printf("FOR9\n");
    			if($6.counting == 1){
    				printf("quads before last add: %d\n",NEXTQUAD());
    				GENQUAD("+",strdup(W3->id),$6.step,strdup(W3->id));
    				sprintf(temp_name1,"%d",loop_seq->start);
    				printf("quads before last jump: %d\n",NEXTQUAD());
    				GENQUAD("jmp1","-","-",temp_name1);
    				$$.NEXT = $1.NEXT;}
    			else if($6.counting == 2){
    				GENQUAD("-",strdup(W3->id),$6.step,strdup(W3->id));
    				sprintf(temp_name1,"%d",loop_seq->start);
    				GENQUAD("jmp1","-","-",temp_name1);
    				$$.NEXT = $1.NEXT;
    			}
    			loop_seq = LoopPop(loop_seq); 
    			printf("FOR10\n");
    						}
     | T_do {/*quad*/ Q = NEXTQUAD(); 
    		      printf("before do_while stmt\n");
     			if(loop_seq == NULL)
     				{loop_seq = makeLoopStack(&($1),Q);}
     			else 
     				{loop_seq = LoopPush(loop_seq,Q,&($1));}
     								}
       stmt {/*quad*/   printf("before do_while stmt\n");sprintf(temp_name1,"%d",NEXTQUAD());printf("%s\n",temp_name1);BACKPATCH(fp,$3.NEXT,temp_name1);printf("after do_while stmt\n");}
       T_while { loop_counter++; $1.NEXT = EMPTYLIST();} 
       T_lpar cond T_rpar 
       T_mark {    if (!equalType($8.type,typeBoolean)) 
			fatal("Expression in while statement not boolean. Line = %d\n",lineno);	
		printf("before 'closing' do-while statement\n");     	
		loop_counter--;
		/*quad*/ 
		printf("'closing' do-while statement 1\n"); 
		loop_seq = LoopPop(loop_seq);
		printf("'closing' do-while statement 2\n");
		sprintf(temp_name3,"%d",loop_seq->start);
		printf("'closing' do-while statement 3\n");
		BACKPATCH(fp,$8._TRUE_,temp_name3);
		if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
		printf("   fp =  %d \n",fileno(fp));
		$$.NEXT = MERGE($1.NEXT,$8._FALSE_);
		//printf("next of while is %d\n",$$.NEXT->quad_num);
		}
     | T_switch T_lpar expr {/*quad*/ printf("before switch expr\n");if(switch_seq == NULL){switch_seq = makeSwitchStack(&($3));}else {switch_seq = SwitchPush(switch_seq,&($3));printf("after switch expr\n");} }
       T_rpar T_lhook switch_cases 
       T_rhook  {    if ($3.type!=typeInteger)
     				fatal("Expression in switch statement is not integer. Line = %d\n",lineno);
     			/*quad*/ 
     				printf("before close switch\n");
     				switch_seq = SwitchPop(switch_seq);
     				printf("before close switch 1\n");
     			 	sprintf(temp_name1,"%d",NEXTQUAD());
     			 	printf("before close switch 2\n"); 
     			 	if($7.NEXT == NULL)	printf("malakia\n");
     			 	print_list($7.NEXT);
     			 	printf("before close switch 3\n");
     				BACKPATCH(fp,$7.NEXT,temp_name1);
     				if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
     				printf("after close switch \n");
     				$$.NEXT = NULL;
     						}
     | T_break T_mark { if (loop_counter==0) 
     			    	fatal("Break statement is not in a loop. Line = %d\n",lineno);
     		       /*quad*/ L = MAKELIST(NEXTQUAD());
     			   	GENQUAD("jmp","-","-","*");
     			   	(loop_seq->stmt)->NEXT = MERGE((loop_seq->stmt)->NEXT,L);
     			   	$$.NEXT = NULL;
     				   							}
     | T_cont T_mark  { if (loop_counter==0)
     				fatal("Continue statement is not in a loop. Line =%d\n",lineno);
     			/*quad*/ 
     			printf("entering continue\n");
     			sprintf(temp_name1,"%d",loop_seq->start);
     			printf("quads before cont: %d\n",NEXTQUAD());
     			GENQUAD("jmp","-","-",temp_name1);
     			printf("quads after cont: %d\n",NEXTQUAD());
     			printf("leaving continue\n");
     			$$.NEXT = NULL;
     				  					}
     | T_return expr T_mark { validate_return($2.type); found_return_statement = true; 
     				/*quad*/ 
     				GENQUAD(":=",$2.name,"-","$$");
     				GENQUAD("ret","-","-","-");
     				$$.NEXT = NULL;
     													}
     | T_return T_mark 		{ validate_return(typeVoid); /*quad*/ GENQUAD("ret","-","-","-");$$.NEXT = NULL;}
     | block { /*quad*/ $$.NEXT = $1.NEXT; }
     | write T_lpar T_rpar T_mark { }
     | write T_lpar format format_more T_rpar T_mark {  };




switch_cases : switch_cases choose_case   { /*quad*/ $$.NEXT = MERGE($1.NEXT,$2.NEXT); }
		   | /***nothing***/ {} ;

choose_case : T_case expr {/*quad*/ L = MAKELIST(NEXTQUAD());GENQUAD("<>",(switch_seq->expression)->name,$2.name,"*");}
	      T_2dots statement_list T_break T_mark {if (!equalType(typeInteger,$2.type)) 
							  fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
						   	  /*quad*/ 
						      L1 = MAKELIST(NEXTQUAD());
						      $$.NEXT = L1;
						      GENQUAD("jmp","-","-","*");
						      sprintf(temp_name1,"%d",NEXTQUAD());
						      BACKPATCH(fp,L,temp_name1);
						      if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
										}
		    | T_case expr {/*quad*/ L = MAKELIST(NEXTQUAD());GENQUAD("<>",(switch_seq->expression)->name,$2.name,"*");} 
		      T_2dots statement_list T_NEXT T_mark {   if (!equalType(typeInteger,$2.type)) 
									fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
									/*quad*/ 
								 	$$.NEXT = NULL; 
									sprintf(temp_name3,"%d",NEXTQUAD());
									BACKPATCH(fp,L,temp_name3);
									if(fileno(fp) == -1) fp = fopen("quads.txt","a+");			
											}
		    | T_def T_2dots statement_list T_break T_mark { $$.NEXT = NULL; } 
		    | T_def T_2dots statement_list T_NEXT T_mark { $$.NEXT = NULL;};
statement_list : statement_list  stmt { }
			   | { /*nothing*/ };


range : expr range_choose expr { validate_range_and_step($1,$3,$1,0);  /*quad*/ printf("entered range\n");
										$$.first = $1.name;
										$$.last = $3.name;
										printf("range1\n");
										if($2 == "TO")	
											$$.counting = 1;
										else if($2 == "DOWNTO")	
											$$.counting = 2;
										t = (Type) new(sizeof(struct Type_tag));
										printf("range2\n");
										t->kind = TYPE_INTEGER;
										printf("range3\n");
										t->refCount = 0;
										printf("range4\n");
										W = newTemporary(t);
										printf("range5\n");
										$$.step = strdup(W->id);
										printf("range6\n");
										GENQUAD(":=","1","-",$$.step);
										printf("left range\n"); 
										
															}
	  | expr range_choose expr T_STEP expr{ validate_range_and_step($1,$3,$5,1); 
	  					/*quad*/ printf("entered range TO/DOWN\n");
	  						 $$.first = $1.name;
	  						 $$.last = $3.name;
	  						 if($2 == "TO")	
	  							$$.counting = 1;
	  						 else if($2 == "DOWNTO")	
	  							$$.counting = 2;
	  						 $$.step = $5.name;
	  						 printf("left range TO/DOWN\n");
	  						 			}
range_choose : T_TO { $$ = "TO";  }
			 | T_DOWNTO { $$ = "DOWNTO"; };


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

/* Expressions.
 */

const_expr : { evaluate_constant=1; } expr { $$=$2; } ;

expr : T_const_int  { printf("   fp =  %d \n",fileno(fp));$$.type=typeInteger; $$.is_constant=1;  l_value_flag=0;   /*quad*/ Wq = newTemporary($$.type);sprintf(temp_name1,"%d",$1.value.x);$$.name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",$$.name);printf("temp var created\n");}
	 | T_const_real { $$.type=typeReal; $$.is_constant=1;  l_value_flag=0;     /*quad*/ Wq = newTemporary($$.type);sprintf(temp_name1,"%Lf",$1.value.w);$$.name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",$$.name);printf("temp var created\n");}
	 | T_const_char { $$.type=typeChar; $$.is_constant=1;  l_value_flag=0;     /*quad*/ Wq = newTemporary($$.type);sprintf(temp_name1,"%c",$1.value.z);printf("character %c  ---\n",($1.value.z));$$.name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",$$.name);printf("temp var created\n");}
	 | T_string 	{  $$.type=typeArray(strlen($$.value.q)+1,typeChar); $$.is_constant=1; l_value_flag=0;    /*quad*/Wq = newTemporary($$.type);sprintf(temp_name1,"%s",$1.value.q);$$.name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",$$.name);printf("temp var created\n");}
	 | T_true		{ $$.type=typeBoolean; $$.is_constant=1; l_value_flag=0;    /*quad*/ Wq = newTemporary($$.type);sprintf(temp_name1,"%u",$1.value.y);$$.name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",$$.name);printf("temp var created\n");}
	 | T_false		{ $$.type=typeBoolean; $$.is_constant=1; l_value_flag=0;    /*quad*/ Wq = newTemporary($$.type);sprintf(temp_name1,"%u",$1.value.y);$$.name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",$$.name);printf("temp var created\n");}
 	 | T_lpar expr T_rpar { $$=$2; l_value_flag=0;    } 
	 | l_value	      { $$=$1;  }
	 | call		      { $$.is_constant=0; $$.type=$1.type;l_value_flag=0;    /*quad*/  $$.name = $1.name;}
	 | T_plus expr 	        { $$=typeInference($2,$2,T_plus,0); l_value_flag=0;    /*quad*/ $$ = $2;}
	 | T_minus expr         { $$=typeInference($2,$2,T_minus,0);l_value_flag=0;    /*quad*/ Wq = newTemporary($$.type);$$.name = strdup(W->id);GENQUAD("-",$2.name,"-",$$.name);}
	 | expr T_plus expr     { $$=typeInference($1,$3,T_plus,1);l_value_flag=0;    /*quad*/ printf("before addition1\n");W = newTemporary($$.type);printf("before addition2\n");$$.name = strdup(W->id);printf("before addition3\n");GENQUAD("+",$1.name,$3.name,$$.name);printf("addition done new temp var created\n");}
	 | expr T_minus expr    { $$=typeInference($1,$3,T_minus,1);l_value_flag=0;    /*quad*/ W = newTemporary($$.type);$$.name = strdup(W->id);GENQUAD("-",$1.name,$3.name,$$.name);}
	 | expr T_mult expr     { $$=typeInference($1,$3,T_mult,1);l_value_flag=0;	/*quad*/ W = newTemporary($$.type);$$.name = strdup(W->id);GENQUAD("*",$1.name,$3.name,$$.name);}
	 | expr T_div expr      { $$=typeInference($1,$3,T_div,1);l_value_flag=0;	/*quad*/ W = newTemporary($$.type);$$.name = strdup(W->id);GENQUAD("/",$1.name,$3.name,$$.name);}
	 | expr T_mod expr      { $$=typeInference($1,$3,T_mod,1);l_value_flag=0;	/*quad*/ W = newTemporary($$.type);$$.name = strdup(W->id);GENQUAD("%",$1.name,$3.name,$$.name);}
	 | expr T_MOD expr      { $$=typeInference($1,$3,T_MOD,1);l_value_flag=0;	/*quad*/ W = newTemporary($$.type);$$.name = strdup(W->id);GENQUAD("%",$1.name,$3.name,$$.name);}
	 




cond	:	expr T_equal expr  { $$=typeInference($1,$3,T_less,1);l_value_flag=0;   /*quad*/ printf("before expr equal\n");$$._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("==",$1.name,$3.name,"*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr equal\n");}  
	|	expr T_nequal expr  { $$=typeInference($1,$3,T_nequal,1);l_value_flag=0;    /*quad*/ printf("before expr n_equal\n");$$._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("<>",$1.name,$3.name,"*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr n_equal\n");}  
	|	expr T_less expr   { $$=typeInference($1,$3,T_less,1);l_value_flag=0;    /*quad*/ printf("before expr less\n");$$._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("<",$1.name,$3.name,"*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr less\n");}  
	|	expr T_greater expr   { $$=typeInference($1,$3,T_greater,1);l_value_flag=0;    /*quad*/ printf("before expr greater\n");$$._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD(">",$1.name,$3.name,"*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr greater\n");}   
	|	expr T_lequal expr   { $$=typeInference($1,$3,T_lequal,1);l_value_flag=0;     /*quad*/ printf("before expr lequal\n");$$._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("<=",$1.name,$3.name,"*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr lequal\n");}   
	|	expr T_egreater expr   { $$=typeInference($1,$3,T_egreater,1);l_value_flag=0;    /*quad*/ printf("before expr egreater\n");$$._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD(">=",$1.name,$3.name,"*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr egreater\n");}   	;
	
cond	:	T_not cond  { $$=typeInference($2,$2,T_not,0);l_value_flag=0;   /*quad*/  $$._TRUE_ = $2._FALSE_; $$._FALSE_ = $2._TRUE_;} 
	|	T_notb cond  { $$=typeInference($2,$2,T_notb,0); l_value_flag=0;    /*quad*/  $$._TRUE_ = $2._FALSE_; $$._FALSE_ = $2._TRUE_;}  
	|	cond T_AND {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,$1._TRUE_,temp_name3 );if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); }cond  { $$=typeInference($1,$4,T_AND,1);l_value_flag=0;    /*quad*/ $$._TRUE_ = $4._TRUE_;$$._FALSE_ = MERGE($1._FALSE_,$4._FALSE_);} 
	|	cond T_and {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,$1._TRUE_,temp_name3 );if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); } cond  { $$=typeInference($1,$4,T_and,1);l_value_flag=0;    /*quad*/ $$._TRUE_ = $4._TRUE_;$$._FALSE_ = MERGE($1._FALSE_,$4._FALSE_);} 
	|	cond T_OR {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,$1._FALSE_,temp_name3 );if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); } cond   { $$=typeInference($1,$4,T_OR,1);l_value_flag=0;    /*quad*/ $$._TRUE_ = MERGE($1._TRUE_,$4._TRUE_);$$._FALSE_ = $4._FALSE_;}  
	|	cond T_or {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,$1._FALSE_,temp_name3);if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); } cond	 { $$=typeInference($1,$4,T_or,1);l_value_flag=0;    /*quad*/ $$._TRUE_ = MERGE($1._TRUE_,$4._TRUE_);$$._FALSE_ = $4._FALSE_;}  	;  

cond	:	expr	{/*quad*/printf("before expr->cond\n");$$._TRUE_ = MAKELIST(NEXTQUAD()); GENQUAD("ifb",$1.name,"-","*");$$._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr->cond\n");};
	
expr	:	cond	{/*quad*/ printf("before cond->expr\n");$$.temp = tempNumber;sprintf(temp_name1,"$%d",tempNumber);$$.name = temp_name1;W = newTemporary(typeBoolean);sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,$1._TRUE_,temp_name3);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");GENQUAD(":=","true","-",$$.name);Q = NEXTQUAD()+2;sprintf(temp_name2,"%d",Q);GENQUAD("jump","-","-",temp_name2);sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,$1._FALSE_,temp_name3);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");GENQUAD(":=","false","-",$$.name);printf("after cond->expr\n");};




%%

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
	openScope();

	int result = yyparse();
	destroySymbolTable();
	
	if (!result) 
		printf("Parsing was complete\n");
	return 1;
}

