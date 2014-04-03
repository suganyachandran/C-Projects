#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int i;
	int size = 20;
	char input[size];
	FILE *file;   
	file = fopen("/home/lars/mystuff/code/RandDump.log", "r");
	fgets(input, size, file);
	printf("\nInput was: %s\n", input);
return 0;
}

