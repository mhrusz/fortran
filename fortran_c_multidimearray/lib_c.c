/*******************************************************************************
*  File Name           :     lib_c.c
*  Created By          :     mhrusz <mhrusz+github@gmail.com>
*  Creation Date       :     [2016-07-18 12:59]
*  Last Modified       :     [2016-09-04 16:00]
*  Description         :     Operations on multidimensional arrays in C
*  Based on:
*  http://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays/
********************************************************************************/
#include <stdlib.h>
#include <stdio.h>


/* 
 * Passing 2D array to print
 * 2D array is passed as one memory chunk
 */
void arr_print_(int *a, int *N, int *M)
{
    for(unsigned j=0; j<*M; j++)
    {
      for(unsigned i=0; i<*N; i++)
      {
          printf("%d ", a[i+j*(*N)]);
      }
      printf("\n");
    }
}

/*
 * That array comes from Fortran so it is column major ordered.
 */
void arr_print3d_(int *a, int *N, int *M, int *K)
{
    for(unsigned k=0; k<*K; k++)
    {
      for(unsigned j=0; j<*M; j++)
      {
        for(unsigned i=0; i<*N; i++)
        {
          // formula for accessing given element in the table
          printf("%d ", a[i + j*(*N) + k*(*M * *N)]);
        }
        printf(" | ");
      }
      printf("\n");
    }
}

/*
 * That array comes from Fortran so it is column major ordered.
 */
void arr_print4d_(int *a, int *N, int *M, int *K, int *L)
{
    for(unsigned l=0; l<*L; l++)
    {
      for(unsigned k=0; k<*K; k++)
      {
        for(unsigned j=0; j<*M; j++)
        {
          for(unsigned i=0; i<*N; i++)
          {
            // formula for accessing given element in the table
            printf("%d ", a[i + j*(*N) + k*(*M * *N) + l*(*M* *N * *K)]);
          }
          printf("|\n");
        }
        printf("\n");
      }
      printf("\n");
    }
}
