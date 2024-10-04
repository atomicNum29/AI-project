#include "my_matrix.h"

// res = A * B
void matrix_multiplication(matrix *res, matrix *A, matrix *B)
{
    if (res->row < A->row || res->col < B->col)
    {
        fprintf(stderr, "Matrix multiplication error: 'res' is too small.\n");
        exit(-1);
    }
    if (A->col != B->row)
    {
        fprintf(stderr, "Matrix multiplication error: A.col (%zu) != B.row (%zu)\n", A->col, B->row);
        exit(-1);
    }

    for (size_t i = 0; i < A->row; i++)
    {
        for (size_t ii = 0; ii < B->col; ii++)
        {
            dtype tmp = 0;
            for (size_t iii = 0; iii < A->col; iii++)
            {
                tmp += A->data[i][iii] * B->data[iii][ii];
            }
            res->data[i][ii] = tmp;
        }
    }

    return;
}

dtype sigmoid(dtype x)
{
    return (1 / (1 + exp(-x)));
}

void set_matrix(matrix *mat, size_t row, size_t col)
{
    mat->row = row;
    mat->col = col;

    size_t pointers_size = sizeof(dtype *) * row;
    size_t data_size = sizeof(dtype) * row * col;
    mat->data = (dtype **)malloc(data_size + pointers_size);

    dtype *data_block = (dtype *)(mat->data + row);
    for (size_t i = 0; i < row; i++)
    {
        mat->data[i] = data_block + (i * col);
    }

    memset(data_block, 0, data_size);

    return;
}

void del_matrix(matrix *mat)
{
    free(mat->data);
    mat->data = NULL;
    mat->row = mat->col = 0;
    return;
}
