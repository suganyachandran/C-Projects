#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern void dump(unsigned int input);

int main(){
	char check;
	int loop, i, r;
	unsigned int seed;	
	printf("\nZahl eingeben:...");
	scanf("%i", &seed);
	loop = seed % 3;
	srand( time( NULL) );

	for(i=0; i<=loop; i++){
		r = rand() % seed;
	}
	printf("\n\nRand_Zahl: %d\n", r);
	printf("\nsoll ein listing bis zahl %d erstellt werden? <y/n> ...", seed);
	while(getchar() != '\n');
	scanf("%c", &check);
	if(check == 'y'){
		printf("\nInitialisiere DUMP...\n");
		dump(seed);		
	} else{
		printf("\nFalsche Eingabe oder 'n'...Beende");
	}

return 0;
}

void dump(unsigned int input){
	int j, r;
	char yn;
	FILE *rand_dump;
	if((rand_dump = fopen("/home/lars/mystuff/code/RandDump.log", "r")) == NULL){
		rand_dump = fopen("/home/lars/mystuff/code/RandDump.log", "w");
	} else{
			printf("Altes Dumpfile loeschen?\n<y>");
			while(getchar() != '\n');
			scanf("%c", &yn);
			if(yn == 'y'){
				system("rm ~/mystuff/code/RandDump.log");
			}
			rand_dump = fopen("/home/lars/mystuff/code/RandDump.log", "a");
			}
	srand( time(NULL) );
	fprintf(rand_dump,"\n\n\n0<= RAND <= %d\n", input);
	fprintf(rand_dump,"Durchlauf\tRand\n\n");
	for(j=0; j <= input; j++){
		r = rand()% input;
		fprintf(rand_dump,"    %d\t\t  %d\n",j, r);
	}
	fclose(rand_dump);
printf("\n...DONE!\n");
}
	
	
