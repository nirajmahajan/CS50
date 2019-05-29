#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>


bool search(int value, int values[], int n);
void sort(int values[], int n);


// Returns true if value is in array of n values, else false.
bool search(int value, int values[], int n)
{
    // define midlle position for an array
    int midpos = (n / 2);
    int mid = values[midpos];
    
    // compare between tofind and mid
    if (mid == value)
    {
        return true;
        
    }
    else if (mid > value)
    {
        // define another array with half the number of elements
        int value1[n - midpos];
        for (int pos1 = 0, temp = n - midpos - 1;  pos1 <= temp ; pos1++)
        {
            // iterate over so as to assign elements to new array
            value1[pos1] = values[pos1];
        }
        
        if (n - midpos == 1)
        {
            // if the new array has only 1 member, 
            // check whether that element matches or not
            
            // neccesity of this step :
            // if a 1 element array is sent in search again, (line 59)
            // then n = 1 and midpos = 0
            // so basically, the new array will have size 0
            // which is an error
            
            if (value1[0] == value)
            {
                return true;
            }
            else
            {
                return false;
            }        
        }
        
        return search(value, value1, n - midpos);
    }
    else
    {
        // repeat similar stps here
        
        int value2[n - midpos];
        for (int pos2 = 0, temp2 = n - midpos - 1;  pos2 <= temp2 ; pos2++)
        {
            value2[pos2] = values[midpos + pos2];
        }
        
        if (n - midpos == 1)
        {
            
            if (value2[0] == value)
            {
                return true;
            }
            else
            {
                return false;
            }        
        }
        
        return search(value, value2, n - midpos);
    }
    
}

// Sorts array of n values by Counting sort
void sort(int values[], int n)
{
    int max = 0;
    
    // iterate over given array to find the max element
    for (int temp3 = 0; temp3 < n; temp3++)
    {
        if (max < values[temp3])
        {
            max = values[temp3];
        }
    }
    
    // define an array having n + 1 elements
    int array[max + 1];
    
    // iterate over to assign numbers from 0 to max to new array
    for (int k = 0; k < max + 1; k++)
    {
        array[k] = 0;
    }
    
    // increse the "array" element corresponding to 
    // every element in "values"
    for (int f = 0; f < n; f++)
    {
        int temp = values[f];
        array[temp]++;
    }
    
    // initialize add count to 0
    int add_count = 0;
    
    // iterate over "array"
    for (int t = 0; t < max + 1; t++)
    {
        // define freq as the number of times an element is in "values"
        int freq = array[t];
        
        if (array[t] != 0)
        {
            // if freq != 0, then 
            // iterate over the frequency and assign values to "values"
            // whil increasind add_count each time
            for (int p = 0; p < freq; p++)
            {
                values[add_count] = t;
                add_count++;
            }
        }
    }
    
    return;
}