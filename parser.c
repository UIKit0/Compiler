/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

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





/* Line 268 of yacc.c  */
#line 92 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
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




/* Line 288 of yacc.c  */
#line 161 "parser.c"

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

/* Line 293 of yacc.c  */
#line 66 "parser.y"

RepInteger integer_value;
RepBoolean boolean_value;
RepChar character_value;
RepReal real_value;
RepString string_value;
Expression expression;
Type type;



/* Line 293 of yacc.c  */
#line 265 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 277 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1073

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      25,    31,    32,    33,    39,    40,    48,    49,    56,    57,
      62,    63,    70,    71,    77,    78,    79,    85,    89,    94,
      97,   101,   105,   106,   111,   112,   115,   117,   120,   122,
     123,   128,   132,   135,   138,   143,   144,   148,   150,   152,
     154,   156,   157,   160,   162,   164,   166,   168,   170,   172,
     176,   178,   180,   183,   186,   189,   192,   196,   200,   204,
     208,   212,   216,   220,   224,   228,   232,   236,   240,   244,
     248,   252,   256,   258,   264,   265,   270,   271,   277,   278,
     279,   284,   285,   286,   287,   293,   294,   298,   301,   304,
     305,   307,   309,   311,   316,   321,   326,   331,   336,   341,
     345,   349,   352,   358,   366,   367,   374,   375,   384,   385,
     393,   401,   404,   407,   411,   414,   416,   421,   428,   431,
     432,   439,   446,   452,   458,   461,   462,   466,   472,   474,
     476,   480,   481,   483,   492,   499,   501,   503,   505
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      77,     0,    -1,    78,    -1,    79,    78,    -1,    -1,    80,
      -1,    82,    -1,    99,    -1,   101,    -1,     8,   103,    39,
      58,   104,    81,    65,    -1,    70,    39,    58,   104,    81,
      -1,    -1,    -1,   103,    39,    83,    86,    65,    -1,    -1,
     103,    39,    58,   106,    84,    86,    65,    -1,    -1,   103,
      39,    90,    85,    86,    65,    -1,    -1,    70,    39,    87,
      86,    -1,    -1,    70,    39,    58,   106,    88,    86,    -1,
      -1,    70,    39,    90,    89,    86,    -1,    -1,    -1,    71,
     104,    72,    91,    90,    -1,    71,   104,    72,    -1,    93,
      67,    94,    68,    -1,    24,    39,    -1,    17,   103,    39,
      -1,   103,    96,    95,    -1,    -1,    70,   103,    96,    95,
      -1,    -1,    64,    39,    -1,    39,    -1,    39,    98,    -1,
     104,    -1,    -1,    71,    97,    72,    98,    -1,    71,    97,
      72,    -1,    92,    65,    -1,    92,   117,    -1,    25,    39,
      67,    68,    -1,    -1,   100,   102,   117,    -1,    19,    -1,
       3,    -1,     7,    -1,    26,    -1,    -1,   105,   106,    -1,
      37,    -1,    38,    -1,    40,    -1,    41,    -1,    31,    -1,
      14,    -1,    67,   106,    68,    -1,   107,    -1,   109,    -1,
      48,   106,    -1,    22,   106,    -1,    53,   106,    -1,    49,
     106,    -1,   106,    48,   106,    -1,   106,    49,   106,    -1,
     106,    50,   106,    -1,   106,    51,   106,    -1,   106,    52,
     106,    -1,   106,    20,   106,    -1,   106,    42,   106,    -1,
     106,    45,   106,    -1,   106,    44,   106,    -1,   106,    43,
     106,    -1,   106,    47,   106,    -1,   106,    46,   106,    -1,
     106,    54,   106,    -1,   106,     4,   106,    -1,   106,    55,
     106,    -1,   106,    23,   106,    -1,    39,    -1,    39,    71,
     106,    72,   108,    -1,    -1,    71,   106,    72,   108,    -1,
      -1,    39,   110,    67,   111,    68,    -1,    -1,    -1,   112,
     106,   113,   114,    -1,    -1,    -1,    -1,    70,   115,   106,
     116,   114,    -1,    -1,    73,   118,    74,    -1,   119,   118,
      -1,   120,   118,    -1,    -1,    80,    -1,    82,    -1,    65,
      -1,   107,    58,   106,    65,    -1,   107,    59,   106,    65,
      -1,   107,    60,   106,    65,    -1,   107,    61,   106,    65,
      -1,   107,    62,   106,    65,    -1,   107,    63,   106,    65,
      -1,   107,    56,    65,    -1,   107,    57,    65,    -1,   109,
      65,    -1,    18,    67,   106,    68,   120,    -1,    18,    67,
     106,    68,   120,    13,   120,    -1,    -1,    32,   121,    67,
     106,    68,   120,    -1,    -1,    15,   122,    67,    39,    70,
     127,    68,   120,    -1,    -1,    11,    32,   123,    67,   106,
      68,    65,    -1,    29,    67,   106,    68,    73,   124,    74,
      -1,     5,    65,    -1,     9,    65,    -1,    27,   106,    65,
      -1,    27,    65,    -1,   117,    -1,   131,    67,    68,    65,
      -1,   131,    67,   130,   129,    68,    65,    -1,   124,   125,
      -1,    -1,     6,   106,    69,   126,     5,    65,    -1,     6,
     106,    69,   126,    21,    65,    -1,    10,    69,   126,     5,
      65,    -1,    10,    69,   126,    21,    65,    -1,   126,   120,
      -1,    -1,   106,   128,   106,    -1,   106,   128,   106,    28,
     106,    -1,    30,    -1,    12,    -1,    70,   130,   129,    -1,
      -1,   106,    -1,    16,    67,   106,    70,   106,    70,   106,
      68,    -1,    16,    67,   106,    70,   106,    68,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   193,   194,   196,   197,   198,   199,   204,
     207,   208,   215,   215,   217,   217,   218,   218,   220,   220,
     222,   222,   223,   223,   224,   226,   226,   229,   238,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   256,   265,   272,   272,   280,   281,   282,
     283,   292,   292,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   334,   335,   343,   344,   357,   357,   365,   365,
     365,   366,   369,   369,   369,   370,   379,   380,   381,   382,
     384,   385,   395,   396,   401,   402,   403,   404,   405,   406,
     409,   412,   413,   416,   419,   419,   423,   423,   430,   430,
     434,   437,   440,   443,   444,   445,   446,   447,   452,   453,
     455,   458,   461,   462,   463,   464,   467,   468,   469,   470,
     474,   475,   476,   477,   479,   481,   482,   483,   484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"bool\"", "\"and\"", "\"break\"",
  "\"case\"", "\"char\"", "\"const\"", "\"continue\"", "\"default\"",
  "\"do\"", "\"DOWNTO\"", "\"else\"", "\"false\"", "\"FOR\"", "\"FORM\"",
  "\"FUNC\"", "\"if\"", "\"int\"", "\"MOD\"", "\"NEXT\"", "\"not\"",
  "\"or\"", "\"PROC\"", "\"PROGRAM\"", "\"REAL\"", "\"return\"",
  "\"STEP\"", "\"switch\"", "\"TO\"", "\"true\"", "\"while\"", "\"WRITE\"",
  "\"WRITELN\"", "\"WRITESP\"", "\"WRITESPLN\"", "T_const_int",
  "T_const_real", "T_id", "T_const_char", "T_string", "\"==\"", "\">\"",
  "\"<\"", "\"!=\"", "\">=\"", "\"<=\"", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"!\"", "\"AND\"", "\"OR\"", "\"++\"", "\"--\"",
  "\"=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&\"",
  "\";\"", "\".\"", "\"(\"", "\")\"", "\":\"", "\",\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "T_eof", "$accept", "module", "declaration_list",
  "declaration", "const_def", "const_def_list", "var_def", "$@1", "$@2",
  "$@3", "var_def_list", "$@4", "$@5", "$@6", "var_init_list", "$@7",
  "routine_header", "choose", "routine_header_if",
  "routine_header_if_list", "formal", "formal_if2", "formal_list",
  "routine", "program_header", "program", "$@8", "type", "const_expr",
  "$@9", "expr", "l_value", "l_value_list", "call", "$@10", "call_if",
  "$@11", "$@12", "call_if_list", "$@13", "$@14", "block", "block_list",
  "local_def", "stmt", "$@15", "$@16", "$@17", "switch_cases",
  "choose_case", "statement_list", "range", "range_choose", "format_more",
  "format", "write", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    79,    79,    80,
      81,    81,    83,    82,    84,    82,    85,    82,    87,    86,
      88,    86,    89,    86,    86,    91,    90,    90,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   102,   101,   103,   103,   103,
     103,   105,   104,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   110,   109,   112,   113,
     111,   111,   115,   116,   114,   114,   117,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   120,   122,   120,   123,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   124,   124,
     125,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   131,   131,   131,   131
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     7,
       5,     0,     0,     5,     0,     7,     0,     6,     0,     4,
       0,     6,     0,     5,     0,     0,     5,     3,     4,     2,
       3,     3,     0,     4,     0,     2,     1,     2,     1,     0,
       4,     3,     2,     2,     4,     0,     3,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     5,     0,     4,     0,     5,     0,     0,
       4,     0,     0,     0,     5,     0,     3,     2,     2,     0,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     3,
       3,     2,     5,     7,     0,     6,     0,     8,     0,     7,
       7,     2,     2,     3,     2,     1,     4,     6,     2,     0,
       6,     6,     5,     5,     2,     0,     3,     5,     1,     1,
       3,     0,     1,     8,     6,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    48,    49,     0,     0,    47,     0,     0,    50,     0,
       2,     4,     5,     6,     0,     0,     7,    45,     8,     0,
       0,     0,    29,     0,     1,     3,    42,    99,    43,    32,
       0,    12,     0,    30,     0,     0,     0,     0,   116,     0,
       0,     0,   114,   145,   146,   147,   148,    82,   102,   100,
     101,     0,     0,   125,     0,    99,    99,     0,     0,     0,
      46,     0,    51,    24,    16,    51,    44,   121,   122,   118,
       0,     0,    58,     0,    57,    53,    54,    55,    56,     0,
       0,     0,   124,     0,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
      96,    97,    98,     0,    28,    36,     0,    34,    14,     0,
       0,     0,     0,    24,    11,     0,     0,     0,    63,    62,
      65,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,    88,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   141,    51,    37,    35,     0,
      31,    24,    27,    52,    18,    13,     0,     0,     0,     0,
       0,     0,    59,    79,    71,    81,    72,    75,    74,    73,
      77,    76,    66,    67,    68,    69,    70,    78,    80,     0,
       0,    84,     0,     0,   103,   104,   105,   106,   107,   108,
       0,   126,     0,     0,     0,    38,     0,     0,     0,     0,
      24,    22,    17,     0,     9,     0,     0,   112,   129,     0,
       0,    83,    87,    89,     0,   141,     0,    41,    34,    15,
      26,    20,    19,    24,    51,     0,     0,     0,     0,     0,
     115,     0,    95,     0,   140,   127,    40,    33,    24,    23,
      11,   119,   139,   138,     0,     0,   113,     0,     0,   120,
     128,    84,    92,    90,     0,    21,    10,   136,   117,     0,
     135,    85,     0,   144,     0,     0,   135,     0,    93,     0,
     137,     0,     0,     0,   134,    95,   143,     0,     0,   121,
     133,    94,   121,   131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    49,   168,    50,    63,   161,   113,
     112,   210,   248,   233,    64,   208,    14,    15,    58,   160,
     107,   204,   157,    16,    17,    18,    30,    19,   109,   110,
     154,    85,   221,    86,    90,   192,   193,   242,   263,   272,
     285,    53,    54,    55,    56,    88,    70,   115,   239,   260,
     277,   237,   254,   203,   155,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -162
static const yytype_int16 yypact[] =
{
     108,  -162,  -162,    20,    20,  -162,   -22,    -3,  -162,    51,
    -162,   108,  -162,  -162,   -20,    -5,  -162,  -162,  -162,    33,
      34,    36,  -162,     9,  -162,  -162,  -162,   190,  -162,    20,
      30,   -45,    24,  -162,    37,    13,    39,    74,  -162,    16,
     881,    40,  -162,  -162,  -162,  -162,  -162,    10,  -162,  -162,
    -162,   414,    43,  -162,    38,   190,   190,    46,    42,   -21,
    -162,   921,  -162,    44,  -162,  -162,  -162,  -162,  -162,  -162,
      50,   921,  -162,   921,  -162,  -162,  -162,  -162,  -162,   921,
     921,   921,  -162,   921,   644,  -162,  -162,   921,    52,   921,
      53,    56,    57,   921,   921,   921,   921,   921,   921,  -162,
    -162,  -162,  -162,   135,  -162,    47,    84,    59,  1018,    54,
     921,    92,    70,    44,    66,    71,    98,   446,  -162,    18,
      18,  -162,   479,   921,   921,   921,   921,   921,   921,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   921,  -162,
     512,   921,   223,    72,  -162,  -162,   677,   710,   743,   776,
     809,   842,    75,    76,  1018,    73,    78,  -162,  -162,    20,
    -162,    44,    77,  1018,   -34,  -162,    82,   113,    88,   921,
      85,   355,  -162,   461,  -162,  1005,   526,    15,    15,   526,
      15,    15,    18,    18,  -162,  -162,  -162,   461,  1005,    83,
     545,    87,    91,   921,  -162,  -162,  -162,  -162,  -162,  -162,
     921,  -162,   901,    94,    93,  -162,   -21,    95,    97,   921,
      44,  -162,  -162,   106,  -162,   578,   921,   156,  -162,   355,
     921,  -162,  -162,  1018,   393,    73,   114,    47,    59,  -162,
    -162,  1018,  -162,    44,  -162,   115,   952,   117,   355,     0,
    -162,   237,   112,   921,  -162,  -162,  -162,  -162,    44,  -162,
      66,  -162,  -162,  -162,   921,   355,  -162,   921,   118,  -162,
    -162,    87,  -162,  -162,   357,  -162,  -162,   985,  -162,   410,
    -162,  -162,   921,  -162,   921,   921,  -162,   285,  1018,   611,
    1018,   320,   121,   124,  -162,   112,  -162,   125,   126,     5,
    -162,  -162,     6,  -162
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,   185,  -162,    14,   -50,    49,  -162,  -162,  -162,
    -109,  -162,  -162,  -162,  -161,  -162,  -162,  -162,  -162,   -18,
       1,  -162,   -15,  -162,  -162,  -162,  -162,     4,   -56,  -162,
     -39,   -27,   -55,   -25,  -162,  -162,  -162,  -162,   -71,  -162,
    -162,    -9,   -36,  -162,  -110,  -162,  -162,  -162,  -162,  -162,
     -44,  -162,  -162,    -4,    29,  -162
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -133
static const yytype_int16 yytable[] =
{
      51,    84,    52,   211,   166,    28,   257,    20,    21,   114,
     258,  -132,  -130,    61,    12,  -132,  -130,    22,   105,   101,
     102,    60,   108,     1,   209,    12,    62,     2,    51,    51,
      52,    52,   117,    59,   118,   124,    23,    62,   124,     5,
     119,   120,   121,   106,   122,    26,     8,   230,   140,    13,
     142,    24,   207,    27,   146,   147,   148,   149,   150,   151,
      13,   217,    29,   132,   133,   134,   135,   136,   134,   135,
     136,   163,    31,    32,   259,    33,    34,   -86,    67,  -132,
    -130,    89,    65,    71,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     205,   232,   190,    27,    68,    66,    69,    87,    99,   240,
     104,     1,   100,   103,   111,     2,     3,   116,   156,   141,
     143,   144,   145,   158,   249,     4,   162,     5,   256,   159,
     215,   164,     6,     7,     8,   165,   167,   170,   169,   265,
     -91,   201,   200,   202,    51,   268,    52,   212,   -25,    72,
     -39,   152,   213,   214,   223,   216,   218,    73,   220,   222,
     229,   224,   226,   206,   234,   227,    74,   284,    62,   238,
     231,   284,    75,    76,    47,    77,    78,   236,   250,   245,
     251,   241,   262,    79,    80,   255,   289,   270,    81,   290,
     292,   293,    51,     1,    52,    35,    25,     2,     3,    36,
     266,    37,    83,   153,   264,    38,   271,   228,    39,     5,
     247,    51,   246,    52,   291,   267,     8,    40,   269,    41,
       0,   244,    42,    43,    44,    45,    46,   123,    51,    47,
      52,   225,   281,   278,     0,   279,   280,     0,     0,     0,
       0,   123,     0,   124,     0,     0,   125,     0,     0,     0,
      51,     0,    52,     0,    51,    48,    52,   124,     0,     0,
     125,     0,     0,    27,     0,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,   137,   138,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     282,   137,   138,     0,    36,   191,    37,     0,     0,     0,
      38,     0,     0,    39,     0,     0,   283,     0,     0,   261,
       0,     0,    40,     0,    41,     0,     0,    42,    43,    44,
      45,    46,     0,     0,    47,   287,     0,     0,     0,    36,
       0,    37,     0,     0,     0,    38,     0,     0,    39,     0,
       0,   288,     0,     0,     0,     0,     0,    40,     0,    41,
      48,     0,    42,    43,    44,    45,    46,     0,    27,    47,
      35,   123,     0,     0,    36,     0,    37,     0,     0,     0,
      38,     0,     0,    39,     0,     0,     0,   124,     0,     0,
     125,     0,    40,     0,    41,    48,     0,    42,    43,    44,
      45,    46,     0,    27,    47,     0,     0,   123,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   124,   123,     0,   125,     0,     0,     0,
      48,     0,     0,     0,     0,   273,     0,   274,    27,     0,
     124,     0,     0,   125,     0,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,   137,   138,     0,
     123,     0,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   243,   137,   138,   124,     0,     0,   125,
      91,    92,    93,    94,    95,    96,    97,    98,     0,   276,
       0,   124,     0,   123,     0,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   124,
     137,   138,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   171,     0,   123,     0,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   124,   137,   138,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   172,     0,   123,
       0,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   124,   137,   138,   125,   127,
     128,     0,   130,   131,   132,   133,   134,   135,   136,     0,
     189,     0,   123,     0,     0,     0,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   124,   137,
     138,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,   123,     0,     0,     0,     0,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   124,   137,   138,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,   123,     0,
       0,     0,     0,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   124,   137,   138,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,   123,     0,     0,     0,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   124,   137,   138,
     125,     0,     0,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     124,   137,   138,   125,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,   123,     0,     0,
       0,     0,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   124,   137,   138,   125,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,     0,     0,
     123,     0,     0,     0,     0,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   124,   137,   138,   125,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,     0,     0,   123,     0,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   124,
     137,   138,   125,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,   123,     0,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   124,   137,   138,   125,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    72,   137,   138,     0,     0,
       0,     0,     0,    73,     0,     0,     0,   199,     0,     0,
       0,     0,    74,     0,     0,    72,     0,   152,    75,    76,
      47,    77,    78,    73,     0,     0,     0,     0,     0,    79,
      80,     0,    74,     0,    81,    72,     0,     0,    75,    76,
      47,    77,    78,    73,     0,     0,    82,     0,    83,    79,
      80,     0,    74,     0,    81,     0,   123,     0,    75,    76,
      47,    77,    78,     0,   252,     0,     0,     0,    83,    79,
      80,     0,   124,     0,    81,   125,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,     0,     0,    83,   123,
       0,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   124,   137,   138,   125,   123,
       0,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,   124,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   124,   137,
     138,   125,     0,     0,     0,     0,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,   137,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,     0,   137,   138
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-162))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      27,    40,    27,   164,   113,    14,     6,     3,     4,    65,
      10,     6,     6,    58,     0,    10,    10,    39,    39,    55,
      56,    30,    61,     3,    58,    11,    71,     7,    55,    56,
      55,    56,    71,    29,    73,    20,    39,    71,    20,    19,
      79,    80,    81,    64,    83,    65,    26,   208,    87,     0,
      89,     0,   161,    73,    93,    94,    95,    96,    97,    98,
      11,   171,    67,    48,    49,    50,    51,    52,    50,    51,
      52,   110,    39,    39,    74,    39,    67,    67,    65,    74,
      74,    71,    58,    67,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     156,   210,   141,    73,    65,    68,    32,    67,    65,   219,
      68,     3,    74,    67,    70,     7,     8,    67,    71,    67,
      67,    65,    65,    39,   233,    17,    72,    19,   238,    70,
     169,    39,    24,    25,    26,    65,    70,    39,    67,   248,
      68,    65,    67,    70,   171,   255,   171,    65,    71,    14,
      72,    16,    39,    65,   193,    70,    73,    22,    71,    68,
      65,   200,    68,   159,    58,    72,    31,   277,    71,    13,
     209,   281,    37,    38,    39,    40,    41,   216,   234,    65,
      65,   220,    70,    48,    49,    68,    65,    69,    53,    65,
      65,    65,   219,     3,   219,     5,    11,     7,     8,     9,
     250,    11,    67,    68,   243,    15,   261,   206,    18,    19,
     228,   238,   227,   238,   285,   254,    26,    27,   257,    29,
      -1,   225,    32,    33,    34,    35,    36,     4,   255,    39,
     255,   202,   276,   272,    -1,   274,   275,    -1,    -1,    -1,
      -1,     4,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
     277,    -1,   277,    -1,   281,    65,   281,    20,    -1,    -1,
      23,    -1,    -1,    73,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       5,    54,    55,    -1,     9,    72,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    -1,    -1,    21,    -1,    -1,    72,
      -1,    -1,    27,    -1,    29,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    39,     5,    -1,    -1,    -1,     9,
      -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,
      65,    -1,    32,    33,    34,    35,    36,    -1,    73,    39,
       5,     4,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    -1,    -1,    -1,    20,    -1,    -1,
      23,    -1,    27,    -1,    29,    65,    -1,    32,    33,    34,
      35,    36,    -1,    73,    39,    -1,    -1,     4,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    20,     4,    -1,    23,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    68,    -1,    70,    73,    -1,
      20,    -1,    -1,    23,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
       4,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    70,    54,    55,    20,    -1,    -1,    23,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    69,
      -1,    20,    -1,     4,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    20,
      54,    55,    23,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    68,    -1,     4,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    20,    54,    55,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    68,    -1,     4,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    20,    54,    55,    23,    43,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    -1,
      68,    -1,     4,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    20,    54,
      55,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,     4,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    20,    54,    55,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,     4,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    20,    54,    55,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,     4,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    20,    54,    55,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      20,    54,    55,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    20,    54,    55,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    20,    54,    55,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    20,
      54,    55,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    20,    54,    55,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    14,    54,    55,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    14,    -1,    16,    37,    38,
      39,    40,    41,    22,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    31,    -1,    53,    14,    -1,    -1,    37,    38,
      39,    40,    41,    22,    -1,    -1,    65,    -1,    67,    48,
      49,    -1,    31,    -1,    53,    -1,     4,    -1,    37,    38,
      39,    40,    41,    -1,    12,    -1,    -1,    -1,    67,    48,
      49,    -1,    20,    -1,    53,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    67,     4,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    20,    54,    55,    23,     4,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    20,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    20,    54,
      55,    23,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     8,    17,    19,    24,    25,    26,    77,
      78,    79,    80,    82,    92,    93,    99,   100,   101,   103,
     103,   103,    39,    39,     0,    78,    65,    73,   117,    67,
     102,    39,    39,    39,    67,     5,     9,    11,    15,    18,
      27,    29,    32,    33,    34,    35,    36,    39,    65,    80,
      82,   107,   109,   117,   118,   119,   120,   131,    94,   103,
     117,    58,    71,    83,    90,    58,    68,    65,    65,    32,
     122,    67,    14,    22,    31,    37,    38,    40,    41,    48,
      49,    53,    65,    67,   106,   107,   109,    67,   121,    71,
     110,    56,    57,    58,    59,    60,    61,    62,    63,    65,
      74,   118,   118,    67,    68,    39,    64,    96,   106,   104,
     105,    70,    86,    85,   104,   123,    67,   106,   106,   106,
     106,   106,   106,     4,    20,    23,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    54,    55,    65,
     106,    67,   106,    67,    65,    65,   106,   106,   106,   106,
     106,   106,    16,    68,   106,   130,    71,    98,    39,    70,
      95,    84,    72,   106,    39,    65,    86,    70,    81,    67,
      39,    68,    68,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,    68,
     106,    72,   111,   112,    65,    65,    65,    65,    65,    65,
      67,    65,    70,   129,    97,   104,   103,    86,    91,    58,
      87,    90,    65,    39,    65,   106,    70,   120,    73,    68,
      71,   108,    68,   106,   106,   130,    68,    72,    96,    65,
      90,   106,    86,    89,    58,    68,   106,   127,    13,   124,
     120,   106,   113,    70,   129,    65,    98,    95,    88,    86,
     104,    65,    12,    30,   128,    68,   120,     6,    10,    74,
     125,    72,    70,   114,   106,    86,    81,   106,   120,   106,
      69,   108,   115,    68,    70,    28,    69,   126,   106,   106,
     106,   126,     5,    21,   120,   116,    68,     5,    21,    65,
      65,   114,    65,    65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 191 "parser.y"
    {  closeScope(); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 193 "parser.y"
    { }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    { }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    { }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { we_define_globals = 1;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 199 "parser.y"
    { we_define_globals = 1;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    { 	validate_Constant((yyvsp[(3) - (7)].string_value),(yyvsp[(5) - (7)].expression)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    { 	validate_Constant((yyvsp[(2) - (5)].string_value),(yyvsp[(4) - (5)].expression)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    {  }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 215 "parser.y"
    { validate_Variable((yyvsp[(2) - (2)].string_value),global_type); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 216 "parser.y"
    { }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 217 "parser.y"
    { validate_Variable_with_assignment((yyvsp[(2) - (4)].string_value),global_type,(yyvsp[(4) - (4)].expression)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 217 "parser.y"
    { }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 218 "parser.y"
    { validate_Variable((yyvsp[(2) - (3)].string_value),(yyvsp[(3) - (3)].type)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 218 "parser.y"
    { }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    {  validate_Variable((yyvsp[(2) - (2)].string_value),global_type);  }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 221 "parser.y"
    { }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    { validate_Variable_with_assignment((yyvsp[(2) - (4)].string_value),global_type,(yyvsp[(4) - (4)].expression)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    { }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    { validate_Variable((yyvsp[(2) - (3)].string_value),(yyvsp[(3) - (3)].type)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    { }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 224 "parser.y"
    {  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    {  if ((!(yyvsp[(2) - (3)].expression).is_constant)||check_array_dimension((yyvsp[(2) - (3)].expression))) 
												   		fatal("Expression in array dimension is not a possitive integer constant. Line = %d\n",lineno); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { (yyval.type)=makeArray((yyvsp[(2) - (5)].expression),(yyvsp[(5) - (5)].type)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 229 "parser.y"
    {  if ((!(yyvsp[(2) - (3)].expression).is_constant)||check_array_dimension((yyvsp[(2) - (3)].expression))) 
			  									   		fatal("Expression in array dimension is not a possitive integer constant. Line = %d\n",lineno); 
			  									    else 
			  									    	(yyval.type)=makeArray((yyvsp[(2) - (3)].expression),global_type); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { endFunctionHeader(p,function_type); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 240 "parser.y"
    {  validate_Routine((yyvsp[(2) - (2)].string_value),typeVoid); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 241 "parser.y"
    { validate_Routine((yyvsp[(3) - (3)].string_value),global_type); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    { }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    {   }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 244 "parser.y"
    {  }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 245 "parser.y"
    { }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    { newParameter((yyvsp[(2) - (2)].string_value), global_type, PASS_BY_REFERENCE, p); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 247 "parser.y"
    { newParameter((yyvsp[(1) - (1)].string_value), global_type, PASS_BY_VALUE, p); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 248 "parser.y"
    { newParameter((yyvsp[(1) - (2)].string_value),(yyvsp[(2) - (2)].type),PASS_BY_REFERENCE,p); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 249 "parser.y"
    { }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 250 "parser.y"
    { }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 251 "parser.y"
    { (yyval.type) = typeArray(1,(yyvsp[(4) - (4)].type)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 252 "parser.y"
    { (yyval.type) = typeArray(1,global_type); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 253 "parser.y"
    { forwardFunction(p); 
								   closeScope(); 
								 }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 256 "parser.y"
    { if ((!found_return_statement)&&(function_type != typeVoid))
	    						 	fatal("Function '%s' does not return aprropriate value\n",p->id);
	    						 we_define_globals = 1; 
	    						 function_is_defined = false; 
	    						 found_return_statement = false;
	    						 closeScope(); 
	    					   }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
    { if (lookupEntry((yyvsp[(2) - (4)].string_value),LOOKUP_CURRENT_SCOPE,0))
	   												fatal("Can not declare main program with name '%s',name already used. Line = %d\n",(yyvsp[(2) - (4)].string_value),lineno);
	   											p = newFunction((yyvsp[(2) - (4)].string_value)); 
												openScope(); 
												endFunctionHeader(p,typeVoid); 
											  }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 272 "parser.y"
    { we_define_globals = 0; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 272 "parser.y"
    {   closeScope(); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 280 "parser.y"
    { (yyval.string_value)=strdup("Integer"); global_type=typeInteger; global_type_string=strdup("Integer"); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 281 "parser.y"
    { (yyval.string_value)=strdup("Boolean"); global_type=typeBoolean; global_type_string=strdup("Boolean"); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 282 "parser.y"
    { (yyval.string_value)=strdup("Character");    global_type=typeChar; global_type_string=strdup("Character"); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 283 "parser.y"
    { (yyval.string_value)=strdup("Real");    global_type=typeReal; global_type_string=strdup("Real"); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 292 "parser.y"
    { evaluate_constant=1; }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 292 "parser.y"
    { (yyval.expression)=(yyvsp[(2) - (2)].expression); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 294 "parser.y"
    { (yyval.expression).type=typeInteger; (yyval.expression).is_constant=1;  l_value_flag=0; }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 295 "parser.y"
    { (yyval.expression).type=typeReal; (yyval.expression).is_constant=1;  l_value_flag=0;   }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 296 "parser.y"
    { (yyval.expression).type=typeChar; (yyval.expression).is_constant=1;  l_value_flag=0;   }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 297 "parser.y"
    {  (yyval.expression).type=typeArray(strlen((yyval.expression).value.q)+1,typeChar); (yyval.expression).is_constant=1; l_value_flag=0;}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 298 "parser.y"
    { (yyval.expression).type=typeBoolean; (yyval.expression).is_constant=1; l_value_flag=0;}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 299 "parser.y"
    { (yyval.expression).type=typeBoolean; (yyval.expression).is_constant=1; l_value_flag=0;}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 300 "parser.y"
    { (yyval.expression)=(yyvsp[(2) - (3)].expression); l_value_flag=0;}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 301 "parser.y"
    { (yyval.expression)=(yyvsp[(1) - (1)].expression);  }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 302 "parser.y"
    { (yyval.expression).is_constant=0; (yyval.expression).type=(yyvsp[(1) - (1)].type);l_value_flag=0; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 303 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_plus,0); l_value_flag=0;}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 304 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_not,0);l_value_flag=0; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 305 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_notb,0); l_value_flag=0;}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 306 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_minus,0);l_value_flag=0;}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 307 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_plus,1);l_value_flag=0;}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 308 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_minus,1);l_value_flag=0;}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 309 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_mult,1);l_value_flag=0;}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 310 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_div,1);l_value_flag=0;}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 311 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_mod,1);l_value_flag=0;}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 312 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_MOD,1);l_value_flag=0;}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 313 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_equal,1);l_value_flag=0;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 314 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_nequal,1);l_value_flag=0;}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 315 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_less,1);l_value_flag=0;}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 316 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_greater,1);l_value_flag=0;}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 317 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_lequal,1);l_value_flag=0;}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 318 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_egreater,1);l_value_flag=0;}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 319 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_AND,1);l_value_flag=0;}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 320 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_and,1);l_value_flag=0;}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 321 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_OR,1);l_value_flag=0;}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 322 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_or,1);l_value_flag=0;}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 334 "parser.y"
    { (yyval.expression) = checkForLvalue((yyvsp[(1) - (1)].string_value));  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 335 "parser.y"
    {   if ((yyvsp[(3) - (5)].expression).is_constant) 
		     													if (check_array_dimension((yyvsp[(3) - (5)].expression))) 
		     														fatal("Array subscript is not an integer. Line = %d",lineno);
		     												dimensions_in_expressions++;
		     												(yyval.expression) = checkForArrayLvalue((yyvsp[(1) - (5)].string_value));
		     												dimensions_in_expressions = 0;
		     											}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 343 "parser.y"
    { }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 344 "parser.y"
    { dimensions_in_expressions++;
		     											 if ((yyvsp[(2) - (4)].expression).is_constant) 
		     											 	if (check_array_dimension((yyvsp[(2) - (4)].expression))) 
		     													fatal("Array subscript is not an integer. Line = %d",lineno);
		     										   }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 357 "parser.y"
    {  f = lookupEntry((yyvsp[(1) - (1)].string_value),LOOKUP_ALL_SCOPES,0);
		        if ((!f)||(f->entryType!=ENTRY_FUNCTION))
		       		fatal("Function '%s' is not declared. Line = %d\n",(yyvsp[(1) - (1)].string_value),lineno);
                next_parameter = f->u.eFunction.firstArgument; 
                parameter_counter = 0;; 
                total_parameters = countParameters(f) ;
              }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 364 "parser.y"
    { (yyval.type)=f->u.eFunction.resultType; }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    { l_value_flag = 1; }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    {  validateParameter((yyvsp[(2) - (2)].expression),next_parameter);  }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    { }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 366 "parser.y"
    { if (next_parameter) 
								fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno);
						  }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 369 "parser.y"
    { l_value_flag = 1; }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 369 "parser.y"
    {  validateParameter((yyvsp[(3) - (3)].expression),next_parameter); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 369 "parser.y"
    { }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 370 "parser.y"
    { if (next_parameter) 
									fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno); 
							   }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 379 "parser.y"
    { }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 380 "parser.y"
    {  }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 381 "parser.y"
    {  }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 382 "parser.y"
    {  }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 384 "parser.y"
    { }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 385 "parser.y"
    { }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 395 "parser.y"
    { /* empty statement */ }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 396 "parser.y"
    {   if ((yyvsp[(1) - (4)].expression).is_constant) 
     								  		fatal("Cannot change constant value. Line = %d\n",lineno);
     								  	else if (!assignmentEvaluation((yyvsp[(1) - (4)].expression).type,(yyvsp[(3) - (4)].expression).type))
     								  		fatal("Invalid assignment.Cannot assign %s to %s. Line = %d\n",getType((yyvsp[(3) - (4)].expression).type),getType((yyvsp[(1) - (4)].expression).type),lineno);
     								}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 401 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_plus);   }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 402 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_minus);  }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 403 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_mult);   }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 404 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_div);    }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 405 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_mod);    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 406 "parser.y"
    { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     						  operationAndAssignment((yyvsp[(1) - (3)].expression),unit_expression,T_plus); 
     						}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 409 "parser.y"
    { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     						  operationAndAssignment((yyvsp[(1) - (3)].expression),unit_expression,T_minus);   
     						}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 412 "parser.y"
    { }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 413 "parser.y"
    {   if (!equalType((yyvsp[(3) - (5)].expression).type,typeBoolean)) 
											fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     													
     								}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 416 "parser.y"
    {   if (!equalType((yyvsp[(3) - (7)].expression).type,typeBoolean)) 
														fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     													
     								  }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 419 "parser.y"
    { loop_counter++; }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 419 "parser.y"
    {    if (!equalType((yyvsp[(4) - (6)].expression).type,typeBoolean)) 
															    	fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     													
																loop_counter--;     								   						
     								   						}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 423 "parser.y"
    { loop_counter++; }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 423 "parser.y"
    {  p = lookupEntry((yyvsp[(4) - (8)].string_value),LOOKUP_ALL_SCOPES,0);
     																	if (!p) 
     																		fatal("Variable '%s' in for loop does not exist. Line = %d\n",(yyvsp[(4) - (8)].string_value),lineno);
     																	else if (!valid_loop_variable(p))
	   																		fatal("Variable '%s' in for loop is not an integer. Line = %d\n");
    																	loop_counter--;
     																  }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 430 "parser.y"
    { loop_counter++; }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 430 "parser.y"
    {    if (!equalType((yyvsp[(5) - (7)].expression).type,typeBoolean)) 
													  							fatal("Expression in while statement not boolean. Line = %d\n",lineno);	     													
     								  							   	   		loop_counter--;
     								  							   	   }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 434 "parser.y"
    {    if ((yyvsp[(3) - (7)].expression).type!=typeInteger)
     																	fatal("Expression in switch statement is not integer. Line = %d\n",lineno);
     															}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 437 "parser.y"
    { if (loop_counter==0) 
     						fatal("Break statement is not in a loop. Line = %d\n",lineno);
     				   }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 440 "parser.y"
    { if (loop_counter==0)
     						fatal("Continue statement is not in a loop. Line =%d\n",lineno);
     				  }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 443 "parser.y"
    { validate_return((yyvsp[(2) - (3)].expression).type); found_return_statement = true; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 444 "parser.y"
    { validate_return(typeVoid); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 445 "parser.y"
    { }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 446 "parser.y"
    { }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 447 "parser.y"
    {  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 452 "parser.y"
    { }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 453 "parser.y"
    {}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 455 "parser.y"
    {   if (!equalType(typeInteger,(yyvsp[(2) - (6)].expression).type)) 
																		fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
																}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 458 "parser.y"
    {   if (!equalType(typeInteger,(yyvsp[(2) - (6)].expression).type)) 
																		fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
																}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 461 "parser.y"
    { }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 462 "parser.y"
    { }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 463 "parser.y"
    { }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 464 "parser.y"
    { /*nothing*/ }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 467 "parser.y"
    { validate_range_and_step((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),(yyvsp[(1) - (3)].expression),0);; }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 468 "parser.y"
    { validate_range_and_step((yyvsp[(1) - (5)].expression),(yyvsp[(3) - (5)].expression),(yyvsp[(5) - (5)].expression),1); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 469 "parser.y"
    {  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 470 "parser.y"
    {  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 474 "parser.y"
    { }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 475 "parser.y"
    {  }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 476 "parser.y"
    { validate_print_expression((yyvsp[(1) - (1)].expression),(yyvsp[(1) - (1)].expression),(yyvsp[(1) - (1)].expression),1); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 477 "parser.y"
    {  validate_print_expression((yyvsp[(3) - (8)].expression),(yyvsp[(5) - (8)].expression),(yyvsp[(7) - (8)].expression),2);
       													   }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 479 "parser.y"
    { validate_print_expression((yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression),(yyvsp[(5) - (6)].expression),3);
       											}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 481 "parser.y"
    { }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 482 "parser.y"
    { }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 483 "parser.y"
    { }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 484 "parser.y"
    { }
    break;



/* Line 1806 of yacc.c  */
#line 3041 "parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 489 "parser.y"


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


