#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
  FILE * flag=NULL;
  char ch;
  int i,j,k=0;
  do{
  textcolor(RED);
  printf("\n");
  for(j=1;j<=7;j++)
  {
    for(i=1;i<=77;i++)
      cprintf("|");
    printf("\n");
    delay(100);
  }
  flag=fopen("FLAG.txt","r");
  if(flag==NULL)
  {
   printf("error");
   exit(1);
   }
  while(!feof(flag))
  {
    ch=fgetc(flag);
    printf("%c",ch);
    if(ch=='\n')
     delay(100);
  }
  fclose(flag);
  printf("\n");
  textcolor(GREEN);
  for(j=1;j<=7;j++)
  {
    for(i=1;i<=77;i++)
      cprintf("|");
    printf("\n");
    delay(100);
  }
  k++;
  }while(k<5);
  getch();
}
