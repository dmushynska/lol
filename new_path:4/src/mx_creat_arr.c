#include "pathfinder.h"

int **mx_creat_arr(const char *str) {
    int i = 0;
    int j = 0;
    int len = mx_count(str) + 1;
    int **n = (int **)(malloc)(sizeof(int *) * (len));

    for (int q = 0; q < len; q++) {
        n[q] = (int *)malloc(sizeof(int) * (len));
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            n[i][j] = -1;
        }
    }
    return n;
}
