#!/bin/bash

# Run Bison to generate parser code
bison -d parser.y

# Run Flex to generate lexer code
flex lexer.l

# Compile the generated parser and lexer files
# gcc -o my_parser parser.tab.c lex.yy.c
gcc -o my_parser parser.tab.c lex.yy.c symbol_table.c type_mismatch_handler.c operators.c quadruples.c

./my_parser code.txt