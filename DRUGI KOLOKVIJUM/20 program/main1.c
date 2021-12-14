#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE_ID 11
#define MAX_SIZE_OZNA 4
#define MAX_SIZE_N 30

typedef struct let_st{
    char ID_leta[MAX_SIZE_ID];
    char mesto_polaska[MAX_SIZE_OZNA];
    char mesto_dolaska[MAX_SIZE_OZNA];
    int km;
    int presedanje;


}LET;

FILE *safeOPEN(char *name,char *mode)
{
    FILE *pfin = fopen(name,mode);

    if(pfin == NULL)
    {
    printf("GRESKA!\nFajl %s ne postoji!\n",name);
    exit(EXIT_FAILURE);
    }

    return pfin;
}

void unos(FILE *pfin,LET *letovi,int *n)
{
    int i=0;

while(fscanf(pfin,"%s %s %s %d %d",letovi[i].ID_leta,letovi[i].mesto_polaska,letovi[i].mesto_dolaska,&letovi[i].km,&letovi[i].presedanje) != EOF)
    i++;

    *n=i;
}

double cena(LET *letovi)
{
    int i;
    double c=0;


    if(letovi[i].km < 5000)
    c = letovi[i].km * 0.5;
    else if(letovi[i].km >=5000 && letovi[i].km < 10000)
    c = letovi[i].km * 0.75;
    else if(letovi[i].km >= 10000)
    c = letovi[i].km;


    c -= letovi[i].presedanje * 5;

    return c;
}

void ispis(FILE *pfout,LET *letovi,int n,char *x)
{
    int i,k=0;

    for(i=0;i<n;i++){
    if(strcmp(letovi[i].mesto_dolaska,x) == 0)
    fprintf(pfout,"%s %s %lf \n",letovi[i].ID_leta,letovi[i].mesto_polaska,cena(&letovi[i]));
    k++;
    }

    if(k==0)
    printf("NEMA LETOVA KA ZADATOJ DESTINACIJI!\n");
}

int main(int argbr, char *argvr[])
{
    int n;
    LET letovi[MAX_SIZE_N];
    FILE *pfin, *pfout;
    char out_name[MAX_SIZE_N];

    if(argbr != 3){
    printf("GRESKA!\nArgumenti komandne linije treba da budu:\n");
    printf("./let letovi.txt <ID mesta dolaska>\n");
    exit(EXIT_FAILURE);
    }
    pfin = safeOPEN(argvr[1],"r");
    unos(pfin,letovi,&n);
    fclose(pfin);

    strcpy(out_name,"let_ka");
    strcat(out_name,argvr[2]);
    strcat(out_name,".txt");

    pfout = safeOPEN(out_name,"w"); 
    ispis(pfout,letovi,n,argvr[2]);
    fclose(pfout);
    return 0;
}