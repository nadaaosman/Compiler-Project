#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Types
//======================
struct nodeType
{
    char *type;
};

// Function prototypes
struct nodeType *check_types_math_op(struct nodeType *operand1, struct nodeType *operand2, char operator, int line_number);
struct nodeType *check_types_logic_op(struct nodeType *operand1, struct nodeType *operand2, int line_number);
struct nodeType *check_types_comp(struct nodeType *operand1, struct nodeType *operand2, int line_number);
struct nodeType *assign_type(char *type);
struct nodeType *get_type(char *name);
struct nodeType *check_types_unary_op(struct nodeType *operand, char operator, int line_number);
#endif /* FUNCTIONS_H */
