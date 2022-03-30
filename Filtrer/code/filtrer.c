#include <stdlib.h>
#include <assert.h>
#include "filtrer.h"
#include "propriete.h"


int filtrer(int *T, int N){
    assert(T != NULL && N >0);
    //∀ T[i], 0 ≤ i ≤ N, T[i] ∈ Z (Z = les entiers)  ∧  N > 0
    int i= 0;
    int taille_utile = 0;
    //∀ T[i], 0 ≤ i ≤ N, T[i] ∈ Z (Z = les entiers)  ∧  N > 0  ∧ i=0  ∧  taille_utile=0
    /*N = N_initial  
      ∧
      0 ≤ taille_utile ≤ i < N
      ∧  
      ∀ x, 0 ≤ x < taille_utile, Filtrage(T_initial, N, taille_utile), Sous_Suite(T_initial, taille_utile, T, N)
    */
    while(i<N){
    /*N = N_initial  
      ∧
      0 ≤ taille_utile ≤ i < N
      ∧  
      ∀ x, 0 ≤ x < taille_utile, Filtrage(T_initial, N, taille_utile), Sous_Suite(T_initial, taille_utile, T, N)
      ∧
      i < N
    */        
        if(!test(T[i])){
            T[i]= 0;
            i++;
            

        }else{
            if(taille_utile!= i){
                T[taille_utile]= T[i];
                T[i]= 0;
                i++;
                taille_utile++;
            }else{
                taille_utile++;
                i++;
            }
        }

    }

    return taille_utile;

}