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

struct shapes shape[7];
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

//checking shape
shape[6].pos[0][0] = 1;
shape[6].pos[0][1] = 1;
shape[6].pos[0][2] = 1;
shape[6].pos[0][3] = 0;
shape[6].pos[1][0] = 1;
shape[6].pos[1][1] = 1;
shape[6].pos[1][2] = 1;
shape[6].pos[1][3] = 0;
shape[6].pos[2][0] = 0;
shape[6].pos[2][1] = 0;
shape[6].pos[2][2] = 0;
shape[6].pos[2][3] = 0;
shape[6].pos[3][0] = 0;
shape[6].pos[3][1] = 0;
shape[6].pos[3][2] = 0;
shape[6].pos[3][3] = 0;
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

void remove_row(struct board* previous){
    struct board* p=previous->link;
    previous->link=p->link;
    free(p);

}

int get_count(struct board* last){
    int count=0;
    struct board* p=last;
    while(p!=NULL){
    count++;
    p=p->link;
    }
    return count;
}

struct board* get_row(int row,struct board* last){
     for(int a=b_len+shp_siz;a>0;a--){
            if(a==row)
            return last;
            last=last->link;
        }
        return last;
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
            cursor.pos[i][j]=shape[shape_no].pos[i][j]*2;
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
 int get_size(){
    int size=0,temp=0;
    for(int i=0;i<shp_siz;i++){
            
        for(int j=0;j<shp_siz;j++){
         if(cursor.pos[i][j]>=1)
         temp=j+1;
        }
        if(temp>=size)
            size=temp;
        temp=0;
    }
    return size;
}
 int print_cursor(int row,int col,int size,int i,int j){
    int value=0;
if(row!=-1&&(i<=row&&i>row-shp_siz)&&(j>=col&&j<col+size)){
        i=shp_siz-1-(row-i);
        j=(j-col);
     if(cursor.pos[i][j]==0)
            value=1;
            else
            printf("0");
}
else{
    value=1;
}
return value;
 } 

 void print_board(struct board* last,int row,int col,int size){
    system("cls");
    int i,j,k;
    struct board* current=get_row(b_len,last);
    for(i=b_len;i>0;i--){
       
        printf("||");
        for(j=0;j<b_wdt;j++){
            if(print_cursor(row,col,size,i,j)){
            if(current->column[j]==0)
            printf(" ");
            else
            printf("+");
            }
            
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

        current=current->link;
        printf("\n");
    }


}


 int check_board(int col,int size,struct board* last){
    int temp[shp_siz][shp_siz],i,j,row;
    
    struct board* p=last;
    
    for(row=b_len+shp_siz;row>=shp_siz;row--){
        struct board* current=p;
        for(i=shp_siz-1;i>-1;i--){
            for(j=0;j<size;j++){
                temp[i][j]=current->column[col+j];
            }
            current=current->link;
        }

        for(i=0;i<shp_siz;i++){
            for(j=0;j<shp_siz;j++){
                if(temp[i][j]+cursor.pos[i][j]==3)
                break;
            }
            if(temp[i][j]+cursor.pos[i][j]==3)
            break;
        }

        
    if(temp[i][j]+cursor.pos[i][j]==3){
        row++;
        break;
    }
     p=p->link;
    }
  if(row==3)
  row=4;
    
return row;
 }

 struct board* update_board(int row,int col,int size,struct board* last){
    int i,j,a;
        //printf("\n\nstarted updating");
       struct board* current;
        struct board* p;
    
       current=get_row(row,last);

      for(i=shp_siz-1;i>-1;i--){
           
            for(j=0;j<size;j++){
              current->column[j+col]=current->column[j+col]+cursor.pos[i][j];
              if(current->column[j+col]!=0)
              current->column[j+col]=1;
            }
            current=current->link;

        }
       // printf("\nCompleted phase 1");
        current=last;
       while(1){
            p=current;
            current=current->link;
            if(current==NULL)
            break;
        a=0;
        for(j=0;j<b_wdt;j++){
            a=a+current->column[j];
        }
        if(a>=b_wdt){
            remove_row(p);
            current=p;
        }        
        }
       // printf("\nCompleted phase 2");
       // print_board(last);
        if(get_count(last)<b_len+shp_siz){
        for (i=get_count(last);get_count(last)<b_len+shp_siz;i++)
        last=add_row(last);
        }
        //printf("\nCompleted phase 3");
        return last;
 }




int check_lose(struct board* last){
    last=get_row(b_len+1,last);
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
    struct board* last=NULL;
    last=set_board();
    int key,col=0,temp=0,size=0,i,j,row=-1;
    set_shapes();
    do{
        col=0,row=-1;
        
        get_cursor(rand_shape());
        //get_cursor(6);
        size=get_size();
        row=check_board(col,size,last);
      
   
     print_board(last,row,col,size);
         printf("Use 'a' to move shape left or 'd' to move shape right,\n Use 'r' to rotate,press enter to continue  ");
      
        while(1){
             //printf("\n row-%d col-%d size-%d",row,col,size);
            
            key=getch();
            if(key==13)
            break;
            if(key=='a'){
                if(col==0)
                col=b_wdt-size;
                else
                col=col-1;
            }
            if(key=='d'){
                if(col==(b_wdt-size))
                col=0;
                else
                col=col+1;
            }
            if(key=='r'){
                rotate();
                size=get_size();
                if(col>(b_wdt-size))
                col=b_wdt-size;
            }
            row=check_board(col,size,last);
         print_board(last,row,col,size);
         printf("Use 'a' to move shape left or 'd' to move shape right,\n Use 'r' to rotate,press enter to continue");
        }
       
        if(key==13){
             
        last=update_board(row,col,size,last);
       // key=getch();
        }

        if(check_lose(last)==1){
        END(last);
        return;
        }
    }while(1);   
}