#include<stdio.h>
#include<stdlib.h>
#include"Polyligne.h"

int main(){



    Point2D *a= Create(1.0,1.0);
    Point2D *b= Create(-5,-8);
    Point2D *c= Create(3,3);

    float gxa = get_x(a);
    float gya = get_y(a);

    float gxb = get_x(b);
    float gyb = get_y(b);

    float gxc = get_x(c);
    float gyc = get_y(c);

    float dist = EuclDist(a,c);

    Point2D* translation = TranslatePoint2D(a, c);

    printf("a = ( %f, %f)\n", gxa, gya );
    printf("b = ( %f, %f)\n", gxb, gyb );
    printf("c = ( %f, %f)\n", gxc, gyc );

    printf("distance = %f \n", dist);
    printf("transl = %f, %f\n", get_x(TranslatePoint2D(a, b)), get_y(TranslatePoint2D(a, b)));
    printf("rot = %f, %f\n", get_x(RotatePoint2D(a, c, 30)), get_y(RotatePoint2D(a, c, 30)));


    Polyligne* P1 = CreatePolyligne(a,c);
    //Open(P1);
    //Close(P1);



    int nb = NbrPoint(P1);
    printf("nombre de points = %u\n", nb);

    for(int i = 0; i<nb; i++){
    printf("point[%u]:(%f,%f)\n", i, get_x(GetPoint(P1,i)),get_y(GetPoint(P1,i)));
    }

    Open(P1);

    int o = IsOpen(P1);
    printf("ouvert? %u\n", o);

    float lon = Length(P1);


    P1 = AddPoint(P1, b);
    nb = NbrPoint(P1);

    for(int i = 0; i<nb; i++){
    printf("point[%u]:(%f,%f)\n", i, get_x(GetPoint(P1,i)),get_y(GetPoint(P1,i)));
    }

    lon = Length(P1);
    printf("longueur = %f\n", lon);

    P1 = AddPoint(P1, b);
    nb = NbrPoint(P1);

    for(int i = 0; i<nb; i++){
    printf("point[%u]:(%f,%f)\n", i, get_x(GetPoint(P1,i)),get_y(GetPoint(P1,i)));
    }

    lon = Length(P1);
    printf("longueur = %f\n", lon);

    SuppPoint(P1);
    SuppPoint(P1);

    nb = NbrPoint(P1);

    for(int i = 0; i<nb; i++){
    printf("point[%u]:(%f,%f)\n", i, get_x(GetPoint(P1,i)),get_y(GetPoint(P1,i)));
    }
    
    lon = Length(P1);
    printf("longueur = %f\n", lon);


    P1 = PolyTranslate(P1, a);

    nb = NbrPoint(P1);

    for(int i = 0; i<nb; i++){
    printf("point[%u]:(%f,%f)\n", i, get_x(GetPoint(P1,i)),get_y(GetPoint(P1,i)));
    }
    
    lon = Length(P1);
    printf("longueur = %f\n", lon);
    
    float angle = 30;

    P1 = PolyRotate(P1, c, angle);

    nb = NbrPoint(P1);

    for(int i = 0; i<nb; i++){
    printf("point[%u]:(%f,%f)\n", i, get_x(GetPoint(P1,i)),get_y(GetPoint(P1,i)));
    }
    
    lon = Length(P1);
    printf("longueur = %f\n", lon);




    return 0;
}