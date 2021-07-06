#include <stdio.h>
#include<conio.h>
int main()
{
for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
        if (i+j>4)
         {
             printf("*   ");
         }
         else
         {
             printf("#   ");
         }
        }
        printf("\n");
    }   
getch();
return 0;
}
