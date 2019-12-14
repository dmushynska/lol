NAME = pathfinder

OBJ = obj

LIBMX.A = ./libmx/libmx.a

LIB = libmx

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic

SRC = src/main.c \
	src/mx_test_file.c \
	src/mx_test_line.c \
	src/mx_allline.c \
	src/mx_test_countwords.c \
	src/mx_isdigit.c \
	src/mx_isword.c \
	src/mx_creat_arr.c \
	src/mx_count.c \
	src/mx_printerr.c \
	src/mx_printinterr.c \
	src/mx_del_intarr.c \
	src/mx_write_matrix.c \
	src/mx_creat_second_arr.c \
	src/mx_write_result.c \
	src/mx_search_rout.c \
	src/mx_search_rout_2.c \
	src/mx_print_result.c \
	src/mx_search_j.c \
	src/mx_sort_arr_int.c \
	src/mx_search_m_func.c

OUT = main.o \
	mx_test_file.o \
	mx_test_line.o \
	mx_allline.o \
	mx_test_countwords.o \
	mx_isdigit.o \
	mx_isword.o \
	mx_creat_arr.o \
	mx_count.o \
	mx_printerr.o \
	mx_printinterr.o \
	mx_del_intarr.o \
	mx_write_matrix.o \
	mx_creat_second_arr.o \
	mx_write_result.o \
	mx_search_rout.o \
	mx_search_rout_2.o \
	mx_print_result.o \
	mx_search_j.o \
	mx_sort_arr_int.o \
	mx_search_m_func.o


INC = inc/pathfinder.h

all: install uninstall

install:
	@mkdir -p $(OBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@mv $(OUT) $(OBJ)
	@make install -C $(LIB)
	@clang $(CLANG) $(SRC) $(LIBMX.A) -o $(NAME) -I $(INC)

uninstall:
	@rm -rf $(OBJ)
	@make uninstall -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@rm -rf $(OUT)

reinstall: clean all
	@make reinstall -C $(LIB)
