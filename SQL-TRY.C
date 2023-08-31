#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct column_info{
	char col_name[10];
	int size;}column;

void create();
void openf();
void append(char[10]);
void view(char[10]);
void main()
{
  void (*ptr[2])()={create,openf};
  char option,again;
  do{
  clrscr();
  printf("1.>for creating a new table\n2.>for open a table\n");
  option=getch();
  (*ptr[option-49])();
  printf("\nfor home press(H)...\nfor exit press any key...");
  again=getch();
  if(again>=65&&again<=90)
   again+=32;
  }while(again=='h');
}
void create()
{
  FILE * fptr=NULL;
  int n,i,column_size;
  column c;
  char table_name[10];
  clrscr();
  printf("enter the table name: ");
  scanf("%s",table_name);
  strupr(table_name);
  strcat(table_name,".txt");
  fptr=fopen(table_name,"r+");
   if(fptr==NULL)
      printf("\ntable name is avilable");
   else
   {
      printf("\ntable name is already taken");
      goto out;
   }
  fclose(fptr);

  printf("\nenter how many coloumn you want: ");
  scanf("%d",&n);
  printf("\n");

  fptr=fopen(table_name,"w+");
  fprintf(fptr,"%d",n);
  for(i=0;i<n;i++)
  {
    printf("enter the %d coloumn name: ",i+1);
    scanf("%s",c.col_name);
    printf("enter the size of data in byte: ");
    scanf("%d",&c.size);
    fprintf(fptr," %s %d",c.col_name,c.size);
    printf("\n");
  }

  out:
  fclose(fptr);

}

void openf()
{
  FILE * fptr;
  void (*ptr[2])()={view,append};
  char table_name[10],option,again;

  clrscr();
  printf("enter the table name: ");
  scanf("%s",table_name);
  strupr(table_name);
  strcat(table_name,".txt");
  do{
  clrscr();
  fptr=fopen(table_name,"r+");
   if(fptr==NULL)
   {
      printf("\ntable not found");
      goto out;
   }
  fclose(fptr);
  printf("\n1.>for viewing table\n2.>for appending on table\n");
  option=getch();
  (*ptr[option-49])(table_name);
  out:
  printf("\ndo you want to use again(Y/N)");
  again=getch();
  if(again>=65&&again<=90)
   again+=32;
  }while(again=='y');


}

void append(char table_name[10])
{
  char * c_name;
  char * c_size,* temp;
  int n_col,i,j;
  char again;
  FILE * fptr;
  clrscr();
  fptr=fopen(table_name,"r");
  fscanf(fptr,"%d",&n_col);
  c_name=(char*)calloc(n_col,10);
  c_size=(char*)calloc(n_col,sizeof(int));
  for(i=0,j=0;i<n_col*10;i+=10,j++){
     fscanf(fptr," %s %s",c_name+i,c_size+j);
     //printf(" %s %d",c_name+i,atoi(c_size+j));
     }
  fclose(fptr);
  fptr=fopen(table_name,"a");
  do{
  fprintf(fptr,"\n");
  for(i=0,j=0;i<n_col*10;i+=10,j++)
  {
    temp=(char*)calloc(atoi(c_size+j),1);
    printf("\nenter the value in %s: ",c_name+i);
    scanf("%s",temp);
    //printf("%s",temp);
    fprintf(fptr," %s",temp);
    free(temp);
  }
  printf("\ndo you want to append more (Y/N)");
  again=getch();
  if(again>=65&&again<=90)
   again+=32;
  }while(again=='y');
  fclose(fptr);
  free(c_name);
  free(c_size);

}
void view(char table_name[10])
{
  char * c_name,bin[10],ch;
  int n_col,i;
  FILE * fptr;
  clrscr();
  fptr=fopen(table_name,"r");
  fscanf(fptr,"%d",&n_col);
  c_name=(char*)calloc(n_col,10);
  for(i=0;i<n_col*10;i+=10){
     fscanf(fptr," %s %s",c_name+i,&bin);
     printf(" %s",c_name+i);
     }
  while(!feof(fptr))
  {
    fscanf(fptr,"%c",&ch);
    printf("%c",ch);
  }
  fclose(fptr);
  free(c_name);
}