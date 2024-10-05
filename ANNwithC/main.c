#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "my_datatype.h"
#include "my_matrix.h"
#include "my_activ_func.h"

int main(int argc, char const *argv[])
{
    uint32_t L = 0; // 레이어 수
    scanf("%u", &L);

    // 레이어별 노드 수
    uint32_t *numofNode = (uint32_t *)calloc(L + 1, sizeof(uint32_t));
    numofNode[0] = 1;
    for (size_t i = 1; i <= L; i++)
        scanf("%u", &numofNode[i]);

    // 레이어별 노드들의 가중치를 저장할 행렬
    matrix *weight_matrix = (matrix *)calloc(L, sizeof(matrix));
    for (size_t i = 0; i < L; i++)
        init_matrix(&weight_matrix[i], numofNode[i + 1], numofNode[i]);

    // 행렬에 값을 입력함. w_11 w_21 w_12 w_22 순으로 입력 (노드1과 관련된 가중치가 1행)
    for (size_t i = 0; i < L; i++)
        input_matrix(&weight_matrix[i]);

    // 각 레이어별 계산 결과를 저장할 공간
    matrix *y = (matrix *)calloc(L, sizeof(matrix));
    for (size_t i = 0; i < L; i++)
        init_matrix(&y[i], numofNode[i + 1], 1);

    // 신경망 계산
    for (size_t i = 0; i < L; i++)
    {
        if (i == 0) // 처음 레이어는 입력 레이어
        {
            copy_matrix(&y[i], &weight_matrix[i]);
            continue;
        }
        // y = A*x
        multiply_matrix(&y[i], &weight_matrix[i], &y[i - 1]);
        // y = sigmoid(y)
        map_matrix(&y[i], sigmoid);
    }

    print_matrix(&y[L - 1]);

    // free
    for (size_t i = 0; i < L; i++)
        free_matrix(&y[i]);
    free(y);
    for (size_t i = 0; i < L; i++)
        free_matrix(&weight_matrix[i]);
    free(weight_matrix);
    free(numofNode);

    return 0;
}
