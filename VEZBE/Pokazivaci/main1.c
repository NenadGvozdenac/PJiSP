#include<stdio.h>
#define MAX_SIZE 30
int main(){
int A[MAX_SIZE],n,br,i,ponavljanje=0;
printf("unesite broj elemenata niza veci od 0 a manji od 30 \n");
do{
scanf("%i",&n);
}while(0>=n || n>MAX_SIZE);



printf("unesite broj cije ponavljanje pratimo \n");
scanf("%i",&br);



for(i=0;i<n;i++){
printf("unesite clan niza \n");
scanf("%i",&A[i]);




if(A[i]==br){
ponavljanje+=1;
}
}





printf("broj ponavljanja je %i",ponavljanje);
return 0;
}