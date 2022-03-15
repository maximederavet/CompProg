#include <stdio.h>
#include "filtrer.h"


int main(){
   int N = 7;
   int T[7] ={2,2,2,2,2,2,2};
   int taille_utile;

   taille_utile = filtrer(T, N);


   for(int i=0 ; i<N; i++){
      printf("%d ",T[i]);
   }
   printf("\n");
   printf("la taille utile est %d\n", taille_utile);

return 0;
}



