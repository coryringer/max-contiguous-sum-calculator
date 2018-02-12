/* main.c for MaxContig Project */
#include <stdio.h>
#include "maxcontig.h"
#include "post_script.h"

int 
main(void)
{
  int y = 750; /* y-coord for displaying text in .ps file (y will change) */
  int arr[ARRAY_SIZE];
  int max_sum;
  FILE* psfile; /* PostScript File (.ps) */
	const char* psfilename = "output.ps";
  char buffer[ARRAY_SIZE];
	
  fill_arr(ARRAY_SIZE, arr); /* populate array with pseudo-random numbers */
  max_sum = max_subsum(ARRAY_SIZE, arr);
	
  psfile = fopen(psfilename, "w");

  /* Print to .ps file */
  PS_START(psfile);
  PS_FONT(psfile, "Courier", 10); /* font and size for .ps */
  PS_TEXT(psfile, "maxcontig.c output:", X_COORD, y); /* title */
  y -= PS_NEWLINE; /* prepare y for next line (drop y by PS_NEWLINE) */
  print_arr(psfile, arr, &y); /* write array to .ps */
  sprintf(buffer, "%d is the largest contiguous sum of array a[].", max_sum);
  PS_TEXT(psfile, buffer, X_COORD, y);
  PS_SHOW(psfile); /* display all contents of .ps to Ghostview */
  fclose(psfile);
  return 0;
}
