#ifndef __POINT2D__
#define __POINT2D__

#include "boolean.h"

/**
 * Struct Point2D
 * @brief Structure représentant un point via ses dedux coordonnées (x,y)
 * 
 */
typedef struct Point2D_t Point2D;


/**
 * 
 * @fn Point2D* Create(float x, float y);
 * @brief Fonction qui crée le  point en partant de ses deux coordonnées
 * 
 * @param x, coordonnée X du point dans le plan
 * @param y, coordonnée Y du point dans le plan
 * 
 *
 */
Point2D* Create(float x, float y);


/**
 * 
 * @fn float get_x(Point2D* A);
 * @brief Fonction qui retourne la coordonnée X du point A
 * 
 * @param A, Le point dont on veut la coordonnée X
 * 
 * 
 */
float get_x(Point2D* A);


/**
 * 
 * @fn float get_y(Point2D* A);
 * @brief Fonction qui retourne la coordonnée Y du point A
 * 
 * @param A, Le point dont on veut la coordonnée Y
 * 
 */
float get_y(Point2D* A);


/**
 * 
 * @fn float EuclDist(Point2D* A, Point2D* B);
 * @brief Fonction qui calcule la distance entre deux points
 * 
 * @param A, Point de départ du calcul de la distance
 * @param B, Point d'arrivée du calcul de la distance
 * 
 * 
 */
float EuclDist(Point2D* A, Point2D* B);


/**
 * 
 * @fn Point2D* TranslatePoint2D(Point2D* A, Point2D* B);
 * @brief Fonction qui fait subir une traslation du point A par rapport au point B
 * 
 * @param A, Point qui va subir la translation
 * @param B, Point de repère immobile pour effectuer le translation
 * 
 * 
 */
Point2D* TranslatePoint2D(Point2D* A, Point2D* B);


/**
 * 
 * @fn Point2D* RotatePoint2D(Point2D* A, Point2D* B, float x);
 * @brief Fonction qui fait subir une rotation du point A par rapport au point B d'un angle de x degrés
 * 
 * @param A, Point qui va subir la rotation
 * @param B, Point de repère immobile pour effectuer le rotation
 * @param x, amplitude de l'angle de la rotation (sens trigonométrique = anti horloger)
 * 
 * 
 */
Point2D* RotatePoint2D(Point2D* A, Point2D* B, float x);


#endif