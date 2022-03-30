#include <stdlib.h>
#include <assert.h>
#include "filtrer.h"
#include "propriete.h"


int filtrer(int *T, int N){
    assert(T != NULL && N >0);

    int i= 0;
    int taille_utile = 0;
<<<<<<< HEAD
    
=======

>>>>>>> e41cec8a1960c3940ecfe4babcebd71a46715076

    while(i<N){
        if(!test(T[i])){
            T[i]= 0;
            i++;
<<<<<<< HEAD
            
=======

>>>>>>> e41cec8a1960c3940ecfe4babcebd71a46715076

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