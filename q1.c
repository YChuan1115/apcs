/*
 *  Created on: 2017年8月20日
 *   大學程式設計先修檢測」（APCS）
 *     Author: 艾鍗學院
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
int toInt(char c);
int main()
{
   int i;
   int even=0;
   int odd=0;
   char x[1000]={0}; 
   //get input
   scanf("%s",x);
   
   for (i=0;x[i]!=0;i+=2)
      even+=toInt(x[i]);
   
   for (i=1;x[i]!=0;i+=2)
      odd+=toInt(x[i]);
   
  // printf("%d %d\n",even, odd); 
   //Output
   printf("%d\n",abs(even-odd));
   system("PAUSE");
  return 0;
}

int toInt(char c)
{
  return c-'0';
     
}
