// my_datatype.h
// 행렬의 내부 자료형을 지정하기 위한 헤더파일

#ifndef __MY_DATATYPE_H__
#define __MY_DATATYPE_H__

#ifdef USE_FLOAT
typedef float dtype;
#define DTYPE_FORMAT "%f"
#else
typedef double dtype;
#define DTYPE_FORMAT "%lf"
#endif

#endif