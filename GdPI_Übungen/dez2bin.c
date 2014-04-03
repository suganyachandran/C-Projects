#include <stdio.h>
#include <math.h>

int main(){
  int dez, lol;
  int x, i;
  int bin[31];
for(i=0; i<32; i++){
  bin[i]=0;
}
fflush(stdout);
printf("\n\n\nGanzzahl zur Umrechnug:  ");
scanf("%i", &dez);
lol=dez;
x=dez;
for(i=31; i>=0; i--){
  bin[i]=x%2;
    if(bin[i]==1){
      x=(x-1)/2;
    }
    else{
      x=x/2;
    }
  }
printf("\n\nDezimal  %i entspricht ", lol);
i=0;
while (i<32){
  printf("%i", bin[i]);
  i++;
}
printf("\n\n");
return 0;
}
