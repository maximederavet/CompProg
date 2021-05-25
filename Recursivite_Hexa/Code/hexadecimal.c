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



/**
* Précondition : - Hexa doit être une chaine de caractères composée de chiffres compris entre 0 et 9 ou des lettres comprises entre A et F
*                - n doit être égal à la taille de la chaine hexa
* Postcondition : retourne le nombre hexadécimal entré en base 10
*
*/
unsigned int hexa_dec_rec(char *hexa, int n){
   assert(n>-1);


  unsigned int nombre;


  if (n >0){
    assert(convert(hexa[n-1]) != 4294967295);
    nombre = convert(hexa[n-1]);
    return nombre + 16 * hexa_dec_rec(hexa, n-1);
  }

else
  return 0;






}//fin hexa_dec_rec()
