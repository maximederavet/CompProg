#include <stdio.h>
#include "multiplicite.h"



int main(){

   int T[10] = {16, 16,10, 16,160, 16, 16, 16, 16, 16};
   int max = 0;
   multiplicite(T,10,&max);
   printf("%d - %d\n",multiplicite(T,10,&max),max );



}
