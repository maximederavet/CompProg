#include <stdio.h>
#include "multiplicite.h"



int main(){

   int T [9] = {16,17,16,16,17,16,16,17,16};
   int max = 0;
   multiplicite(T,9,&max);
   printf("%d - %d\n",multiplicite(T,9,&max),max );



}
