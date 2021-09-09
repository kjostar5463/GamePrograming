#include <stdio.h>

int main()
{
   char string[20];
   char c;
   
   printf("문자열 입력 : ");
   scanf("%s", string);
   fflush(stdin); 
   printf("문자 입력 : "); 
   scanf("%c", &c);
   
   printf("%s\n", string);
   printf("!!%c!!", c);
   
   return 0;
}
