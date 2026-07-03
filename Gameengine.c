#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"menu.h"
#include"Gameengine.h"

struct shapes {
    int pos[4][4];
};
struct board{
    int column[8];
    struct board *link;
};

struct shapes shape[6];
struct shapes cursor;

void set_shapes(){
//shape 1
shape[0].pos[0][0]=1;
shape[0].pos[0][1]=1;
shape[0].pos[0][2]=1;
shape[0].pos[0][3]=0;
shape[0].pos[1][0]=0;
shape[0].pos[1][1]=1;
shape[0].pos[1][2]=0;
shape[0].pos[1][3]=0;
shape[0].pos[2][0]=0;
shape[0].pos[2][1]=0;
shape[0].pos[2][2]=0;
shape[0].pos[2][3]=0;
shape[0].pos[3][0]=0;
shape[0].pos[3][1]=0;
shape[0].pos[3][2]=0;
shape[0].pos[3][3]=0;


//shape 2
shape[1].pos[0][0]=1;
shape[1].pos[0][1]=0;
shape[1].pos[0][2]=0;
shape[1].pos[0][3]=0;
shape[1].pos[1][0]=1;
shape[1].pos[1][1]=1;
shape[1].pos[1][2]=0;
shape[1].pos[1][3]=0;
shape[1].pos[2][0]=0;
shape[1].pos[2][1]=1;
shape[1].pos[2][2]=0;
shape[1].pos[2][3]=0;
shape[1].pos[3][0]=0;
shape[1].pos[3][1]=0;
shape[1].pos[3][2]=0;
shape[1].pos[3][3]=0;


//shape 3
shape[2].pos[0][0]=0;
shape[2].pos[0][1]=1;
shape[2].pos[0][2]=0;
shape[2].pos[0][3]=0;
shape[2].pos[1][0]=1;
shape[2].pos[1][1]=1;
shape[2].pos[1][2]=0;
shape[2].pos[1][3]=0;
shape[2].pos[2][0]=1;
shape[2].pos[2][1]=0;
shape[2].pos[2][2]=0;
shape[2].pos[2][3]=0;
shape[2].pos[3][0]=0;
shape[2].pos[3][1]=0;
shape[2].pos[3][2]=0;
shape[2].pos[3][3]=0;


//shape 4
shape[3].pos[0][0]=1;
shape[3].pos[0][1]=1;
shape[3].pos[0][2]=1;
shape[3].pos[0][3]=1;
shape[3].pos[1][0]=0;
shape[3].pos[1][1]=0;
shape[3].pos[1][2]=0;
shape[3].pos[1][3]=0;
shape[3].pos[2][0]=0;
shape[3].pos[2][1]=0;
shape[3].pos[2][2]=0;
shape[3].pos[2][3]=0;
shape[3].pos[3][0]=0;
shape[3].pos[3][1]=0;
shape[3].pos[3][2]=0;
shape[3].pos[3][3]=0;


//shape 5
shape[4].pos[0][0]=1;
shape[4].pos[0][1]=1;
shape[4].pos[0][2]=0;
shape[4].pos[0][3]=0;
shape[4].pos[1][0]=1;
shape[4].pos[1][1]=1;
shape[4].pos[1][2]=0;
shape[4].pos[1][3]=0;
shape[4].pos[2][0]=0;
shape[4].pos[2][1]=0;
shape[4].pos[2][2]=0;
shape[4].pos[2][3]=0;
shape[4].pos[3][0]=0;
shape[4].pos[3][1]=0;
shape[4].pos[3][2]=0;
shape[4].pos[3][3]=0;


//shape 6
shape[5].pos[0][0]=1;
shape[5].pos[0][1]=1;
shape[5].pos[0][2]=0;
shape[5].pos[0][3]=0;
shape[5].pos[1][0]=1;
shape[5].pos[1][1]=0;
shape[5].pos[1][2]=0;
shape[5].pos[1][3]=0;
shape[5].pos[2][0]=1;
shape[5].pos[2][1]=0;
shape[5].pos[2][2]=0;
shape[5].pos[2][3]=0;
shape[5].pos[3][0]=0;
shape[5].pos[3][1]=0;
shape[5].pos[3][2]=0;
shape[5].pos[3][3]=0;
}

//linked list funtions
struct board* add_row (struct board*current){

}

void set_board(){
    for(int i=0;i<16;i++){
        for(int j=0;j<8;j++){
          
        }
    }
}

int rand_shape(){
        // Code to get a shape
    
    srand(time(NULL));
    int diceValue = (rand() % 6);
    return diceValue;
}



void get_cursor(int shape_no,struct shapes cursor){
        for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cursor.pos[i][j]=shape[shape_no].pos[i][j];
        }
    }
}






void game(){
    set_board();
    set_shapes();
    do{
        print_board();

    }while(1);
}