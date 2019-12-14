#include "../inc/pathfinder.h"

static void printcharerr(char c) {
	write(2, &c, 1);
}

static int checkint(int n) {
	int check = 0;

	if(n == -2147483648) {
		printcharerr('-');
		printcharerr('2');
		n = 147483648;
	}
	if (n == 0)
		printcharerr('0');
	if(n < 0) {
		n = n * -1;
		check = 1;
	}
	return check;
}

void mx_printinterr(int n) {
	int pow = 1;
	int buffer = 0;
	int count = 0;
	int check = checkint(n);
	int i = 0;

	buffer = n;
	while(n != 0) {
		n = n / 10;
		count++;
	}
	for(i = 0; i < count - 1; i++)
		pow = pow * 10; 
	if(check)
		printcharerr('-');
	for(i = 0; i < count; i++) {
		printcharerr(buffer / pow + 48);
		buffer = buffer % pow;
		pow = pow /10;
	}
}
