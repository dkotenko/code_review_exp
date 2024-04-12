#define _GNU_SOURCE
#include "matrix.h"

#define ERR_EXIT fprintf(stderr, "%s\n", ERROR); exit(1);

char *read_line(void)
{
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        read = getline(&line, &len, stdin);
        printf("Retrieved line of length %zu :\n", read);
        printf("input : %s", line);
        return line;
}

matrix_t create_matrix(int size) {
    matrix_t m = {size=size};
    m.arr = calloc(size, sizeof(int64_t *));
    for (int i = 0 ; i < size; i++) {
        m.arr[i] = calloc(size, sizeof(int64_t));
    }
    return m;
}

void free_all(matrix_t a, matrix_t b) {
    for (int i = 0 ; i < a.size; i++) {
        free(a.arr[i]);
        free(b.arr[i]);
    }
    free(a.arr);
    free(b.arr);
}


void mult_matrices(matrix_t a, matrix_t b) {
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            int tmp = 0;
            for (int k = 0; k < b.size; k++) {
                tmp += a.arr[i][k] * b.arr[k][j];
            }
            printf("%d\t", tmp);
        }
        printf("\n");
    }
}

void populate_matrix(matrix_t m) {
    for (int i = 0; i < m.size; i++) {
        char *row = read_line();
        char *endptr = NULL;
        for (int j = 0; j < m.size; j++) {
            char *num_str = strtok(row, " ");
            m.arr[i][j] = (int64_t)strtoll(num_str, &endptr, 10);
        }
        free(row);
    }
}

int main(void) {
    char *size_str = read_line();
    int64_t size = (int64_t)atoi(size_str);
    free(size_str);
    if (size < 1) {
        ERR_EXIT
    }

    matrix_t a = create_matrix(size);
    matrix_t b = create_matrix(size);

    populate_matrix(a);
    populate_matrix(b);
    mult_matrices(a, b);


    free_all(a, b);
    printf("converted: %lld\n", size);
}