#include "my_ann.h"

int init_ann(ann *A, FILE *data)
{
    uint32_t L = 0; // 레이어 수
    fscanf(data, "%u", &L);
    A->layer = L;

    // 레이어별 노드 수
    uint32_t *numofNode = (uint32_t *)calloc(L + 1, sizeof(uint32_t));
    A->numofNode = numofNode;
    numofNode[0] = 1;
    for (size_t i = 1; i <= L; i++)
        fscanf(data, "%u", &numofNode[i]);

    // 레이어별 노드들의 가중치를 저장할 행렬
    matrix *weight_matrix = (matrix *)calloc(L, sizeof(matrix));
    A->weight_matrix = weight_matrix;
    for (size_t i = 0; i < L; i++)
        init_matrix(&weight_matrix[i], numofNode[i + 1], numofNode[i]);

    // 행렬에 값을 입력함. w_11 w_21 w_12 w_22 순으로 입력 (노드1과 관련된 가중치가 1행)
    for (size_t i = 0; i < L; i++)
        input_matrix(&weight_matrix[i], data);

    // 각 레이어별 계산 결과를 저장할 공간
    matrix *y = (matrix *)calloc(L, sizeof(matrix));
    A->y = y;
    for (size_t i = 0; i < L; i++)
        init_matrix(&y[i], numofNode[i + 1], 1);

    return 0;
}

void forward_propagation(ann *A)
{
    copy_matrix(&A->y[0], &A->weight_matrix[0]); // 처음 레이어는 입력 레이어
    for (size_t i = 1; i < A->layer; i++)
    {
        // y = A*x
        multiply_matrix(&A->y[i], &A->weight_matrix[i], &A->y[i - 1]);
        // y = sigmoid(y)
        map_matrix(&A->y[i], sigmoid);
    }
}

void print_layers(ann *A)
{
    for (size_t i = 1; i < A->layer; i++)
    {
        printf("Layer %zu:\n", i);
        print_matrix(&A->y[i]);
    }

    printf("output:\n");
    print_matrix(&A->y[A->layer - 1]);
}

void free_ann(ann *A)
{
    for (size_t i = 0; i < A->layer; i++)
        free_matrix(&A->y[i]);
    free(A->y);
    for (size_t i = 0; i < A->layer; i++)
        free_matrix(&A->weight_matrix[i]);
    free(A->weight_matrix);
    free(A->numofNode);

    memset(A, 0, sizeof(ann));
}
