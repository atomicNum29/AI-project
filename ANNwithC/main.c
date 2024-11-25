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

    // 신경망 순전파 계산
    forward_propagation(&A);

    // 신경망 순전파 결과 출력
    print_layers(&A);

    // free
    free_ann(&A);

    return 0;
}
