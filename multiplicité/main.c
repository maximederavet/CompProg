#include <stdio.h>
#include <stdlib.h>
#include "multi.h"

//ta mere max der

//salut

int main(){

   int T[9] = {13,-1,7,16,-12,2,4,16,16};
   int max = 0;
   printf("%d - %d\n",multiplicite(T,9,&max),max );


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
