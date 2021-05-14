
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
  assert(n>0);


  //déclaration des variables
  int i = 0;
  int j = 0;
  int caract;
  unsigned int nombre_total = 0;
  int exposant =1;


  //début de la boucle
  while (i<n)
  {
    caract = convert(hexa[i]);
    j = n-i-1;

    //calcul de la puissance de 16 au rang correspondant
    while (j>0)
    {
      exposant*=16;
      j--;
    }


    //Calcul du nombre final
    nombre_total += (caract * exposant);


    //Remise à 0 et incrémentation des compteurs
    exposant = 1;
    i++;
  }

  return nombre_total;
}//fin hexa_dec_rec()
