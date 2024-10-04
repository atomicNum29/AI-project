#include "my_activ_func.h"

dtype sigmoid(dtype x)
{
    return (1 / (1 + exp(-x)));
}
