#ifndef __LIST__
#define __LIST__

/**
 * \file list.h
 * \brief ADT for managing the list type
 * \author Benoit Donnet -- Université de Liège (ULg)
 * \version 0.1
 * \date 30/04/2014
 *
 * Presents a list as an abstract data type
 */

#include "boolean.h"

/**
 * \struct List
 * \brief Data structure representing a List as a contiguous array.  The array is expandable.
 */
typedef struct List_t List;

/**
 * \fn List *empty_list()
 * \brief Creates an instance of a list
 *
 * \return an empty list.  NULL otherwise.
 */
List *empty_list(void);

/**
 * \fn Boolean is_empty(List *l)
 * \brief Determines whether the list L is empty or not.
 *
 * \param L The list to test.
 *
 * \return a Boolean indicating whether the list L is empty or not
 */
Boolean is_empty(List *L);

/**
 * \fn int length(List *L)
 * \brief Returns the length of the list
 *
 * \param L The list to test.
 *
 * \return The number of elements stored in the list.
 */
int length(List *L);

/**
 * \fn void *get(List *L, int i)
 * \brief Returns the element stored at rank i in the list.
 * 
 * \param L The list.
 * \param i The element rank to return (\f$0 \leq i < length(L)\f$).
 *
 * \return The element stored at rank i.
 */
void *get(List *L, int i);

/**
 * \fn List *set(List *L, int i, void *e)
 * \brief Sets a new element for the rank i in the list
 *
 * \param L The list.
 * \param i The index of the rank to modify (\f$0 \leq i < length(L)\f$).
 *
 * \return The list modified.  Previous element at rank i is erased by the new one.
 */
List *set(List *L, int i, void *e);

/**
 * \fn List *add_at(List *L, int i, void *e)
 * \brief Adds a new element at a rank i in the list.
 *
 * \param L The list.
 * \param i The rank where to add the new element
 *
 * \return The list modified.  The new element is added at rank i.
 */
List *add_at(List *L, int i, void *e);

/**
 * \fn List *add_first(List *L, void *e)
 * \brief Adds a new element at the first rank in the list. This is equivalent
 * to add_at(L, 0, e);
 *
 * \param L The list.
 *
 * \return The list modified.  The new element is added at first rank.
 */
List *add_first(List *L, void *e);

/**
 * \fn List *add_last(List *L, void *e)
 * \brief Adds a new element at the last rank in the list. This is equivalent
 * to add_at(L, length(L), e);
 *
 * \param L The list.
 *
 * \return The list modified.  The new element is added at last rank.
 */
List *add_last(List *l, void *e);

/**
 * \fn List *remove(List *L, int i)
 * \brief Removes, from the list, the element at rank i.
 *
 * \param L The list.
 * \param i The element rank to remove
 *
 * \return The list modified.  The element at rank i is removed from the list.
 */
List *remove(List *L, int i);

/**
 * \fn Boolean contains(List *L, void *e,  Boolean (*equal_data)(void *data1, void *data2))
 * \brief Determines whether the list L contains the element e or not according to a given
 * equal_data() function
 *
 * \param L The list.
 * \param e The element to test.
 * \param equal_data The comparison function
 *
 * \return True if e belongs to L.  False otherwise.
 */
Boolean contains(List *L, void *e,  Boolean (*equal_data)(void *data1, void *data2));

#endif
