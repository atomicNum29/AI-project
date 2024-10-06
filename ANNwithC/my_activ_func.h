// my_activ_func.h
// 활성화 함수들을 선언하기 위한 헤더파일

#ifndef __MY_ACTIV_FUNC_H__
#define __MY_ACTIV_FUNC_H__

#include <math.h>
#include "my_datatype.h"

// 1 / ( 1 + e^(-x) )
dtype sigmoid(dtype x);

#endif