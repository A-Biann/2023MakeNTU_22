#pragma once
#include "stdlib.h"
#include "stdbool.h"

typedef struct _msg {
    bool pending;
    char value;
} inter_data;
