/*Sintaktikos Analitis 
NA simplirothei o kanonas gia dangling else an xreiazetai */

%{
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void yyerror (const char *msg);
%}

/* Bison generates numerical codes for 
*  tokes on its own
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
%token T_char "char"
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


%%
/** DIKOI MOU KANONES , PADELO **/

//κανονες Parser

module : declaration_list { };

declaration_list : declaration declaration_list { } 
				   | /*nothing*/ { } ;

declaration : const_def { }
		    | var_def { }
		    | routine { }
		    | program { } ;

const_def  : T_const type T_id T_assign const_expr const_def_list T_mark { } ;

const_def_list : T_coma T_id T_assign const_expr const_def_list { }
			     | /****nothing***/ { } ;

var_def : type var_init var_def_list T_mark { };

var_def_list : T_coma var_init var_def_list  { }
 			   | /***nothing***/ { };

var_init : T_id var_init_if { }
 		 | T_id var_init_list { };
var_init_if : T_assign expr { }
			| /***nothing***/  { } ;
var_init_list : T_lbracket const_expr T_rbracket var_init_list { }
			  | T_lbracket const_expr T_rbracket   { } ;

routine_header : routine_header_choose T_id T_lpar routine_header_if T_rpar { } ;
routine_header_choose : T_PROC { }
		      | T_FUNC type { } ;
routine_header_if : type formal routine_header_if_list { }
				  | /***nothing***/    { } ;
routine_header_if_list : T_coma type formal routine_header_if_list { }
					   | /***nothing***/ { } ;

formal : T_ampersand T_id { }
	   | T_id  { }
       | T_id T_lbracket formal_if2 T_rbracket formal_list { };
formal_if2 : const_expr { }
		   | /***nothing***/ { };
formal_list : T_lbracket const_expr T_rbracket formal_list { }
			|/***nothing***/  { } ;
			
routine : routine_header routine_header_choose  { } ;
routine_header_choose : T_mark { }
					  | block  { } ;

program_header : T_PROGRAM T_id T_lpar T_rpar { };

program : program_header block { };

type : T_int { }
	 | T_bool { }
	 | T_char { }
	 | T_REAL { } ;

const_expr : expr { } ;

expr : T_const_int { }
	 | T_const_real { }
	 | T_const_char { }
	 | T_string 	{ }
	 | T_true	{ }
	 | T_false	{ }
 	 | T_lpar expr T_rpar { } 
	 | l_value	      { }
	 | call
	 | T_plus expr 	      { }
	 | T_not expr 	      { }
	 | T_notb expr 	      { }
	 | T_minus expr       { }
	 | expr T_plus expr   { }
	 | expr T_minus expr  { }
	 | expr T_mult expr   { }
	 | expr T_div expr    { }
	 | expr T_mod expr    { }
	 | expr T_MOD expr    { }
	 | expr T_equal expr  { }
	 | expr T_nequal expr { }
	 | expr T_less expr   { }
	 | expr T_greater expr { }
	 | expr T_lequal expr  { }
	 | expr T_AND expr     { }
	 | expr T_and expr     { }
	 | expr T_OR expr      { }
	 | expr T_or expr      { }
	 | expr T_egreater expr { } ; 
 

l_value : T_id l_value_list { };

l_value_list :   /***nothing***/ { } 
		     | l_value_list T_lbracket expr T_rbracket { } ;
	 		
call : T_id T_lpar call_if T_rpar { }; 
call_if : expr call_if_list       { }
		| /***nothing***/ { } ;
call_if_list :  T_coma expr call_if_list { }
			 | /***nothing***/ { };

block : T_lhook block_list T_rhook { };
block_list : local_def block_list { }
		   | stmt block_list { }
		   | /***nothing***/ { } ;

local_def : const_def { }
		  | var_def { };

stmt : T_mark { }
     | l_value assign expr T_mark { }
     | l_value T_pp  T_mark { }
     | l_value T_mm T_mark { }
     | call T_mark { }
     | T_if T_lpar expr T_rpar stmt { }
     | T_if T_lpar expr T_rpar stmt T_else stmt { }
     | T_while T_lpar expr T_rpar stmt { }
     | T_FOR T_lpar T_id T_coma range T_rpar stmt { }
     | T_do stmt T_while T_lpar expr T_rpar T_mark { }
     | T_switch T_lpar expr T_rpar T_lhook stmt_list1 T_rhook  { }
     | T_switch T_lpar expr T_rpar T_lhook stmt_list1 T_def T_2dots clause T_rhook { }
     | T_break T_mark { }
     | T_cont T_mark  { }
     | T_return expr T_mark { }
     | T_return T_mark { }
     | block { }
     | write T_lpar T_rpar T_mark { }
     | write T_lpar format stmt_if5_list T_rpar T_mark { };

stmt_list1 : stmt_list1 stmt_list1_list clause  { }
		   | /***nothing***/ { } ;
stmt_list1_list : stmt_list1_list T_case const_expr T_2dots { } 
				| T_case const_expr T_2dots { } ;


stmt_if5_list : T_coma format stmt_if5_list { }
		      | /***nothing***/     { };

assign : T_assign { }
	   | T_plusassign { }
	   | T_minusassign { }
	   | T_multassign { }
	   | T_divassign { }
	   | T_modassign { };

range : expr range_choose expr range_if { };
range_choose : T_TO { }
			 | T_DOWNTO { };
range_if     : T_STEP expr { }
		     | /***nothing***/ { };

clause : clause_list T_break T_mark { }
 	   | clause_list T_NEXT T_mark { };
 
clause_list : clause_list stmt { } 
		    | /***nothing***/ { };


write : T_WRITE { }
     | T_WRITELN { }
     | T_WRITESP { }
     | T_WRITESPLN { };

format : expr { }
       | T_FORM T_lpar expr T_coma expr format_if T_lpar { };
format_if : T_coma expr { }
          | /***nothing***/ { };


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
	return yyparse();
	printf("Parsing was complete\n");
}

