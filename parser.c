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
#line 4 "parser.y"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void yyerror (const char *msg);


/* Line 268 of yacc.c  */
#line 80 "parser.c"

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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 197 "parser.c"

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   832

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNRULES -- Number of states.  */
#define YYNSTATES  263

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
      25,    31,    32,    37,    41,    42,    45,    48,    51,    52,
      57,    61,    67,    69,    72,    76,    77,    82,    83,    86,
      88,    94,    96,    97,   102,   103,   106,   108,   110,   115,
     118,   120,   122,   124,   126,   128,   130,   132,   134,   136,
     138,   140,   144,   146,   148,   151,   154,   157,   160,   164,
     168,   172,   176,   180,   184,   188,   192,   196,   200,   204,
     208,   212,   216,   220,   224,   227,   228,   233,   238,   241,
     242,   246,   247,   251,   254,   257,   258,   260,   262,   264,
     269,   273,   277,   280,   286,   294,   300,   308,   316,   324,
     335,   338,   341,   345,   348,   350,   355,   362,   366,   367,
     372,   376,   380,   381,   383,   385,   387,   389,   391,   393,
     398,   400,   402,   405,   406,   410,   414,   417,   418,   420,
     422,   424,   426,   428,   436,   439
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      77,     0,    -1,    78,    -1,    79,    78,    -1,    -1,    80,
      -1,    82,    -1,    94,    -1,    96,    -1,     8,    97,    39,
      58,    98,    81,    65,    -1,    70,    39,    58,    98,    81,
      -1,    -1,    97,    84,    83,    65,    -1,    70,    84,    83,
      -1,    -1,    39,    85,    -1,    39,    86,    -1,    58,    99,
      -1,    -1,    71,    98,    72,    86,    -1,    71,    98,    72,
      -1,    88,    39,    67,    89,    68,    -1,    24,    -1,    17,
      97,    -1,    97,    91,    90,    -1,    -1,    70,    97,    91,
      90,    -1,    -1,    64,    39,    -1,    39,    -1,    39,    71,
      92,    72,    93,    -1,    98,    -1,    -1,    71,    98,    72,
      93,    -1,    -1,    87,    88,    -1,    65,    -1,   105,    -1,
      25,    39,    67,    68,    -1,    95,   105,    -1,    19,    -1,
       3,    -1,     7,    -1,    26,    -1,    99,    -1,    37,    -1,
      38,    -1,    40,    -1,    41,    -1,    31,    -1,    14,    -1,
      67,    99,    68,    -1,   100,    -1,   102,    -1,    48,    99,
      -1,    22,    99,    -1,    53,    99,    -1,    49,    99,    -1,
      99,    48,    99,    -1,    99,    49,    99,    -1,    99,    50,
      99,    -1,    99,    51,    99,    -1,    99,    52,    99,    -1,
      99,    20,    99,    -1,    99,    42,    99,    -1,    99,    45,
      99,    -1,    99,    44,    99,    -1,    99,    43,    99,    -1,
      99,    47,    99,    -1,    99,    54,    99,    -1,    99,     4,
      99,    -1,    99,    55,    99,    -1,    99,    23,    99,    -1,
      99,    46,    99,    -1,    39,   101,    -1,    -1,   101,    71,
      99,    72,    -1,    39,    67,   103,    68,    -1,    99,   104,
      -1,    -1,    70,    99,   104,    -1,    -1,    73,   106,    74,
      -1,   107,   106,    -1,   108,   106,    -1,    -1,    80,    -1,
      82,    -1,    65,    -1,   100,   112,    99,    65,    -1,   100,
      56,    65,    -1,   100,    57,    65,    -1,   102,    65,    -1,
      18,    67,    99,    68,   108,    -1,    18,    67,    99,    68,
     108,    13,   108,    -1,    32,    67,    99,    68,   108,    -1,
      15,    67,    39,    70,   113,    68,   108,    -1,    11,   108,
      32,    67,    99,    68,    65,    -1,    29,    67,    99,    68,
      73,   109,    74,    -1,    29,    67,    99,    68,    73,   109,
      10,    69,   116,    74,    -1,     5,    65,    -1,     9,    65,
      -1,    27,    99,    65,    -1,    27,    65,    -1,   105,    -1,
     118,    67,    68,    65,    -1,   118,    67,   119,   111,    68,
      65,    -1,   109,   110,   116,    -1,    -1,   110,     6,    98,
      69,    -1,     6,    98,    69,    -1,    70,   119,   111,    -1,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    99,   114,    99,   115,    -1,    30,    -1,
      12,    -1,    28,    99,    -1,    -1,   117,     5,    65,    -1,
     117,    21,    65,    -1,   117,   108,    -1,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    99,    -1,    16,    67,
      99,    70,    99,   120,    67,    -1,    70,    99,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   119,   120,   122,   123,   124,   125,   127,
     129,   130,   132,   134,   135,   137,   138,   139,   140,   141,
     142,   144,   145,   146,   147,   148,   149,   150,   152,   153,
     154,   155,   156,   157,   158,   160,   161,   162,   164,   166,
     168,   169,   170,   171,   173,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   206,   208,   209,   211,   212,   213,
     214,   215,   217,   218,   219,   220,   222,   223,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   245,   246,   247,
     248,   251,   252,   254,   255,   256,   257,   258,   259,   261,
     262,   263,   264,   265,   267,   268,   270,   271,   274,   275,
     276,   277,   279,   280,   281,   282
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
  "declaration", "const_def", "const_def_list", "var_def", "var_def_list",
  "var_init", "var_init_if", "var_init_list", "routine_header",
  "routine_header_choose", "routine_header_if", "routine_header_if_list",
  "formal", "formal_if2", "formal_list", "routine", "program_header",
  "program", "type", "const_expr", "expr", "l_value", "l_value_list",
  "call", "call_if", "call_if_list", "block", "block_list", "local_def",
  "stmt", "stmt_list1", "stmt_list1_list", "stmt_if5_list", "assign",
  "range", "range_choose", "range_if", "clause", "clause_list", "write",
  "format", "format_if", 0
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
      81,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    88,    88,    95,    96,
      97,    97,    97,    97,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   101,   101,   102,   103,   103,
     104,   104,   105,   106,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   112,   112,   112,   112,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   119,   119,   120,   120
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     7,
       5,     0,     4,     3,     0,     2,     2,     2,     0,     4,
       3,     5,     1,     2,     3,     0,     4,     0,     2,     1,
       5,     1,     0,     4,     0,     2,     1,     1,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     0,     4,     4,     2,     0,
       3,     0,     3,     2,     2,     0,     1,     1,     1,     4,
       3,     3,     2,     5,     7,     5,     7,     7,     7,    10,
       2,     2,     3,     2,     1,     4,     6,     3,     0,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     2,     0,     3,     3,     2,     0,     1,     1,
       1,     1,     1,     7,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    41,    42,     0,     0,    40,    22,     0,    43,    36,
      85,     0,     2,     4,     5,     6,     0,     0,     7,     0,
       8,     0,    37,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,   130,   131,    75,    88,
      86,    87,     0,     0,   104,     0,    85,    85,     0,     1,
       3,    35,     0,    39,    18,    14,     0,     0,   100,   101,
       0,     0,     0,    50,     0,    49,    45,    46,    47,    48,
       0,     0,     0,   103,     0,     0,    52,    53,     0,     0,
      79,    74,     0,     0,   113,   114,   115,   116,   117,   118,
       0,    92,    82,    83,    84,     0,    25,     0,     0,    15,
      16,     0,     0,     0,    38,     0,     0,     0,    55,    54,
      57,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
       0,     0,    81,     0,     0,    90,    91,     0,     0,     0,
     132,   112,     0,     0,    17,     0,    44,    14,    12,    11,
       0,     0,     0,    51,    70,    63,    72,    64,    67,    66,
      65,    73,    68,    58,    59,    60,    61,    62,    69,    71,
       0,     0,     0,    78,    77,     0,    89,     0,   105,     0,
       0,    21,    29,     0,    27,    20,    13,     0,     0,     0,
       0,     0,    93,   108,    95,    81,    76,     0,   112,     0,
      32,    28,     0,    24,    19,     0,     9,     0,   121,   120,
       0,     0,     0,     0,    80,     0,   111,   106,     0,    31,
       0,     0,    97,   123,    96,    94,     0,     0,    98,   127,
     135,    34,    27,    11,     0,   119,     0,   127,     0,   107,
       0,     0,     0,     0,    30,    26,    10,   122,   110,     0,
       0,     0,     0,   126,   134,   133,     0,    99,   109,   100,
     125,    34,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    40,   188,    41,   102,    55,    99,
     100,    16,    17,   142,   203,   184,   218,   244,    18,    19,
      20,    21,   145,   146,    76,    81,    77,   133,   173,    44,
      45,    46,    47,   213,   229,   180,    90,   191,   210,   235,
     239,   240,    48,   141,   242
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
      52,   -92,   -92,   107,   107,   -92,   -92,   -34,   -92,   -92,
     218,     7,   -92,    52,   -92,   -92,    17,   -28,   -92,   -54,
     -92,   -17,   -92,     8,   -92,   -16,   -12,   -11,   288,    -6,
      -5,   640,    12,    13,   -92,   -92,   -92,   -92,    14,   -92,
     -92,   -92,   347,    19,   -92,    39,   218,   218,    18,   -92,
     -92,   -92,    20,   -92,    50,    45,    30,    48,   -92,   -92,
      87,    81,   680,   -92,   680,   -92,   -92,   -92,   -92,   -92,
     680,   680,   680,   -92,   680,   544,   -92,   -92,   680,   680,
     680,    51,    58,    69,   -92,   -92,   -92,   -92,   -92,   -92,
     680,   -92,   -92,   -92,   -92,   619,   107,   680,   680,   -92,
     -92,   -17,    71,   680,   -92,    72,    67,   379,   -92,    -7,
      -7,   -92,   412,   680,   680,   680,   680,   680,   680,   680,
     680,   680,   680,   680,   680,   680,   680,   680,   680,   -92,
     445,   478,   290,    73,   680,   -92,   -92,   577,    76,    75,
     777,    68,    77,   -18,   777,    82,   777,    45,   -92,    79,
     680,   680,   288,   -92,   -19,   -92,   764,   394,    15,    15,
     394,    15,    15,    -7,    -7,   -92,   -92,   -92,   -19,   764,
      80,   288,   680,   -92,   -92,   128,   -92,   680,   -92,   660,
      88,   -92,    89,   119,    92,    93,   -92,   120,   100,   511,
     711,    98,   154,   -92,   -92,   290,   -92,   326,    68,   103,
     680,   -92,   107,   -92,   -92,   123,   -92,   104,   -92,   -92,
     680,   288,   288,    -2,   -92,   680,   -92,   -92,   112,   -92,
     -18,   680,   -92,   744,   -92,   -92,   680,   116,   -92,   183,
     343,   121,    92,    79,   680,   -92,   122,   -92,   680,   -92,
     253,   680,   127,   680,   -92,   -92,   -92,   777,   -92,   124,
     126,   125,   131,   -92,   777,   -92,   133,   -92,   -92,     0,
     -92,   121,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   184,   -92,   111,   -27,   118,    60,   108,   -92,
      23,   -92,   194,   -92,   -33,    -9,   -92,   -47,   -92,   -92,
     -92,    11,   -91,   -22,   -10,   -92,    -8,   -92,    21,    70,
     -30,   -92,   -25,   -92,   -92,    22,   -92,   -92,   -92,   -92,
     -20,   -92,   -92,    43,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -125
static const yytype_int16 yytable[] =
{
      42,   114,    43,    60,   226,    25,  -124,    49,   227,    75,
    -124,    52,   149,   114,    23,    24,    93,    94,    42,    10,
      43,   182,    54,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     4,   114,    42,    42,    43,    43,
     107,     6,   108,   124,   125,   126,   183,    56,   109,   110,
     111,    57,   112,    58,    59,     1,   130,   131,   132,     2,
       3,    61,    62,   122,   123,   124,   125,   126,   137,     4,
      22,     5,   228,   140,  -124,   144,     6,     7,     8,    78,
      79,    80,     9,    22,    91,    95,    22,    96,   103,    53,
      10,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   143,    97,   219,
       1,    14,   175,    92,     2,   101,   104,     9,    15,   105,
     106,    98,   134,   135,    14,    10,     5,   192,   189,   190,
     233,    15,   113,     8,   136,   236,   148,   151,   179,   150,
     178,   174,    42,   177,    43,   181,   194,   250,   114,   187,
     195,   115,   256,   193,   185,   197,   199,   140,   201,   205,
     200,    42,   202,    43,    98,   206,   211,   212,   217,   222,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   221,   127,   128,   231,   237,   224,   225,   223,   238,
     259,   248,   243,   230,   255,   258,   260,    50,   257,   245,
     196,    42,    42,    43,    43,   261,   246,   186,   204,   147,
      51,   232,   247,   220,   262,   253,   214,   249,     0,   254,
     216,     1,   198,    26,     0,     2,     3,    27,     0,    28,
      42,     0,    43,    29,     0,     0,    30,     5,     0,     0,
       0,     0,     0,     0,     8,    31,     0,    32,     0,     0,
      33,    34,    35,    36,    37,     0,     0,    38,   251,     0,
       0,     0,    27,     0,    28,     0,     0,     0,    29,     0,
       0,    30,     0,     0,   252,     0,     0,     0,     0,     0,
      31,     0,    32,    39,     0,    33,    34,    35,    36,    37,
       0,    10,    38,    26,   113,     0,     0,    27,     0,    28,
       0,     0,     0,    29,     0,     0,    30,     0,     0,     0,
     114,     0,     0,   115,     0,    31,     0,    32,    39,     0,
      33,    34,    35,    36,    37,     0,    10,    38,     0,     0,
     113,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,   127,   128,   114,   113,     0,   115,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
     172,    10,     0,   114,     0,     0,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
     127,   128,     0,   113,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   215,   127,   128,   114,
       0,     0,   115,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,   241,   114,     0,   113,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   114,   127,   128,   115,     0,   117,   118,     0,
     120,   121,   122,   123,   124,   125,   126,   152,     0,   113,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   114,   127,   128,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,   113,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   114,   127,
     128,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,   113,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   114,   127,   128,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,   113,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   114,   127,   128,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,   113,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   114,   127,   128,
     115,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,   128,    63,     0,   138,     0,     0,     0,     0,
       0,    64,   176,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,    63,     0,    66,    67,    38,    68,
      69,     0,    64,     0,     0,     0,     0,    70,    71,     0,
       0,    65,    72,     0,    63,     0,   138,    66,    67,    38,
      68,    69,    64,     0,     0,     0,    74,   139,    70,    71,
       0,    65,     0,    72,    63,     0,     0,    66,    67,    38,
      68,    69,    64,     0,     0,    73,     0,    74,    70,    71,
       0,    65,     0,    72,     0,   113,     0,    66,    67,    38,
      68,    69,     0,   208,     0,     0,     0,    74,    70,    71,
       0,   114,     0,    72,   115,     0,     0,     0,     0,     0,
       0,   209,     0,     0,     0,     0,     0,    74,   113,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   114,   127,   128,   115,   113,     0,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,   114,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   114,   127,   128,
     115,     0,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,   128
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-92))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      10,    20,    10,    28,     6,    39,     6,     0,    10,    31,
      10,    39,   103,    20,     3,     4,    46,    47,    28,    73,
      28,    39,    39,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    17,    20,    46,    47,    46,    47,
      62,    24,    64,    50,    51,    52,    64,    39,    70,    71,
      72,    67,    74,    65,    65,     3,    78,    79,    80,     7,
       8,    67,    67,    48,    49,    50,    51,    52,    90,    17,
       0,    19,    74,    95,    74,    97,    24,    25,    26,    67,
      67,    67,    65,    13,    65,    67,    16,    67,    58,    19,
      73,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    96,    58,   200,
       3,     0,   134,    74,     7,    70,    68,    65,     0,    32,
      39,    71,    71,    65,    13,    73,    19,   152,   150,   151,
     221,    13,     4,    26,    65,   226,    65,    70,    70,    67,
      65,    68,   152,    67,   152,    68,   171,   238,    20,    70,
     172,    23,   243,    73,    72,   177,    68,   179,    39,    39,
      71,   171,    70,   171,    71,    65,    68,    13,    65,    65,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    58,    54,    55,    72,    69,   211,   212,   210,     6,
      65,    69,    71,   215,    67,    69,    65,    13,    74,   232,
      72,   211,   212,   211,   212,    72,   233,   147,   185,   101,
      16,   220,   234,   202,   261,   240,   195,   237,    -1,   241,
     198,     3,   179,     5,    -1,     7,     8,     9,    -1,    11,
     240,    -1,   240,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    39,     5,    -1,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,    -1,
      -1,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    29,    65,    -1,    32,    33,    34,    35,    36,
      -1,    73,    39,     5,     4,    -1,    -1,     9,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    18,    -1,    -1,    -1,
      20,    -1,    -1,    23,    -1,    27,    -1,    29,    65,    -1,
      32,    33,    34,    35,    36,    -1,    73,    39,    -1,    -1,
       4,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    20,     4,    -1,    23,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    73,    -1,    20,    -1,    -1,    23,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,     4,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    70,    54,    55,    20,
      -1,    -1,    23,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    70,    20,    -1,     4,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    20,    54,    55,    23,    -1,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    68,    -1,     4,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    20,    54,    55,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    22,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    14,    -1,    37,    38,    39,    40,
      41,    -1,    22,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    31,    53,    -1,    14,    -1,    16,    37,    38,    39,
      40,    41,    22,    -1,    -1,    -1,    67,    68,    48,    49,
      -1,    31,    -1,    53,    14,    -1,    -1,    37,    38,    39,
      40,    41,    22,    -1,    -1,    65,    -1,    67,    48,    49,
      -1,    31,    -1,    53,    -1,     4,    -1,    37,    38,    39,
      40,    41,    -1,    12,    -1,    -1,    -1,    67,    48,    49,
      -1,    20,    -1,    53,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    67,     4,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    20,    54,    55,    23,     4,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    20,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    20,    54,    55,
      23,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     8,    17,    19,    24,    25,    26,    65,
      73,    77,    78,    79,    80,    82,    87,    88,    94,    95,
      96,    97,   105,    97,    97,    39,     5,     9,    11,    15,
      18,    27,    29,    32,    33,    34,    35,    36,    39,    65,
      80,    82,   100,   102,   105,   106,   107,   108,   118,     0,
      78,    88,    39,   105,    39,    84,    39,    67,    65,    65,
     108,    67,    67,    14,    22,    31,    37,    38,    40,    41,
      48,    49,    53,    65,    67,    99,   100,   102,    67,    67,
      67,   101,    56,    57,    58,    59,    60,    61,    62,    63,
     112,    65,    74,   106,   106,    67,    67,    58,    71,    85,
      86,    70,    83,    58,    68,    32,    39,    99,    99,    99,
      99,    99,    99,     4,    20,    23,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    54,    55,    65,
      99,    99,    99,   103,    71,    65,    65,    99,    16,    68,
      99,   119,    89,    97,    99,    98,    99,    84,    65,    98,
      67,    70,    68,    68,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      68,    68,    70,   104,    68,    99,    65,    67,    65,    70,
     111,    68,    39,    64,    91,    72,    83,    70,    81,    99,
      99,   113,   108,    73,   108,    99,    72,    99,   119,    68,
      71,    39,    70,    90,    86,    39,    65,    68,    12,    30,
     114,    68,    13,   109,   104,    70,   111,    65,    92,    98,
      97,    58,    65,    99,   108,   108,     6,    10,    74,   110,
      99,    72,    91,    98,    28,   115,    98,    69,     6,   116,
     117,    70,   120,    71,    93,    90,    81,    99,    69,   116,
      98,     5,    21,   108,    99,    67,    98,    74,    69,    65,
      65,    72,    93
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
#line 117 "parser.y"
    { }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 119 "parser.y"
    { }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    { }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 122 "parser.y"
    { }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 123 "parser.y"
    { }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 124 "parser.y"
    { }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    { }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 127 "parser.y"
    { }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 130 "parser.y"
    { }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 132 "parser.y"
    { }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    { }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 135 "parser.y"
    { }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    { }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 138 "parser.y"
    { }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    { }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    { }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    { }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    { }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 144 "parser.y"
    { }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    { }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    { }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 147 "parser.y"
    { }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    { }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    { }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 150 "parser.y"
    { }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 152 "parser.y"
    { }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    { }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    { }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    { }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    { }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 157 "parser.y"
    { }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 158 "parser.y"
    { }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 161 "parser.y"
    { }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 162 "parser.y"
    { }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 164 "parser.y"
    { }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    { }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    { }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    { }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    { }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 175 "parser.y"
    { }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    { }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    { }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    { }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 179 "parser.y"
    { }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    { }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    { }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 182 "parser.y"
    { }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    { }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 185 "parser.y"
    { }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    { }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 188 "parser.y"
    { }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 189 "parser.y"
    { }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    { }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 191 "parser.y"
    { }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 192 "parser.y"
    { }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 193 "parser.y"
    { }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    { }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 195 "parser.y"
    { }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    { }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 199 "parser.y"
    { }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    { }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 201 "parser.y"
    { }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    { }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    { }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    { }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    { }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 209 "parser.y"
    { }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 211 "parser.y"
    { }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 212 "parser.y"
    { }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 213 "parser.y"
    { }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 214 "parser.y"
    { }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 215 "parser.y"
    { }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 217 "parser.y"
    { }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 218 "parser.y"
    { }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    { }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    { }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    { }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    { }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 225 "parser.y"
    { }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    { }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    { }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 229 "parser.y"
    { }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    { }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    { }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 232 "parser.y"
    { }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 233 "parser.y"
    { }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 234 "parser.y"
    { }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    { }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 236 "parser.y"
    { }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 237 "parser.y"
    { }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    { }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 240 "parser.y"
    { }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 241 "parser.y"
    { }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    { }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    { }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 245 "parser.y"
    { }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    { }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 247 "parser.y"
    { }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 248 "parser.y"
    { }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 251 "parser.y"
    { }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 252 "parser.y"
    { }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 254 "parser.y"
    { }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 255 "parser.y"
    { }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 256 "parser.y"
    { }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 257 "parser.y"
    { }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 258 "parser.y"
    { }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 259 "parser.y"
    { }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 261 "parser.y"
    { }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 262 "parser.y"
    { }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    { }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 264 "parser.y"
    { }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
    { }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 267 "parser.y"
    { }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 268 "parser.y"
    { }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    { }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 271 "parser.y"
    { }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 274 "parser.y"
    { }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 275 "parser.y"
    { }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 276 "parser.y"
    { }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 277 "parser.y"
    { }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 279 "parser.y"
    { }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 280 "parser.y"
    { }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 281 "parser.y"
    { }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 282 "parser.y"
    { }
    break;



/* Line 1806 of yacc.c  */
#line 2719 "parser.c"
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
#line 285 "parser.y"


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


