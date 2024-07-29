
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 28 "parser.y"

#include<stdbool.h>



/* Line 1676 of yacc.c  */
#line 46 "parser.tab.h"

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

/* Line 1676 of yacc.c  */
#line 18 "parser.y"
 
 int number; 
 char* string_value; 
 char char_value;
 float float_value;
 bool bool_value;

struct nodeType* ptr;



/* Line 1676 of yacc.c  */
#line 116 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


