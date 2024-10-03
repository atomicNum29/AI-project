#include <stdio.h>
#include <math.h>

typedef float dtype;
struct _MATRIX
{
    size_t row;
    size_t col;
    dtype **data;
};
typedef struct _MATRIX matrix;

// 1 / ( 1 + e^(-x) )
dtype sigmoid(dtype x);
// res = A * B
void matrix_multiplication(matrix res, matrix A, matrix B);

int main(int argc, char const *argv[])
{

    return 0;
}

// res = A * B
void matrix_multiplication(matrix res, matrix A, matrix B)
{
    if (res.row < A.row || res.col < B.col)
        perror("MAT MUL: 'res' is too small");
    if (A.col != B.row)
        perror("MAT MUL: matrix size error\n\tA.col != B.row");

    for (size_t i = 0; i < A.row; i++)
    {
        for (size_t ii = 0; ii < B.col; ii++)
        {
            dtype tmp = 0;
            for (size_t iii = 0; iii < A.col; iii++)
            {
                tmp += A.data[i][iii] * B.data[iii][ii];
            }
            res.data[i][ii] = tmp;
        }
    }
    
    return;
}

dtype sigmoid(dtype x)
{
    return (1 / (1 + exp(-x)));
}
