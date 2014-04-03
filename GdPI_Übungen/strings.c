#include <stdio.h>
#include <stdlib.h>


char *reverse(char *input){

char *invert;
int i, j=0;

	for(i=0; input[i]!='\0'; i++);
	invert=malloc(sizeof(char) *(i+1) );
	
	i--;
	//printf("%i", i);
	while(j<=i){
		invert[j]=input[i - j];
		j++;
	}
	invert[j]='\0';

return invert;
}

int main(){

char input[100];
char *invert;
printf("\nEnter string:  ");
//while(getchar() != '\n');
fgets(input, 100, stdin);

invert=reverse(input);
printf("\n\nYour string: \n%s\nReversed: %s\n", input, invert);
free(invert);

return 0;
}
