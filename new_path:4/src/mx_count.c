#include "pathfinder.h"

static int str_to_int(const char *str) {
    int n = 0;

    for (int i = 0; i < mx_strlen(str); i++) {
        n = n * 10;
        n = n + (str[i] - 48);
    }
    return n;
}

int mx_count(const char *str) {
    int i = 0;
    char *s = mx_strdup(str);
    int n;
    char *dst;

    while (mx_isdigit(s[i]) == 1)
        i++;
    dst = mx_strnew(i);
    for (int j = 0; j < i; j++)
        dst[j] = str[j];
    n = str_to_int(dst);
    free(dst);
    free(s);
    return n;
}
