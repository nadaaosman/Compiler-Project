#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Define the sharedData variable
AllSharedData sharedData = {
    .current_symbol_table_index = 0,
    .function_index = -1,
    .arg_count = 0,
    .loop = 0,
    .called_function_index = 0,
    .is_return = 0,
    .current_scope_index = 0,
    .block_count = 0,
    .scope_stack[0] = 0,
    .label_number = 0,
    .current_label = -1,
    .end_label_number = 0,
    .current_end_label = -1,
    .loop_number = 0,
    .current_loop = -1,
    .error_file = NULL,
    .quadruples_file = NULL};

void open_files(const char *errors_file_name, const char *quadruples_file_name)
{
    sharedData.error_file = fopen(errors_file_name, "a");
    if (sharedData.error_file == NULL)
    {
        printf("Error opening errors.txt file!\n");
        exit(1);
    }
    sharedData.quadruples_file = fopen(quadruples_file_name, "a");
    if (sharedData.quadruples_file == NULL)
    {
        printf("Error opening quadruples.txt file!\n");
        exit(1);
    }
}

void close_files()
{
    if (sharedData.error_file != NULL)
    {
        fclose(sharedData.error_file);
        sharedData.error_file = NULL;
    }

    if (sharedData.quadruples_file != NULL)
    {
        fclose(sharedData.quadruples_file);
        sharedData.quadruples_file = NULL;
    }
}

// Function to lookup a variable in the symbol table
int get_index(char *name, bool assign_statement, int line_number)
{
    int start_index = sharedData.current_symbol_table_index - 1;
    while (start_index >= 0)
    {
        struct Identifier *identifier = &sharedData.symbolTable[start_index];
        if (strcmp(identifier->name, name) == 0 && identifier->end_of_scope == 0)
        {
            if (identifier->is_initialized == 0 && strcmp(identifier->type, "var") == 0 && identifier->is_argument == 0)
            {
                if (!assign_statement)
                {
                    write_errors_quadruples(sharedData.error_file, "Error at line %d: %s used before intialization  \n", line_number, name);
                    exit(1);
                }
            }
            if (!assign_statement)
            {
                identifier->is_used = 1;
            }
            return start_index;
        }
        start_index--;
    }
    write_errors_quadruples(sharedData.error_file, "Error at line %d: %s undeclared identifier in this scope \n", line_number, name);
    exit(1);
}

// Function to check if a variable is already declared in the current scope
int is_declared(char *name, int line_number, int is_argument)
{
    for (int i = 0; i < sharedData.current_symbol_table_index; i++)
    {
        printf("name is %s \n", sharedData.symbolTable[i].name);
        printf("name scope is %d \n", sharedData.symbolTable[i].scope);
        printf("current scopeindx %d \n", sharedData.current_scope_index);
        printf("current block number  %d \n", sharedData.block_count);
        printf("name outofscope %d \n", sharedData.symbolTable[i].end_of_scope);

        if (!is_argument)
        {
            if (strcmp(sharedData.symbolTable[i].name, name) == 0 &&
                sharedData.symbolTable[i].scope == sharedData.scope_stack[sharedData.current_scope_index] && sharedData.symbolTable[i].end_of_scope == 0)
            {
                write_errors_quadruples(sharedData.error_file, "Error at line %d: %s is already declared in this scope at line %d \n", line_number, name, sharedData.symbolTable[i].line_of_declaration);
                exit(1);
            }
        }
    }
    return 0;
}

// Function to insert a new symbol table entry
void insert(char *data_type, char *name, char *type, int is_argument, int line_number)
{
    is_declared(name, line_number, is_argument);

    struct Identifier newIdentifier;

    newIdentifier.name = strdup(name);
    newIdentifier.dataType = strdup(data_type);
    newIdentifier.type = strdup(type);
    newIdentifier.is_argument = is_argument;
    newIdentifier.scope = (is_argument == 1 || sharedData.loop == 1) ? sharedData.block_count + 1 : sharedData.scope_stack[sharedData.current_scope_index];
    newIdentifier.line_of_declaration = line_number;
    newIdentifier.id = sharedData.current_symbol_table_index;
    newIdentifier.end_of_scope = 0;
    newIdentifier.is_initialized = 0;
    newIdentifier.is_used = 0;
    newIdentifier.arguments_count = 0;

    if (strcmp(type, "func") == 0)
    {
        int argument_count = 0;
        for (int i = 0; i < sharedData.current_symbol_table_index; i++)
        {
            if (sharedData.symbolTable[i].is_argument && sharedData.symbolTable[i].scope == (sharedData.block_count + 1))
            {
                newIdentifier.arguments_id[argument_count] = sharedData.symbolTable[i].id;
                argument_count++;
            }
        }
        newIdentifier.arguments_count = argument_count;
    }

    sharedData.symbolTable[sharedData.current_symbol_table_index] = newIdentifier;
    sharedData.current_symbol_table_index++;

    // Print the updated symbol table
    printf("Symbol Table:\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("| ID |    Name   | Type | DataType | Line | Scope | is_init | is_used | is_arg | Arguments\n");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < sharedData.current_symbol_table_index; i++)
    {
        struct Identifier identifier = sharedData.symbolTable[i];
        printf("| %-2d | %-9s | %-4s | %-8s | %-4d | %-5d | %-7d | %-7d | %-7d | ",
               identifier.id, identifier.name, identifier.type, identifier.dataType,
               identifier.line_of_declaration, identifier.scope, identifier.is_initialized,
               identifier.is_used, identifier.is_argument);

        if (strcmp(identifier.type, "func") == 0)
        {
            for (int j = 0; j < identifier.arguments_count; j++)
            {
                printf("%-2d,", identifier.arguments_id[j]);
            }
        }
        else
        {
            printf("-");
        }
        printf("\n");
    }
    printf("--------------------------------------------------------------------------------------------\n");
}

// Function to print the symbol table
void print_symbol_table()
{
    FILE *fp = fopen("symbol_table.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening symbol_table.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Symbol Table:\n");
    fprintf(fp, "--------------------------------------------------------------------------------------------\n");
    fprintf(fp, "| ID |    Name   | Type | DataType | Line | Scope | is_init | is_used | is_arg | Arguments\n");
    fprintf(fp, "--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < sharedData.current_symbol_table_index; i++)
    {
        struct Identifier identifier = sharedData.symbolTable[i];
        fprintf(fp, "| %-2d | %-9s | %-4s | %-8s | %-4d | %-5d | %-7d | %-7d | %-7d | ",
                identifier.id, identifier.name, identifier.type, identifier.dataType,
                identifier.line_of_declaration, identifier.scope, identifier.is_initialized,
                identifier.is_used, identifier.is_argument);

        if (strcmp(identifier.type, "func") == 0)
        {
            for (int j = 0; j < identifier.arguments_count; j++)
            {
                fprintf(fp, "%-2d,", identifier.arguments_id[j]);
            }
        }
        else
        {
            fprintf(fp, "-");
        }
        fprintf(fp, "\n");
        fprintf(fp, "---------------------------------------------------------------------------------------------\n");
    }

    fclose(fp);
}

void write_errors_quadruples(FILE *file, const char *format, ...)
{
    if (file == NULL)
    {
        printf("Error: File not open for writing!\n");
        return;
    }

    va_list args;
    va_start(args, format);

    vfprintf(file, format, args);
    fprintf(file, "\n");

    va_end(args);
}
