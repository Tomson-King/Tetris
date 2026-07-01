#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"menu.h"


int key_move(int a){
  int x;
   switch(a){
      case 119: x=-1;
               break;
      case 115:x=1;
               break;
      case 13:x=0;
               break;
      default:x=2;
   }
   return x;

 }

  void Main_Menu(){
   int opt=1,mv,a;
   while(1){
       Print_main_menu(opt);
     while(1){
      mv=getch();
      a=key_move(mv);
     switch(a){
       case -1: opt-=1;
               if(opt==-1)
                 opt=2;
                system("cls");
               Print_main_menu(opt);
               break;
      case 1:opt+=1;
              if(opt==3)
                opt=0;
              system("cls");
              Print_main_menu(opt);
              break;
       case 0:break;
       default:system("cls");
       Print_main_menu(opt);

     }
     if(mv==13)
       break;
     }
     system("cls");
     switch(opt){
       case 1:start_game();
              break;
       case 2:rules();
              break;
       case 0:exit_game();
              break;
      
       default:continue;
     }
     if(opt==5)
       break;
   }
 }


void Print_main_menu(int opt){
    // Code to display the main menu and handle user input
    system("cls");
      printf("\n\n\tTETRIS\t");
   if(opt==1)
   printf("\n<");
  else
     printf("\n");
  printf("Start Game");
  
   if(opt==1)
   printf(">");
   
   if(opt==2)
   printf("\n<");
   else
     printf("\n");
  printf("Rules");
   
   if(opt==2)
   printf(">");
   if(opt==0)
   printf("\n<");
   else
  printf("\n");
   printf("Exit");

   if(opt==0)
   printf(">");


   printf("\n\nUse W and S to navigate the menu and press Enter to select an option.");
  
}


void start_game(){

    // Code to start the game
    printf("Starting the game...");
   // setup_board();
    
    printf("\nPress any key to continue...");
    getch();
    system("cls");
    // You can add your game logic here
 // game();
}

void rules(){
    // Code to display the game rules
    printf("Game Rules:");
    printf("\n");
    printf("\nPress any key to return to the main menu...");
    getch();
    system("cls");
}

void exit_game(){
    // Code to exit the game
    printf("Exiting the game...");
    exit(0);
}

