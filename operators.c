#include "operators.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

// set the  type
struct nodeType *assign_type(char *type)
{
    struct nodeType *p = malloc(sizeof(struct nodeType));
    p->type = type;
    return p;
}

// Function definitions
struct nodeType *check_types_math_op(struct nodeType *operand1, struct nodeType *operand2, char operator, int line_number)
{
    struct nodeType *p = malloc(sizeof(struct nodeType));

    // valid
    // string + string
    // not valid
    // string - string , string - int , string / float , void func call ,
    if ((operator!= '+' &&(strcmp(operand1->type, "string") == 0 || strcmp(operand2->type, "string") == 0)) || strcmp(operand2->type, "void") == 0 ||
        strcmp(operand1->type, "void") == 0 || (operator== '+' &&((strcmp(operand1->type, "string") == 0 && (strcmp(operand2->type, "string") != 0 && strcmp(operand2->type, "char") != 0)) || (strcmp(operand2->type, "string") == 0 && (strcmp(operand1->type, "string") != 0 && strcmp(operand1->type, "char") != 0)))))
    {
        write_errors_quadruples(sharedData.error_file, "invalid operator incompatible types between operands at line %d \n", line_number);
        exit(1);
    }
    else
    {
        if (strcmp(operand1->type, "float") == 0 || strcmp(operand2->type, "float") == 0)
            p->type = "float";
        else if (strcmp(operand1->type, "string") == 0 && strcmp(operand2->type, "string") == 0)
            p->type = "string";
        else
            p->type = "int";

        return p;
    }
}

struct nodeType *check_types_logic_op(struct nodeType *operand1, struct nodeType *operand2, int line_number)
{
    printf("hello %d tib\n", line_number);
    printf("operand2type %s tib\n", operand2->type);
    printf("logical operand1type %s tib\n", operand1->type);
    printf("logical operand2type %s tib\n", operand2->type);
    struct nodeType *p = malloc(sizeof(struct nodeType));

    // insure that not make logic operation between string with anything else or void
    if (strcmp(operand1->type, "string") == 0 || strcmp(operand2->type, "string") == 0 || strcmp(operand2->type, "void") == 0 || strcmp(operand1->type, "void") == 0)
    {
        write_errors_quadruples(sharedData.error_file, "invalid operator incompatible types between operands at line %d \n", line_number);
        exit(1);
    }
    else
    {
        p->type = "bool";
        return p;
    }
}

struct nodeType *check_types_comp(struct nodeType *operand1, struct nodeType *operand2, int line_number)
{
    struct nodeType *p = malloc(sizeof(struct nodeType));
    printf("hello comaprison%d tib\n", line_number);
    printf("operand1type %s tib\n", operand1->type);
    printf("operand2type %s tib\n", operand2->type);

    // insure that not comparing string with anything else or void
    if ((strcmp(operand1->type, "string") == 0 && strcmp(operand2->type, "string") != 0) || (strcmp(operand2->type, "string") == 0 && strcmp(operand1->type, "string") != 0) || strcmp(operand2->type, "void") == 0 || strcmp(operand1->type, "void") == 0)
    {
        write_errors_quadruples(sharedData.error_file, "invalid operator incompatible types between operands at line %d \n", line_number);
        exit(1);
    }
    else
    {
        p->type = "bool";
        return p;
    }
}

struct nodeType *get_type(char *name)
{
    printf("symbolval of name %s tib\n", name);
    struct nodeType *p = malloc(sizeof(struct nodeType));

    for (int i = sharedData.current_symbol_table_index - 1; i >= 0; i--)
    {
        if (strcmp(sharedData.symbolTable[i].name, name) == 0 &&
            sharedData.symbolTable[i].end_of_scope == 0)
        {
            p->type = sharedData.symbolTable[i].dataType;
            return p;
        }
    }
}

struct nodeType *check_types_unary_op(struct nodeType *operand, char operator, int line_number)
{
    struct nodeType *p = malloc(sizeof(struct nodeType));

    if (strcmp(operand->type, "string") == 0 || strcmp(operand->type, "void") == 0)
    {
        write_errors_quadruples(sharedData.error_file, "invalid operator incompatible operand type of operator %c at line %d \n", operator, line_number);
        exit(1);
    }
    else if (operator== '!')
    {
        p->type = "bool";
    }
    else if (strcmp(operand->type, "char") == 0 || strcmp(operand->type, "bool") == 0)
    {
        p->type = "int";
    }
    else
    {
        p->type = operand->type;
    }
    return p;
}