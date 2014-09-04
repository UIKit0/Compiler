
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"



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


	/* l_value_flag is used in routine calls in pass by reference mode
	 * in order to determine if we give a PROPER lvalue
	 */


	count_lvalues++;

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
		if (type==typeInteger) { 
			expr.value.x = symbol_table_entry->u.eConstant.value.vInteger;
			expr.type = type;
		}
		else if (type==typeBoolean) 
			expr.value.y = symbol_table_entry->u.eConstant.value.vBoolean;
		else if (type==typeChar) { 
			expr.value.z = symbol_table_entry->u.eConstant.value.vChar;
			expr.type = type;
		}	
		else if (type==typeReal) { 
			expr.value.w = symbol_table_entry->u.eConstant.value.vReal;
			expr.type = type;
		}
		else {
			expr.value.q = strdup(symbol_table_entry->u.eConstant.value.vString);
			expr.type = typeArray(strlen(expr.value.q)+1,typeChar);
		}

		
		return expr;

	}

	
	
	// returns the actual type of varialbe or parameter
	// it may return arrayType

	if (symbol_table_entry->entryType==ENTRY_PARAMETER)
		type = symbol_table_entry->u.eParameter.type;
	else
		type = symbol_table_entry->u.eVariable.type;

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
	Type x,y;
	
	/* Two cases in which types CAN not match...i*/
	if (((t2!=typeInteger)&&(t2!=typeReal)&&(t2!=typeBoolean)&&(t2!=typeChar)) && ( !(t1!=typeInteger)&&(t1!=typeReal)&&(t1!=typeBoolean)&&(t1!=typeChar)))
		return false;

	if ( !((t2!=typeInteger)&&(t2!=typeReal)&&(t2!=typeBoolean)&&(t2!=typeChar)) && ((t1!=typeInteger)&&(t1!=typeReal)&&(t1!=typeBoolean)&&(t1!=typeChar)))
		return false;

	/* Case where both types are not original...check if they match */

	if (((t2!=typeInteger)&&(t2!=typeReal)&&(t2!=typeBoolean)&&(t2!=typeChar)) && ((t1!=typeInteger)&&(t1!=typeReal)&&(t1!=typeBoolean)&&(t1!=typeChar))) {
		
		x = t1->refType;
		while ((x!=typeInteger)&&(x!=typeReal)&&(x!=typeBoolean)&&(x!=typeChar)) 
			x = x->refType;
			
		y = t1->refType;
		while ((y!=typeInteger)&&(y!=typeReal)&&(y!=typeBoolean)&&(y!=typeChar)) 
			y = y->refType;

		if (x != y) 
			return false;
		else
			return true;

	}
	
	/* Types are all original simple type checking... */
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
