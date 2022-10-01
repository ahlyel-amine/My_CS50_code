#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, i, j, c;

    h = i = 0;
    j = 0;
    while (h >= 9 || h <= 0) //geting height
    {
        printf("Height: ");
        scanf("%d", &h);
    }
    while (h > j)   // loop the height
    {
        i = 0;
        c = h - j - 1;
        while (i <= j)  // loop print spaces and hash's left side
        {
            while (c > 0)
            {
                printf(" ");
                c--;
            }
            printf("#");
            i++;
        }
        printf("  ");
        i = 0;
        while (i <= j)  // loop print hash's right side
        {
            printf("#");
            i++;
        }
        printf("\n");
        j++;
    }
}