#include<stdio.h>
#include<conio.h>

void sum(int[10][10],int[10][10],int,int);
void sub(int[10][10],int[10][10],int,int);
void mul();
void transpose(int[10][10],int,int);
void adj();

void main()
{
  char again;
  int i,j;
  int row,coloumn,option;
  int matrix1[10][10],matrix2[10][10];
  void (*ptrfun[3])(int[10][10],int[10][10],int,int)={sum,sub,mul};
  do
  {

  clrscr();

  printf("\t\tWelcome to matrix calculator\n\n");

  printf("Chose what you want to do\n'0' for addition\n'1' for subtraction\n'2' for multiplication\n'3' for transpose\n'4' for adjoint of 3X3 matrix\n");
  scanf("%d",&option);
  printf("\n\n");

  if(option==0||option==1)
   {
     clrscr();
     printf("Enter the number of row and number of coloumn:\n");
     scanf("%d%d",&row,&coloumn);


     for(i=0;i<row;i++)
      {
	printf("enter the first matrix row %d: ",i+1);
	for(j=0;j<coloumn;j++)
	 {
	   scanf("%d",&matrix1[i][j]);
	 }
      }


     for(i=0;i<row;i++)
      {
	printf("Enter the second matrix row %d: ",i+1);
	for(j=0;j<coloumn;j++)
	 {
	   scanf("%d",&matrix2[i][j]);
	 }
      }
     printf("matrix A=\n");
     for(i=0;i<row;i++)
      {
	for(j=0;j<coloumn;j++)
	 {
	   printf("%d\t",matrix1[i][j]);
	 }
	printf("\n");
      }

     printf("matrix B=\n");
     for(i=0;i<row;i++)
      {
	for(j=0;j<coloumn;j++)
	 {
	   printf("%d\t",matrix2[i][j]);
	 }
	 printf("\n");
      }
     (*ptrfun[option])(matrix1,matrix2,row,coloumn);
   }
  if(option==2)
   {
     mul();
   }

  if(option==3)
   {
     clrscr();
     printf("enter the row and coloumn: ");
     scanf("%d%d",&row,&coloumn);

     for(i=0;i<row;i++)
      {
	printf("enter the element of matrix row %d: ",i+1);
	for(j=0;j<coloumn;j++)
	 {
	   scanf("%d",&matrix1[i][j]);
	 }
      }
     printf("matrix A=\n");
     for(i=0;i<row;i++)
      {
	for(j=0;j<coloumn;j++)
	 {
	   printf("%d\t",matrix1[i][j]);
	 }
	printf("\n");
      }
     transpose(matrix1,row,coloumn);
   }
  if(option==4)
   {
     adj();
   }
  printf("\n\ndo you wnat to continue press (Y)...\nor for exit press any key....");
  again=getch();
  if(again==89)
   again+=32;
  }while(again=='y');
}

void sum(int m1[10][10],int m2[10][10],int m,int n)
{
 int i,j;
 printf("sum=\n");
 for(i=0;i<m;i++)
 {
   for(j=0;j<n;j++)
    {
     printf("%d\t",m1[i][j]+m2[i][j]);
    }
    printf("\n");
 }
}




void sub(int m1[10][10],int m2[10][10],int m,int n)
{
 int i,j;
 printf("subtraction=\n");
 for(i=0;i<m;i++)
 {
   for(j=0;j<n;j++)
    {
     printf("%d\t",m1[i][j]-m2[i][j]);
    }
    printf("\n");
 }
}




void mul()
{
 int matrix1[10][10],matrix2[10][10],m1,n1,m2,n2;
 int i,j,k;
 int multi[10][10];
 clrscr();

 printf("enter the number of row and coloumn of first matrix: ");
 scanf("%d%d",&m1,&n1);
 printf("\nenter the number of row and column of second matrix: ");
 scanf("%d%d",&m2,&n2);

 if(n1==m2)
 {
 for(i=0;i<m1;i++)
  {
    printf("enter the element of first matrix row %d: ",i+1);
    for(j=0;j<n1;j++)
     {
       scanf("%d",&matrix1[i][j]);
     }
  }

 for(i=0;i<m2;i++)
  {
    printf("\nEnter the element of second matrix row %d: ",i+1);
    for(j=0;j<n2;j++)
     {
       scanf("%d",&matrix2[i][j]);
     }
  }
 clrscr();
 printf("matrix A=\n");
 for(i=0;i<m1;i++)
  {
    for(j=0;j<n1;j++)
     {
       printf("%d\t",matrix1[i][j]);
     }
    printf("\n");
  }

 printf("matrix B=\n");
 for(i=0;i<m2;i++)
  {
    for(j=0;j<n2;j++)
     {
       printf("%d\t",matrix2[i][j]);
     }
    printf("\n");
  }

  for(i=0;i<m1;i++)
   {
    for(j=0;j<n2;j++)
     {
       multi[i][j]=0;
       for(k=0;k<n2;k++)
       multi[i][j]=multi[i][j]+(matrix1[i][k]*matrix2[k][j]);
     }
   }
  printf("multiple=\n");
  for(i=0;i<m1;i++)
  {
    for(j=0;j<n2;j++)
     printf("%d\t",multi[i][j]);
    printf("\n");
  }
 }
 else
  printf("multipication is not possible");
}


void transpose(int matrix[10][10],int m,int n)
{
  int i,j,trans[10][10];
  for(i=0;i<m;i++)
   {
     for(j=0;j<n;j++)
      {
	trans[j][i]=matrix[i][j];
      }
   }
  printf("transpose of matrix is:\n");
  for(i=0;i<n;i++)
   {
     for(j=0;j<m;j++)
      {
	printf("%d\t",trans[i][j]);
      }
      printf("\n");
   }
}



void adj()
{
 int i,j,k,l,m=0,n=0,c;
 int a[3][3],b[2][2],adj[3][3];
 clrscr();

 for(i=0;i<3;i++)
  {
   printf("enter the matrix row %d: ",i+1);
   for(j=0;j<3;j++)
    scanf("%d",&a[i][j]);
  }
 printf("your matrix is:\n");
 for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
	printf("%d\t",a[i][j]);
      printf("\n");
    }

 for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
      {
	m=0;
	for(k=0;k<3;k++)
	  {
	    n=0;
	    for(l=0;l<3;l++)
	      {
		if(k!=i&&l!=j)
		  {
		    b[m][n]=a[k][l];
		    n++;
		  }
	      }
	      if(k!=i)
		m++;
	  }
	  adj[i][j]=pow(-1,(i+j))*((b[0][0]*b[1][1])-(b[0][1]*b[1][0]));
      }
  }
   printf("adjoint of the given matrix is:\n");
   for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
	printf("%d\t",adj[i][j]);
      printf("\n");
    }
}