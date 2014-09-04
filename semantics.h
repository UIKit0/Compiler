#ifndef SEMANTICS_H_
#define SEMANTICS_H_

/* structs used in bison YYLVAL 
 * return value 
 */
typedef struct node{
	int quad_num;
	struct node *next;
} quad_node ;


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
  bool is_constant ;
  quad_node *_TRUE_;
  quad_node *_FALSE_;
  int temp;
  char *name;} Expression;
  
typedef struct b
{
  quad_node *NEXT;} Statement;
  
typedef struct d
{
	char *first;
	char *last;		//names of temporary vars containing limit expressions
	int counting;		//1 for up counting,2 for down counting
	char *step;		//name of temp var containing step expression
}	Range;
  
typedef struct rout
{
  char *name;}Routine;

extern int lineno;
extern Type global_type,function_type;
extern SymbolEntry *p,*f,*next_parameter;
extern bool evaluate_constant,l_value_flag,we_define_globals ,got_lvalue_from_table,function_is_defined,found_return_statement ;
extern char *global_type_string;
extern int parameter_counter,total_parameters,loop_counter,count_lvalue_dimensions ,dimensions_in_expressions,count_lvalues;



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

#endif
