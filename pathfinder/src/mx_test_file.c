#include "../inc/pathfinder.h" 

static void test(char const *argv[]) {
	int fd = 0;
	char *str = mx_file_to_str(argv[1]);

	if ((fd = open(argv[1], O_RDONLY))== -1) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" does not exist \n");
		close(fd);
		free(str);
		exit(0);
	}
	if (mx_strlen(str) == 0) {
		mx_printerr("error: file ");
		mx_printerr(argv[1]);
		mx_printerr(" is empty \n");
		free(str);
		exit(0);
	}
	free(str);
}

void mx_test_file(int argc, char const *argv[]) {
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename] \n");
		exit(0);
	}
	if (argc > 1)
		test(argv);
}
