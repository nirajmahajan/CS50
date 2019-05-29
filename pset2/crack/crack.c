#include <crypt.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define _XOPEN_SOURCE

int main(int argc, string argv[])
{
    // check for only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
   
    // define hash
    string hash = argv[1];
   
    // iterate for password to be one digit
    for(int k = 65 ; k < 123; k++)
    {
        // define array of 2 having char and terminator
        char one_dig[2] = {k, '\0'};
        
        // convert it to crypt
        string code1 = crypt(one_dig, "50");
        
        // compare this guesssed code with given hash
        if (strcmp(code1, hash) == 0 )
        {
            printf("%s\n", one_dig);
            return 0;
        }
    }
    
    // iterate for password to be two digit
    for (int m1 = 65 ; m1 < 123 ; m1++)
    {
        for (int m2 = 65 ; m2 < 123 ; m2++)
        {
            // define array of 3 having chars and terminator
            char two_dig[3] = {m1, m2, '\0'};
            
            // convert it to crypt
            string code2 = crypt(two_dig, "50");
            
            // compare this guesssed code with given hash
            if (strcmp(code2, hash) == 0)
            {
                printf("%s\n", two_dig);
                return 0;
            }
        }
    }
    
    // iterate for password to be three digit
    for (int n1 = 65 ; n1 < 123 ; n1++)
    {
        for (int n2 = 65 ; n2 < 123 ; n2++)
        {
            for (int n3 = 65 ; n3 < 123 ; n3++)
            {
                // define array of 4 having chars and terminator
                char three_dig[4] = {n1, n2, n3, '\0'};
                
                // convert it to crypt
                string code3 = crypt(three_dig, "50");
                
                // compare this guesssed code with given hash
                if (strcmp(code3, hash) == 0)
                {
                    printf("%s\n", three_dig);
                    return 0;
                }
            }
        }
    }
    
    // iterate for password to be four digit
    for (int j1 = 65; j1 < 123; j1++)
    {
        for(int j2 = 65; j2 < 123; j2++)
        {
            for(int j3 = 65; j3 < 123; j3++)
            {
                for (int j4 = 65; j4 < 123; j4++)
                {
                    // define array of 5 having chars and terminator
                    char four_dig[5] = {j1, j2, j3, j4, '\0'};
                    
                    // convert it to crypt
                    string code4 = crypt(four_dig, "50");
                    
                    // compare this guesssed code with given hash
                    if (strcmp(code4, hash) == 0)
                    {
                        printf("%s\n", four_dig);
                        return 0;
                    }
                }
            }
        }
    }
    
    // note: code will reach this phase only if the hash does not match
    // so now singnify the wrong password and return 0
    printf("Wrong password entered!!\n");
    return 0;
}