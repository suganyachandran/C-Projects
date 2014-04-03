#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print2file(float *vals, char **argv){
  FILE *list;
  
  if( (list=fopen("/home/lars/Dokumente/Pudding.txt", "r")) == NULL){
    list=fopen("/home/lars/Dokumente/Pudding.txt", "w");
  }else{
    list=fopen("/home/lars/Dokumente/Pudding.txt", "a");
  }

    fprintf(list, "\nEnkaufsliste für %.1f %s Schildkroetenpudding wird benoetogt:\n", atof(argv[1]) , argv[2]);
    fprintf(list, "\n\t%.3f g Fisch", vals[0]);
    fprintf(list, "\n\t%.3f g Gruenfutter", vals[1]);
    fprintf(list, "\n\t%.3f stk Ei", vals[2]);
    fprintf(list, "\n\t%.3f ml Milch", vals[3]);
    fprintf(list, "\n\t%.3f ml Wasser", vals[4]);
    fprintf(list, "\n\t%.3f TL Olivenoel", vals[5]);
    fprintf(list, "\n\t%.1f SKT Glukose\n\n", vals[6]);
    
  fclose(list);
}

int main (int argc, char *argv[]){
  
  /*Einheiten:
   * fisch, gruen: g(gramm)
   * ei, gluk: stk
   * milch, wasser: ml
   * oel: tl (Teaspoon)
  */
  
  float fisch=150, gruen=387.5, ei=0.5, milch=125, wasser=200, oel=0.5, gluk=30;
  float amount, fact;
  float values[7];
  char yn;
  
  if(argc != 3){
    printf("Error! Using: %s [amount] [unit]\n", argv[0]);
    return 1;
  }else{
    
    printf("\n\tTool zur Berechnung der Einkaufliste fuer Schildkroetenpudding\n");
    amount = atof(argv[1]);
    
    if(strcmp(argv[2], "ml") == 0){
      fact= 0.001;
      }else{
	fact=1;
    }

    
    //amount= amount * fact;
    
    fisch *= amount;
    gruen *= amount;
    ei *= amount;
    milch *= amount;
    wasser *=amount;
    oel *= amount;
    gluk *= amount;
    
    printf("\nEnkaufsliste für %.1f %s Schildkroetenpudding wird benoetogt:\n", atof(argv[1]) , argv[2]);
    printf("\n\t%.3f g Fisch", fisch*fact);
    printf("\n\t%.3f g Gruenfutter", gruen*fact);
    printf("\n\t%.3f Stk Ei", ei*fact);
    printf("\n\t%.3f ml Milch", milch*fact);
    printf("\n\t%.3f ml Wasser", wasser*fact);
    printf("\n\t%.3f TL Olivenoel", oel*fact);
    printf("\n\t%.1f Stk Glukose", gluk*fact);
    
    printf("\n\nAusgabe in Datei? <y/n>   ");
    scanf("%c", &yn);
    
    if (yn == 'y'){
      printf("\nWriting to file...");
      values[0]=fisch;
      values[1]=gruen;
      values[2]=ei;
      values[3]=milch;
      values[4]=wasser;
      values[5]=oel;
      values[6]=gluk;
      print2file(values, argv);
    }
    
    printf("\n\nAdee\n");
    return 0;
  }
}