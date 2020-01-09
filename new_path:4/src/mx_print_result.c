#include "pathfinder.h"

void mx_print_list(t_result *struct_result, t_hehx *heh, int **ser) {
    int vlad = heh->k + 1;
    int vlad1 = heh->k + 1;

    while (struct_result != NULL) {
        mx_printstr("Path: ");
        mx_printstr(heh->arr[heh->j]);
        mx_printstr(" -> ");
        mx_printstr(heh->arr[heh->i]);
        mx_printstr("\nRoute: ");
        while (struct_result->arr_result[--vlad] == NULL);
        while (vlad > -1) {
            mx_printstr(struct_result->arr_result[vlad--]);
            if (vlad >= 0)
            mx_printstr(" -> ");
        }
        mx_printstr("\nDistance: ");
        while (struct_result->result[--vlad1] == -1);
        while (vlad1 > -1) {
            mx_printint(struct_result->result[vlad1--]);
            if (vlad1 >= 0)
            mx_printstr(" + ");
        }
        mx_printstr(" = ");
        mx_printint(ser[0][heh->i]);
        mx_printchar(10);
        free(struct_result->result);
        mx_del_strarr(&struct_result->arr_result);
        free(struct_result);
        struct_result = struct_result->next;
        vlad = heh->k + 1;
        vlad1 = heh->k + 1;
        mx_printchar('\n');
    }
}
