#ifndef __GREP_H
#define __GREP_H

int match(char* regular,char* text);

int match_here(char* regular,char* text); 

int match_star(char* c,char* regular,char* text); 

#endif 