#include <stdio.h>
#include <stdbool.h>

extern bool input(int var);
extern void printFib(int var);
int i;

int main(){
	printf("\n\n\n\t\t\t*+~-_Fibonaccifolge_-~+*");
	if(input(i)== false){
		return 1;
	}else{
	printFib(i);
	printf("\n\nSUCCESS!");
	return 0;
	}
}

bool input(int var){
	printf("\n\nWie viele Schritte sollen gelistet werden?   ");
	scanf("%i", &var);
	if(var<3 || var > 47){
		printf("\n\nERROR!\n");
		return false;
	}
	i=var;
	return true;
}

void printFib(int var){
	int erg, a=0, b=1, i=0;
	printf("\n\n0, 1");
		do{
		erg=a+b;
		printf(" ,%i", erg);
		a=b;		
		b=erg;
		i++;
		if(i==17 || i==27 || i== 36){
			printf("\n");
		}		
	}while(i<var-2);
}
