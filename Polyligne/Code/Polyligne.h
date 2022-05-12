#ifndef __POLYLIGNE__
#define __POLYLIGNE__

#include "boolean.h"
#include "Point2D.h"


/**
 * @fn struct Polyligne
 * @brief Structure de donnée représentant une polyligne 
 * 
 */
typedef struct Polyligne_t Polyligne;


/**
 * @fn Polyligne *CreatePolyligne(Point2D *A, Point2D *B, boolean open);
 * @brief crée une polyligne sur base des 2points formant le premier segment de droite
 * 
 * @param A, Le point de départ du premier segment de la polyligne
 * @param B, Le point d'arrivée du premier segment de la polyligne
 * @param open, Un booléen qui donne l'état d'ouverture de la polyligne. On l'initialise à True par défaut.
 * 
 * \return a brief race with a single step
 */
Polyligne *CreatePolyligne(Point2D *A, Point2D *B, Boolean open);

#endif