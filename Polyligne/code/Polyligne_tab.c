#include <stdlib.h>
#include <assert.h>
#include <math.h>


#include "Polyligne.h"

#define INITIAL_SIZE 10
#define REALLOCATION_FACTOR 2


struct Polyligne_t{
    Boolean open;
    unsigned int nbpoint;
    unsigned int arraysize;
    Point2D** pointArray;
};

/**
 * @fn static Polyligne*  ReallocArray(Polyligne* P){
 * @brief multiplie par deux la taille du tableau
 *
 * @param P, La Polyligne dont on veut multiplier la taille du  tableau qui la contient
 *
 * @return La polyligne P après la réallocation de la mémoire du tableau
 */
static Polyligne*  ReallocArray(Polyligne* P){
    assert(P!=NULL);
    
    P->arraysize *= REALLOCATION_FACTOR;
    P->pointArray = realloc(P->pointArray, P->arraysize*sizeof(Polyligne *));
    
     for(unsigned int i=P->nbpoint; i<P->arraysize; i++){
        P->pointArray[i] = NULL;
    };

    return P;
}//end realloc()


Polyligne *CreatePolyligne(Point2D *A, Point2D *B){
    assert(A != NULL && B != NULL && A != B);


    Polyligne* P = malloc(sizeof(Polyligne));
    if(P==NULL)
        return NULL;

    P->arraysize = INITIAL_SIZE;
    P->nbpoint = 2;
    P->open = True;

    P->pointArray = malloc(INITIAL_SIZE * sizeof(Polyligne*));
    if(P->pointArray==NULL){
        free(P);

        return NULL;
    }

    for(unsigned int i=0; i<INITIAL_SIZE; i++){
        P->pointArray[i] = NULL;
    };

    P->pointArray[0] = A;
    P->pointArray[1] = B;

    return P;    

}//end create()


void Open(Polyligne* P){
    assert(P!=NULL);

    if(P->open != True){
        P->open = True;
        DeletePoint(P);
    }

}//end Open()


void Close(Polyligne* P){
    assert(P!=NULL);

    if(P->open == True){
        P->open = False;
        AddPoint(P, P->pointArray[0]);
    }

}//end Close()



Boolean IsOpen(Polyligne* P){

    if(P->pointArray[0]==P->pointArray[P->nbpoint - 1])
        P->open = False;
    else
        P->open = True;

    return P->open;

}// en IsOpen


unsigned int NbrPoint(Polyligne* P){
    assert(P!=NULL);

    return P->nbpoint;

}//end NbrPoint()


Point2D* GetPoint(Polyligne* P, unsigned int number){
    assert(P!=NULL && number < P->nbpoint);

    return P->pointArray[number];

}//end GetPoint()


Polyligne* AddPoint(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!=NULL);

    if(P->nbpoint + 1 >= P->arraysize)
        ReallocArray(P);
    
    P->pointArray[P->nbpoint] = A;
    P->nbpoint += 1;

    if(A==P->pointArray[0])
        P->open = False;
    else    
        P->open = True;

    return P;

}//end AddPoint()


Polyligne* DeletePoint(Polyligne* P){
    assert(P!=NULL);

    P->pointArray[P->nbpoint - 1] = NULL;
    P->nbpoint -= 1;
    P->open = True;

    return P;
//end DeletePoint()
}


float Length(Polyligne* P){
    assert(P!=NULL);

    float length = 0;

    for(unsigned int i=0; i<P->nbpoint-1; i++){

        length += EuclDist(P->pointArray[i], P->pointArray[i+1]);
    };

    return length;

}//end Length()


Polyligne* PolyTranslate(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!=NULL);
    
    for(unsigned int i=0; i<P->nbpoint; i++){

        P->pointArray[i] = TranslatePoint2D(P->pointArray[i], A);
    };

    return P;

}


Polyligne* PolyRotate(Polyligne* P, Point2D* A, float x){
    assert(P!=NULL && A!=NULL && 0<= x && x <= 360);

    for(unsigned int i=0; i<P->nbpoint; i++){

        P->pointArray[i] = RotatePoint2D(P->pointArray[i], A, x);
    };

    return P;


}