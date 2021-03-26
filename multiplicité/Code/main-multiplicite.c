#include <stdio.h>
#include "multi.h"



int main(){

   int T[8] = {16, 1966, 16, 19666, 16, 16, 16, 16};
   int max = 0;
   multiplicite(T,8,&max);
   printf("%d - %d\n",multiplicite(T,8,&max),max );



}
