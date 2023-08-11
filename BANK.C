#include<stdio.h>
#include<conio.h>

void new_account();
void login();
char choice;

void main()
{
  char option;
  do
  {
  clrscr();

  printf("\t\tWelcome to digital Bank\n");
  printf("\nfor new create new account press (N):\nfor login to your account press (L):\n");
  option=getch();
  if(option>=65&&option<=90)
   option=option+32;
  switch(option)
  {
    case 'n':
      new_account();
      break;
    case 'l':
      login();
      break;
    default:
      printf("\nwrong input");
  }
  }while(choice=='h');
}


void new_account()
{

  char ch;
  int password,fpass,cpass,k;
  float balance;
  FILE * data=NULL;

  do
  {
  fpass=0;
  cpass=0;
  clrscr();
  printf("Set the 4 digit PIN for your account: ");
  for(k=0;k<4;k++)
   {
     ch=getch();
     printf("*");
     ch=ch-48;
     fpass=fpass*10+ch;
   }
  printf("\nconform your PIN: ");

  for(k=0;k<4;k++)
   {
     ch=getch();
     printf("*");
     ch=ch-48;
     cpass=cpass*10+ch;
   }
  if(fpass!=cpass)
  {
    printf("\nPIN not match!\nTry again..");
  }
  else
  {
  password=fpass;
  printf("\nenter the amount you want to deposite: ");
  scanf("%f",&balance);
  data=fopen("DATA.txt","a+");
  if(data==NULL)
   {
     printf("something went wrong!");
     exit(1);
   }
  fprintf(data,"\n%d %f",password,balance);
  printf("\nyour account is created successfully!");
  fclose(data);
  }
  printf("\n\npress (N) for creating new account..");
  printf("\npress (H) for home menu...\nfor exit press any key...");
  choice=getch();
  if(choice>=65&&choice<=90)
   choice=choice+32;
  }while(choice=='n');

}


void login()
{
  FILE * data=NULL;
  char option,ch;
  int password[10];
  int pass=0,j,i=0,k;
  float balance[10];
  float deposite,withdrawal;

  //do{
  pass=0;
  i=0;
  clrscr();
  data=fopen("DATA.txt","r");
  if(data==NULL)
   {
     printf("something went wrong!\ndata not found.");
   }
  else
  {

  while(!feof(data))
  {
    fscanf(data,"%d",&password[i]);
    fscanf(data,"%f",&balance[i]);
   // printf("%d\t%f\n",password[i],balance[i]);

    i++;
  }
  j=i-1;
  fclose(data);
  printf("enter your PIN: ");
  for(k=0;k<4;k++)
   {
     ch=getch();
     printf("*");
     ch=ch-48;
     pass=pass*10+ch;
   }

  i=0;
  while(password[i]!=pass)
  {
    i++;
    if(i==10)
     break;
  }

  if(i==10)
   printf("\nworng password");
  else
  {
    clrscr();
    printf("\nfor balance check press (B)\nfor deposite money press (D)\nfor withdrawal press (W)\nfor PIN change press (P)\n");
    option=getch();
    clrscr();
    if(option>=65&&option<=90)
     option=option+32;
    switch(option)
    {
      case 'b':
	printf("your balance is: %f",balance[i]);
	break;
      case 'd':
	printf("enter the amount: ");
	scanf("%f",&deposite);
	balance[i]=balance[i]+deposite;
	break;
	      case 'w':
	printf("enter the amount: ");
	scanf("%f",&withdrawal);
	if(withdrawal>balance[i])
	 printf("you don't have enough balance");
	else
	 balance[i]=balance[i]-withdrawal;
	break;
      case 'p':
	printf("enter your new PIN: ");
	scanf("%d",&password[i]);
	printf("your PIN is changed\n");
	break;
      default:
	printf("wrong input!");
    }
  }

  data=fopen("DATA.txt","w");
  fprintf(data,"\n");
  for(i=0;i<j;i++)
   {
     fprintf(data,"%d %f\n",password[i],balance[i]);
     //printf("\n%d %f\n",password[i],balance[i]);
   }
  fprintf(data,"%d %f",password[i],balance[i]);
  //printf("%d %f",password[i],balance[i]);
  fclose(data);
 }
 //printf("\n\npress (B) for back to menu..");
 printf("\npress (H) for home menu...\nfor exit press any key...");
 choice=getch();
 if(choice>=65&&choice<=90)
  choice=choice+32;
 //}while(choice=='b');

}

