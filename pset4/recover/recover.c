/**recover.c
  * reads from a infile
  * and recovers jpegs
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <cs50.h>

bool jpeg_start(char *blo);


int main(int argc, char *argv[])
{
    // ensure correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover <file name>\n");
        return 1;
    }
    
    // read the infile from cmd line argument
    char *infile = argv[1];
    
    // open the file
    FILE *input = fopen(infile, "r");
    if (input == NULL)
    {
        fprintf(stderr, "Couldn't open the file\n");
        return 1;
    }

    char buffer[512];

    // reach untill the 1st jpeg
    do
    {
        // read from the input
        fread(buffer, 1, 512, input);
        // if jpeg reached, break the loop
        if (jpeg_start(buffer) == true)
        {
            break;
        }
    }
    while (true);
    
    fseek(input, -512, SEEK_CUR);
    
    // keep track of the number of jpegs formed
    int jpeg_count = 0;

    // status == 0 if no jpeg formed till now
    // status == 1 if atleast one jpeg has been formed
    int status = 0;
    
    // define a file pointer img
    FILE *img;
    
    /** this loop repeats untill loop broken
      * this creates a jpeg
      * writes in the jpeg till the start of new jpeg
      * closes the jpeg and opens another jpeg
      * breaks the loop if EOF is reached
      */
    while(fread(buffer, 1, 512, input) == 512)
    {
        if (jpeg_start(buffer) == true)
        {
            // ie, if this is 1st image
            if (status == 0)
            {
                // create a filename
                jpeg_count++;
                char *filename = malloc(0);
                sprintf(filename, "%03i.jpg", jpeg_count - 1);
                
                // open the .jpg file
                img = fopen(filename, "w");
                free(filename);
                status = 1;
                
                // write the 1st block of new jpeg
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            // ie, this is not the 1st img
            else
            {
                // first close the previous img
                fclose(img);

                // make new filename
                jpeg_count++;
                char *filename = malloc(0);
                sprintf(filename, "%03i.jpg", jpeg_count - 1);
                
                // open the .jpg file
                img = fopen(filename, "w");
                free(filename);
                
                // write the 1st block of new jpeg
                fwrite(buffer, sizeof(buffer), 1, img);
            }
        }
        // if this is not the start block of jpeg
        // then write this block as it is
        else
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }
    
    // close the input file
    fclose(input);
    
    // code is ready!!!!
    return 0;
}

// checks whether it is a start of new jpeg or not
bool jpeg_start(char *blo)
{
    if ((blo[0] == (char) 0xff) && (blo[1] == (char) 0xd8) && (blo[2] == (char) 0xff))
    {
        int temp = 0xe0;
        for (int n = 0; n < 16; n++)
        {
            if (blo[3] == (char) temp)
            {
                return true;
            }
            else
            {
                temp++;
            }
        }
    }
    return false;
}