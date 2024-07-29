
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include "symbol_table.h"
#include "operators.h"
#include "type_mismatch_handler.h"
#include "quadruples.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

void yyerror(char * s);
int yylex();
extern int yylineno;
extern FILE *yyin;


/* Line 189 of yacc.c  */
#line 91 "parser.tab.c"

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

/* Line 209 of yacc.c  */
#line 28 "parser.y"

#include<stdbool.h>



/* Line 209 of yacc.c  */
#line 121 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_TYPE = 258,
     FLOAT_TYPE = 259,
     STRING_TYPE = 260,
     BOOL_TYPE = 261,
     CHARACTER_TYPE = 262,
     CONST = 263,
     VOID = 264,
     IF = 265,
     ELSE = 266,
     DO = 267,
     WHILE = 268,
     FOR = 269,
     SWITCH = 270,
     CASE = 271,
     DEFAULT = 272,
     BREAK = 273,
     RETURN = 274,
     MOD = 275,
     MUL = 276,
     DIV = 277,
     ADD = 278,
     SUB = 279,
     AND = 280,
     OR = 281,
     ASSIGNMENT = 282,
     NOT = 283,
     EQUAL_TO = 284,
     NOT_EQUAL = 285,
     LESS = 286,
     GREATER = 287,
     INT = 288,
     STRING = 289,
     FLOAT = 290,
     BOOL = 291,
     CHARACTER = 292,
     IDENTIFIER = 293,
     SEMICOLON = 294,
     COMMA = 295,
     COLON = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 18 "parser.y"
 
 int number; 
 char* string_value; 
 char char_value;
 float float_value;
 bool bool_value;

struct nodeType* ptr;



/* Line 214 of yacc.c  */
#line 191 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 203 "parser.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     9,    11,    13,    16,    19,
      20,    23,    24,    27,    29,    30,    33,    34,    37,    39,
      42,    44,    46,    48,    50,    52,    54,    55,    62,    63,
      68,    69,    76,    78,    81,    82,    88,    92,    96,    97,
      98,   106,   108,   109,   110,   117,   121,   124,   128,   130,
     131,   135,   138,   141,   144,   149,   150,   156,   164,   165,
     166,   167,   168,   181,   186,   191,   192,   197,   198,   199,
     206,   207,   212,   214,   215,   217,   219,   221,   223,   225,
     227,   229,   232,   236,   240,   244,   248,   252,   254,   256,
     260,   264,   268,   273,   278,   282,   286,   290,   294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    47,    48,    -1,    -1,    54,    -1,    66,
      -1,    84,    -1,    58,    39,    -1,    92,    39,    -1,    -1,
      49,    75,    -1,    -1,    50,    76,    -1,    79,    -1,    -1,
      51,    78,    -1,    -1,    52,    61,    -1,    85,    -1,    18,
      39,    -1,     3,    -1,     4,    -1,     6,    -1,     7,    -1,
       5,    -1,     9,    -1,    -1,    53,    38,    55,    27,    92,
      39,    -1,    -1,    53,    38,    56,    39,    -1,    -1,    53,
       8,    57,    27,    92,    39,    -1,    19,    -1,    19,    92,
      -1,    -1,    15,    38,    41,    60,    42,    -1,    59,    63,
      43,    -1,    17,    41,    85,    -1,    -1,    -1,    16,    92,
      64,    41,    85,    65,    63,    -1,    62,    -1,    -1,    -1,
      53,    38,    67,    69,    68,    85,    -1,    44,    70,    45,
      -1,    44,    45,    -1,    71,    40,    70,    -1,    71,    -1,
      -1,    53,    38,    72,    -1,    10,    92,    -1,    41,    85,
      -1,    73,    74,    -1,    73,    74,    11,    85,    -1,    -1,
      13,    92,    41,    77,    85,    -1,    12,    85,    13,    44,
      92,    45,    39,    -1,    -1,    -1,    -1,    -1,    14,    44,
      80,    48,    81,    92,    39,    82,    84,    45,    83,    85,
      -1,    38,    27,    92,    39,    -1,     8,    27,    92,    39,
      -1,    -1,    42,    86,    47,    43,    -1,    -1,    -1,    38,
      88,    44,    90,    89,    45,    -1,    -1,    92,    91,    40,
      90,    -1,    92,    -1,    -1,    38,    -1,    33,    -1,    35,
      -1,    36,    -1,    37,    -1,    34,    -1,     8,    -1,    24,
      92,    -1,    92,    23,    92,    -1,    92,    20,    92,    -1,
      92,    24,    92,    -1,    92,    21,    92,    -1,    92,    22,
      92,    -1,    93,    -1,    87,    -1,    44,    92,    45,    -1,
      92,    32,    92,    -1,    92,    31,    92,    -1,    92,    31,
      27,    92,    -1,    92,    32,    27,    92,    -1,    92,    29,
      92,    -1,    92,    30,    92,    -1,    92,    25,    92,    -1,
      92,    26,    92,    -1,    28,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    75,    76,    77,    78,    79,    80,
      80,    81,    81,    82,    83,    83,    84,    84,    85,    86,
      90,    91,    92,    93,    94,    95,    99,    99,   100,   100,
     101,   101,   105,   106,   110,   110,   112,   116,   120,   123,
     120,   125,   130,   130,   130,   133,   134,   136,   137,   141,
     141,   145,   149,   156,   157,   161,   161,   169,   179,   179,
     179,   179,   179,   187,   188,   192,   192,   197,   199,   197,
     203,   203,   204,   205,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     228,   229,   230,   231,   232,   233,   234,   235,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TYPE", "FLOAT_TYPE", "STRING_TYPE",
  "BOOL_TYPE", "CHARACTER_TYPE", "CONST", "VOID", "IF", "ELSE", "DO",
  "WHILE", "FOR", "SWITCH", "CASE", "DEFAULT", "BREAK", "RETURN", "MOD",
  "MUL", "DIV", "ADD", "SUB", "AND", "OR", "ASSIGNMENT", "NOT", "EQUAL_TO",
  "NOT_EQUAL", "LESS", "GREATER", "INT", "STRING", "FLOAT", "BOOL",
  "CHARACTER", "IDENTIFIER", "SEMICOLON", "COMMA", "COLON", "'{'", "'}'",
  "'('", "')'", "$accept", "program", "statement", "$@1", "$@2", "$@3",
  "$@4", "data_type", "declaration", "$@5", "$@6", "$@7", "return_",
  "switch_header", "$@8", "switch_", "default_case", "CASES", "$@9",
  "$@10", "function_declaration", "$@11", "$@12", "function_arg_part",
  "arguments", "arguments_declaration", "$@13", "if_header", "if_body",
  "if_", "while_", "$@14", "do_while", "for_", "$@15", "$@16", "$@17",
  "$@18", "assignment", "block", "$@19", "function_call", "$@20", "$@21",
  "function_call_arguments", "$@22", "expression", "logics", 0
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
     295,   296,   123,   125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    49,
      48,    50,    48,    48,    51,    48,    52,    48,    48,    48,
      53,    53,    53,    53,    53,    53,    55,    54,    56,    54,
      57,    54,    58,    58,    60,    59,    61,    62,    64,    65,
      63,    63,    67,    68,    66,    69,    69,    70,    70,    72,
      71,    73,    74,    75,    75,    77,    76,    78,    80,    81,
      82,    83,    79,    84,    84,    86,    85,    88,    89,    87,
      91,    90,    90,    90,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     2,     2,     0,
       2,     0,     2,     1,     0,     2,     0,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     0,     6,     0,     4,
       0,     6,     1,     2,     0,     5,     3,     3,     0,     0,
       7,     1,     0,     0,     6,     3,     2,     3,     1,     0,
       3,     2,     2,     2,     4,     0,     5,     7,     0,     0,
       0,     0,    12,     4,     4,     0,     4,     0,     0,     6,
       0,     4,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     4,     4,     3,     3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     9,     1,    20,    21,    24,    22,    23,    80,    25,
       0,     0,    32,     0,     0,    75,    79,    76,    77,    78,
      74,    65,     0,     2,     0,     0,     0,     0,     0,     4,
       0,     5,    13,     6,    18,    88,     0,    87,     0,    58,
      19,    80,    74,    33,    81,    98,     0,     0,     3,     0,
       0,     0,    10,     0,    12,     0,    15,     0,     0,    17,
      30,    26,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,     0,    73,     9,
      89,    51,     0,    53,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,    83,    85,    86,    82,    84,
      96,    97,    94,    95,     0,    91,     0,    90,    64,    59,
      63,    68,    70,    66,    52,     0,    55,     0,    34,    38,
       0,    36,     0,     0,    29,     0,    43,    92,    93,     0,
       0,     0,    54,     0,     0,     0,     0,    37,     0,     0,
      46,     0,     0,    48,     0,     0,    69,    73,    56,     0,
      35,     0,    31,    27,    49,    45,     0,    44,    60,    71,
       0,    39,    50,    47,     0,    57,     0,     0,     0,     0,
      40,    61,     0,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    23,    24,    25,    26,    27,    28,    29,    92,
      93,    91,    30,    58,   135,    59,    89,    90,   136,   166,
      31,    94,   144,   126,   142,   143,   162,    51,    83,    52,
      54,   133,    56,    32,    76,   129,   164,   172,    33,    34,
      48,    35,    47,   130,   111,   131,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
    -114,   124,  -114,  -114,  -114,  -114,  -114,  -114,   -14,  -114,
     -27,     1,   245,   245,   245,  -114,  -114,  -114,  -114,  -114,
       5,  -114,   245,  -114,    15,    24,    30,    33,    -5,  -114,
      11,  -114,  -114,  -114,  -114,  -114,   321,  -114,   245,  -114,
    -114,  -114,    26,   441,    14,    65,   245,    27,  -114,   270,
     245,    43,  -114,   245,  -114,    32,  -114,    52,    -1,  -114,
    -114,    39,  -114,   245,   245,   245,   245,   245,   245,   245,
     245,   245,    71,   227,  -114,   341,   208,   361,   245,   166,
    -114,   441,    32,    57,    -2,    78,    60,   245,    61,  -114,
      69,    76,    86,    75,    72,    41,    45,    49,    41,    14,
     454,   454,    65,    65,   245,    87,   245,    49,  -114,  -114,
    -114,  -114,   287,  -114,  -114,    32,  -114,    79,  -114,   441,
      32,  -114,   245,   245,  -114,     2,  -114,    49,    49,   245,
      74,    80,  -114,    32,   245,    83,    85,  -114,   381,   401,
    -114,    96,    95,   101,    32,   421,  -114,   245,  -114,   304,
    -114,    32,  -114,  -114,  -114,  -114,   484,  -114,  -114,  -114,
     105,  -114,  -114,  -114,     6,  -114,    -1,   -14,   118,   102,
    -114,  -114,    32,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,    98,    73,  -114,  -114,  -114,  -114,  -113,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,   -16,  -114,  -114,
    -114,  -114,  -114,  -114,    -3,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   -13,   -51,
    -114,  -114,  -114,  -114,     7,  -114,   -12,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      43,    44,    45,    60,    85,     3,     4,     5,     6,     7,
      49,     9,   141,    38,   167,    87,    88,    39,    63,    64,
      65,    66,    67,    68,    69,    50,    75,    70,    71,    72,
      73,   114,    46,    61,    77,    64,    65,    53,    81,   116,
      40,    84,    55,   141,   168,    72,    73,   140,    57,   -67,
      62,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     105,   107,    64,    65,   132,    67,   112,    65,   115,   137,
     -67,    78,    72,    73,    21,   119,    72,    73,   -28,    41,
      72,    73,   148,   -42,    82,    63,    64,    65,    66,    67,
      86,   117,   127,   157,   128,    13,    72,    73,   104,    14,
     161,   118,   120,   122,    15,    16,    17,    18,    19,    42,
     138,   139,   121,   123,   124,    22,   125,   145,    72,   146,
     147,   173,   149,   134,     2,   150,   151,     3,     4,     5,
       6,     7,     8,     9,   154,   112,   -14,   -11,    10,   -16,
     155,   156,    11,    12,   165,    46,    79,   171,    13,   109,
     170,   169,    14,   163,   159,     0,     0,    15,    16,    17,
      18,    19,    20,     0,     0,     0,    21,     0,    22,     3,
       4,     5,     6,     7,     8,     9,     0,     0,   -14,   -11,
      10,   -16,     0,     0,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,     0,     0,     0,    21,   113,
      22,     3,     4,     5,     6,     7,     8,     9,     0,     0,
     -14,   -11,    10,   -16,     0,     0,    11,    12,     0,     0,
       0,     0,    13,     0,     0,    41,    14,     0,     0,     0,
       0,    15,    16,    17,    18,    19,    20,     0,     0,     0,
      21,    13,    22,    41,   106,    14,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    42,     0,     0,     0,    13,
       0,    22,     0,    14,     0,     0,     0,     0,    15,    16,
      17,    18,    19,    42,     0,     0,     0,     0,     0,    22,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    70,
      71,    72,    73,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,     0,    80,    70,    71,    72,    73,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,   -72,    70,    71,    72,    73,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,   160,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
      74,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
     108,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
     110,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
     152,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
     153,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
     158,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      70,    71,    72,    73,    63,    64,    65,    66,    67,     0,
       0,     0,     0,    70,    71,    72,    73,     3,     4,     5,
       6,     7,     0,     9
};

static const yytype_int16 yycheck[] =
{
      12,    13,    14,     8,    55,     3,     4,     5,     6,     7,
      22,     9,   125,    27,     8,    16,    17,    44,    20,    21,
      22,    23,    24,    25,    26,    10,    38,    29,    30,    31,
      32,    82,    27,    38,    46,    21,    22,    13,    50,    41,
      39,    53,    12,   156,    38,    31,    32,    45,    15,    44,
      39,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    21,    22,   115,    24,    78,    22,    11,   120,
      44,    44,    31,    32,    42,    87,    31,    32,    39,     8,
      31,    32,   133,    44,    41,    20,    21,    22,    23,    24,
      38,    13,   104,   144,   106,    24,    31,    32,    27,    28,
     151,    41,    41,    27,    33,    34,    35,    36,    37,    38,
     122,   123,    43,    27,    39,    44,    44,   129,    31,    45,
      40,   172,   134,    44,     0,    42,    41,     3,     4,     5,
       6,     7,     8,     9,    38,   147,    12,    13,    14,    15,
      45,    40,    18,    19,    39,    27,    48,    45,    24,    76,
     166,   164,    28,   156,   147,    -1,    -1,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    -1,    44,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      44,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    -1,     8,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    24,    44,     8,    27,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    24,
      -1,    44,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    45,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    45,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    45,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,     3,     4,     5,
       6,     7,    -1,     9
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     3,     4,     5,     6,     7,     8,     9,
      14,    18,    19,    24,    28,    33,    34,    35,    36,    37,
      38,    42,    44,    48,    49,    50,    51,    52,    53,    54,
      58,    66,    79,    84,    85,    87,    92,    93,    27,    44,
      39,     8,    38,    92,    92,    92,    27,    88,    86,    92,
      10,    73,    75,    13,    76,    12,    78,    15,    59,    61,
       8,    38,    39,    20,    21,    22,    23,    24,    25,    26,
      29,    30,    31,    32,    39,    92,    80,    92,    44,    47,
      45,    92,    41,    74,    92,    85,    38,    16,    17,    62,
      63,    57,    55,    56,    67,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    27,    92,    27,    92,    39,    48,
      39,    90,    92,    43,    85,    11,    41,    13,    41,    92,
      41,    43,    27,    27,    39,    44,    69,    92,    92,    81,
      89,    91,    85,    77,    44,    60,    64,    85,    92,    92,
      45,    53,    70,    71,    68,    92,    45,    40,    85,    92,
      42,    41,    39,    39,    38,    45,    40,    85,    39,    90,
      45,    85,    72,    70,    82,    39,    65,     8,    38,    84,
      63,    45,    83,    85
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 9:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { inc_label('E'); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"E_IF%d:",sharedData.end_label[sharedData.current_end_label]); dec_label('E');;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {inc_label('L'); write_errors_quadruples(sharedData.quadruples_file, "LOOP%d: ", sharedData.loop_number);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { dec_label('L'); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {dec_label('L');;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {inc_label('L'); write_errors_quadruples(sharedData.quadruples_file, "LOOP%d: ", sharedData.loop_number);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {dec_label('L'); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {inc_label('E'); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    { write_errors_quadruples(sharedData.quadruples_file,"EL%d:",sharedData.end_label[sharedData.current_end_label]); dec_label('E');;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { write_errors_quadruples(sharedData.quadruples_file,"JMP EL%d", sharedData.end_label[sharedData.current_end_label]);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { (yyval.string_value) = "int";   ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { (yyval.string_value) = "float"; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    { (yyval.string_value) = "bool";  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {(yyval.string_value) ="char";;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { (yyval.string_value) = "string";;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {(yyval.string_value) ="void";;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {insert((yyvsp[(1) - (2)].string_value), (yyvsp[(2) - (2)].string_value),"var",0,yylineno);  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { int i =get_index((yyvsp[(2) - (6)].string_value),true,yylineno);check_type_assignment((yyvsp[(1) - (6)].string_value),(yyvsp[(5) - (6)].ptr)->type,i,yylineno,"assignment"); write_errors_quadruples(sharedData.quadruples_file,"POP %s", (yyvsp[(2) - (6)].string_value));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {insert((yyvsp[(1) - (2)].string_value), (yyvsp[(2) - (2)].string_value),"var",0,yylineno);  ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {insert((yyvsp[(1) - (2)].string_value), (yyvsp[(2) - (2)].string_value),"const",0,yylineno);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { int i =get_index((yyvsp[(2) - (6)].string_value),true,yylineno);check_type_assignment((yyvsp[(1) - (6)].string_value),(yyvsp[(5) - (6)].ptr)->type,i,yylineno,"assignment");write_errors_quadruples(sharedData.quadruples_file,"POP %s",(yyvsp[(2) - (6)].string_value));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    { write_errors_quadruples(sharedData.quadruples_file,"RET");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {check_type_assignment(sharedData.symbolTable[sharedData.function_index].dataType,(yyvsp[(2) - (2)].ptr)->type,sharedData.function_index,yylineno,"func_return"); sharedData.is_return = 1; write_errors_quadruples(sharedData.quadruples_file,"RET");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    { sharedData.switch_identifier = (yyvsp[(2) - (3)].string_value);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"PUSH %s", sharedData.switch_identifier);
                write_errors_quadruples(sharedData.quadruples_file,"EQ "); 
                inc_label('N');
                write_errors_quadruples(sharedData.quadruples_file,"JF L%d",sharedData.label_number);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {
                    write_errors_quadruples(sharedData.quadruples_file,"L%d:", sharedData.label[sharedData.current_label]); dec_label('N');;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"FUNC %s",(yyvsp[(2) - (2)].string_value));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {insert((yyvsp[(1) - (4)].string_value), (yyvsp[(2) - (4)].string_value),"func",0,yylineno);sharedData.function_index = get_index((yyvsp[(2) - (4)].string_value),false,yylineno);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { write_errors_quadruples(sharedData.quadruples_file,"E_FUNC %s",(yyvsp[(2) - (6)].string_value));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {insert((yyvsp[(1) - (2)].string_value), (yyvsp[(2) - (2)].string_value),"var",1,yylineno); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { write_errors_quadruples(sharedData.quadruples_file,"POP %s",(yyvsp[(2) - (3)].string_value));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {inc_label('N');write_errors_quadruples(sharedData.quadruples_file,"JF ELSE%d",sharedData.label_number);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"JMP E_IF%d",sharedData.end_label[sharedData.current_end_label]);
                write_errors_quadruples(sharedData.quadruples_file,"ELSE%d:",sharedData.label[sharedData.current_label]);
                dec_label('N');      
      ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { inc_label('N');write_errors_quadruples(sharedData.quadruples_file,"JF E_LOOP%d",sharedData.label_number);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {
                write_errors_quadruples(sharedData.quadruples_file,"JMP LOOP%d", sharedData.loop_labels[sharedData.current_loop]);
                write_errors_quadruples(sharedData.quadruples_file,"E_LOOP%d:",sharedData.label[sharedData.current_label]);
                dec_label('N');
                ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {
                     inc_label('N');
                     write_errors_quadruples(sharedData.quadruples_file,"JF E_LOOP%d",sharedData.label_number);            
                     write_errors_quadruples(sharedData.quadruples_file,"JMP LOOP%d", sharedData.loop_labels[sharedData.current_loop]);
                     write_errors_quadruples(sharedData.quadruples_file,"E_LOOP%d:",sharedData.label[sharedData.current_label]);
                     dec_label('N');
                     ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {sharedData.loop=1;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {inc_label('L');write_errors_quadruples(sharedData.quadruples_file,"LOOP%d:",sharedData.loop_number);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {inc_label('N');write_errors_quadruples(sharedData.quadruples_file,"JF E_LOOP%d",sharedData.label_number);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {sharedData.loop=0;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
                write_errors_quadruples(sharedData.quadruples_file,"JMP LOOP%d",sharedData.loop_labels[sharedData.current_loop]);
                write_errors_quadruples(sharedData.quadruples_file,"E_LOOP%d:",sharedData.label[sharedData.current_label]);
                dec_label('N');
                ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {int i =get_index((yyvsp[(1) - (4)].string_value),true,yylineno);check_type_assignment(sharedData.symbolTable[i].dataType,(yyvsp[(3) - (4)].ptr)->type,i,yylineno,"assignment");write_errors_quadruples(sharedData.quadruples_file,"POP %s",(yyvsp[(1) - (4)].string_value));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { int i =get_index((yyvsp[(1) - (4)].string_value),true,yylineno);check_type_assignment(sharedData.symbolTable[i].dataType,(yyvsp[(3) - (4)].ptr)->type,i,yylineno,"assignment"); write_errors_quadruples(sharedData.quadruples_file,"POP %s",(yyvsp[(1) - (4)].string_value));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {scope_start();;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {check_return(yylineno);sharedData.function_index = -1; sharedData.is_return = 0; handle_end_of_scope(); sharedData.current_scope_index--;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {sharedData.called_function_index = get_index((yyvsp[(1) - (1)].string_value),false,yylineno); 
                 ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {  arguments_check(yylineno);  sharedData.arg_count=0; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { sharedData.called_function_index=-1;(yyval.ptr)=get_type((yyvsp[(1) - (6)].string_value)); write_errors_quadruples(sharedData.quadruples_file,"CALL %s",(yyvsp[(1) - (6)].string_value));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { check_arguments_type((yyvsp[(1) - (1)].ptr)->type,yylineno); sharedData.arg_count++; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {check_arguments_type((yyvsp[(1) - (1)].ptr)->type,yylineno);sharedData.arg_count++ ;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {get_index((yyvsp[(1) - (1)].string_value),false,yylineno); (yyval.ptr) = get_type((yyvsp[(1) - (1)].string_value));  write_errors_quadruples(sharedData.quadruples_file,"PUSH %s",(yyvsp[(1) - (1)].string_value));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { (yyval.ptr) = assign_type("int"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %d",(yyvsp[(1) - (1)].number));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {(yyval.ptr)=assign_type("float"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %f",(yyvsp[(1) - (1)].float_value));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {(yyval.ptr)=assign_type("bool");  write_errors_quadruples(sharedData.quadruples_file,"PUSH %d",(yyvsp[(1) - (1)].bool_value)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {(yyval.ptr)=assign_type("char"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %c",(yyvsp[(1) - (1)].char_value));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.ptr)=assign_type("string"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %s",(yyvsp[(1) - (1)].string_value)); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {get_index((yyvsp[(1) - (1)].string_value),false,yylineno);(yyval.ptr) = get_type((yyvsp[(1) - (1)].string_value));  write_errors_quadruples(sharedData.quadruples_file,"PUSH %s",(yyvsp[(1) - (1)].string_value));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {(yyval.ptr) = check_types_unary_op((yyvsp[(2) - (2)].ptr),'-',yylineno); write_errors_quadruples(sharedData.quadruples_file,"NEG "); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"ADD"); (yyval.ptr) = check_types_math_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),'+',yylineno); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"MOD"); (yyval.ptr) = check_types_math_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),'%',yylineno);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"SUB"); (yyval.ptr) = check_types_math_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),'-',yylineno); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"MUL"); (yyval.ptr) = check_types_math_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),'*',yylineno);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"DIV"); (yyval.ptr) = check_types_math_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),'/',yylineno);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {(yyval.ptr)=(yyvsp[(2) - (3)].ptr);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"GT"); (yyval.ptr) = check_types_comp((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),yylineno);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"LT"); (yyval.ptr) = check_types_comp((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),yylineno);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"LEQ"); (yyval.ptr) = check_types_comp((yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),yylineno);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"GEQ"); (yyval.ptr) = check_types_comp((yyvsp[(1) - (4)].ptr),(yyvsp[(4) - (4)].ptr),yylineno);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"EQ"); (yyval.ptr) = check_types_comp((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),yylineno);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"NEQ"); (yyval.ptr) = check_types_comp((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),yylineno);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"AND"); (yyval.ptr) = check_types_logic_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),yylineno); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"OR"); (yyval.ptr) = check_types_logic_op((yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr),yylineno); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {write_errors_quadruples(sharedData.quadruples_file,"NOT");(yyval.ptr) = check_types_unary_op((yyvsp[(2) - (2)].ptr),'!',yylineno);;}
    break;



/* Line 1455 of yacc.c  */
#line 2155 "parser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 238 "parser.y"

void yyerror(char * s){
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

int yywrap()
{
    return 1;
}

int main(int argc, char *argv[]){

     if (remove("errors.txt") != 0 && errno != ENOENT) {
        perror("Error deleting errors.txt");
    }

    if (remove("quadruples.txt") != 0 && errno != ENOENT) {
        perror("Error deleting quadruples.txt");
    }

    if (remove("symbol_table.txt") != 0 && errno != ENOENT) {
        perror("Error deleting symbol_table.txt");
    }
    open_files("errors.txt","quadruples.txt");
    yyin = fopen(argv[1], "r");
    yyparse();
    print_symbol_table();
    print_unused_identifiers();
    close_files();
    printf("DONE\n");
    return 0;
}

