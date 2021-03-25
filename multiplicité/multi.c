#include <stdio.h>
#include <stdlib.h>
#include "multi.h"

int multiplicite(int *T, const int N, int *max){

   int i = 0;
   int j = N-1;
   int temp = 0;
   int occurence = 0;
   int nbri = T[i];
   int nbrj = T[j];
   int maxi = T[i];

   while (i <= j){

     if (nbri > nbrj){
       temp = nbri;
     }//fin if i>j

     else{
       temp = nbrj;
     }//fin else


     if (maxi < temp){
       maxi = temp;
       occurence = 1;
     }//fin if max<temp

     else if(maxi == temp){
       occurence++;
     }//fin if ==

     i++;
     j--;

   return occurence;


 }//fin while
}//fin multiplicite
