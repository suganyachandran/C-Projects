#include <stdio.h>
#include <strings.h>

#define MAX 30

struct person{
  int month;
  int date;
  int year;
  char street[MAX];
  int number;
  char city[MAX];
  int plz;
  char v_name[MAX];
  char n_name[MAX];
};//pers1;

void input(struct person *pers){
  printf("\n\nYour input:\n\n\t");
  printf("Name:.............%s\n\t", pers->v_name);
  printf("Lastname:.........%s\n\t", pers->n_name);
  printf("Birthdate:........%d.%d.%d\n\t", pers->date, pers->month,
                                                          pers->year);
  printf("Address:..........%s %i\n\t..................%i %s", pers->street, pers->number, pers->plz, pers->city);
}


int main(){
  struct person pers1;
  printf("\nSurename Lastname: ");
  scanf("%s %s", &pers1.v_name[0], &pers1.n_name[0]);
  printf("\nBirthdate:");
  scanf("%2i.%2i.%4i", &pers1.date, &pers1.month, &pers1.year);
  if(pers1.year < 100){
    pers1.year += 1900;
  }

  printf("\nStreetname, PLZ & Cityname:");
  scanf("%s %i, %i %s",&pers1.street[0], &pers1.number, &pers1.plz, &pers1.city[0]);


  input(&pers1);
  printf("\a\n\nDONE!");

return 0;

}
