#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int gr , i, r;
int *array;
srand( time(NULL) );

	printf("\n\nFeldgroesse:...");
	scanf("%i", &gr);
	
	if ( (array = malloc(sizeof(int) * gr)) == NULL) {
		printf("FEHLER! Zu wenig Speicherplatz!");
		return 1;
		}
printf("\n");
for(i=0; i<gr; i++){
	r = rand() % 50;
	array[i] = r;
	printf("Feldindex %2i enthaelt %2i an Adresse %p\n", i, array[i], &array[i]);
}

printf("\nReservierter Speicher: %iByte\n", gr*sizeof(int));

free (array);

return 0;
}

