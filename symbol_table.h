#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

// Define a struct to hold shared variables
typedef struct
{
    FILE *error_file;
    FILE *quadruples_file;
    // symbol table
    struct Identifier
    {
        int id, scope;
        char *name;
        char *type;     // var,const, func
        char *dataType; // int, float, bool, string , char(for func: return type -->also there is void)
        int arguments_id[100];
        int arguments_count;
        int line_of_declaration;
        int is_argument, is_used, is_initialized, end_of_scope;
    } symbolTable[1000];
    int current_symbol_table_index;
    int function_index;
    int arg_count;
    int called_function_index;
    int is_return;
    int loop;
    int current_scope_index;
    int block_count;
    int scope_stack[500];
    // quadruples
    int label_number;
    int current_label;
    int label[100];     //N  jump false
    int end_label_number;
    int current_end_label;
    int end_label[100]; //E
    int loop_number;
    int current_loop;
    int loop_labels[100];   //L
    char *switch_identifier;

} AllSharedData;

extern AllSharedData sharedData;

void open_files(const char *errors_file_name, const char *quadruples_file_name);
void close_files();
void write_errors_quadruples(FILE *file, const char *format, ...);
void insert(char *data_type, char *name, char *type, int is_argument, int line_number);
int is_declared(char *name, int line_number,int is_argument);
int get_index(char *name, bool assign_statement, int line_number);
void print_symbol_table();
#endif