#ifndef __MY_MATRIX_H__
#define __MY_MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef float dtype;
struct _MATRIX
{
    size_t row;
    size_t col;
    dtype **data;
};
typedef struct _MATRIX matrix;
void set_matrix(matrix *mat, size_t row, size_t col);
void del_matrix(matrix *mat);

// 1 / ( 1 + e^(-x) )
dtype sigmoid(dtype x);
// res = A * B
void matrix_multiplication(matrix *res, matrix *A, matrix *B);

#endif