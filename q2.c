/*
 *  Created on: 2017年8月20日
 *   大學程式設計先修檢測（APCS）
 *      Author: 艾鍗學院 
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */

#include <stdio.h>
#define TEST 1

int find_group(int *a,int *b,int index);
int main()
{
   int i;
   int g=0;
   int n;
   int y[1000]={0};      
   
  #if TEST 
  int x[]={4,7,2,9,6,0,8,1,5,3}; 
  //int x[]={0,2,1}; 
  n=sizeof(x)/sizeof(x[0]);

  #else
   int x[1000]={0}; 
   //get_input
   scanf("%d",&n); //for n
   for (i=0;i<n;i++) { //for relation-ship
     scanf("%d",&x[i]); 
   }
   
  #endif

   for (i=0;i<n;i++)   
    if (y[i]==0) {
        g++;
        find_group(x,y,i);  
    }
      
   printf("%d\n",g);     
   system("PAUSE");
  return 0;
}


int find_group(int *a,int *b,int index)
{
    int i=index;
    int my_friend;
    my_friend=a[i];
 
    while (my_friend!=i) {
     b[my_friend]=1;    //visited
     my_friend=a[my_friend];    
   }

    
}
