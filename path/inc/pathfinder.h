#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx.h"

typedef struct s_add_in_func {
    int m;
    int k; // кількість островів
    int i; // звідки
    int h;
    int j; // куди
    int index;
    int new;
    int lol;
    int *str_result;
    char **arr;
    char **new_arr;
} t_hehx;

typedef struct s_result {
    char **arr_result;
    int *result;
    struct s_result *next;
    struct s_result *prev;
} t_result;

bool mx_isword(char c);
bool mx_isdigit(char c);
bool mx_allline(const char *str);

char *mx_rewrite_str(char *n);
char **mx_save_arr(char **arr);
char **mx_test_line(const char *str);

int mx_count(const char *str);
int **mx_creat_arr(const char *str);
int ***mx_creat_second_arr(int i, int **new);
int **mx_test_countwords(char **n, int **new, char ***ar);

void mx_printinterr(int n);
void mx_printerr(const char *s);
void mx_del_intarr(int ***arr, int s);
void mx_create_arr_for_heh(t_hehx *heh);
void mx_test_file(int argc, char **argv);
void mx_copy(char **arr, char ***arr2, t_hehx *heh);
void mx_copy_int(int *arr, int **arr2, t_hehx *heh);
void mx_search_rout(int ***ser, t_hehx *heh, int j);
void mx_write_result(int ***ser, char **arr, int k);
void mx_write_matrix(char **n, int **new, char **arr);
void mx_search_b(int ***ser, char **arr, int j, int i);
void mx_print_list(t_result *struct_result, t_hehx *heh, int **ser);
void mx_search_distance(int **ser, t_hehx *heh, int j,
t_result **struct_result);
void mx_push_front_new(t_result **list, int *str_result, char **new_arr,
t_hehx *heh);
void mx_search_rout_2(int **ser, t_hehx *heh, int *str_result,
t_result **struct_result);

#endif
