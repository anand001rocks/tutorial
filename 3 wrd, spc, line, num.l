%{
#include<stdio.h>
int linecnt=0,spacecnt=0,wordcnt=0,numcnt=0;
%}

WORD [a-z][a-z]*
NUMBER [-]?[1-9][0-9]*
BLANK [ ]
EOL [\n]
%%

{WORD} {printf("Word");wordcnt++;}
{NUMBER} {printf("Number");numcnt++;}
{BLANK} {printf("Space");spacecnt++;}
{EOL} {linecnt++;}
%%

int yywrap()
{
return 1;
}
int main(int argc,char *argv[])
{
yyin = fopen("sample.txt","r");
yylex();
printf("\n No of Words:%d \n Total Numbers = %d \n No of Spaces : %d \n No of Lines = %d ",wordcnt,numcnt,spacecnt,linecnt); 
return 0;
}
