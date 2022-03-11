#include <stdio.h>
#include "filtrer.h"


int main(){
   int N = 7;
   int T[7] ={10,-5,0,-3,7,9,-10};
   int taille_utile;

   taille_utile = filtrer(T, N);


   for(int i=0 ; i<N; i++){
      printf("%d ",T[i]);
   }
   printf("\n");
   printf("la taille utile est %d\n", taille_utile);

return 0;
}



