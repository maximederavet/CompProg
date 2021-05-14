#include <assert.h>

#include "hexadecimal.h"

/**
 * \fn static unsigned int convert(char hex)
 * \brief Conversion entre un symbpole hexadécimal et son équivalent décimal
 *
 * \param hex, le symbole hexadécimal
 *
 * \return la représentation décimale du symbole hexadécimal.  -1 en cas d'erreur.
 */
static unsigned int convert(char hex){
  switch(hex){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    case 'A': return 10;
    case 'B': return 11;
    case 'C': return 12;
    case 'D': return 13;
    case 'E': return 14;
    case 'F': return 15;
  }
  return -1;
}//fin convert()

unsigned int hexa_dec_rec(char *hexa, int n){
  //VOTRE CODE ICI

  return 0;
}//fin hexa_dec_rec()
