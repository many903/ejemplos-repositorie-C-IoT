#include <math.h>
#include <stdio.h>
float potencia(float base, int exponente) {
float resultado = 1;
int i;
for (i = 0; i < exponente; ++i) {
resultado *= base;
}
return resultado;
}
int main()
{
int valido=1;
char op;
float resultado,x,y, por;
scanf("%f %c %f",&x,&op,&y);
switch (op) {
    case '+':
    resultado = x + y;
    break;
    case '-':
    resultado = x - y;
    break; 
    case '*':
    resultado = x * y;
    break;
    case '/':
    resultado = x / y;
    break;
    case '^':
    resultado = potencia(x, (int) y);
    break;
    case'P':
    por=y/100;
    resultado =(x*por);
    default:
    valido = 1;
}
if (valido)
printf( "%0.2f\n", resultado);
else
printf("Operacion invalida\n");
}
