/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * TODO: change to binary search
 */
bool search(int value, int values[], int n)
{
    if (n > 0)
    {
        // linear search 
        int i;
        for (i = 0; i < n; i++)
        {
          if (values[i] == value)
          {
            return true;
          }
        }
    }
    
    return false;

}

/**
 * Swaps the elements of array at indices a and b
 */
void swap (int array[], int a, int b)
{
    int temp = array[a];

    array[a] = array[b];
    array[b] = temp;

    return;
}

/**
 * Sorts array of n values using counting sort.
 */
void sort(int values[], int n)
{
    //Implement merge sort or insertion srt
    int swaps;
    int i;
    do
    {
        swaps = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap(values, i, i + 1);
                swaps++;
            }
        }
    }
    while (swaps != 0);

    int j;
    for (j = 0; j < n; j++)
    {
        printf("%i\n", values[j]);
    }
    return;
}

