%{
	#include<stdio.h>
	int pi=0,ni=0,lc=1;
	char file_name[30];
%}    
EOL [\n]*
%%
[-][0-9]* {ni++;}
[+]?[0-9]* {pi++;}
{EOL} {lc++;}
%%

int yywrap()
{
      return(1);
}

int main(int argc[],char *argv[])
{
    printf("Enter input file name : \n");
	scanf("%s",file_name);
	yyin=fopen(file_name,"r");
	yylex();
	fclose(yyin);
	printf("Number of positive numbers : %d\n Number of negative numbers : %d\n Number of lines : %d\n",pi,ni,lc); 
	return 0;
}
