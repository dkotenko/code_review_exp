#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PLATINUM_THICKNESS 21500

#define _GNU_SOURCE
#define EPSILON 1e-7
#define EQUAL(a,b) a - b < EPSILON
#define ERROR "n/a"
#define ERR_EXIT fprintf(stderr, "%s\n", ERROR); exit(1);

double calc_v(double r) {
    return (4. / 3.) * M_PI * pow(r, 3);
}

double calc_m(double v) {
    return v * PLATINUM_THICKNESS;
}

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

int main(void) {

    char *line = read_line();
    double r = 0;
    char *ptr = NULL;
    r = strtod(line, &ptr);
    if (EQUAL(r, 0) || r < 0) {
        ERR_EXIT
    }
    free(line);

    printf("%.0lf", calc_m(calc_v(r)));
    return 0;
}