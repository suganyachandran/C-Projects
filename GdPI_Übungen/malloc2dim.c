#include <stdio.h>
#include <stdlib.h>
#include <curses.h>


int main(){

int z, s ,i, j;
char zent, umg;
char **array;

printf("\nZeilen:...");
scanf("%i", &z);

printf("\nSpalten:...");
scanf("%i", &s);

while(getchar() != '\n');
printf("\nZent:...");
scanf("%c", &zent);

while(getchar() != '\n');
printf("\nUmgebung:...");
scanf("%c", &umg);

if( (array = malloc(sizeof(char*) * s)) == NULL){
	printf("Zu wenig Speicher!");
	return 1;
}

for(i=0; i<s; i++) {
	if( (array[i] = malloc(sizeof (char) * z)) == NULL){
		printf("Zu wenig Speicher!");
		return 1;
	}
}

for(i=0; i < z; i++){
	for(j = 0; j < s; j++){
		array[i][j]=umg;
	}
}

array[z/2][s/2] = zent;


for(i=0; i < z; i++){
	for(j = 0; j < s; j++){
		printf("%c ", array[i][j]);
	}
	printf("\n");
}

for(i=0; i < s; i++){
	free(array[i]);
}

free(array);

return 0;

}
