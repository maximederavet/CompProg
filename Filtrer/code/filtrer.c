#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "filtrer.h"
#include "propriete.h"


int filtrer(int *T, int N){
    assert(T != NULL && N >0);

    int i= 0;
    int taille_utile = 0;
    

    while(i<N){
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

    }//fin while

    return taille_utile;

}//fin filtrer