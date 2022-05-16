/**
 * @file Polyligne_liste_test.c
 *
 *
 * @brief INFO0947 Projet 2 - Récurisivité & TAD
 * @author Luca Matagne et Maxime Deravet
 * @date 15/05/2022
 *
 */

#include "polyligne.h"
#include "point2D.h"
#include "seatest.h"
#include <stdlib.h>
#include <math.h>
/*------------------------------------------------------------------------------
-----------------------------------FONCTION TEST--------------------------------
------------------------------------------------------------------------------*/
static void test_lenght(){
   Point2D *a= Create(1.0,1.0);
   Point2D *b= Create(-5,-8);
   Point2D *c= Create(3,3);

   //Création de la polyligne
   Polyligne* P1 = CreatePolyligne(a,b);
   float L1 = Length(P1);

   //Ajout d'un point supplémentaire
   P1 = AddPoint(P1, c);
   float L2 = Length(P1);

   assert_float_equal(3*sqrt(13) , L1,0.00000001);
   assert_float_equal(L1 + sqrt(185) , L2,0.00000001);
   free(P1);
} 

static void test_NbrPoint(){
   Point2D *a= Create(1.0,1.0);
   Point2D *b= Create(-5,-8);
   Point2D *c= Create(3,3);
   Point2D *d= Create(10,10);

   //Création de la polyligne
   Polyligne* P1 = CreatePolyligne(a,b);
   unsigned int N1 = NbrPoint(P1);

   //Ajout de points supplémentaires
   P1 = AddPoint(P1, c);
   unsigned int N2 = NbrPoint(P1);
   
   P1 = AddPoint(P1, d);
   unsigned int N3 = NbrPoint(P1);

   P1 = DeletePoint(P1);
   unsigned int N4 = NbrPoint(P1);

   assert_ulong_equal(2, N1);
   assert_ulong_equal(3, N2);
   assert_ulong_equal(4, N3);
   assert_ulong_equal(3, N4);

   free(P1);
}

static void test_AddPoint(){
   Point2D *a= Create(1.0,1.0);
   Point2D *b= Create(-5,-8);
   Point2D *c= Create(3,3);
   Point2D *d= Create(-10,10);

   //Création de la polyligne
   Polyligne* P1 = CreatePolyligne(a,b);

   //Ajout de points supplémentaires
   P1 = AddPoint(P1, c);
   P1 = AddPoint(P1, d);

   Point2D *a_test = GetPoint(P1, 0);
   float Xa = get_x(a_test);
   float Ya = get_y(a_test);

   Point2D *b_test = GetPoint(P1, 0);
   float Xb = get_x(b_test);
   float Yb = get_y(b_test);

   Point2D *c_test = GetPoint(P1, 0);
   float Xc = get_x(c_test);
   float Yc = get_y(c_test);

   Point2D *d_test = GetPoint(P1, 0);
   float Xd = get_x(d_test);
   float Yd = get_y(d_test);

   assert_float_equal(1.0 , Xa, 0.00000001);
   assert_float_equal(1.0 , Ya, 0.00000001 );
   assert_float_equal(-5, Xb, 0.00000001 );
   assert_float_equal(-8, Yb, 0.00000001 );
   assert_float_equal(3, Xc, 0.00000001);
   assert_float_equal(3, Yc, 0.00000001);
   assert_float_equal(-10, Xd, 0.00000001);
   assert_float_equal(10, Yd, 0.00000001);

   free(P1);
}


/*------------------------------------------------------------------------------
-----------------------------------INIT SEATEST---------------------------------
------------------------------------------------------------------------------*/
static void test_fixture(){
  test_fixture_start();

  run_test(test_lenght);
  run_test(test_NbrPoint);
  run_test(test_AddPoint);

  test_fixture_end();
}

static void all_tests(){
  test_fixture();
}
/*------------------------------------------------------------------------------
-----------------------------------MAIN----------------------------------------
------------------------------------------------------------------------------*/
int main(){
  return run_tests(all_tests);
}