%{
#include<stdio.h>
int cc=0,bc=0,wc=0,lc=0;
%}
%%
[^ \t\n]+  { wc++;
             cc=cc+yyleng;
           }
\n   lc++;
" "  bc++;
\t   bc=bc+5;
%%
main(int argc,char *argv[])
{
     if (argc!=2)   {
          printf("\nusage:./a.out filename\n");
          return(0);
     }
     yyin=fopen(argv[1],"r");
     yylex();
     printf("\n no of lines are %d\n",lc);
     printf("\n no of words are %d\n",wc);
     printf("\n no of blanks are %d\n",bc);
     printf("\n no of character are %d\n",cc);
}
int yywrap()
{
    return 1;
}