// my_ann.h
// 인공신경망 자료형과 관련 함수를 작성

#ifndef __MY_ANN_H__
#define __MY_ANN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "my_datatype.h"
#include "my_matrix.h"
#include "my_activ_func.h"

struct _ANN
{
    // 레이어 수
    uint32_t layer;
    // 레이어별 노드 수
    uint32_t *numofNode;
    // 레이어별 노드들의 가중치를 저장할 행렬
    matrix *weight_matrix;
    // 각 레이어별 계산 결과를 저장할 행렬
    matrix *y;
};
typedef struct _ANN ann;

// 신경망에 대한 정보가 저장된 파일을 읽고, 신경망을 세팅하는 함수
int init_ann(ann *A, FILE *data);

// 신경망에 할당한 공간들을 반환하는 함수
void free_ann(ann *A);

#endif