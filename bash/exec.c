#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
	//printf("This program is executed with these command line\n");
	//printf("arguments: ");
	printf("argv[1] = %s\n", argv[1]);
	printf("argv[2] = %d\n", atoi(argv[2]));
	int a = atoi(argv[2]);
	int b = atoi(argv[1]);
	a = a + b;
	printf("return: %d\n", a);
	exit(1);
}