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



/* Line 268 of yacc.c  */
#line 103 "parser.c"

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
#line 33 "parser.y"


#include "symbol.h"
#include "quadruples.h"



/* Line 288 of yacc.c  */
#line 135 "parser.c"

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
#line 40 "parser.y"

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



/* Line 293 of yacc.c  */
#line 242 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 254 "parser.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1052

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNRULES -- Number of states.  */
#define YYNSTATES  319

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
       0,     0,     3,     4,     7,    10,    11,    13,    15,    17,
      19,    27,    33,    34,    35,    41,    42,    50,    51,    58,
      59,    64,    65,    72,    73,    79,    80,    81,    87,    91,
      96,    99,   103,   107,   108,   113,   114,   117,   119,   122,
     124,   125,   130,   134,   137,   138,   142,   147,   148,   152,
     154,   156,   158,   160,   162,   163,   170,   171,   176,   177,
     178,   185,   186,   187,   192,   193,   194,   195,   201,   202,
     206,   209,   210,   214,   215,   217,   219,   221,   226,   231,
     236,   241,   246,   251,   255,   259,   262,   263,   270,   271,
     272,   282,   283,   284,   292,   293,   294,   304,   305,   306,
     307,   318,   319,   328,   331,   334,   338,   341,   343,   348,
     355,   358,   359,   360,   368,   369,   377,   383,   389,   392,
     393,   397,   403,   405,   407,   411,   412,   414,   423,   430,
     432,   434,   436,   438,   439,   442,   444,   446,   448,   450,
     452,   454,   458,   460,   462,   465,   468,   472,   476,   480,
     484,   488,   492,   496,   500,   504,   508,   512,   516,   519,
     522,   523,   528,   529,   534,   535,   540,   541,   546,   548
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      77,     0,    -1,    -1,    78,    79,    -1,    80,    79,    -1,
      -1,    81,    -1,    83,    -1,   100,    -1,   103,    -1,     8,
     105,    39,    58,   144,    82,    65,    -1,    70,    39,    58,
     144,    82,    -1,    -1,    -1,   105,    39,    84,    87,    65,
      -1,    -1,   105,    39,    58,   146,    85,    87,    65,    -1,
      -1,   105,    39,    91,    86,    87,    65,    -1,    -1,    70,
      39,    88,    87,    -1,    -1,    70,    39,    58,   146,    89,
      87,    -1,    -1,    70,    39,    91,    90,    87,    -1,    -1,
      -1,    71,   144,    72,    92,    91,    -1,    71,   144,    72,
      -1,    94,    67,    95,    68,    -1,    24,    39,    -1,    17,
     105,    39,    -1,   105,    97,    96,    -1,    -1,    70,   105,
      97,    96,    -1,    -1,    64,    39,    -1,    39,    -1,    39,
      99,    -1,   144,    -1,    -1,    71,    98,    72,    99,    -1,
      71,    98,    72,    -1,    93,    65,    -1,    -1,    93,   101,
     118,    -1,    25,    39,    67,    68,    -1,    -1,   102,   104,
     118,    -1,    19,    -1,     3,    -1,     7,    -1,    26,    -1,
      39,    -1,    -1,    39,   107,    71,   146,    72,   108,    -1,
      -1,    71,   146,    72,   108,    -1,    -1,    -1,    39,   110,
      67,   111,   112,    68,    -1,    -1,    -1,   113,   146,   114,
     115,    -1,    -1,    -1,    -1,    70,   116,   146,   117,   115,
      -1,    -1,    73,   119,    74,    -1,   121,   119,    -1,    -1,
     122,   120,   119,    -1,    -1,    81,    -1,    83,    -1,    65,
      -1,   106,    58,   146,    65,    -1,   106,    59,   146,    65,
      -1,   106,    60,   146,    65,    -1,   106,    61,   146,    65,
      -1,   106,    62,   146,    65,    -1,   106,    63,   146,    65,
      -1,   106,    56,    65,    -1,   106,    57,    65,    -1,   109,
      65,    -1,    -1,    18,    67,   147,    68,   123,   122,    -1,
      -1,    -1,    18,    67,   147,    68,   124,   122,    13,   125,
     122,    -1,    -1,    -1,    32,   126,    67,   147,    68,   127,
     122,    -1,    -1,    -1,    15,   128,    67,    39,    70,   139,
     129,    68,   122,    -1,    -1,    -1,    -1,    11,   130,   122,
     131,    32,   132,    67,   147,    68,    65,    -1,    -1,    29,
      67,   146,   133,    68,    73,   134,    74,    -1,     5,    65,
      -1,     9,    65,    -1,    27,   146,    65,    -1,    27,    65,
      -1,   118,    -1,   143,    67,    68,    65,    -1,   143,    67,
     142,   141,    68,    65,    -1,   134,   135,    -1,    -1,    -1,
       6,   146,   136,    69,   138,     5,    65,    -1,    -1,     6,
     146,   137,    69,   138,    21,    65,    -1,    10,    69,   138,
       5,    65,    -1,    10,    69,   138,    21,    65,    -1,   138,
     122,    -1,    -1,   146,   140,   146,    -1,   146,   140,   146,
      28,   146,    -1,    30,    -1,    12,    -1,    70,   142,   141,
      -1,    -1,   146,    -1,    16,    67,   146,    70,   146,    70,
     146,    68,    -1,    16,    67,   146,    70,   146,    68,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,   145,
     146,    -1,    37,    -1,    38,    -1,    40,    -1,    41,    -1,
      31,    -1,    14,    -1,    67,   146,    68,    -1,   106,    -1,
     109,    -1,    48,   146,    -1,    49,   146,    -1,   146,    48,
     146,    -1,   146,    49,   146,    -1,   146,    50,   146,    -1,
     146,    51,   146,    -1,   146,    52,   146,    -1,   146,    20,
     146,    -1,   146,    42,   146,    -1,   146,    45,   146,    -1,
     146,    44,   146,    -1,   146,    43,   146,    -1,   146,    47,
     146,    -1,   146,    46,   146,    -1,    22,   147,    -1,    53,
     147,    -1,    -1,   147,    54,   148,   147,    -1,    -1,   147,
       4,   149,   147,    -1,    -1,   147,    55,   150,   147,    -1,
      -1,   147,    23,   151,   147,    -1,   146,    -1,   147,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   171,   173,   174,   176,   177,   178,   179,
     184,   187,   188,   195,   195,   197,   197,   198,   198,   200,
     200,   202,   202,   203,   203,   204,   206,   206,   209,   218,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   236,   236,   255,   263,   263,   271,
     272,   273,   274,   284,   285,   285,   328,   329,   373,   381,
     373,   382,   382,   382,   390,   393,   393,   393,   399,   408,
     409,   410,   410,   411,   413,   414,   424,   425,   436,   437,
     438,   439,   440,   441,   445,   449,   450,   450,   459,   460,
     459,   470,   481,   470,   501,   508,   501,   552,   559,   560,
     552,   578,   578,   596,   603,   614,   620,   621,   622,   623,
     628,   629,   631,   631,   642,   642,   651,   652,   653,   654,
     657,   679,   690,   691,   695,   696,   697,   698,   700,   702,
     703,   704,   705,   710,   710,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   734,   735,   736,   737,   738,   739,   741,   742,
     743,   743,   744,   744,   745,   745,   746,   746,   748,   750
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"bool\"", "\"and\"", "\"break\"",
  "\"case\"", "\"char\"", "\"const\"", "\"continue\"", "\"default\"",
  "T_do", "\"DOWNTO\"", "\"else\"", "\"false\"", "T_FOR", "\"FORM\"",
  "\"FUNC\"", "\"if\"", "\"int\"", "\"MOD\"", "\"NEXT\"", "\"not\"",
  "\"or\"", "\"PROC\"", "\"PROGRAM\"", "\"REAL\"", "\"return\"",
  "\"STEP\"", "\"switch\"", "\"TO\"", "\"true\"", "T_while", "\"WRITE\"",
  "\"WRITELN\"", "\"WRITESP\"", "\"WRITESPLN\"", "T_const_int",
  "T_const_real", "T_id", "T_const_char", "T_string", "\"==\"", "\">\"",
  "\"<\"", "\"!=\"", "\">=\"", "\"<=\"", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"%\"", "\"!\"", "\"AND\"", "\"OR\"", "\"++\"", "\"--\"",
  "\"=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&\"",
  "\";\"", "\".\"", "\"(\"", "\")\"", "\":\"", "\",\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "T_eof", "$accept", "module", "$@1",
  "declaration_list", "declaration", "const_def", "const_def_list",
  "var_def", "$@2", "$@3", "$@4", "var_def_list", "$@5", "$@6", "$@7",
  "var_init_list", "$@8", "routine_header", "choose", "routine_header_if",
  "routine_header_if_list", "formal", "formal_if2", "formal_list",
  "routine", "$@9", "program_header", "program", "$@10", "type", "l_value",
  "$@11", "l_value_list", "call", "$@12", "$@13", "call_if", "$@14",
  "$@15", "call_if_list", "$@16", "$@17", "block", "block_list", "$@18",
  "local_def", "stmt", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "switch_cases", "choose_case",
  "$@30", "$@31", "statement_list", "range", "range_choose", "format_more",
  "format", "write", "const_expr", "$@32", "expr", "cond", "$@33", "$@34",
  "$@35", "$@36", 0
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
       0,    76,    78,    77,    79,    79,    80,    80,    80,    80,
      81,    82,    82,    84,    83,    85,    83,    86,    83,    88,
      87,    89,    87,    90,    87,    87,    92,    91,    91,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    98,
      98,    99,    99,   100,   101,   100,   102,   104,   103,   105,
     105,   105,   105,   106,   107,   106,   108,   108,   110,   111,
     109,   113,   114,   112,   112,   116,   117,   115,   115,   118,
     119,   120,   119,   119,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   122,   124,   125,
     122,   126,   127,   122,   128,   129,   122,   130,   131,   132,
     122,   133,   122,   122,   122,   122,   122,   122,   122,   122,
     134,   134,   136,   135,   137,   135,   135,   135,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   145,   144,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   147,   147,   147,   147,   147,   147,   147,   147,
     148,   147,   149,   147,   150,   147,   151,   147,   147,   146
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     1,     1,     1,
       7,     5,     0,     0,     5,     0,     7,     0,     6,     0,
       4,     0,     6,     0,     5,     0,     0,     5,     3,     4,
       2,     3,     3,     0,     4,     0,     2,     1,     2,     1,
       0,     4,     3,     2,     0,     3,     4,     0,     3,     1,
       1,     1,     1,     1,     0,     6,     0,     4,     0,     0,
       6,     0,     0,     4,     0,     0,     0,     5,     0,     3,
       2,     0,     3,     0,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     3,     3,     2,     0,     6,     0,     0,
       9,     0,     0,     7,     0,     0,     9,     0,     0,     0,
      10,     0,     8,     2,     2,     3,     2,     1,     4,     6,
       2,     0,     0,     7,     0,     7,     5,     5,     2,     0,
       3,     5,     1,     1,     3,     0,     1,     8,     6,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       0,     4,     0,     4,     0,     4,     0,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,    50,    51,     0,     0,    49,     0,
       0,    52,     3,     5,     6,     7,    44,     0,     8,    47,
       9,     0,     0,     0,    30,     0,     4,    43,     0,    33,
       0,    13,     0,    31,     0,    73,    45,     0,     0,    48,
       0,   133,    25,    17,   133,    46,     0,     0,    97,    94,
       0,     0,     0,    91,   129,   130,   131,   132,    53,    76,
      74,    75,     0,     0,   107,     0,    73,    71,     0,    29,
      37,     0,    35,   140,     0,   139,   135,   136,   137,   138,
       0,     0,     0,     0,   142,   143,   168,   169,     0,     0,
       0,     0,    25,    12,   103,   104,     0,     0,     0,   106,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    69,    70,    73,     0,   133,    38,
      36,     0,    32,   168,   158,   144,   145,   159,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,   162,   166,   160,   164,    28,   168,    19,    14,
       0,     0,     0,    98,     0,   169,   105,   168,     0,     0,
      59,    83,    84,   168,   168,   168,   168,   168,   168,    72,
       0,     0,   125,   168,     0,    39,     0,   141,   151,   152,
     155,   154,   153,   157,   156,   146,   147,   148,   149,   150,
       0,     0,     0,     0,     0,     0,     0,    25,    23,    18,
       0,    10,     0,     0,    86,     0,   169,   168,    61,    77,
      78,    79,    80,    81,    82,     0,   108,     0,     0,    42,
      35,    16,   163,   167,   161,   165,    27,   168,    20,    25,
     133,    99,     0,     0,     0,     0,    92,    56,     0,     0,
     168,   125,     0,    41,    34,    25,    24,    12,     0,    95,
     168,    87,     0,   111,     0,     0,    55,    60,   168,     0,
     124,   109,    22,    11,     0,     0,   123,   122,     0,    89,
       0,    93,   168,    68,   168,   169,     0,   168,     0,     0,
       0,   102,   110,    56,    65,    63,   128,     0,     0,    96,
       0,    90,   168,   119,    57,     0,   168,   100,   168,     0,
       0,     0,   168,   127,   119,   119,     0,     0,   118,    68,
       0,     0,   103,   117,    67,     0,     0,   103,   115
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    12,    13,    60,   152,    61,    42,   141,
      92,    91,   197,   245,   229,    43,   195,    16,    17,    37,
     122,    72,   174,   119,    18,    28,    19,    20,    30,    21,
      84,   103,   256,    85,   104,   208,   238,   239,   273,   285,
     295,   309,    64,    65,   116,    66,    67,   233,   234,   278,
     102,   254,    97,   265,    96,   202,   248,   205,   270,   282,
     299,   300,   301,   249,   268,   218,   172,    68,    88,    89,
     123,    87,   193,   191,   194,   192
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -273
static const yytype_int16 yypact[] =
{
    -273,    26,   137,  -273,  -273,  -273,    21,    21,  -273,    -3,
       9,  -273,  -273,   137,  -273,  -273,   -26,   -18,  -273,  -273,
    -273,    13,    17,    35,  -273,    16,  -273,  -273,     6,    21,
       6,   -33,    22,  -273,    14,   277,  -273,    19,   -19,  -273,
     452,  -273,    33,  -273,  -273,  -273,    40,    41,  -273,  -273,
      42,   412,    45,  -273,  -273,  -273,  -273,  -273,   -48,  -273,
    -273,  -273,   149,    48,  -273,    53,   277,  -273,    49,  -273,
      36,    76,    66,  -273,   452,  -273,  -273,  -273,  -273,  -273,
     452,   452,   452,   452,  -273,  -273,   541,     4,    47,   452,
     100,    77,    33,    71,  -273,  -273,    99,    81,   452,  -273,
     816,   452,    83,    80,    91,    95,   105,   452,   452,   452,
     452,   452,   452,  -273,  -273,  -273,   277,   391,    93,  -273,
    -273,    21,  -273,  1000,  -273,    15,    15,  -273,   728,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,    33,  -273,  -273,  -273,  -273,   102,   464,   -28,  -273,
     106,   136,   109,  -273,   138,    98,  -273,   761,   452,   452,
    -273,  -273,  -273,   849,   860,   893,   904,   937,   948,  -273,
     112,   125,   122,   552,   124,  -273,   -19,  -273,  -273,   184,
     135,   135,   184,   135,   135,    15,    15,  -273,  -273,  -273,
     132,   452,   452,   452,   452,   142,   452,    33,  -273,  -273,
     145,  -273,   183,   147,  -273,   150,   114,   497,   153,  -273,
    -273,  -273,  -273,  -273,  -273,   452,  -273,   432,   157,    36,
      66,  -273,  -273,     0,  -273,     0,  -273,   585,  -273,    33,
    -273,  -273,   452,    99,    99,   164,  -273,   155,   170,   452,
     673,   122,   174,  -273,  -273,    33,  -273,    71,   175,  -273,
     989,  -273,   232,  -273,    99,   452,  -273,  -273,   596,   452,
    -273,  -273,  -273,  -273,   452,   179,  -273,  -273,   452,  -273,
       1,  -273,   508,   180,   629,   126,    99,   717,    99,   452,
     185,  -273,  -273,   155,  -273,  -273,  -273,   452,   187,  -273,
     452,  -273,   684,  -273,  -273,   452,   772,  -273,   805,   186,
     188,   312,   640,  -273,  -273,  -273,   193,   194,  -273,   180,
     382,   347,    11,  -273,  -273,   195,   196,    12,  -273
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,   236,  -273,    44,    18,    75,  -273,  -273,
    -273,   -86,  -273,  -273,  -273,  -132,  -273,  -273,  -273,  -273,
      43,    86,  -273,    34,  -273,  -273,  -273,  -273,  -273,     8,
     -35,  -273,   -16,   -32,  -273,  -273,  -273,  -273,  -273,   -45,
    -273,  -273,    23,   -56,  -273,  -273,   -87,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -272,  -273,  -273,    27,    54,  -273,   -42,  -273,
     -39,   -69,  -273,  -273,  -273,  -273
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -135
static const yytype_int16 yytable[] =
{
      62,    86,    93,    63,   142,   124,   150,   279,   142,   153,
     115,   280,   100,   127,    22,    23,   198,  -116,  -113,   -58,
      70,  -116,  -113,   -54,     4,    40,     3,   143,     5,   155,
     196,    62,   310,   311,    63,   129,    24,    38,    41,    27,
       8,   125,   126,    41,   128,    71,    14,    11,    25,    29,
     147,    36,    31,    39,   144,   190,    32,    14,   144,   145,
     169,    62,   157,   226,    63,   138,   139,   140,   163,   164,
     165,   166,   167,   168,    33,   281,   175,    15,   173,    35,
      44,    62,    45,    34,    63,  -116,  -113,    69,    15,   206,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   142,    90,    46,    94,    95,   118,    47,    98,
      48,   228,   101,   113,    49,   120,   117,    50,   142,   146,
     207,   143,   222,   223,   224,   225,    51,   114,    52,   176,
     142,    53,    54,    55,    56,    57,   121,   143,    58,   148,
       4,   151,   149,   246,     5,     6,   251,   252,   154,   143,
     158,   159,   144,   145,     7,   129,     8,   227,   160,   262,
     161,     9,    10,    11,    59,   -40,   204,   271,   144,   145,
     162,   199,    35,   -26,   201,   200,   240,   203,   173,   215,
     144,   145,   236,   136,   137,   138,   139,   140,   247,   289,
     216,   291,   217,   250,   288,   275,   219,   221,    62,    62,
     258,    63,    63,   230,   129,   105,   106,   107,   108,   109,
     110,   111,   112,    41,   308,   231,   272,   232,   235,    62,
     274,   -64,    63,   308,   308,   242,   255,   131,   132,   277,
     134,   135,   136,   137,   138,   139,   140,   253,   257,   261,
     292,    62,   264,    62,    63,   269,    63,   276,   296,    26,
     284,   298,   297,   243,   293,   304,   302,   305,   312,   313,
     317,   318,   220,   244,   314,   263,    62,   294,   260,    63,
       0,   241,     0,     0,     0,    62,    62,     0,    63,    63,
       4,     0,    46,     0,     5,     6,    47,     0,    48,     0,
       0,     0,    49,     0,     0,    50,     8,     0,     0,     0,
       0,     0,     0,    11,    51,     0,    52,     0,     0,    53,
      54,    55,    56,    57,     0,     0,    58,   306,     0,     0,
       0,    47,     0,    48,     0,     0,     0,    49,     0,     0,
      50,     0,     0,   307,     0,     0,     0,     0,     0,    51,
       0,    52,    59,     0,    53,    54,    55,    56,    57,     0,
      35,    58,    46,     0,     0,     0,    47,     0,    48,     0,
       0,     0,    49,     0,     0,    50,     0,     0,   316,     0,
       0,     0,     0,     0,    51,     0,    52,    59,     0,    53,
      54,    55,    56,    57,     0,    35,    58,   315,     0,     0,
       0,    47,     0,    48,     0,     0,     0,    49,     0,     0,
      50,     0,     0,     0,     0,    73,     0,   170,     0,    51,
       0,    52,    59,    74,    53,    54,    55,    56,    57,     0,
      35,    58,    75,     0,     0,     0,    73,     0,    76,    77,
      58,    78,    79,     0,    74,     0,     0,     0,     0,    80,
      81,     0,     0,    75,    82,     0,    73,    59,   170,    76,
      77,    58,    78,    79,    74,    35,     0,     0,    83,   171,
      80,    81,     0,    75,     0,    82,    73,     0,     0,    76,
      77,    58,    78,    79,    74,     0,     0,    99,     0,    83,
      80,    81,     0,    75,   129,    82,     0,     0,     0,    76,
      77,    58,    78,    79,     0,     0,     0,     0,     0,    83,
      80,    81,     0,     0,     0,    82,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   129,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,   129,  -134,
       0,     0,     0,     0,  -134,     0,  -134,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   129,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
     283,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   129,   -15,     0,     0,     0,
       0,   -15,     0,     0,     0,     0,   129,     0,     0,     0,
    -126,     0,  -126,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   129,
     -21,     0,     0,     0,     0,   -21,     0,     0,     0,     0,
     129,     0,     0,     0,   -62,     0,   -62,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   129,     0,     0,     0,   286,     0,   287,
       0,     0,     0,     0,   129,     0,     0,     0,   -66,     0,
     -66,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   129,     0,     0,
       0,     0,     0,   259,     0,   290,     0,     0,   129,     0,
       0,     0,     0,  -112,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   129,     0,     0,     0,  -120,     0,     0,     0,     0,
       0,     0,   129,     0,     0,     0,   177,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   129,     0,     0,     0,  -101,
       0,     0,     0,     0,     0,     0,   129,     0,     0,     0,
     303,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   129,
       0,     0,     0,  -121,     0,     0,     0,     0,     0,     0,
     129,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   129,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   129,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   266,   213,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,   214,     0,     0,     0,     0,     0,   267,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-273))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      35,    40,    44,    35,     4,    74,    92,     6,     4,    96,
      66,    10,    51,    82,     6,     7,   148,     6,     6,    67,
      39,    10,    10,    71,     3,    58,     0,    23,     7,    98,
      58,    66,   304,   305,    66,    20,    39,    29,    71,    65,
      19,    80,    81,    71,    83,    64,     2,    26,    39,    67,
      89,    28,    39,    30,    54,   141,    39,    13,    54,    55,
     116,    96,   101,   195,    96,    50,    51,    52,   107,   108,
     109,   110,   111,   112,    39,    74,   118,     2,   117,    73,
      58,   116,    68,    67,   116,    74,    74,    68,    13,   158,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     4,    70,     5,    65,    65,    71,     9,    67,
      11,   197,    67,    65,    15,    39,    67,    18,     4,    72,
     159,    23,   191,   192,   193,   194,    27,    74,    29,   121,
       4,    32,    33,    34,    35,    36,    70,    23,    39,    39,
       3,    70,    65,   229,     7,     8,   233,   234,    67,    23,
      67,    71,    54,    55,    17,    20,    19,   196,    67,   245,
      65,    24,    25,    26,    65,    72,    68,   254,    54,    55,
      65,    65,    73,    71,    65,    39,   215,    39,   217,    67,
      54,    55,    68,    48,    49,    50,    51,    52,   230,   276,
      65,   278,    70,   232,    68,   264,    72,    65,   233,   234,
     239,   233,   234,    58,    20,    56,    57,    58,    59,    60,
      61,    62,    63,    71,   301,    32,   255,    70,    68,   254,
     259,    68,   254,   310,   311,    68,    71,    43,    44,   268,
      46,    47,    48,    49,    50,    51,    52,    73,    68,    65,
     279,   276,    67,   278,   276,    13,   278,    68,   287,    13,
      70,   290,    65,   219,    69,    69,   295,    69,    65,    65,
      65,    65,   176,   220,   309,   247,   301,   283,   241,   301,
      -1,   217,    -1,    -1,    -1,   310,   311,    -1,   310,   311,
       3,    -1,     5,    -1,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    39,     5,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    15,    -1,    -1,
      18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    29,    65,    -1,    32,    33,    34,    35,    36,    -1,
      73,    39,     5,    -1,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    15,    -1,    -1,    18,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    29,    65,    -1,    32,
      33,    34,    35,    36,    -1,    73,    39,     5,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    15,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    14,    -1,    16,    -1,    27,
      -1,    29,    65,    22,    32,    33,    34,    35,    36,    -1,
      73,    39,    31,    -1,    -1,    -1,    14,    -1,    37,    38,
      39,    40,    41,    -1,    22,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    31,    53,    -1,    14,    65,    16,    37,
      38,    39,    40,    41,    22,    73,    -1,    -1,    67,    68,
      48,    49,    -1,    31,    -1,    53,    14,    -1,    -1,    37,
      38,    39,    40,    41,    22,    -1,    -1,    65,    -1,    67,
      48,    49,    -1,    31,    20,    53,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    67,
      48,    49,    -1,    -1,    -1,    53,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    20,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    65,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    20,    65,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      68,    -1,    70,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    20,
      65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    20,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    20,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    28,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    20,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    20,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    20,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    20,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    20,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    12,    65,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    30,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    77,    78,     0,     3,     7,     8,    17,    19,    24,
      25,    26,    79,    80,    81,    83,    93,    94,   100,   102,
     103,   105,   105,   105,    39,    39,    79,    65,   101,    67,
     104,    39,    39,    39,    67,    73,   118,    95,   105,   118,
      58,    71,    84,    91,    58,    68,     5,     9,    11,    15,
      18,    27,    29,    32,    33,    34,    35,    36,    39,    65,
      81,    83,   106,   109,   118,   119,   121,   122,   143,    68,
      39,    64,    97,    14,    22,    31,    37,    38,    40,    41,
      48,    49,    53,    67,   106,   109,   146,   147,   144,   145,
      70,    87,    86,   144,    65,    65,   130,   128,    67,    65,
     146,    67,   126,   107,   110,    56,    57,    58,    59,    60,
      61,    62,    63,    65,    74,   119,   120,    67,    71,    99,
      39,    70,    96,   146,   147,   146,   146,   147,   146,    20,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    85,     4,    23,    54,    55,    72,   146,    39,    65,
      87,    70,    82,   122,    67,   147,    65,   146,    67,    71,
      67,    65,    65,   146,   146,   146,   146,   146,   146,   119,
      16,    68,   142,   146,    98,   144,   105,    68,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
      87,   149,   151,   148,   150,    92,    58,    88,    91,    65,
      39,    65,   131,    39,    68,   133,   147,   146,   111,    65,
      65,    65,    65,    65,    65,    67,    65,    70,   141,    72,
      97,    65,   147,   147,   147,   147,    91,   146,    87,    90,
      58,    32,    70,   123,   124,    68,    68,    72,   112,   113,
     146,   142,    68,    99,    96,    89,    87,   144,   132,   139,
     146,   122,   122,    73,   127,    71,   108,    68,   146,    70,
     141,    65,    87,    82,    67,   129,    12,    30,   140,    13,
     134,   122,   146,   114,   146,   147,    68,   146,   125,     6,
      10,    74,   135,    72,    70,   115,    68,    70,    68,   122,
      28,   122,   146,    69,   108,   116,   146,    65,   146,   136,
     137,   138,   146,    68,    69,    69,     5,    21,   122,   117,
     138,   138,    65,    65,   115,     5,    21,    65,    65
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
#line 171 "parser.y"
    {fp = fopen("quads.txt","w+");printf("file opened"); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    {  closeScope();printf("program finished\n"); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    { }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    { }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    { }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    { we_define_globals = 1;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 179 "parser.y"
    { we_define_globals = 1;}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    { 	validate_Constant((yyvsp[(3) - (7)].string_value),(yyvsp[(5) - (7)].expression)); /*quad*/ GENQUAD(":=",(yyvsp[(5) - (7)].expression).name,"-",strdup((yyvsp[(3) - (7)].string_value)));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { 	validate_Constant(strdup((yyvsp[(2) - (5)].string_value)),(yyvsp[(4) - (5)].expression)); /*quad*/ GENQUAD(":=",(yyvsp[(4) - (5)].expression).name,"-",strdup((yyvsp[(2) - (5)].string_value)));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 188 "parser.y"
    {  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 195 "parser.y"
    { validate_Variable((yyvsp[(2) - (2)].string_value),global_type); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    { }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { validate_Variable_with_assignment(strdup((yyvsp[(2) - (4)].string_value)),global_type,(yyvsp[(4) - (4)].expression)); /*quad*/ GENQUAD(":=",(yyvsp[(4) - (4)].expression).name,"-",strdup((yyvsp[(2) - (4)].string_value)));printf("expression passed to temp var\n");}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { validate_Variable((yyvsp[(2) - (3)].string_value),(yyvsp[(3) - (3)].type)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    {  validate_Variable((yyvsp[(2) - (2)].string_value),global_type);  }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 201 "parser.y"
    { }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    { validate_Variable_with_assignment(strdup((yyvsp[(2) - (4)].string_value)),global_type,(yyvsp[(4) - (4)].expression)); /*quad*/ GENQUAD(":=",(yyvsp[(4) - (4)].expression).name,"-",strdup((yyvsp[(2) - (4)].string_value)));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    { }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    { validate_Variable((yyvsp[(2) - (3)].string_value),(yyvsp[(3) - (3)].type)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    { }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    {  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    {  if ((!(yyvsp[(2) - (3)].expression).is_constant)||check_array_dimension((yyvsp[(2) - (3)].expression))) 
												   		fatal("Expression in array dimension is not a possitive integer constant. Line = %d\n",lineno); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    { (yyval.type)=makeArray((yyvsp[(2) - (5)].expression),(yyvsp[(5) - (5)].type)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 209 "parser.y"
    {  if ((!(yyvsp[(2) - (3)].expression).is_constant)||check_array_dimension((yyvsp[(2) - (3)].expression))) 
			  									   		fatal("Expression in array dimension is not a possitive integer constant. Line = %d\n",lineno); 
			  									    else 
			  									    	(yyval.type)=makeArray((yyvsp[(2) - (3)].expression),global_type); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 218 "parser.y"
    { endFunctionHeader(p,function_type); /*quad*/(yyval.routine).name = (yyvsp[(1) - (4)].routine).name;}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    {  validate_Routine((yyvsp[(2) - (2)].string_value),typeVoid); /*quad*/(yyval.routine).name = strdup((yyvsp[(2) - (2)].string_value));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 221 "parser.y"
    { validate_Routine((yyvsp[(3) - (3)].string_value),global_type); /*quad*/ (yyval.routine).name = strdup((yyvsp[(3) - (3)].string_value));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    { }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    {   }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 224 "parser.y"
    {  }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 225 "parser.y"
    { }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    { newParameter((yyvsp[(2) - (2)].string_value), global_type, PASS_BY_REFERENCE, p); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    { newParameter((yyvsp[(1) - (1)].string_value), global_type, PASS_BY_VALUE, p); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { newParameter((yyvsp[(1) - (2)].string_value),(yyvsp[(2) - (2)].type),PASS_BY_REFERENCE,p); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 229 "parser.y"
    { }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    { }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    { (yyval.type) = typeArray(1,(yyvsp[(4) - (4)].type)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 232 "parser.y"
    { (yyval.type) = typeArray(1,global_type); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 233 "parser.y"
    { forwardFunction(p); 
				   closeScope(); 
								 }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 236 "parser.y"
    {/*quad*/printf("before routine header\n");
	    			      GENQUAD("unit",(yyvsp[(1) - (1)].routine).name,"-","-");
	    			      printf("after routine header\n");}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { if ((!found_return_statement)&&(function_type != typeVoid))
	    						 	fatal("Function '%s' does not return aprropriate value\n",p->id);
	    						 we_define_globals = 1; 
	    						 function_is_defined = false; 
	    						 found_return_statement = false;
	    						 closeScope(); 
	    						 
	    						 /*quad*/
	    						 printf("before whole program block\n");
	    						 sprintf(temp_name1,"%d",NEXTQUAD());
	    						 BACKPATCH(fp,(yyvsp[(3) - (3)].statement).NEXT,temp_name1);GENQUAD("endu",(yyvsp[(1) - (3)].routine).name,"-","-");
	    						 if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
	    						 printf("after whole program block\n");
	    						 
	    					   }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 255 "parser.y"
    { if (lookupEntry((yyvsp[(2) - (4)].string_value),LOOKUP_CURRENT_SCOPE,0))
	   						fatal("Can not declare main program with name '%s',name already used. Line = %d\n",(yyvsp[(2) - (4)].string_value),lineno);
	   					p = newFunction((yyvsp[(2) - (4)].string_value)); 
						openScope(); 
						endFunctionHeader(p,typeVoid);
						/*quad*/ (yyval.routine).name = strdup((yyvsp[(2) - (4)].string_value)); 
						}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    { we_define_globals = 0; /*quad*/ GENQUAD("unit",(yyvsp[(1) - (1)].routine).name,"-","-");printf("program unit created\n");}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    {   printf("before whole program block\n");sprintf(temp_name1,"%d",NEXTQUAD());printf("inside whole program block 1\n");print_list((yyvsp[(3) - (3)].statement).NEXT);BACKPATCH(fp,(yyvsp[(3) - (3)].statement).NEXT,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("inside whole program block 2\n");printf("program name: %s\n",(yyvsp[(1) - (3)].routine).name);GENQUAD("endu",(yyvsp[(1) - (3)].routine).name,"-","-");printf("after whole program block\n"); /*quad*/ closeScope(); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 271 "parser.y"
    { (yyval.string_value)=strdup("Integer"); global_type=typeInteger; global_type_string=strdup("Integer"); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 272 "parser.y"
    { (yyval.string_value)=strdup("Boolean"); global_type=typeBoolean; global_type_string=strdup("Boolean"); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 273 "parser.y"
    { (yyval.string_value)=strdup("Character");    global_type=typeChar; global_type_string=strdup("Character"); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 274 "parser.y"
    { (yyval.string_value)=strdup("Real");    global_type=typeReal; global_type_string=strdup("Real"); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 284 "parser.y"
    { (yyval.expression) = checkForLvalue((yyvsp[(1) - (1)].string_value));  /*quad*/(yyval.expression).name = strdup((yyvsp[(1) - (1)].string_value));}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 285 "parser.y"
    {printf("writing array name\n");array_result_name = strdup((yyvsp[(1) - (1)].string_value));min_expr = tempNumber;}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 285 "parser.y"
    {   if ((yyvsp[(4) - (6)].expression).is_constant) 
		     							if (check_array_dimension((yyvsp[(4) - (6)].expression))) 
		     								fatal("Array subscript is not an integer. Line = %d",lineno);
		     						dimensions_in_expressions++;
		     						(yyval.expression) = checkForArrayLvalue((yyvsp[(1) - (6)].string_value));
		     						dimensions_in_expressions = 0;
		     				       /*quad*/ printf("before array\n");
		     						W = newTemporary((yyval.expression).type);
		     						(yyval.expression).name = strdup(W->id);
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
		     							GENQUAD("array",strdup((yyvsp[(1) - (6)].string_value)),temp_name3,strdup(W1->id));
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
		     									}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 328 "parser.y"
    { }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 329 "parser.y"
    { dimensions_in_expressions++;
		     						if ((yyvsp[(2) - (4)].expression).is_constant) 
		     							if (check_array_dimension((yyvsp[(2) - (4)].expression))) 
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
		     				}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 373 "parser.y"
    {  f = lookupEntry((yyvsp[(1) - (1)].string_value),LOOKUP_ALL_SCOPES,0);
		if ((!f)||(f->entryType!=ENTRY_FUNCTION))
		       	fatal("Function '%s' is not declared. Line = %d\n",(yyvsp[(1) - (1)].string_value),lineno);
                next_parameter = f->u.eFunction.firstArgument; 
                parameter_counter = 0;; 
                total_parameters = countParameters(f) ;
                /*quad*/ global_routine_name = strdup((yyvsp[(1) - (1)].string_value));
                				  }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 381 "parser.y"
    {/*quad*/  N = 1;}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 381 "parser.y"
    { (yyval.expression).type=f->u.eFunction.resultType; /*quad*/ if ( ISFUNCTION(strdup((yyvsp[(1) - (6)].string_value))) ){(yyval.expression).temp = tempNumber;W = newTemporary(FUNCRESULT(strdup((yyvsp[(1) - (6)].string_value))));(yyval.expression).name = strdup(W->id);GENQUAD("par","RET",strdup(W->id),"-");}GENQUAD("call","-","-",strdup((yyvsp[(1) - (6)].string_value)));}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 382 "parser.y"
    { l_value_flag = 1; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 382 "parser.y"
    {  validateParameter((yyvsp[(2) - (2)].expression),next_parameter);
		  	      /*quad*/ if ( PARAMMODE(global_routine_name,N) == "V" && ((yyvsp[(2) - (2)].expression).type != PARAMTYPE(global_routine_name,N) ) )
						{GENQUAD("par",(yyvsp[(2) - (2)].expression).name,PARAMMODE(global_routine_name,N),"-");}
					else
						{
						exit(0);
						GENQUAD("par",(yyvsp[(2) - (2)].expression).name,PARAMMODE(global_routine_name,N),"-");}
					N = N+1;}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 389 "parser.y"
    { }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 390 "parser.y"
    { if (next_parameter) 
					fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno);
						  }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 393 "parser.y"
    { l_value_flag = 1; }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 393 "parser.y"
    {  validateParameter((yyvsp[(3) - (3)].expression),next_parameter);
				/*quad*/ if ( PARAMMODE(global_routine_name,N) == "V" && ((yyvsp[(3) - (3)].expression).type != PARAMTYPE(global_routine_name,N) ) )
						{GENQUAD("par",(yyvsp[(3) - (3)].expression).name,PARAMMODE(global_routine_name,N),"-");}
					else
						{GENQUAD("par",(yyvsp[(3) - (3)].expression).name,PARAMMODE(global_routine_name,N),"-");}
					N = N+1; }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 398 "parser.y"
    { }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 399 "parser.y"
    { if (next_parameter) 
						fatal("Not enough arguments in function %s, total %d arguments expected. Line = %d",f->id,total_parameters,lineno); 
							   }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 408 "parser.y"
    { /*quad*/ printf("open hook-block\n");(yyval.statement).NEXT = (yyvsp[(2) - (3)].statement).NEXT;printf("close hook-block\n");}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 409 "parser.y"
    {  /*quad*/ printf("first local_def of block list\n");(yyval.statement).NEXT = (yyvsp[(2) - (2)].statement).NEXT;printf("rest local_defs of block list\n");}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 410 "parser.y"
    {/*quad*/ printf("first stmt of block list\n");L = (yyvsp[(1) - (1)].statement).NEXT; printf("first stmt of block list 1\n");sprintf(temp_name1,"%d",NEXTQUAD());printf("first stmt of block list 2\n");print_list(L);printf("   fp =  %d \n",fileno(fp));BACKPATCH(fp,L,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("   fp =  %d \n",fileno(fp));printf("after first stmt of block list\n");}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 410 "parser.y"
    { /*quad*/ printf("rest stmts of block list\n");(yyval.statement).NEXT = (yyvsp[(3) - (3)].statement).NEXT;printf("after rest stmts of block list\n"); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 411 "parser.y"
    { /*quad*/ printf("no other stmts-defs in block\n");(yyval.statement).NEXT = NULL;}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 413 "parser.y"
    { }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 414 "parser.y"
    { }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 424 "parser.y"
    { /*quad*/  (yyval.statement).NEXT = EMPTYLIST();}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 425 "parser.y"
    {   if ((yyvsp[(1) - (4)].expression).is_constant) 
     						fatal("Cannot change constant value. Line = %d\n",lineno);
     					else if (!assignmentEvaluation((yyvsp[(1) - (4)].expression).type,(yyvsp[(3) - (4)].expression).type))
     						fatal("Invalid assignment.Cannot assign %s to %s. Line = %d\n",getType((yyvsp[(3) - (4)].expression).type),getType((yyvsp[(1) - (4)].expression).type),lineno);
     					/*quad*/  
     					printf("before assign statement\n");
     					GENQUAD(":=",(yyvsp[(3) - (4)].expression).name,"-",(yyvsp[(1) - (4)].expression).name);
     					(yyval.statement).NEXT = EMPTYLIST();
     					printf("after assign statement\n");
     					
     									}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 436 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_plus);  /*quad*/  printf("before plusassign\n");GENQUAD("+",(yyvsp[(3) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after plusassign\n"); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 437 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_minus);  /*quad*/   printf("before minusassign\n");GENQUAD("-",(yyvsp[(3) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after minusassign\n");}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 438 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_mult);   /*quad*/   printf("before multassign\n");GENQUAD("*",(yyvsp[(3) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after multassign\n");}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 439 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_div);    /*quad*/   printf("before divassign\n");GENQUAD("/",(yyvsp[(3) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after divassign\n");}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 440 "parser.y"
    {  operationAndAssignment((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression),T_mod);    /*quad*/   printf("before modassign\n");GENQUAD("%",(yyvsp[(3) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name,(yyvsp[(1) - (4)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after modassign\n");}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 441 "parser.y"
    { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     				operationAndAssignment((yyvsp[(1) - (3)].expression),unit_expression,T_plus); 
     			/*quad*/   printf("before ++\n");GENQUAD("+",(yyvsp[(1) - (3)].expression).name,"1",(yyvsp[(1) - (3)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after ++\n");
     						}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 445 "parser.y"
    { unit_expression.type = typeInteger; unit_expression.is_constant = 1; unit_expression.value.x = 1;
     					operationAndAssignment((yyvsp[(1) - (3)].expression),unit_expression,T_minus);   
     					/*quad*/   printf("before --\n");GENQUAD("-",(yyvsp[(1) - (3)].expression).name,"1",(yyvsp[(1) - (3)].expression).name);(yyval.statement).NEXT = EMPTYLIST();printf("after --\n");
     													}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 449 "parser.y"
    { /*quad*/ (yyval.statement).NEXT = EMPTYLIST();}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 450 "parser.y"
    {/*quad*/ printf("before if cond\n");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(3) - (4)].expression)._TRUE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");L1 = (yyvsp[(3) - (4)].expression)._FALSE_; L2 = EMPTYLIST();printf("after if cond\n");}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 451 "parser.y"
    {   if (!equalType((yyvsp[(3) - (6)].expression).type,typeBoolean)) 
			fatal("Expression in if statement not boolean. Line = %d\n",lineno);	     			
		/*quad*/ printf("before if stmt\n");
			L3 = MERGE((yyvsp[(6) - (6)].statement).NEXT,L2);
			printf("if stmt 1 \n");
			(yyval.statement).NEXT = MERGE(L1,L3);
			printf("after if stmt\n");							
     								}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 459 "parser.y"
    {/*quad*/ printf("before if-else cond\n");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(3) - (4)].expression)._TRUE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");L1 = (yyvsp[(3) - (4)].expression)._FALSE_; L2 = EMPTYLIST();printf("after if-else cond\n");}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 460 "parser.y"
    {/*quad*/printf("before if-else stmt\n");L1 = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(3) - (7)].expression)._FALSE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("after if-else stmt\n");}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 461 "parser.y"
    {  if (!equalType((yyvsp[(3) - (9)].expression).type,typeBoolean)) 
			fatal("Expression in if statement not boolean. Line = %d\n",lineno);
		/*quad*/ 
		printf("before if-else\n"); 
		L2 = (yyvsp[(9) - (9)].statement).NEXT;
		L3 = MERGE((yyvsp[(6) - (9)].statement).NEXT,L2);
		(yyval.statement).NEXT = MERGE(L1,L3);	
		printf("after if-else\n"); 
     					}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 470 "parser.y"
    { loop_counter++; 
     		/*quad*/ 
     		printf("entered while\n");
     		(yyvsp[(1) - (1)].statement).NEXT = EMPTYLIST();
     		Q = NEXTQUAD();
     		if(loop_seq == NULL)
     			loop_seq = makeLoopStack(&((yyvsp[(1) - (1)].statement)),Q);
     		else 
     			loop_seq = LoopPush(loop_seq,Q,&((yyvsp[(1) - (1)].statement)));
     		printf("after word while\n");
     						}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 481 "parser.y"
    {/*quad*/ printf("enter after cond\n");sprintf(temp_name1,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(4) - (5)].expression)._TRUE_,temp_name1);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");printf("leave after cond\n");}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 482 "parser.y"
    {    if (!equalType((yyvsp[(4) - (7)].expression).type,typeBoolean)) 
			fatal("Expression in if statement not boolean. Line = %d\n",lineno);	
		loop_counter--; 
	/*quad*/
		printf("enter after stmt\n");
		sprintf(temp_name1,"%d",loop_seq->start);
		printf("while 1\n");
		BACKPATCH(fp,(yyvsp[(7) - (7)].statement).NEXT,temp_name1);
		if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
		printf("while 2\n");
		sprintf(temp_name1,"%d",loop_seq->start);
		printf("while 3\n");
		GENQUAD("jump","-","-",temp_name1);
		printf("while 4\n");
		loop_seq = LoopPop(loop_seq);
		printf("while 5\n");
		//$$.NEXT = $4.NEXT;
		(yyval.statement).NEXT = MERGE((yyvsp[(1) - (7)].statement).NEXT,(yyvsp[(4) - (7)].expression)._FALSE_);
		printf("leave after stmt\n");}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 501 "parser.y"
    { loop_counter++; 
               /*quad*/ Q = NEXTQUAD()+4; 
               if(loop_seq == NULL)
              		loop_seq = makeLoopStack(&((yyvsp[(1) - (1)].statement)),Q);
              	else 
              		loop_seq = LoopPush(loop_seq,Q,&((yyvsp[(1) - (1)].statement)));
              						}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 508 "parser.y"
    {/*quad*/ 
       				  t = (Type) new(sizeof(struct Type_tag));
				  printf("FOR2\n");
				  t->kind = TYPE_INTEGER;
				  printf("FOR3\n");
				  t->refCount = 0;
			          printf("FOR4\n");
				  W3 = newTemporary(t);
				  printf("FOR5\n");
       				  GENQUAD(":=",(yyvsp[(6) - (6)].range).first,"-",strdup(W3->id));
       				  printf("FOR6\n");
       				  GENQUAD(":=",strdup(W3->id),"-",strdup((yyvsp[(4) - (6)].string_value))); 
       				  printf("FOR7\n");
       				  
       				  if((yyvsp[(6) - (6)].range).counting == 1) 
       				  	{ (yyvsp[(1) - (6)].statement).NEXT = MAKELIST(NEXTQUAD());GENQUAD(">",strdup((yyvsp[(4) - (6)].string_value)),(yyvsp[(6) - (6)].range).last,"*"); } 
       				  else if((yyvsp[(6) - (6)].range).counting == 2) 
       				  	{ (yyvsp[(1) - (6)].statement).NEXT = MAKELIST(NEXTQUAD());GENQUAD("<",strdup((yyvsp[(4) - (6)].string_value)),(yyvsp[(6) - (6)].range).last,"*");}
       				  									}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 527 "parser.y"
    {  	p = lookupEntry((yyvsp[(4) - (9)].string_value),LOOKUP_ALL_SCOPES,0);
     			if (!p) 
     				fatal("Variable '%s' in for loop does not exist. Line = %d\n",(yyvsp[(4) - (9)].string_value),lineno);
     			else if (!valid_loop_variable(p))
	   			fatal("Variable '%s' in for loop is not an integer. Line = %d\n");
    			loop_counter--;
    			/*quad*/ 
    			printf("FOR8\n");
    			printf("FOR9\n");
    			if((yyvsp[(6) - (9)].range).counting == 1){
    				printf("quads before last add: %d\n",NEXTQUAD());
    				GENQUAD("+",strdup(W3->id),(yyvsp[(6) - (9)].range).step,strdup(W3->id));
    				sprintf(temp_name1,"%d",loop_seq->start);
    				printf("quads before last jump: %d\n",NEXTQUAD());
    				GENQUAD("jmp1","-","-",temp_name1);
    				(yyval.statement).NEXT = (yyvsp[(1) - (9)].statement).NEXT;}
    			else if((yyvsp[(6) - (9)].range).counting == 2){
    				GENQUAD("-",strdup(W3->id),(yyvsp[(6) - (9)].range).step,strdup(W3->id));
    				sprintf(temp_name1,"%d",loop_seq->start);
    				GENQUAD("jmp1","-","-",temp_name1);
    				(yyval.statement).NEXT = (yyvsp[(1) - (9)].statement).NEXT;
    			}
    			loop_seq = LoopPop(loop_seq); 
    			printf("FOR10\n");
    						}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 552 "parser.y"
    {/*quad*/ Q = NEXTQUAD(); 
    		      printf("before do_while stmt\n");
     			if(loop_seq == NULL)
     				{loop_seq = makeLoopStack(&((yyvsp[(1) - (1)].statement)),Q);}
     			else 
     				{loop_seq = LoopPush(loop_seq,Q,&((yyvsp[(1) - (1)].statement)));}
     								}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 559 "parser.y"
    {/*quad*/   printf("before do_while stmt\n");sprintf(temp_name1,"%d",NEXTQUAD());printf("%s\n",temp_name1);BACKPATCH(fp,(yyvsp[(3) - (3)].statement).NEXT,temp_name1);printf("after do_while stmt\n");}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 560 "parser.y"
    { loop_counter++; (yyvsp[(1) - (5)].statement).NEXT = EMPTYLIST();}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 562 "parser.y"
    {    if (!equalType((yyvsp[(8) - (10)].expression).type,typeBoolean)) 
			fatal("Expression in while statement not boolean. Line = %d\n",lineno);	
		printf("before 'closing' do-while statement\n");     	
		loop_counter--;
		/*quad*/ 
		printf("'closing' do-while statement 1\n"); 
		loop_seq = LoopPop(loop_seq);
		printf("'closing' do-while statement 2\n");
		sprintf(temp_name3,"%d",loop_seq->start);
		printf("'closing' do-while statement 3\n");
		BACKPATCH(fp,(yyvsp[(8) - (10)].expression)._TRUE_,temp_name3);
		if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
		printf("   fp =  %d \n",fileno(fp));
		(yyval.statement).NEXT = MERGE((yyvsp[(1) - (10)].statement).NEXT,(yyvsp[(8) - (10)].expression)._FALSE_);
		//printf("next of while is %d\n",$$.NEXT->quad_num);
		}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 578 "parser.y"
    {/*quad*/ printf("before switch expr\n");if(switch_seq == NULL){switch_seq = makeSwitchStack(&((yyvsp[(3) - (3)].expression)));}else {switch_seq = SwitchPush(switch_seq,&((yyvsp[(3) - (3)].expression)));printf("after switch expr\n");} }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 580 "parser.y"
    {    if ((yyvsp[(3) - (8)].expression).type!=typeInteger)
     				fatal("Expression in switch statement is not integer. Line = %d\n",lineno);
     			/*quad*/ 
     				printf("before close switch\n");
     				switch_seq = SwitchPop(switch_seq);
     				printf("before close switch 1\n");
     			 	sprintf(temp_name1,"%d",NEXTQUAD());
     			 	printf("before close switch 2\n"); 
     			 	if((yyvsp[(7) - (8)].statement).NEXT == NULL)	printf("malakia\n");
     			 	print_list((yyvsp[(7) - (8)].statement).NEXT);
     			 	printf("before close switch 3\n");
     				BACKPATCH(fp,(yyvsp[(7) - (8)].statement).NEXT,temp_name1);
     				if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
     				printf("after close switch \n");
     				(yyval.statement).NEXT = NULL;
     						}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 596 "parser.y"
    { if (loop_counter==0) 
     			    	fatal("Break statement is not in a loop. Line = %d\n",lineno);
     		       /*quad*/ L = MAKELIST(NEXTQUAD());
     			   	GENQUAD("jmp","-","-","*");
     			   	(loop_seq->stmt)->NEXT = MERGE((loop_seq->stmt)->NEXT,L);
     			   	(yyval.statement).NEXT = NULL;
     				   							}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 603 "parser.y"
    { if (loop_counter==0)
     				fatal("Continue statement is not in a loop. Line =%d\n",lineno);
     			/*quad*/ 
     			printf("entering continue\n");
     			sprintf(temp_name1,"%d",loop_seq->start);
     			printf("quads before cont: %d\n",NEXTQUAD());
     			GENQUAD("jmp","-","-",temp_name1);
     			printf("quads after cont: %d\n",NEXTQUAD());
     			printf("leaving continue\n");
     			(yyval.statement).NEXT = NULL;
     				  					}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 614 "parser.y"
    { validate_return((yyvsp[(2) - (3)].expression).type); found_return_statement = true; 
     				/*quad*/ 
     				GENQUAD(":=",(yyvsp[(2) - (3)].expression).name,"-","$$");
     				GENQUAD("ret","-","-","-");
     				(yyval.statement).NEXT = NULL;
     													}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 620 "parser.y"
    { validate_return(typeVoid); /*quad*/ GENQUAD("ret","-","-","-");(yyval.statement).NEXT = NULL;}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 621 "parser.y"
    { /*quad*/ (yyval.statement).NEXT = (yyvsp[(1) - (1)].statement).NEXT; }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 622 "parser.y"
    { }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 623 "parser.y"
    {  }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 628 "parser.y"
    { /*quad*/ (yyval.statement).NEXT = MERGE((yyvsp[(1) - (2)].statement).NEXT,(yyvsp[(2) - (2)].statement).NEXT); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 629 "parser.y"
    {}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 631 "parser.y"
    {/*quad*/ L = MAKELIST(NEXTQUAD());GENQUAD("<>",(switch_seq->expression)->name,(yyvsp[(2) - (2)].expression).name,"*");}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 632 "parser.y"
    {if (!equalType(typeInteger,(yyvsp[(2) - (7)].expression).type)) 
							  fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
						   	  /*quad*/ 
						      L1 = MAKELIST(NEXTQUAD());
						      (yyval.statement).NEXT = L1;
						      GENQUAD("jmp","-","-","*");
						      sprintf(temp_name1,"%d",NEXTQUAD());
						      BACKPATCH(fp,L,temp_name1);
						      if(fileno(fp) == -1) fp = fopen("quads.txt","a+");
										}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 642 "parser.y"
    {/*quad*/ L = MAKELIST(NEXTQUAD());GENQUAD("<>",(switch_seq->expression)->name,(yyvsp[(2) - (2)].expression).name,"*");}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 643 "parser.y"
    {   if (!equalType(typeInteger,(yyvsp[(2) - (7)].expression).type)) 
									fatal("Expression in case statement not of integer type. Line = %d\n",lineno);
									/*quad*/ 
								 	(yyval.statement).NEXT = NULL; 
									sprintf(temp_name3,"%d",NEXTQUAD());
									BACKPATCH(fp,L,temp_name3);
									if(fileno(fp) == -1) fp = fopen("quads.txt","a+");			
											}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 651 "parser.y"
    { (yyval.statement).NEXT = NULL; }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 652 "parser.y"
    { (yyval.statement).NEXT = NULL;}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 653 "parser.y"
    { }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 654 "parser.y"
    { /*nothing*/ }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 657 "parser.y"
    { validate_range_and_step((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),(yyvsp[(1) - (3)].expression),0);  /*quad*/ printf("entered range\n");
										(yyval.range).first = (yyvsp[(1) - (3)].expression).name;
										(yyval.range).last = (yyvsp[(3) - (3)].expression).name;
										printf("range1\n");
										if((yyvsp[(2) - (3)].string_value) == "TO")	
											(yyval.range).counting = 1;
										else if((yyvsp[(2) - (3)].string_value) == "DOWNTO")	
											(yyval.range).counting = 2;
										t = (Type) new(sizeof(struct Type_tag));
										printf("range2\n");
										t->kind = TYPE_INTEGER;
										printf("range3\n");
										t->refCount = 0;
										printf("range4\n");
										W = newTemporary(t);
										printf("range5\n");
										(yyval.range).step = strdup(W->id);
										printf("range6\n");
										GENQUAD(":=","1","-",(yyval.range).step);
										printf("left range\n"); 
										
															}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 679 "parser.y"
    { validate_range_and_step((yyvsp[(1) - (5)].expression),(yyvsp[(3) - (5)].expression),(yyvsp[(5) - (5)].expression),1); 
	  					/*quad*/ printf("entered range TO/DOWN\n");
	  						 (yyval.range).first = (yyvsp[(1) - (5)].expression).name;
	  						 (yyval.range).last = (yyvsp[(3) - (5)].expression).name;
	  						 if((yyvsp[(2) - (5)].string_value) == "TO")	
	  							(yyval.range).counting = 1;
	  						 else if((yyvsp[(2) - (5)].string_value) == "DOWNTO")	
	  							(yyval.range).counting = 2;
	  						 (yyval.range).step = (yyvsp[(5) - (5)].expression).name;
	  						 printf("left range TO/DOWN\n");
	  						 			}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 690 "parser.y"
    { (yyval.string_value) = "TO";  }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 691 "parser.y"
    { (yyval.string_value) = "DOWNTO"; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 695 "parser.y"
    { }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 696 "parser.y"
    {  }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 697 "parser.y"
    { validate_print_expression((yyvsp[(1) - (1)].expression),(yyvsp[(1) - (1)].expression),(yyvsp[(1) - (1)].expression),1); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 698 "parser.y"
    {  validate_print_expression((yyvsp[(3) - (8)].expression),(yyvsp[(5) - (8)].expression),(yyvsp[(7) - (8)].expression),2);
       													   }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 700 "parser.y"
    { validate_print_expression((yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression),(yyvsp[(5) - (6)].expression),3);
       											}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 702 "parser.y"
    { }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 703 "parser.y"
    { }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 704 "parser.y"
    { }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 705 "parser.y"
    { }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 710 "parser.y"
    { evaluate_constant=1; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 710 "parser.y"
    { (yyval.expression)=(yyvsp[(2) - (2)].expression); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 712 "parser.y"
    { printf("   fp =  %d \n",fileno(fp));(yyval.expression).type=typeInteger; (yyval.expression).is_constant=1;  l_value_flag=0;   /*quad*/ Wq = newTemporary((yyval.expression).type);sprintf(temp_name1,"%d",(yyvsp[(1) - (1)].expression).value.x);(yyval.expression).name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",(yyval.expression).name);printf("temp var created\n");}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 713 "parser.y"
    { (yyval.expression).type=typeReal; (yyval.expression).is_constant=1;  l_value_flag=0;     /*quad*/ Wq = newTemporary((yyval.expression).type);sprintf(temp_name1,"%Lf",(yyvsp[(1) - (1)].expression).value.w);(yyval.expression).name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",(yyval.expression).name);printf("temp var created\n");}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 714 "parser.y"
    { (yyval.expression).type=typeChar; (yyval.expression).is_constant=1;  l_value_flag=0;     /*quad*/ Wq = newTemporary((yyval.expression).type);sprintf(temp_name1,"%c",(yyvsp[(1) - (1)].expression).value.z);printf("character %c  ---\n",((yyvsp[(1) - (1)].expression).value.z));(yyval.expression).name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",(yyval.expression).name);printf("temp var created\n");}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 715 "parser.y"
    {  (yyval.expression).type=typeArray(strlen((yyval.expression).value.q)+1,typeChar); (yyval.expression).is_constant=1; l_value_flag=0;    /*quad*/Wq = newTemporary((yyval.expression).type);sprintf(temp_name1,"%s",(yyvsp[(1) - (1)].expression).value.q);(yyval.expression).name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",(yyval.expression).name);printf("temp var created\n");}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 716 "parser.y"
    { (yyval.expression).type=typeBoolean; (yyval.expression).is_constant=1; l_value_flag=0;    /*quad*/ Wq = newTemporary((yyval.expression).type);sprintf(temp_name1,"%u",(yyvsp[(1) - (1)].expression).value.y);(yyval.expression).name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",(yyval.expression).name);printf("temp var created\n");}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 717 "parser.y"
    { (yyval.expression).type=typeBoolean; (yyval.expression).is_constant=1; l_value_flag=0;    /*quad*/ Wq = newTemporary((yyval.expression).type);sprintf(temp_name1,"%u",(yyvsp[(1) - (1)].expression).value.y);(yyval.expression).name = strdup(Wq->id);GENQUAD(":=",temp_name1,"-",(yyval.expression).name);printf("temp var created\n");}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 718 "parser.y"
    { (yyval.expression)=(yyvsp[(2) - (3)].expression); l_value_flag=0;    }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 719 "parser.y"
    { (yyval.expression)=(yyvsp[(1) - (1)].expression);  }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 720 "parser.y"
    { (yyval.expression).is_constant=0; (yyval.expression).type=(yyvsp[(1) - (1)].expression).type;l_value_flag=0;    /*quad*/  (yyval.expression).name = (yyvsp[(1) - (1)].expression).name;}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 721 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_plus,0); l_value_flag=0;    /*quad*/ (yyval.expression) = (yyvsp[(2) - (2)].expression);}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 722 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_minus,0);l_value_flag=0;    /*quad*/ Wq = newTemporary((yyval.expression).type);(yyval.expression).name = strdup(W->id);GENQUAD("-",(yyvsp[(2) - (2)].expression).name,"-",(yyval.expression).name);}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 723 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_plus,1);l_value_flag=0;    /*quad*/ printf("before addition1\n");W = newTemporary((yyval.expression).type);printf("before addition2\n");(yyval.expression).name = strdup(W->id);printf("before addition3\n");GENQUAD("+",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,(yyval.expression).name);printf("addition done new temp var created\n");}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 724 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_minus,1);l_value_flag=0;    /*quad*/ W = newTemporary((yyval.expression).type);(yyval.expression).name = strdup(W->id);GENQUAD("-",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,(yyval.expression).name);}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 725 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_mult,1);l_value_flag=0;	/*quad*/ W = newTemporary((yyval.expression).type);(yyval.expression).name = strdup(W->id);GENQUAD("*",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,(yyval.expression).name);}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 726 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_div,1);l_value_flag=0;	/*quad*/ W = newTemporary((yyval.expression).type);(yyval.expression).name = strdup(W->id);GENQUAD("/",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,(yyval.expression).name);}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 727 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_mod,1);l_value_flag=0;	/*quad*/ W = newTemporary((yyval.expression).type);(yyval.expression).name = strdup(W->id);GENQUAD("%",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,(yyval.expression).name);}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 728 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_MOD,1);l_value_flag=0;	/*quad*/ W = newTemporary((yyval.expression).type);(yyval.expression).name = strdup(W->id);GENQUAD("%",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,(yyval.expression).name);}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 734 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_less,1);l_value_flag=0;   /*quad*/ printf("before expr equal\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("==",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,"*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr equal\n");}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 735 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_nequal,1);l_value_flag=0;    /*quad*/ printf("before expr n_equal\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("<>",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,"*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr n_equal\n");}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 736 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_less,1);l_value_flag=0;    /*quad*/ printf("before expr less\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("<",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,"*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr less\n");}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 737 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_greater,1);l_value_flag=0;    /*quad*/ printf("before expr greater\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD(">",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,"*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr greater\n");}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 738 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_lequal,1);l_value_flag=0;     /*quad*/ printf("before expr lequal\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD("<=",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,"*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr lequal\n");}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 739 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression),T_egreater,1);l_value_flag=0;    /*quad*/ printf("before expr egreater\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD());GENQUAD(">=",(yyvsp[(1) - (3)].expression).name,(yyvsp[(3) - (3)].expression).name,"*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr egreater\n");}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 741 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_not,0);l_value_flag=0;   /*quad*/  (yyval.expression)._TRUE_ = (yyvsp[(2) - (2)].expression)._FALSE_; (yyval.expression)._FALSE_ = (yyvsp[(2) - (2)].expression)._TRUE_;}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 742 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(2) - (2)].expression),(yyvsp[(2) - (2)].expression),T_notb,0); l_value_flag=0;    /*quad*/  (yyval.expression)._TRUE_ = (yyvsp[(2) - (2)].expression)._FALSE_; (yyval.expression)._FALSE_ = (yyvsp[(2) - (2)].expression)._TRUE_;}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 743 "parser.y"
    {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(1) - (2)].expression)._TRUE_,temp_name3 );if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 743 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (4)].expression),(yyvsp[(4) - (4)].expression),T_AND,1);l_value_flag=0;    /*quad*/ (yyval.expression)._TRUE_ = (yyvsp[(4) - (4)].expression)._TRUE_;(yyval.expression)._FALSE_ = MERGE((yyvsp[(1) - (4)].expression)._FALSE_,(yyvsp[(4) - (4)].expression)._FALSE_);}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 744 "parser.y"
    {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(1) - (2)].expression)._TRUE_,temp_name3 );if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 744 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (4)].expression),(yyvsp[(4) - (4)].expression),T_and,1);l_value_flag=0;    /*quad*/ (yyval.expression)._TRUE_ = (yyvsp[(4) - (4)].expression)._TRUE_;(yyval.expression)._FALSE_ = MERGE((yyvsp[(1) - (4)].expression)._FALSE_,(yyvsp[(4) - (4)].expression)._FALSE_);}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 745 "parser.y"
    {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(1) - (2)].expression)._FALSE_,temp_name3 );if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 745 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (4)].expression),(yyvsp[(4) - (4)].expression),T_OR,1);l_value_flag=0;    /*quad*/ (yyval.expression)._TRUE_ = MERGE((yyvsp[(1) - (4)].expression)._TRUE_,(yyvsp[(4) - (4)].expression)._TRUE_);(yyval.expression)._FALSE_ = (yyvsp[(4) - (4)].expression)._FALSE_;}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 746 "parser.y"
    {/*quad*/sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(1) - (2)].expression)._FALSE_,temp_name3);if(fileno(fp) == -1) fp = fopen("quads.txt","a+"); }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 746 "parser.y"
    { (yyval.expression)=typeInference((yyvsp[(1) - (4)].expression),(yyvsp[(4) - (4)].expression),T_or,1);l_value_flag=0;    /*quad*/ (yyval.expression)._TRUE_ = MERGE((yyvsp[(1) - (4)].expression)._TRUE_,(yyvsp[(4) - (4)].expression)._TRUE_);(yyval.expression)._FALSE_ = (yyvsp[(4) - (4)].expression)._FALSE_;}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 748 "parser.y"
    {/*quad*/printf("before expr->cond\n");(yyval.expression)._TRUE_ = MAKELIST(NEXTQUAD()); GENQUAD("ifb",(yyvsp[(1) - (1)].expression).name,"-","*");(yyval.expression)._FALSE_ = MAKELIST(NEXTQUAD());GENQUAD("jump","-","-","*");printf("after expr->cond\n");}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 750 "parser.y"
    {/*quad*/ printf("before cond->expr\n");(yyval.expression).temp = tempNumber;sprintf(temp_name1,"$%d",tempNumber);(yyval.expression).name = temp_name1;W = newTemporary(typeBoolean);sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(1) - (1)].expression)._TRUE_,temp_name3);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");GENQUAD(":=","true","-",(yyval.expression).name);Q = NEXTQUAD()+2;sprintf(temp_name2,"%d",Q);GENQUAD("jump","-","-",temp_name2);sprintf(temp_name3,"%d",NEXTQUAD());BACKPATCH(fp,(yyvsp[(1) - (1)].expression)._FALSE_,temp_name3);if(fileno(fp) == -1) fp = fopen("quads.txt","a+");GENQUAD(":=","false","-",(yyval.expression).name);printf("after cond->expr\n");}
    break;



/* Line 1806 of yacc.c  */
#line 3452 "parser.c"
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
#line 755 "parser.y"


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


