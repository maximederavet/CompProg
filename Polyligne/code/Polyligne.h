#ifndef __POLYLIGNE__
#define __POLYLIGNE__


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
 * 
 * @return Une Polyligne ouverte composée du segment AB
 */
Polyligne *CreatePolyligne(Point2D *A, Point2D *B);


/**
 * @fn Polyligne *Open(Polyligne* P);
 * @brief Ouvre la polyligne entrée en argument (si elle est fermée)
 * 
 * @param P, La Polyligne à ouvrir (si elle est fermée)
 * 
 * 
 */
void Open(Polyligne* P);


/**
 * @fn Polyligne *Close(Polyligne* P);
 * @brief Ferme la polyligne entrée en argument (si elle est ouverte)
 * 
 * @param P, La Polyligne à fermer (si elle est ouverte)
 * 
 * 
 */
void Close(Polyligne* P);


/**
 * @fn Polyligne *IsOpen(Polyligne* P);
 * @brief Observateur qui donne l'état d'ouverture de la polyligne
 * 
 * @param P, La Polyligne à checker 
 * 
 *
 */
Boolean IsOpen(Polyligne* P);


/**
 * @fn unsigned int NbrPoint(Polyligne* P);
 * @brief Donne le nombre de points qui composent la polyligne
 * 
 * @param P, La Polyligne dont on cherche le nombre de points
 * 
 * 
 * @return Le nombre de points de la polyligne 
 */
unsigned int NbrPoint(Polyligne* P);


/**
 * @fn Point2D GetPoint(Polyligne* P, unsigned int number);
 * @brief Donne le point se trouvant à l'indice "number"
 * 
 * @param P, La Polyligne contenant le point que l'on cherche
 * @param number, L'indice auquel se trouve le point que l'on cherche
 * 
 * 
 * @return Le nombre de points de la polyligne 
 */
Point2D* GetPoint(Polyligne* P, unsigned int number);


/**
 * @fn Polyligne AddPoint(Polyligne* P, Point2D* A);
 * @brief Ajoute le point "A" à la fin de la polyligne "P"
 * 
 * @param P, La Polyligne contenant dans laquelle on veut ajouter le point A
 * @param A, Le oint que l'on veut ajouter à la polyligne P
 * 
 * 
 * @return Le nombre de points de la polyligne 
 */
Polyligne* AddPoint(Polyligne* P, Point2D* A);


/**
 * @fn Polyligne DeletePoint(Polyligne* P);
 * @brief Supprime le dernier point de la polyligne
 * 
 * @param P, La Polyligne à laquelle on veut supprimer un point
 * 
 * 
 * @return Le nombre de points de la polyligne 
 */
Polyligne* DeletePoint(Polyligne* P);


/**
 * @fn float Length(Polyligne* P);
 * @brief Calcule la longueur de la polyligne
 * 
 * @param P, La Polyligne dont on cherche la longueur
 * 
 * 
 * @return La longueur de la polyligne
 */
float Length(Polyligne* P);


/**
 * @fn Polyligne PolyTranslate(Polyligne* P, Point2D* A);
 * @brief Fait subir la translation de point A à le polyligne P
 * 
 * @param P, La Polyligne qui va subir la translation
 * @param A, Le poit de référence de la translation
 * 
 * 
 * @return La longueur de la polyligne
 */
Polyligne* PolyTranslate(Polyligne* P, Point2D* A);


/**
 * @fn Polyligne PolyRotate(Polyligne* P, Point2D* A, float, x);
 * @brief Fait subir la rotation de point A et d'angle x à la polyligne P
 * 
 * @param P, La Polyligne qui va subir la rotation
 * @param A, Le poit de référence de la rotation
 * @param x, angle de rotation (en degrés) de P par rapport à A (sens trigonométrique)
 * 
 * 
 * @return La longueur de la polyligne
 */
Polyligne* PolyRotate(Polyligne* P, Point2D* A, float x);


#endif