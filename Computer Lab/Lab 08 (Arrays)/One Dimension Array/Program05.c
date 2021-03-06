/*Write a progam to find the highest or lowest elements of an array of size 5*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    /*Declaration of variable*/
    int i, num[5], lowest, highest;

    system("cls");

    /*Taking input from user*/
    printf("Enter the members of array: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
    }

    /*Initialization of lowest and highest*/
    lowest = num[0];
    highest = num[0];

    /*Iterate over all elements of array and find lowest and highest number from array and store to a variable*/
    for (int i = 1; i < 6; i++)
    {
        (lowest < num[i]) ? (lowest = lowest) : (lowest = num[i]);
        (highest > num[i]) ? (highest = highest) : (highest = num[i]);
    }

    /*Printing result*/
    printf("\nHighest Number is %d\n", highest);
    printf("Lowest Number is %d", lowest);

    getch();
    return 0;
}