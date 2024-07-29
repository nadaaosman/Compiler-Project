%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}
%option yylineno
%%
"int"               {   return INT_TYPE; }
"float"             {    return FLOAT_TYPE; }
"string"            {    return STRING_TYPE; }
"bool"              {    return BOOL_TYPE;  }
"char"               {  return CHARACTER_TYPE;}
"void"                {    return VOID; }
"return"             {    return RETURN; }

"if"                    {     return IF; }
"else"                  {     return ELSE; }
"while"                 {     return WHILE; }
"do"                 {     return DO; }
"for"                   {     return FOR; }
"switch"                {     return SWITCH; }
"case"                  {     return CASE; }
"default"               {     return DEFAULT; }
"break"                 {     return BREAK; }

"="                 {     return ASSIGNMENT;}
"+"                 {   yylval.string_value = strdup(yytext);     return ADD;}
"-"                 {    yylval.string_value = strdup(yytext);    return SUB;}
"*"                 {     return MUL;}
"/"                 {     return DIV;}
"%"                 {    return MOD;}

"&&"                    {     return AND; }
"||"                    {     return OR; }
"!"                     {     return NOT; }

"=="                {    return EQUAL_TO;}
"!="                {    return NOT_EQUAL; }
"<"                 {     return LESS;}
">"                 {     return GREATER;}

"true"              {     yylval.bool_value = true;         return BOOL;}
"false"             {    yylval.bool_value = false;        return BOOL;}

    /* String*/
\"[^\n\"]*\" {   
                   yylval.string_value = strdup(yytext);   
                        return STRING;
              }

 /*character */
['][a-zA-Z][']                             {yylval.char_value=yytext[1]; return CHARACTER;}
    /*Integer*/
[0-9]+   {    
                 yylval.number = atoi(yytext);  
            return INT;
                  }
    /*Float*/
[0-9]+\.[0-9]+   {
      
     yylval.float_value= atof(yytext);     
                    return FLOAT;
                   }

    /*constant*/
[A-Z]+               {   yylval.string_value = strdup(yytext);     return CONST; }

    /*Variable name*/
[a-zA-Z_][a-zA-Z0-9_]* {
       
      yylval.string_value = strdup(yytext);   
            return IDENTIFIER;
}

    /* Punctuations*/
";"                 {     return SEMICOLON;}
","                 {     return COMMA; }
":"                 {     return COLON; }
    /*Braces */
"{"                     {     return *yytext; }
"}"                     {     return *yytext; }
"("                     {    return *yytext; }
")"                     {     return *yytext; }
    /* whitespace */
[ \t]+  ;
    /* new line */
\n  ;
     /*comments*/
\/\/[^\n]* ;
\/\*([^\*]|\*[^\/])*\*\/ ;

    /*not our language*/
.                       {
                          printf("UNKOWN_TOKEN: %s | ", yytext);   
                        return *yytext;
                        //  yyerror("Unknown character");
                        }
%%