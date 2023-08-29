#include<stdio.h>
#include<conio.h>
#include<time.h>
void main()
{
  int input,count,random,flag;
  char mode,ch;
  do{
  count=0;
  clrscr();
  do{
  flag=0;
  printf("\t\tGuess the number!\n\n");
  printf("select the game mode...\n");
  printf("1.>1 to 10\n2.>1 to 100\n3.>1 to 1000");
  mode=getch();
  srand(time(0));
  switch(mode)
  {
    case '1':
     random=rand()%10;
     flag=1;
     break;
    case '2':
     random=rand()%100;
     flag=1;
     break;
    case '3':
     random=rand()%1000;
     flag=1;
     break;
    default:
     printf("\nplese enter the rigth game mode");
  }

  }while(flag!=1);
  clrscr();
  do{
     printf("\nwhat you guess: ");
     scanf("%d",&input);
     if(input>random)
      printf("you guess high\n");
     if(input<random)
      printf("you guess low\n");
      count++;
    }while(input!=random);
  printf("\nyou guess right");
  printf("\nyou guess the number in %d attempt",count);


  printf("\n\n\ndo you want to play again(Y/N)...\nfor exit press any key");
  ch=getch();
  if(ch>=65&&ch<=90)
   ch=ch+32;
  }while(ch=='y');

}