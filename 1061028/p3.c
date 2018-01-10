/*
 *  Created on: 2018年1月2日
 *   大學程式設計先修檢測_1061028（APCS）
 *     Author: 艾鍗學院
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */
#include <stdio.h>
#define TEST 1
#define ROW 10 
unsigned int h(unsigned int t[][ROW], unsigned int node);
 
int main()
{
  #if TEST 

  unsigned int i,j;
  unsigned int height=0;
  unsigned int hi,most_hi=0;
  int root=1;
  //Examle1: 
/*
  unsigned int n=8;       
  
  unsigned int T[8][8]={ 
               {7},
               {0}, 
               {2,6,7},
               {2,1,4},
               {0},
               {2,3,2},
               {0},
               {0}
               };.
  */
  //Example2:
  
    unsigned int n=10;
  //should change --> #define ROW 10    
  unsigned int T[10][10]={ 
               {9},
               {1,6},
               {3,5,3,8},
               {0},
               {2,1,7},
               {1,9},
               {0},
               {1,2},   
               {0},
               {0}
               };
  

  #else
    //如何做成態度記憶體配置malloc 及填到陣列中, 交給你囉! 
   
   //get_input
   scanf("%d",&n); //for n
   scanf("%d",&dir); //for dir
   for (i=0;i<n;i++)  
     for (j=0;j<n;j++)
        scanf("%d",&T[i][j]); 
 
  #endif

  for (i=1;i<n;i++){
     hi=h(T,i);
     if (hi > most_hi) {
        most_hi=hi;
        root=i;
     }
     
     printf("the height of node %d =%ld\n",i,hi); 
     height+=hi;
   }

   printf("%ld\n",root);
     printf("%ld\n",height);
   
   system("PAUSE");
  return 0;
}

unsigned int h(unsigned int t[][ROW], unsigned int node)
{
    unsigned int height=0;
    unsigned int i=0;
    int temp;
    
    if (t[node][0]==0) {
             return 0; //leaf node
    } else  {
       for (i=1;i<=t[node][0];i++) {
            temp=h(t,t[node][i])+1;
           if (temp > height)  height=temp;

          }     
          // printf("height of node[%ld]=%ld,i=%ld\n",node,height,i);
           return height;   
           
    }     
          
}


