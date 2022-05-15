#include <assert.h>
#include <stdlib.h>

#include "Polyligne.h"



/**
 * @fn struct cell
 * @brief Structure de donnée représentant liste doublement chainée
 * 
 */
typedef struct cell_t cell;
struct cell_t{
    cell* prec;
    Point2D *data;
    cell* suiv;

};



struct Polyligne_t{
    Boolean open;
    unsigned int nbpoint;
    float length;
    cell* tete;
    cell* queue;
};






static Polyligne* create_senti(void){
    Polyligne* senti = malloc(sizeof(Polyligne));
    if(senti==NULL)
        return NULL;
    
    senti->open = True;
    senti->nbpoint = 0;
    senti->length = 0;
    senti->tete = NULL;
    senti->queue = NULL;

    return senti;

}//end create_senti()




Polyligne *CreatePolyligne(Point2D *A, Point2D *B){
    assert(A!=NULL && B!=NULL && A!=B);

    Polyligne* P = create_senti();
   

    AddPoint(P, A);
 
    AddPoint(P, B);

    P->nbpoint = 2;
    P->length = EuclDist(A,B);

    P->open = True;   

    return P;

}//end createPolyligne()


void Open(Polyligne* P){   
    assert(P!=NULL);

    if(P->open==False)
        SuppPoint(P);

}//end Open()


void Close(Polyligne* P){   
    assert(P!=NULL);


    if(P->open==True)
        AddPoint(P, P->tete->data);

}//end Close()


Boolean IsOpen(Polyligne* P){
    assert(P!=NULL);

    return(P->open);

}// en IsOpen


unsigned int NbrPoint(Polyligne* P){
    assert(P!=NULL);

    return(P->nbpoint);

}//end NbrPoint()


static Point2D* GetPointRec(cell* C, unsigned int numero){
    assert(C!=NULL);

    if(numero==0)
        return(C->data);
    else{       
        return(GetPointRec(C->suiv, numero-1));
    }
}


Point2D* GetPoint(Polyligne* P, unsigned int numero){
    assert(P!=NULL && numero < P->nbpoint);

    if(P->queue==NULL)
        return NULL;

    return GetPointRec(P->tete, numero);
   
    

}//end GetPoint()


Polyligne* AddPoint(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!= NULL);

    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->prec = NULL;
    n_cell->data = A;
    n_cell->suiv = NULL;
    

    if(P->queue == NULL){
        P->queue = n_cell;
        P->tete = n_cell;
    }
    else{
        P->queue->suiv = n_cell;
        n_cell->prec = P->queue;
        P->queue = n_cell;
    }

    P->nbpoint += 1;
    P->length += EuclDist(P->queue->prec->data,P->queue->data);
    

    if(P->queue == P->tete)
        P->open = False;
    else{
        P->open = True;
    }

    return P;

}//end add()


Polyligne* SuppPoint(Polyligne* P){
    assert(P!=NULL);

    if(P->queue==NULL)
        return NULL;

    if(P->queue->prec == P->tete)
        P->open = False;
    else{
        P->open = True;
    }


    P->length -= EuclDist(P->queue->prec->data, P->queue->data);
    P->nbpoint -=1;

    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell = P->queue;

    P->queue->data = NULL;
    P->queue->prec = NULL;
    P->queue->prec->suiv = NULL;

    P->queue = n_cell->prec;

    n_cell = NULL;
    free(n_cell);

    return P;

}//end supp()


float Length(Polyligne* P){
    assert(P!=NULL);
    
    return(P->length);

}//end length()


static Polyligne* PolyTranslateRec(cell* C, Point2D* A){
    assert(C!=NULL);



    
}


Polyligne* PolyTranslate(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!=NULL);

 


}



Polyligne* PolyRotate(Polyligne* P, Point2D* A, float x){

/////////////////////////////////////////////////////////////

}