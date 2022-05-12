#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Point2D.h"

typedef struct Point2D_t{
    float x;
    float y;
}Point2D;

Point2D *create_point(float x, float y){
    Point2D *pt = malloc(sizeof(Point2D));
    if(pt==NULL)
        return NULL;
    
    pt->x = x;
    pt->y = y;
    
    return pt;
}//end create_point()
float get_x(Point2D *pt){
    assert(pt!=NULL);
    
    return pt->x;
}//end get_x()

float get_y(Point2D *pt){
    assert(pt!=NULL);
    
    return pt->y;
}//end get_y()