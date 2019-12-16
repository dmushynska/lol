#include "../inc/pathfinder.h"

static bool word_2(const char *str, int i) {
	while (str[i]) {
		while (mx_isword(str[i]) == 1)
			i++;
		if ((mx_isword(str[i]) != 1)) {
			if ((str[i] == ',') && (mx_isword(str[i-1]) == 1))
				break;
			else
				return false;
		}
	}
	return true;
}


static bool word(const char *str) {
	int i = 0;

	while (str[i]) {
		while (mx_isword(str[i]) == 1)
			i++;
		if (mx_isword(str[i]) != 1) {
			if ((str[i] == '-') && (mx_isword(str[i-1]) == 1))
				break;
			else
				return false;
		}
	}
	i++;
	if (word_2(str, i) == false)
		return false;
	return true;
}

static bool sortchar(const char *str) {
	int i = mx_get_char_index(str, ',');

	if (str[i + 1] == '0')
		return false;
	if (mx_strlen(&str[i]) > 10)
		return false;
	if (mx_isdigit(str[i + 1]) != 1)
		return false;
	for (i = i + 1; i < mx_strlen(str); i++) {
		while (mx_isdigit(str[i]) == 1) {
			if (str[i + 1] == '\0')
				return true;
			i++;
		}
		return false;
	}
	return true;
}

bool mx_allline(const char *str) {
	if (word(str) == 0)
		return false;
	if (sortchar(str) == 0)
		return false;
	return true;
}
