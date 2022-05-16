#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "point2d.h"


struct Point2D_t{
    float x;
    float y;
};

Point2D *Create(float x, float y){

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


float EuclDist(Point2D* A, Point2D* B){
    assert(A!=NULL && B!=NULL);

    float square1 = (A->x - B->x)*(A->x - B->x);
    float square2 = (A->y - B->y)*(A->y - B->y);

    float dist = sqrt(square1 + square2);

    return dist;

}//end EuclDIst()


Point2D* TranslatePoint2D(Point2D* A, Point2D* B){
    assert(A!=NULL && B!=NULL);
    
    Point2D* Anew = malloc(sizeof(Point2D));
    if(Anew==NULL)
        return NULL;
    
    float Ax = A->x + B->x;
    float Ay = A->y + B->y;
    
    Anew->x = Ax;
    Anew->y = Ay;

    A = Anew;


    return A;
}//end TranslatePoint2D()


Point2D* RotatePoint2D(Point2D* A, Point2D* B, float x){
    assert(A!=NULL && B!=NULL);
    
    Point2D *Anew = malloc(sizeof(Point2D));
    if(Anew==NULL)
        return NULL;
    
    
    
    float diff1 = A->x - B->x;
    float diff2 = A->y - B->y;

    Anew->x = cos(x) * diff1 - sin(x) * diff2 + B->x;
    Anew->y = sin(x) * diff1 + cos(x) * diff2 + B->y;

    A = Anew;
    

    return A;

}//end RotatePoint2D()