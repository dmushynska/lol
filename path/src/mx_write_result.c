#include "pathfinder.h"

static void save_arr(char **arr, t_hehx *heh) {
    heh->arr = (char **)malloc(sizeof(char *) * (heh->k + 1));
    for (int i = 0; i < heh->k + 1; i++)
        heh->arr[i] = NULL;
    for (int i = 0; i < heh->k; i++)
        heh->arr[i] = mx_strdup(arr[i]);
}

void mx_write_result(int ***ser, char **arr, int k) {
    t_hehx *heh = (t_hehx *)malloc(sizeof(t_hehx));

    heh->k = k;
    save_arr(arr, heh);
    for (int j = 0; j < k; j++) {
        for (int i = j + 1; i < k; i++) {
            heh->i = i;
            heh->j = j;
            mx_search_rout(ser, heh, j);
        }
    }
    mx_del_strarr(&heh->arr);
    free(heh);
}
