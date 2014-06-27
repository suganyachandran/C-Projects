
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printguess(int c, int p1, int p2, int p3, int p4){
  printf("\n");
  printf("*pos %i : %i_%i_%i_%i",c, p1, p2, p3, p4);
}

void allDigits(int k1, int k2, int k3, int k4){
  int g1=0,g2=0,g3=0,g4=0;
  int i, c=1;
  while(i < 10001){

    if(g1 == k1 || g1 == k2 || g1 == k3 || g1 == k4){
      if(g2 == k1 || g2 == k2 || g2 == k3 || g2 == k4){
	if(g3 == k1 || g3 == k2 || g3 == k3 || g3 == k4){
	  if(g4 == k1 || g4 == k2 || g4 == k3 || g4 == k4){
	    c++;
	    printguess(c, g1, g2, g3, g4);
	  }
	}
      }
    }
      g4++;
      
	if(g2==10 && g3==10 && g4==10){
	  g2=0;
	  g1++;
	}
	
	if(g3== 10 && g4 == 10){
	  g3=0;
	  g2++;
	}
	
	if(g4 == 10){
	  g4=0;
	  g3++;	
	}

	i++;
  }
}


int main(int argc, char *argv[]){
  int d1, d2, d3, d4;
  
  if(argc == 5){
    d1=strtol(argv[1], NULL, 10);
    d2=strtol(argv[2], NULL, 10);
    d3=strtol(argv[3], NULL, 10);
    d4=strtol(argv[4], NULL, 10);
  
    allDigits(d1, d2, d3, d4);
  }else{
    printf("\nExecute default numbers '0','2','4','9'...");
    allDigits(0,2,4,9);
  }
  printf("\n\n");
  
  return 0;
}