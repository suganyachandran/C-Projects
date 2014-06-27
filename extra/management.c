#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct members{
  char name[20];
  char v_name[20];
  char bday[15];
  char phone[15];
};

//create a list if there is none
void check4file(char *arg){
  FILE *list;
  if( (list=fopen(arg, "r")) == NULL){
    list=fopen(arg, "w");
  }
  
  fclose(list);
}

//write new data to file
void write2file(struct members *new, char *arg){
  FILE *list;
  int num = findstring(arg) +1;
  
  list=fopen(arg, "a");
  fprintf(list, "\n\nEntry number %i", num);
  fprintf(list, "\nLastname:.......%s", new->name);
  fprintf(list, "\nSurename:.......%s", new->v_name);
  fprintf(list, "\nBirthday:.......%s", new->bday);
  fprintf(list, "\nPhone:..........%s", new->phone);
  
  fclose(list);
}

//create new contact data
void newdata(char *arg){
  struct members new;
  printf("\n\n\n\n");
  system("clear");
  check4file(arg);
  
  printf("\n\nEnter lastname:   ");
  scanf("%s", new.name);
  printf("\nEnter name:   ");
  scanf("%s", new.v_name);
  printf("\nEnter date of birth:   ");
  scanf("%10s", new.bday);
  printf("\nEnter phonenumber   ");
  scanf("%s", new.phone);
  
  write2file(&new, arg);
}

//Display the file using vim
void openfile(char *arg){
  FILE *list;
  char string[80]="vi ";
  system("clear");
  if( (list=fopen(arg, "r")) == NULL){
    printf("\nError! No data!\n");
  } else{
    strcat(string, arg);
    system(string);
  }
}

//remove the file
void removefile(char *arg){
  FILE *list;
  char string[80]="rm ";
  system("clear");
  if( (list=fopen(arg, "r")) == NULL){
    printf("\nError! No data!\n");
  } else{
    printf("\nRemove File");
    strcat(string, arg);
    system(string);
    printf("\n\n");
  }
}

//search file
int findstring(char *arg){
  FILE *list;
  char suche[30]="Lastname";
  char line [50];
  int res=0;
  
  if( (list=fopen(arg, "r")) == NULL){
    printf("\nError! No data!\n");
  } else{
    
    list=fopen(arg, "r");
    
      while((fgets(line, 50, list)) != NULL){
      if( (strstr(line, suche)) != 0){
	res++;
      }
    }
      fclose(list);
  }
  return res;
}


void getentry(char *arg){
  FILE *list;
  char suche[30];
  char line [50];
  char erg;
  
  int res=0, linecount=1, found;
    
  if( (list=fopen(arg, "r")) == NULL){
    printf("\nError! No data!\n");
  } else{
    
    printf("\n What are you looking for?   ");
    scanf("%s", suche);
    
    list=fopen(arg, "r");
    while((fgets(line, 50, list)) != NULL && res==0){
      if( (strstr(line, suche)) != 0){
	res++;
      }
      linecount++;
    }
    
    found=linecount-1;
    linecount = 0;
    
    fclose(list);
    list=fopen(arg, "r");
    
    while((fgets(line, 50, list)) != NULL && linecount!=found){
      if( (strstr(line, "Entry number")) != 0){
	  erg = line[13];
      }
      //printf("%s\n", line);
      linecount++;
    }
    printf("\n\n%s belongs to entry number %c\n", suche, erg);
    fclose(list);
  }
}
  

void displayhelp(char *arg){
  printf("\n\t\tManpage of management");
  printf("\nThis tool creates and edits contact lists.");
  printf("\nUsing: %s path/to/file", arg);
  printf("\nPossible usings:");
  printf("\n\t[1]Neuer Datensatz\n\t[2]Liste Anzeigen\n\t[3]Datei durchsuchen\n\t[4]Anzahl der Datensaetze\n\t[5]Exit\n\t[0]Liste loeschen\n");
  printf("\n[1]Creates an new entry to the list you choose. It also creates an new list at \n\tthe choosen path if there isn't any");
  printf("\n[2]Displays the choosen list using vim");
  printf("\n[3]Searches the choosen list for a string you have to enter and returns the\n\t entry number");
  printf("\n[4]Displays the number of entries in a list");
  printf("\n[5]To leave the program");
  printf("\n[0]Removes the list\n\n");
}
  

//MAIN
int main(int argc, char *argv[]){
  int cmd, loop=1;
  if(argc != 2){
    printf("\nError! Using: %s path/to/file", argv[0]);
    printf("\nUse %s --help\n", argv[0]);
    return 1;
  }
  if( (strcmp(argv[1], "--help")) == 0){
    displayhelp(argv[0]);
    return 0;
  }
  
  
  printf("\n\t\t\tDatenverwaltung");
  printf("\nWaehlen Sie eine Option.");
  
  do{
  printf("\n\t[1]Neuer Datensatz\n\t[2]Liste Anzeigen\n\t[3]Datei durchsuchen\n\t[4]Anzahl der Datensaetze\n\t[5]Exit\n\t[0]Liste loeschen\n");
  scanf("%i", &cmd);
  
  switch (cmd){
    case 1: {
      newdata(argv[1]);
      break;
    }
    case 2: {
      openfile(argv[1]);
      loop = 0;
      break;
    }
    case 3: {
      getentry(argv[1]);
      loop = 0;
      break;
    }
    case 4: {
     // findstring(argv[1]);
      printf("\n\nThere are %i matches\n\n", findstring(argv[1]) );
      loop= 0;
      break;
    }
    case 5:{
      loop=0;
      break;
    }
    case 0: {
      removefile(argv[1]);
      loop = 0;
      break;
    }
  }
  
  }while(loop == 1);
  
  return 0;
}
    