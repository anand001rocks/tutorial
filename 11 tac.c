#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int priority(char ele);

void pop(char *op , char *od);

char* Substr(char * strng, int start, int end);

struct Three_add

{

char arg1,arg2,op,LHS;

char result,RHS[20];

}q[2];

int x=0, asc=65;

char OP[20],OD[20],t1,t2;

int main()

{

char string1[20],str[20];

int i=0,j,len1,len2,len3;

string1[0]='\0';

printf("\n\n enter the infix expression:::");

scanf("%c = %s",&q[0].LHS,&q[0].RHS);

strcpy(string1,q[0].RHS);

len1=strlen(string1);

for(i=0;i<strlen(string1);i++)

{

 str[0]='\0';

if(string1[0]=='-')

 { 

 q[x].arg1=string1[1];

 q[x].op='\0';

 q[x].arg2=string1[0];

 q[x].result=(char) asc;

str[0]=q[x].result;

str[1]='\0';

strcat(str,Substr(string1,2,len1));

asc++;

x++;

strcpy(string1,str);

}

else if(string1[i]=='(')

{

q[x].arg1=string1[i+1];

q[x].op=string1[i+2];

q[x].arg2=string1[i+3];

q[x].result=(char) asc;

strcpy(str,Substr(string1,0,i-1));

len2=strlen(str);

str[len2]=q[x].result;

str[len2+1]='\0';

strcat(str,Substr(string1,i+5,len1));

asc++;

x++;

strcpy(string1,str);

} }

for(i=0;i<strlen(string1);i++)

{

 t1=string1[i];//Creating own library in Linux environment and using it

 if(priority(t1)==0)

 OD[strlen(OD)] =t1;

 else

{

for(j=(strlen(OP)-1);j<=0;j--)

 {

 t2=OP[i];

 if(priority(t1)>priority(t2))

 break;

 else

 pop(OP,OD);

 }

OP[strlen(OP)] =t1;
}
}
for(i=strlen(OP)-1;i>=0;i--)
 pop(OP,OD);
if(q[0].LHS!='\0')
{
q[x].arg1=q[x-1].result;
q[x].result=q[0].LHS;
}
printf("\n\n\n ***********THREE ADDRESS CODE**********");
for(i=0;i<=x;i++)
 {
if(q[i].result!='\0')
 {
 if(i==x)
 printf("\n\n %c= %c ",q[i].result,q[i].arg1);
 printf("\n\n %c =%c %c %c ",q[i].result,q[i].arg2,q[i].op,q[i].arg1);
 }
 }
return 0;
}

char* Substr (char* strng, int start, int end )
{
int k,l;
char substr[20];
substr[0]='\0';
for(l=start,k=0;l<=end;l++,k++)
{
substr[k]=strng[l];
substr[k+1]='\0';
}
return substr;
}
int priority(char ele)
{
int pr;
if(ele=='^')
pr=3;
 else if (ele=='*' || ele=='/' || ele=='%')
pr=2;
else if(ele == '+' || ele=='-')
pr=1;
else
pr=0;
return pr;
}

void pop(char* op, char *od)
{
char op1,od1,od2;
op1=op[strlen(op)-1];
od2=od[strlen(od)-1];
od1=od[strlen(od)-2];
q[x].result=(char) asc;
q[x].arg1= od1;
q[x].op= op1;
q[x].arg2=od2;
od[strlen(od)-2]= (char) asc;
od[strlen(od)-1]='\0';
op[strlen(op)-1]='\0';
asc++;
x++;
}
