/*******************************************************************************
*  File Name           :     lib_c.c
*  Created By          :     mhrusz <mhrusz+github@gmail.com>
*  Creation Date       :     [2016-07-18 12:59]
*  Last Modified       :     [2016-09-16 10:12]
*  Description         :     Operations on complex values
********************************************************************************/
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  double real;
  double imag;
} complex;

/* 
 * Passing complex value to print
 */
void cmplx_print_(complex *N)
{
  printf("complex: (%f, %f)\n", N->real, N->imag);
}

/*
 * Displaying complex array.
 */
void cmplx_print_arr_(const complex *A, const int *N)
{
  for(int i=0; i< *N; ++i)
  {
    for(int j=0; j< *N; ++j)
      printf("(%f, %f)\n", A[j+i* *N].real, A[j+i* *N].imag);
    printf("\n");
  }
}

