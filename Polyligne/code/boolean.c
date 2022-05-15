/**
 * \file boolean.c
 * \brief Implementation the Boolean type
 * \author Benoit Donnet -- Université de Liège (ULg)
 * \version 0.1
 * \date 04/04/2014
 *
 * Presents a boolean as an abstract data type
 */

#include "boolean.h"

Boolean and(Boolean x, Boolean y){
    if(!x)
        return False;
    else
        return y;
}//end and()

Boolean or(Boolean x, Boolean y){
    if(x)
        return True;
    else
        return y;
}//end or()


Boolean not(Boolean x){
    return !x;
}//end not()

