#include<stdio.h>
#include<stdlib.h>
#include"Polyligne.h"

int main(){

    Point2D *a = malloc(sizeof(Point2D*));
    if(a==NULL)
        return NULL;
    
    Point2D *b = malloc(sizeof(Point2D*));
    if(b==NULL)
        return NULL;
    
    Point2D *c = malloc(sizeof(Point2D*));
    if(c==NULL)
        return NULL;

    a= Create(1.0,1.0);
    b= Create(2,2);
    c= Create(3,3);

    float gxa = get_x(a);
    float gya = get_y(a);

    float gxb = get_x(b);
    float gyb = get_y(b);

    float gxc = get_x(c);
    float gyc = get_y(c);

    float dist = EuclDist(a,b);

    printf("a = ( %f, %f)\n", &gxa, &gya );
    printf("b = ( %f, %f)\n", &gxb, &gyb );
    printf("c = ( %f, %f)\n", &gxc, &gyc );

    printf("distance = %f \n", &dist);


    return 0;
}