/* maxcontig.h */
#ifndef MAX_CONTIG_H
#define MAX_CONTIG_H

#include <stdio.h>

#define ARRAY_SIZE  100
#define X_COORD     40 /* x-coord for displaying text in .ps file */
#define PS_NEWLINE  25 /* drop down y-coord constant for new line in .ps file */
#define STRING_SIZE 100
#define NUM_ROWS    4


void fill_arr(int, int []);
int max_subsum(int, int []);
void print_arr(FILE*, int [], int *);

#endif
