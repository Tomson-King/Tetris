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
struct board* add_row (struct board* last){
    struct board* p;
    p=(struct board*)malloc(sizeof (struct board));
    p->link=last;
    for(int i=0;i<8;i++)
    p->column[i]=0;
    return p;

}

void remove_row(struct board* current){
    struct board* p=current->link;
    current->link=p->link;
    free(p);

}

int get_count(struct board* last){
    int count=1;
    struct board* p=last->link;
    while(p!=NULL)
    count++;
    return count;
}

void END(struct board* last){
   
    struct board* p=last;
    while(last!=NULL){
        p=p->link;
        free(last);
        last=p;
    }
    
}

struct board* set_board(){
    struct board* last=NULL;
    last=add_row(last);
    
    for(int i=2;i<=16;i++){
        last=add_row(last);
    }
    return last;
}

int rand_shape(){
        // Code to get a shape
    
    srand(time(NULL));
    int shape_no = (rand() % 6);
    return shape_no;
}



void get_cursor(int shape_no){
        for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cursor.pos[i][j]=shape[shape_no].pos[i][j];
        }
    }
}

 void rotate(){
    int temp[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp[i][j]=cursor.pos[j][3-i];
        }
    }
   
     while(temp[0][0]+temp[1][0]+temp[2][0]+temp[3][0]==0){
         for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(j!=3)
           temp[i][j]= temp[i][j+1];
           else
           temp[i][j]= 0;
        }
    }
    }
     while(temp[0][0]+temp[0][1]+temp[0][2]+temp[0][3]==0){
         for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=3)
           temp[i][j]= temp[i+1][j];
           else
           temp[i][j]= 0;
        }
    }
    }
     for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
           cursor.pos[i][j]= temp[i][j];
        }
    }
    
 }

 void check_board(){
    int temp[4][4],stop=0;
    do{  
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
          if(cursor.pos[i][j]+temp[i][j]==2){
            stop=1;
          }
        }
    }
}while(stop==1)
 }


void print_board(struct board* last){
    system("cls");
    int i,j,k;
    for(i=0;i<16;i++){
        printf("||");
        for(j=0;j<8;j++){
            if(last->column[j]==0)
            printf(" ");
            else
            printf("*");
        }
        printf("||    ");
        if((i<11)&&(i>0)){
          if((i==1)||(i==10)){
            printf("==========");
          }
          else{
            k=4-(i/2);
            printf("|");
            for(j=0;j<4;j++){
                
               if(cursor.pos[k][j]==0)
               printf("  ");
               else
               printf("##");
               
            }  
            printf("|");
        }          
        }

        
        printf("\n");
    }


}



void game(){
    struct board* last=set_board();
    int temp;
    set_shapes();
        get_cursor(rand_shape());
        print_board(last);
        temp=getch();
        while(temp=='r'){
        rotate();
        print_board(last);
        temp=getch();
        }

        END(last);
       
}