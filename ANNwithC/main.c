#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "my_matrix.h"

int main(int argc, char const *argv[])
{
    uint32_t Ar, Ac, Br, Bc;
    uint32_t Cr, Cc;
    scanf("%u%u%u%u", &Ar, &Ac, &Br, &Bc);
    Cr = Ar;
    Cc = Bc;

    matrix A, B, C;
    set_matrix(&A, Ar, Ac);
    set_matrix(&B, Br, Bc);
    set_matrix(&C, Cr, Cc);

    for (size_t i = 0; i < Ar; i++)
    {
        for (size_t ii = 0; ii < Ac; ii++)
        {
            scanf("%f", &A.data[i][ii]);
        }
    }
    for (size_t i = 0; i < Br; i++)
    {
        for (size_t ii = 0; ii < Bc; ii++)
        {
            scanf("%f", &B.data[i][ii]);
        }
    }

    matrix_multiplication(&C, &A, &B);

    for (size_t i = 0; i < Cr; i++)
    {
        for (size_t ii = 0; ii < Cc; ii++)
        {
            printf("%f%c", C.data[i][ii], ii == Cc - 1 ? '\n' : ' ');
        }
    }

    printf("\n");
    for (size_t i = 0; i < Cr; i++)
    {
        for (size_t ii = 0; ii < Cc; ii++)
        {
            C.data[i][ii] = sigmoid(C.data[i][ii]);
            printf("%f%c", C.data[i][ii], ii == Cc - 1 ? '\n' : ' ');
        }
    }

    del_matrix(&A);
    del_matrix(&B);
    del_matrix(&C);

    return 0;
}
