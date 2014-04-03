#include <stdio.h>
#define LineSize 15
#define ColSize 10



void printarray(char anarray[][ColSize], int thelines, int thecols, char usercoice){
     int i, j;
     printf("\n\n");
	
	if(thecols == 1){
		printf("\n\t\t\t   Inhalt Hex\t | Dezimal\n");
		for(i=0; i < thelines; i++){
			//Adresse
			if(i<10){
				printf("Adresse__%i: %p  ->  ",i, &anarray[i][1]);
			}else{
		 	printf("Adresse_%i: %p  ->  ",i, &anarray[i][1]);
			}
		//Inhalt
         	for(j=0; j < thecols; j++){
				printf("%8x\t | %d\n", anarray[i][j], anarray[i][j]);
			}
		}
	}
	else {

		
	for(j=0; j<thecols; j++){
	printf(" COL%i          \t",j);
	}
	printf("\n");
     for(i=0; i < thelines; i++){
         for(j=0; j < thecols; j++){
				if(usercoice == 'a'){
                 	 printf("%p\t", &anarray[i][j]);
                  	}
				else{
					printf("%8x\t", anarray[i][j]);
                  }
		}
          printf("   Line%i\n", i);}
	}
}   


int main(){
int lines, cols;
char choice;
char array[LineSize][ColSize];
printf("\n\nAktuell besitzt das Array %d Zeilen und %d Spalten", LineSize, ColSize);
printf("\nWie viele Zeilen sollen angezeigt werden?  ");
scanf("%i", &lines);
printf("\nWie viele Spalten sollen angezeigt werden?  ");
scanf("%i", &cols);
while(getchar() != '\n');
if(cols != 1){
printf("Soll der Inhalt oder die Adresse[a] angegeben werden?   ");
scanf("%c", &choice);
}

printarray(array, lines, cols, choice);

printf("\n\n\tDONE!");
return 0;
}
    
