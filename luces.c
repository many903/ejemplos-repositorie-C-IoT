/*
creado por Manuel Enrique Garcia Neve
fue echa para imprimir en terminal una corrida (0001,0010,0100,1000) de manera ciclica de
*/
#include <stdio.h>
void camnbio(int a,int b,int c,int d);//es una funcion que perimite hacer los cambios en a,b,c,d 
int main(){
    int a,b,c,d;
    a = 0; b = 0 ; c = 0 ; d = 0;
    camnbio(a,b,c,d);// imboca la fincion declarada al inicio
    while(1);// esto se coloca para que nunca pare la funcion 

}

void camnbio(int a,int b,int c,int d)
{
    printf("%d,%d,%d,%d",a,b,c,d);
    if(d==0){
        printf("%d,%d,%d,%d",&a,&b,&c,&d);
        d=0;
        c=1;
        printf("%d,%d,%d,%d",&a,&b,&c,&d);

    } 
    if (c==1) {
        c=0;
        b=1;
        printf("%d,%d,%d,%d",&a,&b,&c,&d);
    }
    if(b==1){
        a=1;
        b=0;
    }
    if (a==1){
    a=0;
     printf("%d,%d,%d,%d",&a,&b,&c,&d);
    }

}