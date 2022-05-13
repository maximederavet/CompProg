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
 * @pre A != NULL & B != NULL
 * @post A = A_0 & B = B_0 & CreatePolyligne(A,B,open) = P & nbpoint(P) = nbpoint(P) & length(P) = Length(P)
 * 
 * @return Une Polyligne ouverte composée du segment AB
 */
Polyligne *CreatePolyligne(Point2D *A, Point2D *B, Boolean open);


/**
 * @fn Polyligne *Open(Polyligne* P);
 * @brief Ouvre la polyligne entrée en argument (si elle est fermée)
 * 
 * @param P, La Polyligne à ouvrir (si elle est fermée)
 * 
 * @pre P != NULL
 * @post open = True & nbpoint(p) = nbpoint(P_0) - 1 & length = Length(P) - EuclDIst(P->pointarray[nbpoint_0], P->pointarray[0])
 * 
 */
void Open(Polyligne* P);


/**
 * @fn Polyligne *Close(Polyligne* P);
 * @brief Ferme la polyligne entrée en argument (si elle est ouverte)
 * 
 * @param P, La Polyligne à fermer (si elle est ouverte)
 * 
 * @pre P != NULL
 * @post open = False & nbpoint(p) = nbpoint(P_0) + 1 & length = Length(P) + EuclDIst(P->pointarray[nbpoint_0], P->pointarray[0])
 * 
 */
void Close(Polyligne* P);


/**
 * @fn Polyligne *IsOpen(Polyligne* P);
 * @brief Observateur qui donne l'état d'ouverture de la polyligne
 * 
 * @param P, La Polyligne à checker 
 * 
 * @pre P != NULL
 * @post P = P_0
 *
 */
void IsOpen(Polyligne* P);


/**
 * @fn unsigned int NbrPoint(Polyligne* P);
 * @brief Donne le nombre de points qui composent la polyligne
 * 
 * @param P, La Polyligne dont on cherche le nombre de points
 * 
 * @pre P != NULL
 * @post P = P_0 & nbpoint = NBRPoint(P)
 * 
 * @return Le nombre de points de la polyligne 
 */
unsigned int NbrPoint(Polyligne* P);


/**
 * @fn Point2D GetPoint(Polyligne* P, unsigned int numero);
 * @brief Donne le point se trouvant à l'indice "numero"
 * 
 * @param P, La Polyligne contenant le point que l'on cherche
 * @param numero, L'indice auquel se trouve le point que l'on cherche
 * 
 * @pre P != NULL
 * @post P = P_0 & GetPoint(P, numero) = P->pointarray[numero]
 * 
 * @return Le nombre de points de la polyligne 
 */
Point2D GetPoint(Polyligne* P, unsigned int numero);


/**
 * @fn void AddPoint(Polyligne* P, Point2D* A);
 * @brief Ajoute le point "A" à la fin de la polyligne "P"
 * 
 * @param P, La Polyligne contenant dans laquelle on veut ajouter le point A
 * @param A, Le oint que l'on veut ajouter à la polyligne P
 * 
 * @pre P != NULL & A != NULL
 * @post nbpoint(p) = nbpoint(P_0) + 1 & length = Length(P) + EuclDIst(A, P->pointarray[nbpoint_0])
 * 
 * @return Le nombre de points de la polyligne 
 */
void AddPoint(Polyligne* P, Point2D* A);


/**
 * @fn void SuppPoint(Polyligne* P);
 * @brief Supprime le dernier point de la polyligne
 * 
 * @param P, La Polyligne à laquelle on veut supprimer un point
 * 
 * @pre P != NULL 
 * @post nbpoint(p) = nbpoint(P_0) - 1 & length = Length(P) - EuclDIst(P->pointarray[nbpoint_0], P->pointarray[0])
 * 
 * @return Le nombre de points de la polyligne 
 */
void SuppPoint(Polyligne* P);




#endif