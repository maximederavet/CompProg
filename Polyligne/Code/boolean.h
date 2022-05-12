#ifndef __BOOLEAN__
#define __BOOLEAN__

/**
 * \file boolean.h
 * \brief ADT for managing the Boolean type
 * \author Benoit Donnet -- Université de Liège (ULg)
 * \version 0.1
 * \date 04/04/2014
 *
 * Presents a boolean as an abstract data type
 */


/**
 * \struct Boolean
 * \brief Data structure representing a boolean.
 */
typedef enum{
    False, 
    True
}Boolean;

/**
 * \fn Boolean and(Boolean x, Boolean y)
 * \brief Performs the logical AND between two booleans.
 *
 * \param x, a boolean.
 * \param y, a boolean.
 *
 * \return A boolean giving the result of x AND Y
 */
Boolean and(Boolean x, Boolean y);

/**
 * \fn Boolean or(Boolean x, Boolean y)
 * \brief Performs the logical OR between two booleans.
 *
 * \param x, a boolean.
 * \param y, a boolean.
 *
 * \return A boolean giving the result of x OR Y.
 */
Boolean or(Boolean x, Boolean y);

/**
 * \fn Boolean not(Boolean x)
 * \brief Performs the logical negation.
 *
 * \param x, a boolean.
 *
 * \return A boolean giving the result of NOT x.
 */
Boolean not(Boolean x);

#endif
