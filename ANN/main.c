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

}

dtype sigmoid(dtype x)
{
    return (1 / (1 + exp(-x)));
}
