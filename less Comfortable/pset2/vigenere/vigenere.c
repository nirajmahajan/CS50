#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check whether only 2 command prompt arguments are given
    if (argc != 2)
    {
        printf("ERROR\n");
        return (1);
    }
    
    string key = argv[1];
    int keylen = strlen(key);

    // iterate over the key
    for (int iter = 0; iter < keylen; iter++)
    {
        if (isalpha(argv[1][iter]) == false)
        {
            printf("error\n");
            return(1);
        }
    }
    
    // get plain text
    printf("plaintext: ");
    string ptext = get_string();
    
    printf("ciphertext: ");
    
    {
        // iterate over the plaintext
        for (int p = 0, k = 0, length = strlen(ptext); p < length; p++, k++)
        {
            if (isalpha(ptext[p]))
            {
                // we are gonna determine the key for the pth letter of ptext
                if (k == keylen)
                {
                    k = 0;
                }
                
                // convert the specific key for this char of ptext to upper and 
                // subtract 65 to get its alphabetic position
                char temp1 = toupper(key[k]);
                int ascii1 = (int) temp1;
                int key1 = ascii1 - 65;
                
                if (isupper(ptext[p]))
                {
                    char letter = ptext[p];
                    int num1 = (int) letter;
                    
                    // subtract 65 to get '0'.add key then take mod with 26.
                    int codnum1 = (num1 - 65 + key1) % 26;
                    // again add 65 to conver to upper alphabet
                    char code1 = (char) (codnum1 + 65);
                    printf("%c", code1);
                }
                if (islower(ptext[p]))
                {
                    char letter2 = ptext[p];
                    int num2 = (int) letter2;
                    
                    // subtract 97 to get '0'.add key then mod with 26
                    int codnum2 = (num2 - 97 + key1) % 26;
                    // again add 97 to convert to lower alphabets
                    char code2 = (char) (codnum2 + 97);
                    printf("%c", code2);
                }

                // now as the ptext char was alphabet, 
                // the key must move forward to the next letter
            }
            else
            {
                // if not alphabet, print as it is, 
                // while dont increase the position of key, ie 'k'
                printf("%c", ptext[p]);
                k--;
            }
        }
    }

    printf("\n");
    
    return (0);
}