#ifndef __ESCALE__
#define __ESCALE__


typedef struct escale_t Escale;

/**
crée une nouvelle escale
Précondition : /
Postcondition : retourne un pointeur vers l'escale créée(coord X, coord Y, nom de l'étape, temps pour cette escale ),
                Null si erreur
*/

Escale *escale(double x, double y, char nom, double temps);



#endif
