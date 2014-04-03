#include <stdio.h>
#include <stdlib.h>

void drucke(int n, char s){
     int lines, cols, cent, i, j, f;
     char **lamda;
     lines= n+3;
     cols= 2*n+7;
     cent= cols/2;
     
     lamda = (char**)malloc(lines * sizeof(char*));
     for(i=0; i<lines; i++){
              lamda[i]=(char*)malloc(sizeof(char)*cols);
     }
     
     for(i=0; i<lines; i++){
              for(j=0; j<cols; j++){
                       lamda[i][j]= ' ';
              }
     }
	j=0;
     for(i=0; i < lines; i++){
             // for(j=0; j < lines-1; j++){
                       if(i==(lines-1)){
                                      for(f=0; f<3; f++){
                                               lamda[i][f]= s;
                                               lamda[i][cols -f-1]= s;
                                      }
                       }else{
                             lamda[i][cent +j]= s;
                             lamda[i][cent -j]= s;
                             }
				j++;
              //}
     }
   
     for(i=0; i < lines; i++){
              for(j=0; j<cols; j++){
                       printf("%c", lamda[i][j]);
              }
              printf("\n");
     }
     
     for(i=0; i<lines; i++){
              free(lamda[i]);
     }
     free(lamda);
}

int main(){
int s;
char l;
printf("groesse und zeichen:  ");
scanf("%i %c", &s, &l);
             drucke(s, l);
             getchar();
    
return 0;
}
                       
                                               

