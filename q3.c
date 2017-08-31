/*
 *  Created on: 2017年8月20日
 *   大學程式設計先修檢測（APCS）
 *   Author: 艾鍗學院
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */

#include <stdio.h>
#define TEST 0
int x,y;
void move(int dir);

#define LEFT   do{y--;}while(0)
#define RIGHT  do{y++;}while(0)
#define UP     do{x--;}while(0)
#define DOWN   do{x++;}while(0)

int main()
{
   int i;
   int j;
   int b=1;
   int n;
   int dir=0;
   int finish=0;

  #if TEST 
  n=5;
  int a[5][5]={ {3,4,2,1,4},
                {4,2,3,8,9},
                {2,1,9,5,6},
                {4,2,3,7,8},
                {1,2,6,4,3}      
               };
  

  #else
   int a[100][100]={0}; 
   //get_input
   scanf("%d",&n); //for n
   scanf("%d",&dir); //for dir
   for (i=0;i<n;i++)  
     for (j=0;j<n;j++)
        scanf("%d",&a[i][j]); 
 
  #endif
   x=n/2;y=n/2;
   printf("%d",a[x][y]);
   
  //clock-wise rotation   
   i=1;
   j=b;
   int k=0;
   while(i<=n*n) {
     
    while(j && !finish) {
    move(dir);
    printf("%d",a[x][y]);   
    j--;     
    if (++i==n*n) finish=1;
    }
                      
    if (j==0) {     
       k++;
       dir=(dir+1)%4; 
       j=b;
       if (k==2){
         j=b+1; 
         k=0;
         b++;
      }
    }            
}
   printf("\n");
   system("PAUSE");
  return 0;
}

void move(int dir)
{
   switch (dir) {
     case 0: //left
       LEFT; break;
     case 1: //up
       UP;  break;
     case 2: //right
       RIGHT;  break;
     case 3: //down
       DOWN;  break;
       
  }   

}
