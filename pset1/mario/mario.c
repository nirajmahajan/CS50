#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        printf("Height: ");
        h = get_int();
    }
    while (h < 0 || h > 23);
    
    int r;
    
    for (r = 0; r < h; r++)
        {
            int i;
            
            for (i = 0; i < h - r - 1; i++)
            {
                printf(" ");
            }
 
            int p;
            
            for (p = 0; p < r + 1; p++)
            {
                printf("#");
            }
            
            printf("  ");
            
            for (p = 0; p < r + 1; p++)
            {
                printf("#");
            }
            
            printf("\n");
        }
}