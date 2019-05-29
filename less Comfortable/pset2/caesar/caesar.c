#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // ensure only 2 arguments are provided
    if (argc == 2)
    {
        // take mod of provided key with 26
        int key = atoi(argv[1]);

        // get plain text
        printf("plaintext: ");
        string ptext = get_string();

        printf("ciphertext: ");
        
        // iterate over plaintext
        for (int j = 0, length = strlen(ptext); j < length; j++)
        {
            // verify whether alphabet or not
            if (isalpha(ptext[j]))
            {
                if (isupper(ptext[j]))
                {
                    // convert to ascii
                    char letter = ptext[j];
                    int num1 = (int) letter;
                    // subtract 65 to get '0'.add key then take mod with 26.
                    int codnum1 = (num1 - 65 + key) % 26;
                    // again add 65 to conver to upper alphabet
                    char code1 = (char) (codnum1 + 65);
                    printf("%c", code1);
                }
                else
                {
                    // convert to ascii
                    char letter2 = ptext[j];
                    int num2 = (int) letter2;
                    // subtract 97 to get '0'.add key then mod with 26
                    int codnum2 = (num2 - 97 + key) % 26;
                    // again add 97 to convert to lower alphabets
                    char code2 = (char) (codnum2 + 97);
                    printf("%c", code2);
                }
            }
            else
            {
                // if not alphabet, print as it is
                printf("%c", ptext[j]);
            }
        
        }
    
        printf("\n");
    }
    else
    {
        printf("ERROR\n");
        return (1);
    }
}