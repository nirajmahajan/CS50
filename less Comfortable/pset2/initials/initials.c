#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get user's name
    string name = get_string();    
    
    // print 1st letter
    printf("%c", toupper(name[0]));
    
    // iterate over the provided string
    for (int j = 0, length = strlen(name); j < length; j++)
    {
        // check if any other words are present.
        if (name[j] == ' ' && name[j + 1] != '\0')
        {
            // print the very next letter after spacebar
            char t = toupper(name[j + 1]);
            printf("%c", t);
        }
    }
    
    printf("\n");
}