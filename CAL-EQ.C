#include<stdio.h>
#include<conio.h>


#define size 10
int prefer[size];
char oprator[size];
int top=-1,ctr=0,length=0;
int cal[20],topCal=-1;
char eq[20][5];
char equation[50];
char postfixEq[20][5];


void pushCal(int num)
{
  cal[(++topCal)]=num;
}

int popCal()
{
  return cal[(topCal--)];
}



void push(char value,int pre)
{
  oprator[++top]=value;
  prefer[top]=pre;

}

char pop()
{
  return oprator[(top--)];
}

void put(int start,int end)
{
  int i=0,flag=0;
  for(;start<end;start++)
   {
     flag=1;
     eq[ctr][i++]=equation[start];
   }
  if(flag==1)
    ctr++;
  if(end==start)
  {
  eq[ctr][0]=equation[start];
  ctr++;
  }
}


void main()
{
  int i=0,j,pre,num1,num2,para=0,start=0,end;
  char element;
  //taking input
  clrscr();
  printf("Enter the Equation: ");
  gets(equation);

//converting to postfix
  length=strlen(equation);
  equation[length]='\0';
  //converting to eq
  for(i=0;i<=length;i++)
   {
     if(equation[i]=='+'||equation[i]=='-'||equation[i]=='/'|| equation[i]=='*'||equation[i]=='('||equation[i]=='\0'||equation[i]==')')
      {
	end=i;
	put(start,end);
	start=end+1;
      }
   }


  ctr=ctr-1;
  j=0;

  for (i=0;i<ctr;i++)
   {
     if(eq[i][0]=='+')
       pre=1;
     if(eq[i][0]=='-')
       pre=1;
     if(eq[i][0]=='*')
       pre=2;
     if(eq[i][0]=='/')
       pre=2;
     if(eq[i][0]=='(')
       pre=0;

     again:
     if(eq[i][0]=='+'||eq[i][0]=='-'||eq[i][0]=='/'||eq[i][0]=='*'||eq[i][0]=='(')
      {
	if(top==-1)
	  push(eq[i][0],pre);
	else if(oprator[top]=='(')
	{
	  push(eq[i][0],pre);
	}
	else
	 {
	   if(pre>prefer[top])
	     push(eq[i][0],pre);
	   else if(eq[i][0]=='(')
	   {
	     push(eq[i][0],pre);
	     para++;
	   }
	   else
	   {
	     postfixEq[j++][0]=pop();
	     goto again;
	   }
	 }
      }
     else if(eq[i][0]==')')
       {
	 element=NULL;
	 while(element!='(')
	   {
	      element=pop();
	      if(element!='(')
		postfixEq[j++][0]=element;
	   }
       }
     else
       strcpy(postfixEq[j++],eq[i]);
   }
   while(top>=0)
     postfixEq[j++][0]=pop();
 //to see the postfix converted value
 /*
   for(i=0;i<ctr;i++)
     printf(" %s",postfixEq[i]);
   */

  //calculation part
  for(i=0;i<ctr-para*2;i++)
   {
     if(postfixEq[i][0]=='+'||postfixEq[i][0]=='-'||postfixEq[i][0]=='/'||postfixEq[i][0]=='*')
      {
	num2=popCal();
	num1=popCal();
	if(postfixEq[i][0]=='+')
	 {
	   pushCal(num1+num2);
	 }
	if(postfixEq[i][0]=='-')
	 {
	   pushCal(num1-num2);
	 }
	if(postfixEq[i][0]=='*')
	 {
	   pushCal(num1*num2);
	 }
	if(postfixEq[i][0]=='/')
	 {
	   pushCal(num1/num2);
	 }
      }
     else
      {
	pushCal(atoi(postfixEq[i]));
      }
   }
  printf("\nans= %d",popCal());

  getch();

}