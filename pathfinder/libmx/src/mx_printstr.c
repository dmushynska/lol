#include "../inc/libmx.h"

void mx_printstr(const char *s) {
	int f = mx_strlen(s);

	write(1, s, f);
}

