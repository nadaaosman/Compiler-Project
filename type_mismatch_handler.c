#include "symbol_table.h"
#include "type_mismatch_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_type_assignment(char *left_side_type, char *right_side_type, int i, int line_number, char *state)
{
    int is_incompatible_type = 0;
    char *type_mismatch_msg = NULL;
    int has_four_params = 0;
    // Return type of the function and the actually returned
    if (strcmp(state, "func_return") == 0)
    {
        if (strcmp(left_side_type, right_side_type) != 0 && strcmp(left_side_type, "void") != 0 &&
            (strcmp(left_side_type, "char") == 0 ||
             (strcmp(left_side_type, "string") == 0 && strcmp(right_side_type, "char") != 0) ||
             strcmp(right_side_type, "string") == 0))
        {
            write_errors_quadruples(sharedData.error_file,
                                    "Incompatible Types at line %d: return type of the function is %s but expression actually returned %s \n",
                                    line_number, left_side_type, right_side_type);
            exit(1);
        }
    }
    // If const
    else if (strcmp(sharedData.symbolTable[i].type, "const") == 0 && sharedData.symbolTable[i].is_initialized)
    {
        write_errors_quadruples(sharedData.error_file,
                                "Incompatible Types at line %d: Identifier %s is constant can't be reassigned \n",
                                line_number, sharedData.symbolTable[i].name);
        exit(1);
    }
    // integer , float , bool
    else if (strcmp(right_side_type, "int") == 0 || strcmp(right_side_type, "float") == 0 || strcmp(right_side_type, "bool") == 0)
    {
        if (strcmp(left_side_type, "string") == 0 || strcmp(left_side_type, "char") == 0)
        {
            is_incompatible_type = 1;
            type_mismatch_msg = (strcmp(state, "assignment") == 0) ? "Incompatible Types at line %d: variable %s is of type %s but %s is assigned \n" : "Incompatible Types at line %d: Incorrect argument type %s is of type %s but argument of type %s in call \n";
            has_four_params = 1;
        }
    }
    // string
    else if (strcmp(right_side_type, "string") == 0)
    {
        if (strcmp(left_side_type, "string") != 0)
        {
            is_incompatible_type = 1;
            type_mismatch_msg = (strcmp(state, "assignment") == 0) ? "Incompatible Types at line %d: %s %s variable assigned string value \n" : "Incompatible Types at line %d: Incorrect argument type %s is of type %s but argument of type string in call \n";
            has_four_params = 0;
        }
    }
    else if (strcmp(right_side_type, "void") == 0)
    {
        write_errors_quadruples(sharedData.error_file,
                                "Incompatible Types at line %d: %s is %s variable but the function has no return (void) \n",
                                line_number, sharedData.symbolTable[i].name, sharedData.symbolTable[i].dataType);
        exit(1);
    }

    if (is_incompatible_type)
    {
        if (has_four_params)
        {
            write_errors_quadruples(sharedData.error_file, type_mismatch_msg,
                                    line_number, sharedData.symbolTable[i].name, sharedData.symbolTable[i].dataType, right_side_type);
        }
        else
        {
            write_errors_quadruples(sharedData.error_file, type_mismatch_msg,
                                    line_number, sharedData.symbolTable[i].name, sharedData.symbolTable[i].dataType);
        }
        exit(1);
    }

    if (strcmp(state, "assignment") == 0)
    {
        sharedData.symbolTable[i].is_initialized = 1;
    }
}

void check_arguments_type(char *sent_type, int line_number)
{
    if (sharedData.called_function_index != -1)
    {
        if (sharedData.arg_count < sharedData.symbolTable[sharedData.called_function_index].arguments_count)
        {
            int argument_index = sharedData.symbolTable[sharedData.called_function_index].arguments_id[sharedData.arg_count];
            char *argument_type = sharedData.symbolTable[argument_index].dataType;
            printf("argument type %s \n", argument_type);
            printf("sent type %s \n", sent_type);
            check_type_assignment(argument_type, sent_type, argument_index, line_number, "function");
        }
    }
}

void scope_start()
{
    sharedData.block_count++;
    sharedData.current_scope_index++;
    sharedData.scope_stack[sharedData.current_scope_index] = sharedData.block_count;
}

void handle_end_of_scope()
{
    for (int i = 0; i < sharedData.current_symbol_table_index; i++)
    {
        if (sharedData.symbolTable[i].scope == sharedData.scope_stack[sharedData.current_scope_index])
        {
            sharedData.symbolTable[i].end_of_scope = 1;
        }
    }
}

void check_return(int line_number)
{
    if (sharedData.function_index != -1 && strcmp(sharedData.symbolTable[sharedData.function_index].type, "func") == 0)
    {
        if (sharedData.is_return == 0 && strcmp(sharedData.symbolTable[sharedData.function_index].dataType, "void") != 0)
        {
            write_errors_quadruples(sharedData.error_file, "Error at line %d: missing return in Function %s\n", line_number, sharedData.symbolTable[sharedData.function_index].name);
            exit(1);
        }
        else if (sharedData.is_return == 1 && strcmp(sharedData.symbolTable[sharedData.function_index].dataType, "void") == 0)
        {
            write_errors_quadruples(sharedData.error_file, "Error at line %d: void Function %s can't have return statement\n", line_number, sharedData.symbolTable[sharedData.function_index].name);
            exit(1);
        }
    }
}

void print_unused_identifiers()
{
    for (int i = 0; i < sharedData.current_symbol_table_index; i++)
    {
        if (strcmp(sharedData.symbolTable[i].name, "main") == 0)
            continue;

        char *message = NULL;

        if (sharedData.symbolTable[i].is_used == 0)
        {
            if (strcmp(sharedData.symbolTable[i].type, "func") == 0)
                message = "warning : function %s declared at line %d but never called \n";
            else if (sharedData.symbolTable[i].is_argument == 1)
                message = "warning : Unused Argument %s declared in function at line %d \n";
            else
                message = "warning : Unused identifier %s declared at line %d \n";

            write_errors_quadruples(sharedData.error_file, message, sharedData.symbolTable[i].name, sharedData.symbolTable[i].line_of_declaration);
        }
    }
}

void arguments_check(int line_number)
{
    if (sharedData.called_function_index != -1)
    {
        int expected_args = sharedData.symbolTable[sharedData.called_function_index].arguments_count;
        int actual_args = sharedData.arg_count;

        if (actual_args > expected_args)
        {
            write_errors_quadruples(sharedData.error_file, "Error at line %d: too many arguments for function call, expected %d, actually sent %d\n", line_number, expected_args, actual_args);
            exit(1);
        }
        else if (actual_args < expected_args)
        {
            write_errors_quadruples(sharedData.error_file, "Error at line %d: too few arguments for function call, expected %d, actually sent  %d\n", line_number, expected_args, actual_args);
            exit(1);
        }
    }
}
