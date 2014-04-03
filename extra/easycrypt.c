#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Global variable
FILE *file;

int make(char *arg){
  int r;
  int krypt;
  char raw[6];
  
  if( (file=fopen(arg, "r")) == NULL){
  
    srand( time(NULL) );
    r = rand();
    r = r%10000 + 111;
    krypt=r*r;
  
    r = r%1050;
    krypt = krypt + r * 2;
    file = fopen(arg, "w");
    fprintf(file, "%i", krypt);
    fclose(file);
  } else {
    file =fopen(arg, "r");
    fgets(raw, 7, file);
    krypt = atoi(raw);
    fclose(file);
  }
  
  return krypt;
}

int getkey(long int krypt, int pass){
  int key;
  key = krypt%pass;
  key = key % 5;
  return key;
}

//Kryption
char *dokrypt(int pass, char *phrase){
  char *k_phrase;
  int len, i;
  
  len = strlen(phrase);
  k_phrase=malloc(sizeof(char) * len);
  
  for(i=0; i<=len; i++){
    if(i==len){
      k_phrase[i] = phrase[i];
    } else{
      k_phrase[i]=phrase[i]+pass;
    }
  }
  
  return k_phrase;
}

//Dekryption
char *dekrypt(int pass, char *k_phrase){
  char *phrase;
  int len, i;
  
  len = strlen(k_phrase);
  phrase=malloc(sizeof(char) * len);
  
  for(i=0; i<=len; i++){
    if(i==len){
      phrase[i] = k_phrase[i];
    } else{
      phrase[i]=k_phrase[i]-pass;
    }
  }
  
  return phrase;
}  

void save(char *arg, char *phrase){
  file=fopen(arg, "a");
  fprintf(file,"\n%s", phrase);
  fclose(file);
}

//MAIN
int main(int argc, char *argv[]){
  int krypt;
  int pass, choose;
  char *phrase, *k_phrase;
  int i;
  
  if(argc != 2){
    printf("Error! Use %s path/to/file", argv[0]);
    return 1;
  }

  phrase=malloc(sizeof(char) * 100);
  k_phrase = malloc(sizeof(char) *100);
  
  for(i=0; i<100; i++){
    phrase[i]= ' ';
    k_phrase[i] = ' ';
  }

  krypt=make(argv[1]);
  
  printf("\n[1]krypt\n[2]dekrypt\n");
  scanf("%i", &choose);

  
  if(choose != 1 && choose != 2){
    printf("Error!");
    return 1;
  }
  
  printf("\n\nEnter your key:   ");
  scanf("%i", &pass);
  pass = getkey(krypt, pass);
  while(getchar() != '\n');
  
  if(choose == 1){
    printf("\nEnter phrase to krypt:   ");
    fgets (phrase, 100, stdin);  
    k_phrase = dokrypt(pass, phrase);
    save(argv[1], k_phrase);
  } else {
    printf("\nEnter phrase to dekrypt:   ");
    fgets (k_phrase, 100, stdin);
    phrase = dekrypt(pass, k_phrase);
  }
  
  printf("\n\nKrypted: %s\n", k_phrase);
  printf("Dekrypted: %s\n\n", phrase);
  
  return 0;
}
  
  
  
  