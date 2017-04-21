%{
#include<stdio.h>
int linecnt=0,spacecnt=0,vowel=0,concnt=0;
%}

VOWEL [aeoui]
CONSONANT [bcdfghj-np-tv-z]
BLANK [ ]
EOL [\n]

%%
{VOWEL} {vowel++;}
{CONSONANT} {concnt++;}
{BLANK} {spacecnt++;}
{EOL} {linecnt++;}
%%

int yywrap()
{
return 1;
}

int main(int argc, char *argv[])
{
yyin = fopen("sample.txt","r");
yylex();
printf("\nNO OF Vowels =%d\nNO OF SPACES =%d\nNO OF LINES =%d\n NO OF CONSONANT=%d\n",vowel,spacecnt,linecnt,concnt);
return 0;
}
