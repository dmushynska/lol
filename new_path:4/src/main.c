#include "pathfinder.h"

static void max_int(char *str) {
    int i = 0;

    while (mx_isdigit(str[++i]) == 1) {
        if (i >= 10) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }
}

static int arr_len(char **arr) {
    int k = 0;

    while (arr[k]) {
        k++;
    }
    return k;
}

static void del(int ***ser, int arrlen) {
    for (int i = 0; i < arrlen; i++) {
        mx_del_intarr(&ser[i], arrlen + 1);
    }
}

int main(int argc, char **argv) {
    char *str = mx_file_to_str(argv[1]);
    int arrlen;
    int ***ser = NULL;
    char **arr = NULL;
    int **new = NULL;

    mx_test_file(argc, argv);
    max_int(str);
    new = mx_creat_arr(str);
    mx_test_countwords(mx_test_line(str), new, &arr);
    arrlen = arr_len(arr);
    ser = mx_creat_second_arr(arrlen, new);
    mx_write_result(ser, arr, arrlen);
    mx_del_strarr(&arr);
    free(str);
    mx_del_intarr(&new, arrlen + 1);
    del(ser, arrlen);
    // system("leaks -q pathfinder");
    return 0;
}
