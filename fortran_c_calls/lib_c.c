/*******************************************************************************
*  File Name           :     lib_c.c
*  Created By          :     mhrusz <mhrusz+github@gmail.com>
*  Creation Date       :     [2016-07-18 12:59]
*  Last Modified       :     [2016-07-19 12:44]
*  Description         :     Sample library 
********************************************************************************/
#include <stdlib.h>
#include <stdio.h>

/*
 * Sample print function.
 */
void sampPrint(int a)
{
    printf("Hello world %d!!!\n", a);
};

/*
 * Adding two values by value and return results
 */
int samp_add(int a, int b)
{
    return a + b;
}

/*
 * Adding two values by pointer
 */
int samp_addp(int *a, int *b)
{
    return *a + *b;
}

/* 
 * Passing whole array to print
 */
void samp_print_arr(int *a, int size)
{
    for(unsigned i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }
}
