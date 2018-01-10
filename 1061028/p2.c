/*
 *  Created on: 2018年1月2日
 *   大學程式設計先修檢測_1061028（APCS）
 *     Author: 艾鍗學院
 *    http://www.ittraining.com.tw/ittraining/it-elearning/apcs 
 *    
 */
#include <stdio.h>

int is_upper(char c);
int KString(char *s,int k, int type) ; //lower: type=0, upper: type=1  
void print_String(char *s,int lenth) ;

void test_string (char *str, int k);
#define UPPER 1
int main()
{
   
      //Example1:
   char *str1="aBBdaaa";
   char *str2="aafAXbbCDCCC";
   char *str3="DDaasAAbbCC";
   char *str4="DDaaAAbbCC";
   
   test_string(str1,1);
   test_string(str2,2);
   test_string(str3,3);
   test_string(str4,3);
    
      system("PAUSE");
    
    return 0;
}

void test_string (char *str, int k)
{
    char *S1=str;
    char *s=S1;
    int type;
    int j;
   
    int i=0;
    int length=0;
    int lognest_len=0;

    
    type=is_upper(*s);
    while (s!=NULL && *s!='\0') {

       j=KString(s,k,type);
      
       if (j==k) { 
             length+=k;  
             if (length>lognest_len) {
                   S1=str+i;
                   lognest_len=length;
               }
             s+=k; 
             type=1-type;   //switch type
       } else if(j<k) {
          i++;
          s=str+i;  
          length=0;
          type=is_upper(*s);
          }
     
      // getchar();  //uncomment it to enable interactive debug
    
    }
    
    printf("%s,k=%d==>\n",str,k);   
    printf("%d\n",lognest_len);  
    print_String(S1,lognest_len);

}




int KString(char *s,int k, int type) 
{

   int i;
      for (i=0;i<k && s!=NULL && s[i]!='\0';i++) {
          if (is_upper(s[i])!=type)
            break;
        }
   return i;
}


int is_upper(char c)
{
    return c>='A' && c<='Z';
}

void print_String(char *s,int lenth) 
{

   int i;

      for (i=0;i<lenth && s!=NULL && s[i]!='\0';i++) {
           printf("%c",s[i]);
        }
      
   printf("\n");
}





