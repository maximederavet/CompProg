#ifndef __ESCALE__
#define __ESCALE__


typedef struct escale_t Escale;

/**
crée une nouvelle escale
Précondition : /
Postcondition : retourne un pointeur vers l'escale créée(coord X, coord Y, nom de l'escale,
                le temps pour cette escale est initialisé à 0.0 tant qu'iln'a pas été enregistré ),
                retourne Null si erreur
*/
Escale *create(double a, double b, char nom);

/**
destructeur
précondition : *e initialisé
poscondition : *e libéré
*/
void escale_destruct(Escale **e);

/**
obtient la coordonée X de l'escale
Precondition : *e initialisé
postcondition : *coord_x = *x
*/
double coord_x(Escale *e);

/**
obtient la coordonée Y de l'escale
Precondition : *e initialisé
postcondition : *coord_y = *y
*/
double coord_y(Escale *e);

/**
obtient le nom de l'escale
Precondition : *e initialisé
postcondition : *get_name = *nom
*/
char get_name(Escale *e);

/**
obtient la distance entre 2 escales
Precondition : *e ∧ *d initialisés
postcondition : *distance = *√[(Xd−Xe)²+(Yd−Ye)²]
*/
double distance(Escale *e, Escale *d);

/**
enregistre le temps pour atteindre l'escale
Precondition : *e initialisé ∧ nouveau_temps > 0
postcondition : *set_time retourne True si le temps est bien enregistré, Null sinon
*/
bool set_time(Escale *e, double *nouveau_temps);

/**
obtient le temps pour atteindre l'escale l'escale
Precondition : *e initialisé
postcondition : *get_time = *temps
*/
double get_time(Escale *e);


#endif
