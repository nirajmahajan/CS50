#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    while(true)
    {
        printf("single correct questions : ");
        int single = get_int();
        printf("multiple correct questions : ");
        int multi = get_int();
        printf("\n");
        printf("\n");
        
        int t = (2 * single) + (3 * multi);
        int t2 = t % 15;
        int tim = t + 15 - t2;
        
        int hrs = floor(tim / 60);
        int mins = tim - (60 * hrs);
        
        printf("Marks = %i\nTime = %i hrs %i mins\n\n\n\n", (3 * single) + (4 * multi), hrs, mins);
    }        
}