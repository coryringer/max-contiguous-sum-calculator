/* post_script.h */
#ifndef POST_SCRIPT_H
#define POST_SCRIPT_H

#include <stdio.h>

void PS_TEXT(FILE*, char*, int, int); 
void PS_FONT(FILE*, char*, int);
void PS_START(FILE*);
void PS_SHOW(FILE*);

#endif 
