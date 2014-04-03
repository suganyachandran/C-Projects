#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int getLastCol(){
	int col;
	col = COLS -1;
	return col;
}

int getLastLine(){
	int line;
	line = LINES -4;
	return line;
}


void buildBarriers(int li, int col, char **einarray){
	int i, j;
	for(i=0;i<li; i++){
		einarray[i][0]= '#';
		einarray[i][col-1]= '#';
	}
	for(j=0; j<col; j++){
		einarray[0][j] = '#';
		einarray[li-1][j] = '#';
	}
}


void clearArray(int li, int col, char **einarray){
	int i, j;
	for(i=0; i < li; i++){
		for(j=0; j < col; j++){
		einarray[i][j] = ' ';
		}
	}
}

void placeMiddle(int li, int col, char **einarray){
	int i,j;	
	i = li/2;
	j = col/2;
	einarray[i][j] = 'x';
	for(i=0; i < li; i++){
		for(j=0; j < col; j++){
		printf("%c", einarray[i][j]);
		}
	printf("\n");
	}
}


int buildArray(int li, int col, char **einarray){
	int i;
	if((einarray = malloc(sizeof(char* ) * li)) == NULL){
		printf("\nFEHLER! Zu wenig Speicher!");
		return 1;
	}
	for(i=0; i<=li; i++){
		if( (einarray[i]=malloc(sizeof(char) * col)) == NULL ){
			printf("\nFEHLER! Zu wenig Speicher!");
			return 1;
		}			
	}
	clearArray(li, col, einarray);
	buildBarriers(li, col, einarray);
	placeMiddle(li, col, einarray);	
return 0;
}


int main(){

	int lines, cols;
	char **array;
	initscr();
	//getmaxyx(stdscr, lines, cols);

	lines =getLastLine();
	cols  =getLastCol();
	endwin();
	buildArray(lines, cols, array);

printf("\nAllozierter Speicher: %dByte %d lines %d cols\n", ( lines*sizeof(char*) + lines*cols*sizeof(char) ), lines, cols);

return 0;
}
	
	

	
