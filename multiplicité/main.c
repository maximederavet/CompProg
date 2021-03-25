#include <stdio.h>
#include <stdlib.h>
#include "multi.h"



int main(){

   int T[8] = {13,-1,7,16,-12,2,16,4};
   int max;
   printf("%d - %d\n",multiplicite(T,8,&max),max );


}
/*
if (nbri > nbrj){
  temp = nbri;
}//fin if i>j

else{
  temp = nbrj;
}//fin else


if (maxi < temp){
  maxi = temp;
  occurence = 1;
}//fin if max<temp

else if(maxi == temp){
  occurence++;
}//fin if ==

i++;
j--;

return occurence;

*/

/*nombre1 = T[i];
nombre2 = T[j];

if (nombre1 < nombre2)
   maxtemp = nombre2;
else
   maxtemp = nombre1;

if (i == 0){

   *max = maxtemp;

   occurence ++;
}

if ((maxtemp > *max) && (i!=0)){

   *max = maxtemp;
   occurence = 1;
}
else if ((maxtemp == *max)&& (i!=0)) {

   occurence ++;
}


i++;
j--;


{*/
