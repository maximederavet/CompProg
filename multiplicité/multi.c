#include <stdio.h>
#include <stdlib.h>
#include "multi.h"

int multiplicite(int *T, const int N, int *max){

   int i = 0;
   int j = N-1;
   int temp = 0;
   int occurence = 0;
   int nbri;
   int nbrj;
   int maxi;


   while (i <= j){
      nbri = T[i];
      nbrj = T[j];

     if (nbri > nbrj){
       temp = nbri;
     }//fin if i>j

     else{
       temp = nbrj;
     }//fin else

     if (i ==0){
         maxi = temp;
         occurence = 1;
      }

     if (maxi < temp){
       maxi = temp;
       occurence = 1;
     }//fin if max<temp

     else if((maxi == temp) && (i!=0)){
       occurence++;
     }//fin if ==

     i++;
     j--;





 }//fin while

 (*max) = (*max)*2;
 printf("%d\n",maxi );
 return occurence;

}//fin multiplicite
