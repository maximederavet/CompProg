#include <assert.h>
#include <stdlib.h>
#include "filtrer.h"
#include "propriete.h"


int filtrer(int *T, int N){
   assert(T != NULL);
   assert(N >0);

   int i=0;
   int taille_utile = 0;

   while(i<N){
      if(test(T[i])){
         taille_utile++;
         i++;
      }

   }
   return taille_utile;
}


