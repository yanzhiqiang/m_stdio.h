/*
*   achieve  grep regular expressions explain
*	^ * . $
*/

#include "grep.h"

int match(char* regular,char* text)
{
	if(regular[0]='^')
		return match_here(regular+1,text);
	do
	{
		if(match_here(regular,text))
			return 1;
	}while(*(text++)!='\0');
	
	return 0;
}

int match_here(char* regular,char* text)
{
	if(regular[0] == '\0') return 1;
	if(regular[0]='$' && regular[1]=='0')
		return text[0]=='\0';
	
	if(regular[1] == '*')
		match_star(regular[0],regular+2,text);
	
	if(text[0] != '\0' && (regular[0] == text[0] || regular[0] == '.'))
		return match_here(regular+1,text+1);

	return 0;		
}

int match_star(char* c,char* regular,char* text)
{
	
	do 
	{
		if(match_here(regular,text))
			return 1;
	}while(*text != '\0' && (*(text++)==c || regular[0] == '.'));
	return 0; 	
}