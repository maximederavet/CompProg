#include <assert.h>
#include <stdlib.h>
#include "filtrer.h"
#include "propriete.h"


int filtrer(int *T, int N){
   assert(T != NULL);
   assert(N >0);

   int i=0;
   int j=0;
   int tmp;
   int taille_utile=N;

   while(i<taille_utile){
      if(test(T[i])){
         i++;
      }
      else {
         j=i;
         while(j<taille_utile){
            tmp = T[j+1];
            T[j] = tmp;
            j++;
         }
         T[taille_utile-1] = 0;
         taille_utile--;
      }
   }
   return taille_utile;
}


