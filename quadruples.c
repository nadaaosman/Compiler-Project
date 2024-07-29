// quadruples.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadruples.h"
#include "symbol_table.h"

void inc_label(char label)
{
    if (label == 'E')
        sharedData.end_label[++sharedData.current_end_label] = ++sharedData.end_label_number;
    else if (label == 'L')
        sharedData.loop_labels[++sharedData.current_loop] = ++sharedData.loop_number;
    else
        sharedData.label[++sharedData.current_label] = ++sharedData.label_number;
}

void dec_label(char label)
{
    if (label == 'E')
        sharedData.current_end_label--;
    else if (label == 'L')
        sharedData.current_loop--;
    else
        sharedData.current_label--;
}
