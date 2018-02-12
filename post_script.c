/* post_script.c */
#include <stdio.h>
#include "post_script.h"

/**
 * PS_TEXT prints a string to a PostScript
 * page and prints to file.
 */
void 
PS_TEXT(FILE *outfile,     /* output stream */
	      char *string,      /* output string to screen */
	      int   x_coord,     /* x coordinate */
	      int   y_coord)     /* y coordinate */
{
  fprintf(
    outfile,
    "%d %d moveto\n" /* move string to coordinates */
    "(%s) show\n",   /* show string */
    x_coord, y_coord,
    string
  );
}

/**
 * PS_FONT selects the font type and size
 * for a string and prints to file.
 */
void 
PS_FONT(FILE *outfile,   /* output stream */
	      char *font_name, /* PostScript font */
	      int   font_size) /* font size */
{
  fprintf(outfile, "/%s\n%d selectfont\n", font_name, font_size);
}

/**
 * PS_START writes the very first line 
 * of a PostScript file. 
 */
void PS_START(FILE *outfile)	/* output stream */
{
  fprintf(outfile, "%%!PS\n");
}

/**
 * PS_STOP writes the very last line of a PostScript file 
 * that shows the contents onto the page.
 */
void PS_SHOW(FILE *outfile)	/* output stream */
{
  fprintf(outfile, "showpage\n");
}
