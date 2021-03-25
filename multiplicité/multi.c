#include "multi.h"
#include <assert.h>

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


      ////Nombre le plus grand entre les deux valeurs actuelles
      
      if (i!=j){
        if (nbri > nbrj){
          temp = nbri;
        }//fin if i>j

        else{
          temp = nbrj;
        }//fin else
     }
     else
     temp = nbri;


     ////Changement du maximum et du nombre d'occurence

     if (i ==0){ //Premier tour de boucle
         maxi = temp;
         if ((nbri == nbrj)&&(i!=j))
            occurence = 2;
         else
            occurence = 1;
      }//fin if i ==0

     if (maxi < temp){ //si le nouveau nombre est plus grand, changement et reinitialisation de l'occurences
       maxi = temp;
       if ((nbri == nbrj)&&(i!=j)) // si les deux valeurs sont égale et qu'on regarde deux valeur différente => (Occurence ==2)  sinon occurence ==1
          occurence = 2;
       else
          occurence = 1;
     }//fin if max<temp


     if ((maxi == temp) && (i!=0)){//Si le nouveau nombre est égal, augmentation de l'occurence

        if ((nbri == nbrj)&&(i!=j)) // si les deux valeurs sont égale et qu'on regarde deux valeur différente => (Occurence +2)  sinon occurence +1
           occurence += 2;
        else
           occurence += 1;
      }//fin if maxi == temp


   //incrémentation des compteurs
     i++;
     j--;





 }//fin while

 *max = maxi;

 return occurence;

}//fin multiplicite
