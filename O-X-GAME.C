#include<stdio.h>
#include<conio.h>
void multiplayer();
void computer();
char ch;
void main()
{
  void (*ptr[2])()={computer,multiplayer};
  char option;
  do{
  option=NULL;
  clrscr();
  printf("\t\twelcome to tic tac toe game\n");
  printf("\npress any key to start....");
  getch();
  clrscr();
  printf("\nchose game mode: ");
  printf("\n1.>with computer");
  printf("\n2.>with friends");
  option=getch();
  (*ptr[option-49])();
  }while(ch=='h');
}


void computer()
{
  char board[9]={0},winner=NULL;
  int i=0,j,user_in,flag=1;
  do{
winner=NULL;
  for(i=0;i<9;i++)
   board[i]=NULL;
  i=0;

  do{
  clrscr();
  printf("\nyour\t\tcomputer\n  O\t\t  X");
  printf("\n\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
  do{
    flag=1;
    printf("\n\nyour turns enter where you want to put\n1  2  3\n4  5  6\n7  8  9\n");
    scanf("%d",&user_in);
    if(board[user_in-1]==NULL)
      board[user_in-1]='O';
    else
    {
      printf("\nput in valid place");
      flag=0;
    }
    }while(flag==0);
  if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=NULL)
  {
    if(board[3]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=NULL)
  {
    if(board[6]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=NULL)
  {
    if(board[1]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
     winner='X';
    goto out;
  }

  if(i==4)
    goto next;
  if(board[0]==board[1]&&board[2]==NULL&&board[1]!=NULL)
    board[2]='X';
  else if(board[0]==board[2]&&board[1]==NULL&&board[0]!=NULL)
    board[1]='X';
  else if(board[1]==board[2]&&board[0]==NULL&&board[1]!=NULL)
    board[0]='X';

  else if(board[3]==board[4]&&board[5]==NULL&&board[3]!=NULL)
    board[5]='X';
  else if(board[3]==board[5]&&board[4]==NULL&&board[3]!=NULL)
    board[4]='X';
  else if(board[4]==board[5]&&board[3]==NULL&&board[4]!=NULL)
    board[3]='X';

  else if(board[6]==board[7]&&board[8]==NULL&&board[6]!=NULL)
    board[8]='X';
  else if(board[6]==board[8]&&board[7]==NULL&&board[6]!=NULL)
    board[7]='X';
  else if(board[7]==board[8]&&board[6]==NULL&&board[7]!=NULL)
    board[6]='X';

  else if(board[0]==board[3]&&board[6]==NULL&&board[0]!=NULL)
    board[6]='X';
  else if(board[0]==board[6]&&board[3]==NULL&&board[0]!=NULL)
    board[3]='X';
  else if(board[3]==board[6]&&board[0]==NULL&&board[3]!=NULL)
    board[0]='X';

  else if(board[1]==board[4]&&board[7]==NULL&&board[1]!=NULL)
    board[7]='X';
  else if(board[1]==board[7]&&board[4]==NULL&&board[1]!=NULL)
    board[4]='X';
  else if(board[4]==board[7]&&board[1]==NULL&&board[4]!=NULL)
    board[1]='X';

  else if(board[2]==board[5]&&board[8]==NULL&&board[2]!=NULL)
    board[8]='X';
  else if(board[2]==board[8]&&board[5]==NULL&&board[2]!=NULL)
    board[5]='X';
  else if(board[5]==board[8]&&board[2]==NULL&&board[5]!=NULL)
    board[2]='X';

  else if(board[0]==board[4]&&board[8]==NULL&&board[0]!=NULL)
    board[8]='X';
  else if(board[0]==board[8]&&board[4]==NULL&&board[0]!=NULL)
    board[4]='X';
  else if(board[4]==board[8]&&board[0]==NULL&&board[4]!=NULL)
    board[0]='X';

  else if(board[2]==board[4]&&board[6]==NULL&&board[2]!=NULL)
    board[6]='X';
  else if(board[2]==board[6]&&board[4]==NULL&&board[2]!=NULL)
    board[4]='X';
  else if(board[4]==board[6]&&board[2]==NULL&&board[4]!=NULL)
    board[2]='X';

   else if(board[4]=='O'&&(board[0]==NULL||board[2]==NULL||board[6]==NULL||board[8]==NULL))
   {
     for(j=0;j<=8;j++)
     {
       if(board[j]==NULL)
       {
	 board[j]='X';
	 break;
       }
       j++;
     }
   }

  else if(board[0]=='O'||board[2]=='O'||board[6]=='O'||board[8]=='O')
   {
    if(board[4]==NULL)
      board[4]='X';
    else
    for(j=1;j<=8;j++)
     {
       if(board[j]==NULL)
       {
	 board[j]='X';
	 break;
       }
       j++;
     }
   }
  else
   {
     for(j=0;j<=8;j++)
     {
       if(board[j]==NULL)
       {
	 board[j]='X';
	 break;
       }
       j++;
     }
   }

  next:

  if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=NULL)
  {
    if(board[3]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=NULL)
  {
    if(board[6]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=NULL)
  {
    if(board[1]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
     winner='X';
    goto out;
  }
  i++;
  }while(i<5);
  out:
  clrscr();
  printf("\nplayer 1\tcomputer\n  O\t\t  X");
  printf("\n\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
  if(winner=='O')
    printf("\nyou won!");
  else if(winner=='X')
    printf("\ncomputer win!");
  else
    printf("\ndraw");


  printf("\n\ndo you want to play again press (Y)...\nfor home meanu press(H)...\nfor exit press any key...");
  ch=getch();
  if(ch>=65&&ch<=90)
    ch=ch+32;
  }while(ch=='y');


}


void multiplayer()
{
  char board[9]={0},winner=NULL;
  int i=0,user_in,flag=1;
  do{
winner=NULL;
  for(i=0;i<9;i++)
   board[i]=NULL;
  i=0;

  do{
  clrscr();
  printf("\nplayer 1\t\tplayer 2\n  O\t\t  X");
  printf("\n\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
  if(i%2==0)
  {
    do{
    flag=1;
    printf("\n\nplayer 1 turns enter where you want to put\n1  2  3\n4  5  6\n7  8  9\n");
    scanf("%d",&user_in);
    if(board[user_in-1]==NULL)
      board[user_in-1]='O';
    else
    {
      printf("\nput in valid place");
      flag=0;
    }
    }while(flag==0);
  if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=NULL)
  {
    if(board[3]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=NULL)
  {
    if(board[6]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=NULL)
  {
    if(board[1]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
     winner='X';
    goto out;
  }
  }
  else
  {
    do{
    flag=1;
    printf("\n\nplayer 2 turns enter where you want to put\n1  2  3\n4  5  6\n7  8  9\n");
    scanf("%d",&user_in);
    if(board[user_in-1]==NULL)
      board[user_in-1]='X';
    else
    {
      printf("\nput in valid place");
      flag=0;
    }
    }while(flag==0);
  }
  if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=NULL)
  {
    if(board[3]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=NULL)
  {
    if(board[6]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=NULL)
  {
    if(board[1]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=NULL)
  {
    if(board[0]=='O')
      winner='O';
    else
      winner='X';
    goto out;
  }

  if(board[2]==board[4]&&board[4]==board[6]&&board[2]!=NULL)
  {
    if(board[2]=='O')
      winner='O';
    else
     winner='X';
    goto out;
  }
  i++;
  }while(i<9);
  out:
  clrscr();
  printf("\nplayer 1\t\tplayer 2\n  O\t\t\t  X");
  printf("\n\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n",board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
  if(winner=='O')
    printf("\nwinner is player 1");
  else if(winner=='X')
    printf("\nwinner is player 2");
  else
    printf("\ndraw");


  printf("\n\ndo you want to play again press (Y)...\nfor home meanu press(H)...\nfor exit press any key...");
  ch=getch();
  if(ch>=65&&ch<=90)
    ch=ch+32;
  }while(ch=='y');

}

