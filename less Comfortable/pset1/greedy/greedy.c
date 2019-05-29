#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main (void)
{
    float m;
    
    do
    {
        printf("O hai! How much change is owed?\n");
        m = get_float();
    }
    while (m < 0);
    
    int i = round(100 * m);
    
    int a = remainder (i , 25);
    if (a < 0)
        a = (a + 25);
    int w = ((i - a) / 25);

    int b = remainder (a , 10);
    if (b < 0)
        b = (b + 10);
    int x = ((a - b) /10);
    
    int c = remainder (b , 5);
    if (c < 0)
        c = (c + 5);
    int y = ((b - c) /5);

    printf("%i\n", w + x + y + c); 
}