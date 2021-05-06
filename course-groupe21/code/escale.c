#include "escale.h"
#include "assert.h"
#include "math.h"
#include <stdlib.h>

struct escale_t{
  double x;
  double y;
  char nom;
  double temps;
};


Escale *create(double a, double b, char name){
  Escale *temp = (Escale *)malloc(sizeof(Escale));
  if (temp == NULL){
    return NULL;
  }

  temp->x = a;
  temp->y = b;
  temp->nom = name;
  temp->temps = 0.0;

  return temp;
}// end create()


void escale_destruct(Escale **e){
  assert(e != NULL);

  free(*e);
  *e=NULL;
}//end escale_destruct()


double coord_x(Escale *e){
  return e->x;
}//end coord_x()


double coord_y(Escale *e){
  return e->y;
}//end coord_x()


char get_name(Escale *e){
  return e->nom;
}//end get_name()


double distance(Escale *e, Escale *d){
  assert(e != NULL && d != NULL);

  return sqrt(( d->x - e->x )*( d->x - e->x ) + ( d->y - e->y )*( d->y - e->y ));
}//end distance()


bool set_time(Escale *e, double *nouveau_temps){
  assert(e != NULL);
  e->temps = *nouveau_temps;
  return true;
}//end set_time
