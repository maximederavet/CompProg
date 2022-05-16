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
    cell* prev;
    Point2D *data;
    cell* next;

};



struct Polyligne_t{
    Boolean open;
    unsigned int nbpoint;
    float length;
    cell* head;
    cell* tail;
};






static Polyligne* create_senti(){
    Polyligne* senti = malloc(sizeof(Polyligne));
    if(senti==NULL)
        return NULL;
    
    senti->open = True;
    senti->nbpoint = 0;
    senti->length = 0;
    senti->head = NULL;
    senti->tail = NULL;

    return senti;

}//end create_senti()


static cell* CreateCell(){
    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->prev = NULL;
    n_cell->data = NULL;
    n_cell->next = NULL;

    return n_cell;

}//end CreateCell()




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
        AddPoint(P, P->head->data);

}//end Close()


Boolean IsOpen(Polyligne* P){
    assert(P!=NULL);

    return(P->open);

}// en IsOpen


unsigned int NbrPoint(Polyligne* P){
    assert(P!=NULL);

    return(P->nbpoint);

}//end NbrPoint()


static Point2D* GetPointRec(cell* C, unsigned int number){
    

    if(number==0)
        return(C->data);
    else{       
        return(GetPointRec(C->next, number-1));
    }
}


Point2D* GetPoint(Polyligne* P, unsigned int number){
    assert(P!=NULL && number < P->nbpoint);

    if(P->tail==NULL)
        return NULL;

    return GetPointRec(P->head, number);
   
    

}//end GetPoint()




Polyligne* AddPoint(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!= NULL);

   
    cell* n_cell = CreateCell();
   
    n_cell->data = A;
   
    

    if(P->tail == NULL){
        P->tail = n_cell;
        P->head = n_cell;
        P->tail->prev = P->head;
    }
    else{
        P->tail->next = n_cell;
        //P->length += EuclDist(P->tail->data,n_cell->data);
        n_cell->prev = P->tail;
        P->tail = n_cell;
    }

    P->nbpoint += 1;
    P->length += EuclDist(P->tail->prev->data,P->tail->data);
    

    if(P->tail == P->head)
        P->open = False;
    else{
        P->open = True;
    }


    return P;

}//end add()


Polyligne* SuppPoint(Polyligne* P){
    assert(P!=NULL);

    if(P->tail==NULL)
        return NULL;

    if(P->tail->prev == P->head)
        P->open = False;
    else{
        P->open = True;
    }


    P->length -= EuclDist(P->tail->prev->data, P->tail->data);
    P->nbpoint -=1;

    cell *n_cell = CreateCell();

    n_cell = P->tail;

    P->tail->data = NULL;
    P->tail->prev->next = NULL;
    P->tail->prev = NULL;

    P->tail = n_cell->prev;


    return P;

}//end supp()


float Length(Polyligne* P){
    assert(P!=NULL);
    
    return(P->length);

}//end length()


static void PolyTranslateRec(cell* C, Point2D* A){
    assert(C!=NULL);

    if(C->next!=NULL){
        TranslatePoint2D(C->data, A);
        PolyTranslateRec(C->next,A);
    }
    else{
        TranslatePoint2D(C->data, A);
    }

    
    
}


Polyligne* PolyTranslate(Polyligne* P, Point2D* A){
    assert(P!=NULL && A!=NULL);

    if(P->tail == NULL)
        return NULL;

    PolyTranslateRec(P->head, A);

    return P;

}


static void PolyRotateRec(cell* C, Point2D* A, float x){
    assert(C!=NULL);

    if(C->next!=NULL){
        RotatePoint2D(C->data, A, x);
        PolyRotateRec(C->next, A, x);
    }
    else{
        RotatePoint2D(C->data, A, x);
    }

}

Polyligne* PolyRotate(Polyligne* P, Point2D* A, float x){
    assert(P!=NULL && A!=NULL);

    if(P->tail == NULL)
        return NULL;

    PolyRotateRec(P->head, A, x);

    return P;

}