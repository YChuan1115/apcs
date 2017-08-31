/*
 *  Created on: 2017年8月20日
 *   大學程式設計先修檢測」（APCS）
 *     Author: 艾鍗學院
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */
#include <stdio.h>
#define TEST 1
#define SWAP(a,b)   { int t; t=a; a=b; b=t; }

void sort( int a[], int n );
void sort_2( int a[], int n ) ;
void show_array(int a[],int n);
void show_array2(int a[],int left,int right);
unsigned long find_max(int a[],int n);
int *g_ptr;
int main()
{
   int i;
   int N=5;
   int K=4;  //k is always less then N
   int k[50000]={0};
   int diff[50000]={0};
   int diameter[50000]={0};
   unsigned long min;
  #if TEST 

 //unsigned long p[]={5,1,2,8,7};
 unsigned long p[]={1,1,1,8,7};
  N=sizeof(p)/sizeof(p[0]);
  show_array(p,N);
  sort(p,N);
  show_array(p,N);
	#else 
	int p[50000]={0}; 
   //get_input
   scanf("%d",&N); //for N
   scanf("%d",&K); //for K
	#endif
   // caculate the difference 

   
  for (i=1;i<N;i++) {
     diff[i]=p[i]-p[i-1];
 
  }
    
   show_array(diff,N);
   
  //create sorting index to diff 
  for (i=0;i<N;i++)  k[i]=i;
  g_ptr=diff;
  //now k haa a new index to diff 
  sort_2(k,N);
  show_array(k,N);
  //----------------------
  //show all k groups
  sort(k,K); //divide group from left to right
  int l=0,r=0; 
  for(i=0;i<K-1;i++) {
    l=r; r=k[i]; 
    show_array2(p,l,r);
    diameter[i]=p[r-1]-p[l];
  } 
   show_array2(p,r,N);
   diameter[i]=p[N-1]-p[r];
   // show_array(diameter,K);
 //---------------------------
 
  min=find_max(diameter,K);
  printf("Min D=%ld\n",min);
  
   system("PAUSE");
  return 0;
}

void sort( int a[], int n ) 
{
  int i, j;
  int flag;
  for(i=0;i<n;i++) { /* n passes thru the array */
    /* From start to the end of unsorted part */
     flag=0;
    for(j=1;j<(n-i);j++) {
      /* If adjacent items out of order, swap */
      if( a[j-1]>a[j] ) {
           SWAP(a[j-1],a[j]);
            flag=1;
          }
      }
  //  printf("Step%d:\t",i);
  // show_array(a,n);
    
    if (flag==0) break;
      
    }
 }    


void sort_2( int a[], int n ) 
{
  int i, j;
  int flag;
  for(i=0;i<n;i++) { /* n passes thru the array */
    /* From start to the end of unsorted part */
     flag=0;
    for(j=1;j<(n-i);j++) {
      /* If adjacent items out of order, swap */
      if( g_ptr[a[j-1]]<=g_ptr[a[j]] ) {
           SWAP(a[j-1],a[j]);
            flag=1;
          }
      }
  //  printf("Step%d:\t",i);
  // show_array(a,n);
    
    if (flag==0) break;
    
  
    
    }
 } 

void show_array2(int a[],int left,int right)
{
 int i; 
   for(i=left;i<right;i++) {
     printf("%d  ",a[i]);
 
   }

  printf("\n");


}


void show_array(int a[],int n)
{
 int i; 
   for(i=0;i<n;i++) {
     printf("%d  ",a[i]);
 
   }

  printf("\n");


}


unsigned long find_max(int a[],int n)
{
 int i; 
 unsigned long max=a[0];
   for(i=1;i<n;i++) {
     if (a[i]>max) max=a[i];
   }

  return max;


}


