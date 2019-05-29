#include <cs50.h>
#include <math.h>
#include <stdio.h>

int money(long long n);

int odd(long long u);

int main (void)
{
    long long z;
    
    do
    {
        printf("Number: ");
        z = get_long_long();
    }
    while (z <= 0);

    int y = money(z) + odd(z);
    int x = y % 10;
    
    if (x == 0)
    {
        int a = floor(z / 10000000000000);         
        
        if ((35 > a && a > 33) || (38 > a && a > 36))
        {
            printf("AMEX\n");
        }
        
        int b = floor(z / 100000000000000);
        
        if (56 > b && b > 50)
        {
            printf("MASTERCARD\n");
        }
        
        int c = floor(z / 1000000000000);
        int d = floor(z / 1000000000000000);
        
        if ((5 > c && c > 3) || (5 > d && d > 3))
        {
            printf("VISA\n");
        }
    }
    else
    printf("INVALID\n");
}

int money(long long z)
{
    long long i = (floor(z / 10));
    int a = 2 * (i % 10);
    if ((a) > 9)
        a = ((a % 10) + 1);         
    
    long long j = (floor(z / 1000));
    int b = 2 * (j % 10);
    if ((b) > 9)
        b = ((b % 10) + 1);         
    
    long long k = (floor(z / 100000));
    int c = 2 * (k % 10);
    if ((c) > 9)
        c = ((c % 10) + 1);         
    
    long long l = (floor(z / 10000000));
    int d = 2 * (l % 10); 
    if ((d) > 9)
        d = ((d % 10) + 1);         
    
    long long m = (floor(z / 1000000000));
    int e = 2 * (m % 10);
    if ((e) > 9)
        e = ((e % 10) + 1);         
    
    long long n = (floor(z / 100000000000));
    int f = 2 * (n % 10);
    if ((f) > 9)
        f = ((f % 10) + 1);         
    
    long long o = (floor(z / 10000000000000));
    int g = 2 * (o % 10);
    if ((g) > 9)
        g = ((g % 10) + 1);         
    
    long long p = (floor(z / 1000000000000000));
    int h = 2 * (p % 10);
    if ((h) > 9)
        h = ((h % 10) + 1);         
        
    return (a+b+c+d+e+f+g+h);
}

int odd(long long z)
{
    long long a = (floor(z));
    int i = a % 10;
    
    long long b = (floor(z / 100));
    int j = b % 10;
    
    long long c = (floor(z / 10000));
    int k = c % 10;
    
    long long d = (floor(z / 1000000));
    int l = d % 10;
    
    long long e = (floor(z / 100000000));
    int m = e % 10;

    long long f = (floor(z / 10000000000));
    int n = f % 10;
    
    long long g = (floor(z / 1000000000000));
    int o = g % 10;
    
    long long h = (floor(z / 100000000000000));
    int p = h % 10;

    return (i+j+k+l+m+n+o+p);
}