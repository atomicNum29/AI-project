// my_matrix.h
// 행렬 자료형과 행렬 연산 함수들을 선언하기 위한 헤더파일

#ifndef __MY_MATRIX_H__
#define __MY_MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "my_datatype.h"

struct _MATRIX
{
    size_t row;
    size_t col;
    dtype **data;
};
typedef struct _MATRIX matrix;

// set row & col, allocation data
void init_matrix(matrix *mat, size_t row, size_t col);
// free data
void free_matrix(matrix *mat);
// matrix copy ( dest <- orig )
void copy_matrix(matrix *dest, matrix *orig);
// res = A * B
void multiply_matrix(matrix *res, matrix *A, matrix *B);
// applies a func to each matrix element
void map_matrix(matrix *mat, dtype (*func)(dtype));

// input matrix via scanf
void input_matrix(matrix *mat, FILE *data);
// print matrix via printf
void print_matrix(matrix *mat);

#endif