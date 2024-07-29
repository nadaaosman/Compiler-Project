%{
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
%}

%union { 
 int number; 
 char* string_value; 
 char char_value;
 float float_value;
 bool bool_value;

struct nodeType* ptr;
}
%code requires
{
#include<stdbool.h>
}

// Data Types
%token INT_TYPE FLOAT_TYPE STRING_TYPE BOOL_TYPE CHARACTER_TYPE CONST VOID 
// Keywords
%token IF ELSE DO WHILE FOR SWITCH CASE DEFAULT BREAK RETURN
//operations
%token MOD MUL DIV ADD SUB AND OR ASSIGNMENT NOT
//inequalities
%token EQUAL_TO NOT_EQUAL LESS GREATER
// Values
%token INT STRING FLOAT BOOL CHARACTER
// Identifiers
%token IDENTIFIER
// punctuations
%token SEMICOLON COMMA COLON

//operators
%left AND OR
%left EQUAL_TO NOT_EQUAL
%right NOT
%left ADD MOD
%left SUB
%left MUL
%left DIV
%right ASSIGNMENT
%right GREATER
%right LESS
//////////////////////////////////////

%type <string_value> INT_TYPE FLOAT_TYPE STRING_TYPE BOOL_TYPE CHARACTER_TYPE VOID data_type STRING IDENTIFIER CONST
%type <float_value> FLOAT
%type <number> INT
%type <bool_value> BOOL
%type <char_value> CHARACTER

%type <ptr> expression function_call return_ logics  

%%
program:                                                    
                program statement     
                |
                ;
   
statement:
                 declaration
                | function_declaration                 
                | assignment
                | return_ SEMICOLON
                | expression SEMICOLON
                | { inc_label('E'); } if_ {write_errors_quadruples(sharedData.quadruples_file,"E_IF%d:",sharedData.end_label[sharedData.current_end_label]); dec_label('E');}                             
                |{inc_label('L'); write_errors_quadruples(sharedData.quadruples_file, "LOOP%d: ", sharedData.loop_number);} while_ { dec_label('L'); }
                | for_ {dec_label('L');}                                 
                | {inc_label('L'); write_errors_quadruples(sharedData.quadruples_file, "LOOP%d: ", sharedData.loop_number);} do_while {dec_label('L'); }
                | {inc_label('E'); } switch_ { write_errors_quadruples(sharedData.quadruples_file,"EL%d:",sharedData.end_label[sharedData.current_end_label]); dec_label('E');}
                | block
                | BREAK SEMICOLON  { write_errors_quadruples(sharedData.quadruples_file,"JMP EL%d", sharedData.end_label[sharedData.current_end_label]);} 
                ;

data_type:
                INT_TYPE         { $$ = "int";   }
                | FLOAT_TYPE     { $$ = "float"; }
                | BOOL_TYPE     { $$ = "bool";  }
                | CHARACTER_TYPE {$$ ="char";}
                | STRING_TYPE    { $$ = "string";}
                | VOID            {$$ ="void";}
                ;

declaration:                                                            
                data_type IDENTIFIER  {insert($1, $2,"var",0,yylineno);  }     ASSIGNMENT expression  SEMICOLON   { int i =get_index($2,true,yylineno);check_type_assignment($1,$5->type,i,yylineno,"assignment"); write_errors_quadruples(sharedData.quadruples_file,"POP %s", $2);} 
                | data_type IDENTIFIER  {insert($1, $2,"var",0,yylineno);  }     SEMICOLON 
                |data_type  CONST    {insert($1, $2,"const",0,yylineno);}   ASSIGNMENT expression  SEMICOLON   { int i =get_index($2,true,yylineno);check_type_assignment($1,$5->type,i,yylineno,"assignment");write_errors_quadruples(sharedData.quadruples_file,"POP %s",$2);} 
                ;

return_:
                RETURN { write_errors_quadruples(sharedData.quadruples_file,"RET");}
                | RETURN expression {check_type_assignment(sharedData.symbolTable[sharedData.function_index].dataType,$2->type,sharedData.function_index,yylineno,"func_return"); sharedData.is_return = 1; write_errors_quadruples(sharedData.quadruples_file,"RET");}
                ;

switch_header:
           SWITCH IDENTIFIER COLON { sharedData.switch_identifier = $2;}'{';
switch_:
                switch_header CASES '}'
                ;

default_case:
                DEFAULT COLON block 
                ;

CASES:
                CASE  expression {write_errors_quadruples(sharedData.quadruples_file,"PUSH %s", sharedData.switch_identifier);
                write_errors_quadruples(sharedData.quadruples_file,"EQ "); 
                inc_label('N');
                write_errors_quadruples(sharedData.quadruples_file,"JF L%d",sharedData.label_number);}COLON block {
                    write_errors_quadruples(sharedData.quadruples_file,"L%d:", sharedData.label[sharedData.current_label]); dec_label('N');} CASES
                | default_case
                ;


function_declaration:
                data_type IDENTIFIER  {write_errors_quadruples(sharedData.quadruples_file,"FUNC %s",$2);} function_arg_part {insert($1, $2,"func",0,yylineno);sharedData.function_index = get_index($2,false,yylineno);} block { write_errors_quadruples(sharedData.quadruples_file,"E_FUNC %s",$2);}  
                ;

function_arg_part     : '(' arguments ')' 
                        | '('              ')' 
arguments:
                arguments_declaration COMMA arguments
                | arguments_declaration
                ;

arguments_declaration:
        data_type IDENTIFIER {insert($1, $2,"var",1,yylineno); } { write_errors_quadruples(sharedData.quadruples_file,"POP %s",$2);}
        ;
       
if_header:
       IF  expression {inc_label('N');write_errors_quadruples(sharedData.quadruples_file,"JF ELSE%d",sharedData.label_number);}
       ;

if_body:
      COLON block  {write_errors_quadruples(sharedData.quadruples_file,"JMP E_IF%d",sharedData.end_label[sharedData.current_end_label]);
                write_errors_quadruples(sharedData.quadruples_file,"ELSE%d:",sharedData.label[sharedData.current_label]);
                dec_label('N');      
      }
      ;
     
if_:
                if_header if_body
                |  if_header if_body ELSE block 
                ;

while_:
                WHILE expression COLON { inc_label('N');write_errors_quadruples(sharedData.quadruples_file,"JF E_LOOP%d",sharedData.label_number);} block {
                write_errors_quadruples(sharedData.quadruples_file,"JMP LOOP%d", sharedData.loop_labels[sharedData.current_loop]);
                write_errors_quadruples(sharedData.quadruples_file,"E_LOOP%d:",sharedData.label[sharedData.current_label]);
                dec_label('N');
                }
                ;

do_while:
                DO block WHILE '(' expression ')' SEMICOLON {
                     inc_label('N');
                     write_errors_quadruples(sharedData.quadruples_file,"JF E_LOOP%d",sharedData.label_number);            
                     write_errors_quadruples(sharedData.quadruples_file,"JMP LOOP%d", sharedData.loop_labels[sharedData.current_loop]);
                     write_errors_quadruples(sharedData.quadruples_file,"E_LOOP%d:",sharedData.label[sharedData.current_label]);
                     dec_label('N');
                     } 
                ;

for_:
                FOR '(' {sharedData.loop=1;} statement {inc_label('L');write_errors_quadruples(sharedData.quadruples_file,"LOOP%d:",sharedData.loop_number);} expression SEMICOLON {inc_label('N');write_errors_quadruples(sharedData.quadruples_file,"JF E_LOOP%d",sharedData.label_number);} assignment ')' {sharedData.loop=0;} block  {
                write_errors_quadruples(sharedData.quadruples_file,"JMP LOOP%d",sharedData.loop_labels[sharedData.current_loop]);
                write_errors_quadruples(sharedData.quadruples_file,"E_LOOP%d:",sharedData.label[sharedData.current_label]);
                dec_label('N');
                }
                ;

assignment:
                 IDENTIFIER  ASSIGNMENT expression SEMICOLON  {int i =get_index($1,true,yylineno);check_type_assignment(sharedData.symbolTable[i].dataType,$3->type,i,yylineno,"assignment");write_errors_quadruples(sharedData.quadruples_file,"POP %s",$1);}
                 |CONST  ASSIGNMENT expression SEMICOLON { int i =get_index($1,true,yylineno);check_type_assignment(sharedData.symbolTable[i].dataType,$3->type,i,yylineno,"assignment"); write_errors_quadruples(sharedData.quadruples_file,"POP %s",$1);}
                ;

block:
                '{' {scope_start();} program '}' {check_return(yylineno);sharedData.function_index = -1; sharedData.is_return = 0; handle_end_of_scope(); sharedData.current_scope_index--;} 
                ;


function_call:
                IDENTIFIER {sharedData.called_function_index = get_index($1,false,yylineno); 
                 } '('   function_call_arguments
                {  arguments_check(yylineno);  sharedData.arg_count=0; }   ')'  { sharedData.called_function_index=-1;$$=get_type($1); write_errors_quadruples(sharedData.quadruples_file,"CALL %s",$1);}
                ;

function_call_arguments:      
                expression { check_arguments_type($1->type,yylineno); sharedData.arg_count++; }  COMMA function_call_arguments 
                | expression {check_arguments_type($1->type,yylineno);sharedData.arg_count++ ;}
                |
                ;

expression:     
                IDENTIFIER                      {get_index($1,false,yylineno); $$ = get_type($1);  write_errors_quadruples(sharedData.quadruples_file,"PUSH %s",$1);}
                | INT                         { $$ = assign_type("int"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %d",$1);}
                | FLOAT                   {$$=assign_type("float"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %f",$1);}
                | BOOL                  {$$=assign_type("bool");  write_errors_quadruples(sharedData.quadruples_file,"PUSH %d",$1); }
                | CHARACTER            {$$=assign_type("char"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %c",$1);}
                | STRING                { $$=assign_type("string"); write_errors_quadruples(sharedData.quadruples_file,"PUSH %s",$1); } 
                | CONST                      {get_index($1,false,yylineno);$$ = get_type($1);  write_errors_quadruples(sharedData.quadruples_file,"PUSH %s",$1);}
                | SUB expression             {$$ = check_types_unary_op($2,'-',yylineno); write_errors_quadruples(sharedData.quadruples_file,"NEG "); }
                | expression ADD expression  {write_errors_quadruples(sharedData.quadruples_file,"ADD"); $$ = check_types_math_op($1,$3,'+',yylineno); }
                | expression MOD expression  {write_errors_quadruples(sharedData.quadruples_file,"MOD"); $$ = check_types_math_op($1,$3,'%',yylineno);}
                | expression SUB expression  {write_errors_quadruples(sharedData.quadruples_file,"SUB"); $$ = check_types_math_op($1,$3,'-',yylineno); }
                | expression MUL expression  {write_errors_quadruples(sharedData.quadruples_file,"MUL"); $$ = check_types_math_op($1,$3,'*',yylineno);}
                | expression DIV expression  {write_errors_quadruples(sharedData.quadruples_file,"DIV"); $$ = check_types_math_op($1,$3,'/',yylineno);}
                |logics
                | function_call                                
                | '(' expression ')' {$$=$2;}
                ;

logics:     
                expression GREATER expression {write_errors_quadruples(sharedData.quadruples_file,"GT"); $$ = check_types_comp($1,$3,yylineno);}
                | expression LESS expression  {write_errors_quadruples(sharedData.quadruples_file,"LT"); $$ = check_types_comp($1,$3,yylineno);}
                | expression LESS ASSIGNMENT expression {write_errors_quadruples(sharedData.quadruples_file,"LEQ"); $$ = check_types_comp($1,$4,yylineno);}
                | expression GREATER ASSIGNMENT expression {write_errors_quadruples(sharedData.quadruples_file,"GEQ"); $$ = check_types_comp($1,$4,yylineno);}
                | expression EQUAL_TO expression  {write_errors_quadruples(sharedData.quadruples_file,"EQ"); $$ = check_types_comp($1,$3,yylineno);}
                | expression NOT_EQUAL expression {write_errors_quadruples(sharedData.quadruples_file,"NEQ"); $$ = check_types_comp($1,$3,yylineno);}
                | expression AND expression {write_errors_quadruples(sharedData.quadruples_file,"AND"); $$ = check_types_logic_op($1,$3,yylineno); }
                | expression OR expression  {write_errors_quadruples(sharedData.quadruples_file,"OR"); $$ = check_types_logic_op($1,$3,yylineno); }
                | NOT expression {write_errors_quadruples(sharedData.quadruples_file,"NOT");$$ = check_types_unary_op($2,'!',yylineno);}
                ;
%%
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
