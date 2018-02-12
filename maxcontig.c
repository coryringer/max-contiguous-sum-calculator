/* maxcontig.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "maxcontig.h"
#include "post_script.h"

/**
 * Populate the array a[]
 * with pseudo-random numbers.
 */
void 
fill_arr(int N,   /* array size */
	       int a[]) /* array */
{
  int num_range = 60, *p;
  time_t t;

  srand(time(&t));
  for (p = a; p < a + N; p++)
    *p = ((rand() % (num_range * 2)) - num_range);
}

/**
 * Determine the largest contiguous
 * sum of the array a[].
 */
int 
max_subsum(int N,   /* array size */
	         int a[]) /* array */
{
  int *p, max_sum = 0, this_sum = 0;

  for (p = a; p < a + N; p++) {
    this_sum += *p;
    if (this_sum > max_sum)
      max_sum = this_sum;
    else if (this_sum < 0)
      this_sum = 0;
  }
  return max_sum;
}

/**
 * Print the contents of array a[] and the 
 * largest contiguous sum of the array.
 */
void 
print_arr(FILE* stream, /* output stream */
	        int a[],      /* array */
	        int *y_coord) /* y-coord for displaying text */
{
  int i;
  char buffer_arr[ARRAY_SIZE], 
       buffer_num[ARRAY_SIZE], 
       buffer_numtemp[sizeof(int)];

  strcpy(buffer_num, "");
  strcpy(buffer_numtemp, "");
	
  /* Print heading */
  sprintf(buffer_arr, "a[%d] =", ARRAY_SIZE);
  PS_TEXT(stream, buffer_arr, X_COORD, *y_coord);
  *y_coord -= PS_NEWLINE; /* prepare *y_coord for next line down */

	/* Print contents of array */
  for (i = 0; i < ARRAY_SIZE; i++) {
    if ((i % (ARRAY_SIZE / NUM_ROWS)) == 0 && i > 0) {
	    PS_TEXT(stream, buffer_num, X_COORD, *y_coord); /* output numbers */
	    *y_coord -= PS_NEWLINE; /* create newline after every breakpoint */ 
	    strcpy(buffer_num, " ");
    }

    sprintf(buffer_numtemp, "%d ", a[i]); 
    strcat(buffer_num, buffer_numtemp);   /* append buffer_num with bufer_numtemp */
  }

  PS_TEXT(stream, buffer_num, X_COORD, *y_coord); /* output whatever is left */
  *y_coord -= PS_NEWLINE;
}
