#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void scores(int cou){
	FILE *score;
	char name[20];
	char yn;

	time_t t;
	struct tm *ts;
	t = time(NULL);
	ts = localtime(&t);

	printf("\nTo write your score to the logfile enter 'y':...");
	while(getchar() != '\n');
	scanf("%c", &yn);
	if(yn == 'y'){
		if( (score=fopen("/home/lars/mybins/rand_game.log", "r")) == NULL){
			score=fopen("/home/lars/mybins/rand_game.log", "w");
		}else{
			score=fopen("/home/lars/mybins/rand_game.log", "a");
			}
		printf("\nEnter name:...");
		while(getchar() != '\n');
		scanf("%s", &name[0]);
		fprintf(score,"\n%s needed %d attampts\t%s\n", name, cou, asctime(ts));
		fclose(score);
	}else{
	printf("\nBye!\n");
	}
}


int try(char gues[]){
	int uin;
	printf("\tPick a number between 0 and 9:...");
	scanf("%i", &uin);
	if(uin > 9 || uin < 0){
		printf("ERROR: Legit numbers 0-9");
	}else{
	gues[uin]='x';
	}
	return uin;
}

void fillArray(char anarray[]){
int i;
	for(i=0; i<10; i++){
		anarray[i]= '_';
	}
}


int main (){
int r, count, rem, i;
char mark[11]={'_'};
char guess[11]={'_'};
char num[11]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char quit='a';

while(quit != 'q'){
fillArray(mark);
fillArray(guess);
count = 1;
printf("\t\t\tGuess a random number\n");
printf("\t\t\t        v2.0\n\n\n");
srand( time(NULL) );
r = rand() % 9;
mark[r] = 'o';
while(count <= 3){
if(try(guess) == r){
	printf("\n\nWell done! The number was %d\nYou needed %d attampts\n", r, count);
	scores(count);
	goto ende;	
	} else{
		system("clear");
		rem = 3-count;
		printf("\nSorry wrong number. Guess again. Attampts remaining: %d\n\n", rem);
		count++;
		}
}

sleep(1);
system("reset");
printf("\n\nSorry no attampts ramaining. You lost.\n\n");

for(i=0; i<10; i++){
	printf("%c ", num[i]);
}
printf("\n");
for(i=0; i<10; i++){
	printf("%c ", mark[i]);
}

printf(" Random Number\n");

for(i=0; i<10; i++){
	printf("%c ", guess[i]);
}

printf(" User choices\nGraphical display of attampts\n");
ende:
printf("\npress [q] to quit   ");
while(getchar() != '\n');
scanf("%c", &quit);
}
return 0;
}

		
