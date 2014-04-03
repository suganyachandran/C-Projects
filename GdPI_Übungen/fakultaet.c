#include <stdio.h>

//Leeren des Eingabepuffers
void io(){
  fflush(stdout);
  while(getchar() != '\n');
}

//funkt. listing
void list(int x){
	int a, n, b;
	unsigned long long int eing;
	for(a=x; a>=0; a--){
		b=2;
		eing=1;
		n=a;
		while(n>1){
  			eing=eing*b;
  			b++;
  			n--;
		}
		if(a<10){
			printf("\n%d!   =   %lli", a, eing);
		}else{
			printf("\n%2d!   =   %lli", a, eing);
		}
	}
printf("\n\nDONE!");
}		
		
int main(){
int n, i;
unsigned long long int eing;
int b=2;
char choose;
puts("Press [Enter] to start");
//leeren des Eingabepuffers
io();
puts("\n\n\t<<Programm zur Berechnung der natuerlichen Fakultaet>>");
puts("\t\t\t_-fuer 0 < n < 25-_");
printf("\n\nGeben Sie die Zahl ein, deren Fakultaet Sie wissen moechten: ");
scanf("%i", &n);
//Absicherung für korrekte Eingabe
if(n>25 || n<0){
  puts("ERROR: Fehlerhafte Eingabe!");
  return 1;
}

//Listing?
printf("\nFuer eine Auflistung aller Fakultaeten bis zu diesm Wert? (y/n)");
while(getchar() != '\n');
scanf("%c", &choose);
if(choose == 'y'){
	list(n);
}
//End_listing
else{
puts("\n");
i=n;
eing=1;
//Berechnung der Fakultät
while(n>1){
  eing=eing*b;
  b++;
  n--;}
//Ausgabe
printf("\t\t\t~~~~n=%d  n!=%lld~~~~\n\n",i,eing);
}
return 0;
}
