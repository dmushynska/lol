#include "pathfinder.h"

void mx_del_intarr(int ***arr, int s) {
    int **j = *arr;

    for (int i = 0; i < s; i++) {
        free(j[i]);
    }
    free(*arr);
    *arr = NULL;
}
