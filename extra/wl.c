#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char *increment(int digits, int index, char currentsymbol, char *word){
  char *pass;
  pass=malloc(sizeof(char) * (digits+1));
  pass = word;
  pass[index] = currentsymbol;
  pass[digits] = '\0';
  return pass;
}
  


int main(){
  char *word;
  char currentsymbol='a';
  int digits=3, index=0;
  FILE *dump;
  
  
  word=malloc(sizeof(char) * (digits+1));
  dump=fopen("/home/lars/OP_Wordlist/wl.lst", "a");
  
  while(index < digits+1){
    
    word=increment(digits, index, currentsymbol, word);
    if(currentsymbol == 'z'){
      index++;
      if(index >digits){
      currentsymbol='a';
      } else {
	continue;
      }
    }
    currentsymbol++;
      fprintf(dump, "%s\n", word);
    }
  
  return 0;
}