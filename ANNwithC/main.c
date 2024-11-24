#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "my_datatype.h"
#include "my_matrix.h"
#include "my_activ_func.h"
#include "my_ann.h"

int main(int argc, char const *argv[])
{
    // ann initialize
    ann A = {0};
    FILE *fp = fopen("ANNwithC/bin/input.txt", "r");
    init_ann(&A, fp);

    // 신경망 계산
    copy_matrix(&A.y[0], &A.weight_matrix[0]); // 처음 레이어는 입력 레이어
    for (size_t i = 1; i < A.layer; i++)
    {
        // y = A*x
        multiply_matrix(&A.y[i], &A.weight_matrix[i], &A.y[i - 1]);
        // y = sigmoid(y)
        map_matrix(&A.y[i], sigmoid);

        printf("Layer %zu:\n", i);
        print_matrix(&A.y[i]);
    }

    printf("output:\n");
    print_matrix(&A.y[A.layer - 1]);

    // free
    free_ann(&A);

    return 0;
}
