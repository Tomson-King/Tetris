#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"menu.h"
#include"Gameengine.h"
#define b_len 16
#define b_wdt 8
#define shp_siz 4

struct shapes {
    int pos[shp_siz][shp_siz];
};
struct board{
    int column[b_wdt];
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


//shape shp_siz
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
    for(int i=0;i<b_wdt;i++)
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
    
    for(int i=2;i<=b_len+shp_siz;i++){
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
        for(int i=0;i<shp_siz;i++){
        for(int j=0;j<shp_siz;j++){
            cursor.pos[i][j]=shape[shape_no].pos[i][j];
        }
    }
}

 void rotate(){
    int temp[shp_siz][shp_siz];
    for(int i=0;i<shp_siz;i++){
        for(int j=0;j<shp_siz;j++){
            temp[i][j]=cursor.pos[j][3-i];
        }
    }
   
     while(temp[0][0]+temp[1][0]+temp[2][0]+temp[3][0]==0){
         for(int i=0;i<shp_siz;i++){
        for(int j=0;j<shp_siz;j++){
            if(j!=3)
           temp[i][j]= temp[i][j+1];
           else
           temp[i][j]= 0;
        }
    }
    }
     while(temp[0][0]+temp[0][1]+temp[0][2]+temp[0][3]==0){
         for(int i=0;i<shp_siz;i++){
        for(int j=0;j<shp_siz;j++){
            if(i!=3)
           temp[i][j]= temp[i+1][j];
           else
           temp[i][j]= 0;
        }
    }
    }
     for(int i=0;i<shp_siz;i++){
        for(int j=0;j<shp_siz;j++){
           cursor.pos[i][j]= temp[i][j];
        }
    }
    
 }

 int check_board(int col,int size,struct board* last){
    int temp[shp_siz][shp_siz],stop=0,i,j,row=3,a,block;
    do{
        row++;
        stop=0;
        struct board* current=last->link;
        for(a=1;a<b_len-row;a++){
            current=current->link;
        }

        for(i=0;i<shp_siz;i++){
            block=0;
            for(j=col+size-1;j>=col;j--){
                if(current->column[j]!=0)
                block=1;
                temp[i][j-col]=block;
            }
            current=current->link;

        }
    
       
    for(i=0;i<shp_siz;i++){
        for(j=0;j<size;j++){
          if(cursor.pos[i][j]+temp[i][j]==2){
            stop=1;
          }
        }
    }
    
}while(stop==1);
return row;
 }

 struct board* update_board(int row,int col,int size,struct board* last){
    int i,j,a;
    
       struct board* current=last->link;
       struct board* p;

    for(a=1;a<b_len-row;a++){
            current=current->link;
        }
         for(i=0;i<shp_siz;i++){
           
            for(j=col+size-1;j>=col;j--){
              current->column[j]=cursor.pos[i][j-col];
            }
            current=current->link;

        }
        current=last;
        for(i=1;i<=b_len;i++){
            p=current;
            current=p->link;
        a=0;
        for(j=0;j<b_wdt;j++){
            a=a+current->column[j];
        }
        if(a==8){
            remove_row(p);
        }
        }
        for (i=get_count(last);i<=b_len;i++)
        last=add_row(last);

        return last;
 }


void print_board(struct board* last){
    system("cls");
    int i,j,k;
    for(i=b_len+shp_siz;i>0;i--){
        if(i>b_len){
            last=last->link;
        continue;
        }
        printf("||");
        for(j=0;j<b_wdt;j++){
            if(last->column[j]==0)
            printf(" ");
            else
            printf("*");
        }
        printf("||    ");
        if((i>=b_len-((shp_siz+1)*2))&&(i<b_len)){
            if((i==b_len-((shp_siz+1)*2))||(i==b_len-1))
            printf("==========");
          
          else{
            k=((i+1)/2)-shp_siz;
            printf("|");
            for(j=0;j<shp_siz;j++){
            
                
               if(cursor.pos[k][j]==0)
               printf("  ");
               else
               printf("==");
               
            }  
            printf("|");
         
        }          
        }

        last=last->link;
        printf("\n");
    }


}

int check_lose(struct board* last){
    int sum =0;
    for(int i=0;i<shp_siz;i++){
        for(int j=0;j<b_wdt;j++){
            sum=sum+last->column[j];        
        }
    }
    if(sum!=0)
    sum=1;
    return sum;
}

void game(){
    struct board* last=set_board();
    int key,col=0,temp=0,size=0,i,j,row=shp_siz;
    set_shapes();
        get_cursor(rand_shape());
        print_board(last);
        printf("Use 'r' to rotate,press enter to continue");
        key=getch();
        while(key=='r'){
        rotate();
        print_board(last);
        printf("Use 'r' to rotate,press enter to continue");
        key=getch();
        
        }
       
         for(i=0;i<shp_siz;i++){
            
        for(j=0;j<shp_siz;j++){
         if(cursor.pos[i][j]>=1)
         temp=j+1;
        }
        if(temp>=size)
            size=temp;
        temp=0;
    }
     print_board(last);
         printf("Use 'a' to move shape left or 'd' to move shape right,press enter to continue");
        while(1){
             //printf("row-%d col-%d",row,col);
            
            key=getch();
            if(key==13)
            break;
            if(key=='a'){
                if(col==0)
                col=b_wdt-size-1;
                else
                col=col-1;
            }
            if(key=='d'){
                if(col==(b_wdt-size-1))
                col=0;
                else
                col=col+1;
            }
            row=check_board(col,size,last);
        print_board(last);
         printf("Use 'a' to move shape left or 'd' to move shape right,press enter to continue");
        }
       
        if(key==13){
             
        last=update_board(row,col,size,last);
        }

        if(check_lose(last)==1){
        END(last);
        return;
        }
       
}