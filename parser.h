/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 2068 of yacc.c  */
#line 22 "parser.y"


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




/* Line 2068 of yacc.c  */
#line 83 "parser.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_bool = 258,
     T_and = 259,
     T_break = 260,
     T_case = 261,
     T_char = 262,
     T_const = 263,
     T_cont = 264,
     T_def = 265,
     T_do = 266,
     T_DOWNTO = 267,
     T_else = 268,
     T_false = 269,
     T_FOR = 270,
     T_FORM = 271,
     T_FUNC = 272,
     T_if = 273,
     T_int = 274,
     T_MOD = 275,
     T_NEXT = 276,
     T_not = 277,
     T_or = 278,
     T_PROC = 279,
     T_PROGRAM = 280,
     T_REAL = 281,
     T_return = 282,
     T_STEP = 283,
     T_switch = 284,
     T_TO = 285,
     T_true = 286,
     T_while = 287,
     T_WRITE = 288,
     T_WRITELN = 289,
     T_WRITESP = 290,
     T_WRITESPLN = 291,
     T_const_int = 292,
     T_const_real = 293,
     T_id = 294,
     T_const_char = 295,
     T_string = 296,
     T_equal = 297,
     T_greater = 298,
     T_less = 299,
     T_nequal = 300,
     T_egreater = 301,
     T_lequal = 302,
     T_plus = 303,
     T_minus = 304,
     T_mult = 305,
     T_div = 306,
     T_mod = 307,
     T_notb = 308,
     T_AND = 309,
     T_OR = 310,
     T_pp = 311,
     T_mm = 312,
     T_assign = 313,
     T_plusassign = 314,
     T_minusassign = 315,
     T_multassign = 316,
     T_divassign = 317,
     T_modassign = 318,
     T_ampersand = 319,
     T_mark = 320,
     T_dot = 321,
     T_lpar = 322,
     T_rpar = 323,
     T_2dots = 324,
     T_coma = 325,
     T_lbracket = 326,
     T_rbracket = 327,
     T_lhook = 328,
     T_rhook = 329,
     T_eof = 330
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 66 "parser.y"

RepInteger integer_value;
RepBoolean boolean_value;
RepChar character_value;
RepReal real_value;
RepString string_value;
Expression expression;
Type type;



/* Line 2068 of yacc.c  */
#line 187 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


