/*
 *  Created on: 2018�~1��2��
 *   �j�ǵ{���]�p�����˴�_1061028�]APCS�^
 *     Author: ����ǰ|
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */
#include <stdio.h>
int main()
{
    int a,b,c;
    int flag=1;
   //get input
   scanf("%d %d %d",&a,&b,&c);
   if (a!=0) a=1;
   if (b!=0) b=1;
    //printf("a=%d,b=%d,c=%d\n",a,b,c);
    if (a&b==c) { printf("AND\n"); flag=0;}
    if (a|b==c) { printf("OR\n");  flag=0;}
    if (a^b==c) { printf("XOR\n"); flag=0;}
    
    if (flag) printf("IMPOSSIBLE\n");

   system("PAUSE");
  return 0;
}

