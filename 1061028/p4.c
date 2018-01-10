/*
 *  Created on: 2018年1月2日
 *   大學程式設計先修檢測_1061028（APCS）
 *     Author: 艾鍗學院
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */
#include <stdio.h>
#define TEST 0


void show_array(int *a,int size);
void sort( int a[], int n );
#define SWAP(a,b)   { int t; t=a; a=b; b=t; }
int *cost;
int main()
{
    
  int n;
  int i;
  int total_weight=0;
  int total_power=0;
  int W=0;
  int item;
   
  #if TEST 

  n=3;
  int weight[10]={3,4,5};
  int freq[10]={1,2,3};
  

  #else

   int *weight;
   int *freq;
  
   scanf("%d",&n); //for number of items
   weight=(int *)malloc(n*sizeof(int));
   freq=(int *)malloc(n*sizeof(int));
    
   for (i=0;i<n;i++)
      scanf("%ld",&weight[i]);
   for (i=0;i<n;i++)
      scanf("%ld",&freq[i]);  

  #endif
  
  for (i=0;i<n;i++) {
      total_weight+=weight[i];
   }
  
   cost=(int *)malloc(n*sizeof(int));
   int *rank=(int *)malloc(n*sizeof(int));
  
  
  for (i=0;i<n;i++) {
     cost[i]=(total_weight-weight[i])*freq[i];
     rank[i]=i;
  }

   sort(rank,n);
   show_array(cost,n);
   printf("\n\nAnswer: Item sequence(from top to bottom)\n");
   show_array(rank,n);
  
  
  //calculate the total power
  for (item=1;item<n;item++) {
     for(i=item-1;i>=0;i--){
         W+=weight[rank[i]];
     }
    // printf("%ldx%ld=%ld\n",W,freq[rank[item]],W*freq[rank[item]]); 
     total_power+=W*freq[rank[item]];
     W=0;

  }

 printf("total_power=%ld\n",total_power); 
 
   free(cost);
   free(rank);
   #if TEST==0 
    free(weight);
    free(freq);
   #endif 
   system("PAUSE");
  return 0;
}

void sort(int a[],int n )
{
  int i, j;
  int flag;
  for(i=0;i<n;i++) { /* n passes thru the array */
    /* From start to the end of unsorted part */
    flag=0;
    for(j=1;j<(n-i);j++) {
      /* If adjacent items out of order, swap */
      if( cost[a[j-1]]<cost[a[j]] ) {
           SWAP(a[j-1],a[j]);
            flag=1;
          }
      }
    
    if (flag==0) break;
      
    }
 } 


void show_array(int *a,int size)
{
    int i;
    
     for (i=0;i<size;i++)
      printf("%ld ",a[i]);
      
     printf("\n"); 
     
}

