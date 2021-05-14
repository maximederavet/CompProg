#include <assert.h>
#include <stdlib.h>

#include "list.h"

#define INITIAL_SIZE 10
#define REALLOCATION_FACTOR 2

struct List_t{
    int array_size;// current size (i.e., number of squares in the array)
    int length;// number of element recorded in the array
    void **array; //the array itself
};

/**
 * \fn List *realloc_array(List *L);
 * \brief Reallocates the size associated to a given array list (i.e., increase its size).
 *
 * \param L The list to increase.
 *
 * \return a pointer to the new list.  Or NULL in case of allocation issue.
 */
static List *realloc_array(List *L){
    assert(L!=NULL);
    
    L->array_size *= REALLOCATION_FACTOR;
    L->array = realloc(L->array, L->array_size*sizeof(void *));
    
    return L;
}//end realloc_array()

/**
 * \fn List *shift_right(List *L, int begin)
 * \brief Shifts by one position to the right the elements in the array starting from begin
 * to the end of the array.  If required, the array size is increased.
 *
 * \param L, the List to manipulate
 * \param begin, the position where to start the shift
 * 
 * \return A pointer to the new List.
 */
static List *shift_right(List *L, int begin){
    assert(L != NULL && 0<= begin && begin <= length(L));
    
    if(L->length + 1 >= L->array_size)
        L = realloc_array(L);
    
    int i;
    
    for(i=L->length; i>=begin; i--)
        L->array[i+1] = L->array[i];
    
    return L;
}//end shift_right()

/**
 * \fn List *shift_left(List *L, int begin)
 * \brief Shifts by one position to the left the elements in the array starting from begin
 * to the end of the array.
 *
 * \param L, the List to manipulate
 * \param begin, the position where to start the shift
 *
 * \return A pointer to the new List.
 */
static List *shift_left(List *L, int begin){
    assert(L!=NULL && 0 < begin && begin <= L->length);
    
    int i;
    
    for(i=begin; i<L->length; i++)
        L->array[i-1] = L->array[i];
    
    return L;
}//end shift_left()

List *empty_list(void){
    List *L = malloc(sizeof(List));
    if(L==NULL)
        return NULL;
    
    L->array_size = INITIAL_SIZE;
    L->length = 0;
    
    L->array = malloc(INITIAL_SIZE * sizeof(void *));
    if(L->array==NULL){
        free(L);
        
        return NULL;
    }
    
    return L;
}//end empty_list()

Boolean is_empty(List *L){
    return L->length==0;
}//end is_empty()

int length(List *L){
    return L->length;
}//end length()

void *get(List *L, int i){
    assert(0<=i && i<L->length);
    
    return L->array[i];
}//end get()

List *set(List *L, int i, void *e){
    assert(0<=i && i<L->length);
    
    if(L->array[i]!=NULL)
        free(L->array[i]);
    
    L->array[i] = e;
    
    return L;
}//end set()

List *add_at(List *L, int i, void *e){
    assert(0<=i && i<=L->array_size);
    
    if(L->length + 1 >= L->array_size)
        L = realloc_array(L);
    
    if(L->array[i]!=NULL)
        L = shift_right(L, i);
    
    L->array[i] = e;
    L->length++;
    
    return L;
}//end add_at()

List *add_first(List *L, void *e){
    if(L->length + 1 >= L->array_size)
        L = realloc_array(L);
    
    if(L->length!=0)
        L = shift_right(L, 1);

    L->array[0] = e;
    L->length++;
    
    return L;
}//end add_first()

List *add_last(List *L, void *e){
    if(L->length + 1 >= L->array_size)
        L = realloc_array(L);
    
    L->array[L->length] = e;
    
    L->length++;
    
    return L;
}//end add_last()

List *remove(List *L, int i){
    assert(0<=i && i<L->length);
    
    free(L->array[i]);
    
    L = shift_left(L, i+1);
    free(L->array[L->length-1]);
    L->length--;
    
    return L;
}//end remove()

Boolean contains(List *L, void *e,  Boolean (*equal_data)(void *data1, void *data2)){
    int i, eqn;
    
    for(i=0; i<L->length; i++){
        eqn = (*equal_data)(e, L->array[i]);
        
        if(eqn)
            return True;
    }//end for - i
    
    return False;
}//end contains()
