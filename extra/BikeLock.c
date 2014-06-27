#include <stdio.h>
#include <stdlib.h>

int loop = 1;
int *guess = NULL;
int *combo = NULL;
int i = 1;
int comp;

void printGuess(){
  int j;
  printf("Kombination: ");
  for (j = 0; j<comp; j++){
    printf("%i ", guess[j]);
  }
  printf("\nVersuche: %i", i);
  printf("\n\n");
}

void compare(){
  int i;
  int check = 0;
  for(i=0; i<comp; i++){
    if(guess[i] == combo[i]){
      check ++;
    }
  }
  
  if(check == comp){
    printf("\nTreffer\n");
    printGuess();
    loop = 0;
  } else{
    printf(".");
  }
}

/*
 if(combo[0] == guess[0] && combo[1] == guess[1] && combo[2] == guess[2] && combo[3] == guess[3]){
    loop = 0;
    printf("\n\nFertig! Kombination: %i %i %i %i\nVersuch Nr.: %i\n\n", combo[0], combo[1], combo[2], combo[3], i); 
  } else {
    printf("\nVergleiche: %i %i %i %i  -> false", guess[0], guess[1], guess[2], guess[3]);
    loop = 1;
  }
}
*/


void initRand(int i){
  srand(time(NULL) * i);
  guess[i] = rand() % 9; 
}

void increment(int len){
  int index = len;
  //compare();
  if(guess[len] == 9){
    index --;
    guess[len] = 0;
    increment(index);
  } else{
    guess[len] ++;
    compare();
    i++;
  }
}


int main(int argc, char* argv[]){
  
int len = argc - 1;
int k;
combo = malloc(sizeof(int)*len);
guess = malloc(sizeof(int)*len);

comp = len;
//combo[0] ist höchstwertige Stelle

for(k=0; k < len; k++){
  combo[k] = atoi(argv[k+1]);
}

for(k = 0; k < len; k++){
  initRand(k);
}

while(loop == 1){
  increment(len - 1);
}
return 0;
}