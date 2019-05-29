/**
 * Implements a dictionary's functionality.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// define a struct node
#include "dictionary.h"

// useful for the function size
// this is used in load itself to find no. of words
unsigned int word_cnt;

node *root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node *cursor = root;
    
    for (int v = 0, l = strlen(word); v < l; v++)
    {
        int c = (int) tolower(word[v]);
        
        // define an int index
        int index;
        
        // if the character is alphabetic, the index will be wrt 'a'
        if (isalpha(c))
        {
            index = c - 'a';
        }
        // else the index is 26 ie 39 - 13
        else
        {
            index = c - 13;
        }
        
        // if Null then this path does not exist in our dict
        if (cursor->children[index] == NULL)
        {
            return false;
        }
        // else move the cursor ahead
        else
        {
            cursor = cursor->children[index];
        }
    }
    
    /**
     * if reached here, then it means that the path of
     * given word exists. 
     * But we need to check that if that word is in
     * our dict or not
     * 
     * ie
     * if given word is 'caterp'
     * then we will reach this step
     * becoz 'caterp' is a part of 'caterpillar'
     * hence we need to verify that the node to 
     * the last letter has is_word as true
     */
    if (cursor->is_word == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // open the dictionary
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Couldn't open file!!\n");
        return false;
    }
    
    root = (node *) malloc(sizeof(node));
    
    // initialize root to NULL
    for (int k = 0; k < 27; k++)
    {
        root->children[k] = NULL;
    }
    root->is_word = false;
    
    // define a new node to move alon the trie
    node *cursor = root;
    
    // initialize the word count
    word_cnt = 0;
    
    // start reading from the dictionary
    for (int p = fgetc(fp); p != EOF; p = fgetc(fp))
    {
        // if \n is reached, then we have finished a whole word
        if (p == 10)
        {
            // increase word count
            word_cnt++;
            
            // this is an end of a word
            cursor->is_word = true;
            
            // reallocate cursor to root
            cursor = root;
        }
        else
        {
            // define index
            int index;
            
            // if the character is alphabetic, the index will be wrt 'a'
            if (isalpha(p))
            {
                index = p - 'a';
            }
            // else the index is 26 ie 39 - 13
            else
            {
                index = p - 13;
            }
            
            // now if the node is NULL, then we have to first create one
            if (cursor->children[index] == NULL)
            {
                cursor->children[index] = malloc(sizeof(node));
                if (cursor->children[index] == NULL)
                {
                    printf("Cannot Malloc!!\n");
                    return false;
                }

                // initialize the new node to NULL
                cursor->children[index]->is_word = false;
                for (int t = 0; t < 27; t++)
                {
                    cursor->children[index]->children[t] = NULL;
                }
                
                // shift the cursor ahead
                cursor = cursor->children[index];
            }
            else
            {
                // shift the cursor ahead
                cursor = cursor->children[index];
            }
        }
    }
    
    // close the file
    fclose(fp);
    
    // superb!!
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_cnt;    
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    return obliviate(root);
}

// obliviates the trie via recursion
bool obliviate(node *node)
{
    for (int m = 0; m < 27; m++)
    {
        if (node->children[m] != NULL)
        {
            obliviate(node->children[m]);
        }
    }
    
    free(node);
    return true;
}
