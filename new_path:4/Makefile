NAME = pathfinder

OBJ = obj
LIBMX.A = ./libmx/libmx.a
LIB = libmx

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic

FILES = main \
	mx_test_file \
	mx_test_line \
	mx_allline \
	mx_test_countwords \
	mx_isdigit \
	mx_isword \
	mx_creat_arr \
	mx_count \
	mx_printerr \
	mx_printinterr \
	mx_del_intarr \
	mx_write_matrix \
	mx_creat_second_arr \
	mx_write_result \
	mx_search_rout \
	mx_print_result \
	mx_search_j \
	mx_sort_arr_int \
	mx_search_m_func \
	mx_push_front_new

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OUT = $(addsuffix .o, $(FILES))

INC = -Iinc -Ilibmx/inc

all: install uninstall

install:
	@mkdir -p $(OBJ)
	@clang $(CLANG) -c $(SRC) $(INC)
	@mv $(OUT) $(OBJ)
	@make install -C $(LIB)
	@clang $(CLANG) $(SRC) $(LIBMX.A) -o $(NAME) $(INC)

uninstall:
	@rm -rf $(OBJ)
	@make uninstall -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@rm -rf $(OUT)

reinstall: uninstall install
	@make reinstall -C $(LIB)
