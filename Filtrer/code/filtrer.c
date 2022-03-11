#include <assert.h>
#include <stdlib.h>
#include "filtrer.h"
#include "propriete.h"


int filtrer(int *T, int N){
   assert(T != NULL);
   assert(N >0);

   int i=0;
   int j=N-1;
   int taille_utile=0;

   while(i<=j){
      if(test(T[i])){
         i++;
         taille_utile++;
      }
      else {
         T[i]=T[j];
         T[j]=0;
         j--;
      }
   }
   return taille_utile;
}


