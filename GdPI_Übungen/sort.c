#include <stdio.h>
#include <stdlib.h>

//**************************************************//
//					Sortierung						//
//**************************************************//

int sort(int array[]){
	int count=0, i=0, temp;
	while(count<10){
		for(i=0; i<10; i++){
			if(array[i]>array[i+1]){
				temp=array[i+1];
				array[i+1]=array[i];
				array[i]=temp;
			}
		}
		count++;
	}
}

//**************************************************//
//						I/O							//
//**************************************************//

int input(int zahlen[]){
	int i;
	printf("\nBitte 10 Zahlen eigeben:  ");
		for(i=0; i<10; i++){
			//while(getchar()!= '\n');
			scanf("%i", &zahlen[i]);
		}
	printf("Danke");
}

int output(int zahlen[]){
	int i;
	for(i=0; i<10; i++){
		printf("%i ", zahlen[i]);
	}

}


//**************************************************//
//						MAIN						//
//**************************************************//

int main(){
	int zahlen[10];
	int i;

	input(zahlen);
	
	system("clear");

	printf("\n\nDie Zahlen:  ");	
	output(zahlen);

	sort(zahlen);

	printf("\n\nSortiert:  ");	
	output(zahlen);
	printf("\n\a");
return 0;
}
