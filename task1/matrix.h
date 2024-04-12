#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ERROR "n/a"

typedef struct {
    int64_t size;
    int64_t **arr;
} matrix_t; 