#include <stdio.h>
#include "multi.h"



int main(){

   int T[8] = {1,1,1,1,1,1,1,1};
   int max = 0;
   multiplicite(T,8,&max);
   printf("%d - %d\n",multiplicite(T,8,&max),max );



}
