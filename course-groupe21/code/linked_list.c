#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct list_t{
    void *data;
    struct list_t *next;
};

typedef struct list_t cell;

/**
 * \fn static struct cell *create_cell(void *data)
 * \brief Creates a new cell
 *
 * \param data The new data to store in the cell useful part.
 *
 * \return a pointer to a new cell.  The cell linked part is set to NULL.
 */
static cell *create_cell(void *data){
    cell *n_cell = malloc(sizeof(cell));
    if(n_cell==NULL)
        return NULL;
    
    n_cell->data = data;
    n_cell->next = NULL;
    
    return n_cell;
}//end create_cell()

List *empty_list(){
    return NULL;
}//end empty_list()

Boolean is_empty(List *L){
    return L==NULL;
}//end is_empty()

int length(List *L){
    int longueur = 0;
    List *p = L;
    
    while(p!=NULL){
        longueur++;
        p = p->next;
    }//end while - tmp
    
    return longueur;
}//end length()

void *get(List *L, int i){
    assert(0<=i && i<length(L) && !is_empty(L));
    
    int j=0;
    List *p = L;
    
    while(j<i){
        p = p->next;
        j++;
    }//end while - j/tmp
    
    return p->data;
}//end get()

List *set(List *L, int i, void *e){
    assert(0<=i && i<length(L) && !is_empty(L) && e!=NULL);

    void *old;
    List *p = L;
    int j = 0;
    
    while(p!=NULL && j<i){
        p = p->next;
        j++;
    }//end while - j/tmp
    
    old = p->data;
    p->data = e;
    free(old);
    
    return L;
}//end set()

List *add_at(List *L, int i, void *e){
    assert(0<=i && i<length(L) && e!=NULL);
    
    //SP1
    if(i==0)
        return add_first(L, e);
    
    //SP2
    int j=0;
    List *p_cour = L;
    List *p_prec = NULL;
    //SP2.a
    while(j<i){
        p_prec = p_cour;
        p_cour = p_cour->next;
        j++;
    }
    
    //SP2.b
    List *n_cell = create_cell(e);
    if(n_cell == NULL)
        return L;
    
    //SP2.c
    n_cell->next = p_cour;
    p_prec->next = n_cell;
    
    return L;
}//end add_at()

List *add_first(List *L, void *e){
    assert(e!=NULL);
    
    //SP1
    List* n_cell = create_cell(e);
    if(n_cell == NULL)
        return L;
    
    //SP2
    n_cell->next = L;
    
    return n_cell;
}//end add_first()

List *add_last(List *L, void *e){
    assert(e!=NULL);
    
    List *p = L;
    
    //SP1
    List *n_cell = create_cell(e);
    if(n_cell==NULL)
        return L;
    
    if(is_empty(L))
        //SP2 (cas particulier de la liste vide)
        L = n_cell;
    else{
        //SP3 (cas général)
        //SP3.a
        while(p->next!=NULL)
            p = p->next;
        //SP3.b
        p->next = n_cell;
    }
    
    return L;
}//end add_last()

List *remove(List *L, int i){
    assert(0<=i && i<length(L) && !is_empty(L));
    
    //à faire @home
    
    return L;
}//end remove()

Boolean contains(List *L, void *e,  Boolean (*equal_data)(void *data1, void *data2)){
    assert(e!=NULL);
    
    //à faire @home
    
    return False;
}//end contains()
