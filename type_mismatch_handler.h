#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

// Function prototypes
void check_type_assignment(char *left_side_type, char *right_side_type, int i, int line_number, char *state);
void check_arguments_type(char *sent_type, int line_number);
void scope_start();
void check_return(int line_number);
void print_unused_identifiers();
void arguments_check(int line_number);
void handle_end_of_scope();

#endif /* SYMBOLTABLE_H */
