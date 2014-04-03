#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getrand(){
  return rand() /(double)RAND_MAX;
}


int main(int argc, char *argv[]){
  const double PI_ref = 3.14159265359;
  double diff, tmp;
  int InnerCircle=0;
  int TotalCount=0;
  double mypi;
  double x, y;
  
  srand ( time(NULL) );
  
  diff = atof( argv[1] );
  
  printf("\tBerechnung von PI mitteld der Montecarlo-Methode\n\n");
  //printf("Wie weit darf der Ermittelte PI vom tatsaechlichem abweichen?   ");
  //scanf("%lf", &diff);

  do{
    x = getrand();
    y = getrand();
    
    if( x*x + y*y <=1 ){
      InnerCircle ++;
    }
    
    TotalCount ++;
    
    mypi = 4 * InnerCircle/(double)TotalCount;
    
    if(PI_ref < mypi){
      tmp=mypi - PI_ref;
    } else{
      tmp=PI_ref - mypi;
    }
    
  }while(tmp >= diff);
  
  
  printf("\n\n\nNach %d Durchlaeufen ergab sich für PI: %.13f\n", TotalCount, mypi);
  printf("Referenz-PI:.............................%.13f\n", PI_ref);
  printf("Differenz: %.13f\n", tmp);
  
  return 0;
}
  
  