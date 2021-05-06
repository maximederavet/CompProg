#include "escale.h"
#include <stdlib.h>

struct escale_t{
  double x;
  double y;
  char nom;
  double temps;
};


Escale *create(double a, double b, char name){
  Escale *temp = malloc(sizeof Escale);
  if (temp == NULL);
    return NULL;

  temp->x = a;
  temp->y = b;
  temp->nom = name;
  temp->temps = 0.0;
}// end create()
