#include "my_matrix.h"

// res = A * B
void multiply_matrix(matrix *res, matrix *A, matrix *B)
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

void init_matrix(matrix *mat, size_t row, size_t col)
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

void free_matrix(matrix *mat)
{
    free(mat->data);
    mat->data = NULL;
    mat->row = mat->col = 0;
    return;
}

void copy_matrix(matrix *dest, matrix *orig)
{
    if (dest->row != orig->row || dest->col != orig->col)
    {
        fprintf(stderr, "Matrix copy error: sizeof(dest) is not equal sizeof(orig).\n");
        fprintf(stderr, "(%zu, %zu) != (%zu, %zu)\n", dest->row, dest->col, orig->row, orig->col);
        exit(-1);
    }

    for (size_t i = 0; i < orig->row; i++)
    {
        for (size_t ii = 0; ii < orig->col; ii++)
        {
            dest->data[i][ii] = orig->data[i][ii];
        }
    }

    return;
}

void map_matrix(matrix *mat, dtype (*func)(dtype))
{
    for (size_t i = 0; i < mat->row; i++)
    {
        for (size_t ii = 0; ii < mat->col; ii++)
        {
            mat->data[i][ii] = func(mat->data[i][ii]);
        }
    }

    return;
}

void input_matrix(matrix *mat)
{
    for (size_t i = 0; i < mat->row; i++)
    {
        for (size_t ii = 0; ii < mat->col; ii++)
        {
            scanf(DTYPE_FORMAT, &mat->data[i][ii]);
        }
    }

    return;
}

void print_matrix(matrix *mat)
{
    for (size_t i = 0; i < mat->row; i++)
    {
        for (size_t ii = 0; ii < mat->col; ii++)
        {
            printf(DTYPE_FORMAT "%c", mat->data[i][ii], ii == mat->col ? '\n' : ' ');
        }
    }

    return;
}
