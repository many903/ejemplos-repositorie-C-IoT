#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

typedef struct videoJ 
{
     char clave[35];
     char nombre[35];
     char tipo[35];
     char precio[35];
     char descuento[11];
} Gamer;

int menu_contacto();

Gamer leer();

void leeTeclado(Gamer p[MAX], int n);

void leeDatos(Gamer p[MAX], int n);

void escribeDatos(Gamer p[MAX],int n);

void despliegaDatos(struct videoJ q[MAX], int n);

void desplegar(struct videoJ q);

Gamer busca(struct videoJ q[MAX], int n);

void alta(Gamer p[MAX], int *n);

Gamer modificar(struct videoJ q[MAX],int n,int menu_contacto());

int busca_elint(struct videoJ p[MAX], int n );

void baja(Gamer q[MAX], int n);


void alta(Gamer p[MAX], int *n)
{
    p[*n] = leer();
    (*n)++;
}

void leeTeclado(Gamer p[MAX], int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            p[i] = leer();
        }
}

void leeDatos(Gamer p[MAX], int n)
{
    FILE * fp;
    int tam, i;
    fp = fopen("datos", "rb");
    if (fp == NULL)
    {
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        tam = fread(&p[i],sizeof(p[i]),1,fp);
        if (tam > 0) printf("registro leido\n");
    }
}

void escribeDatos(Gamer p[MAX],int n)
{
    FILE * fp;
    int tam, i;
    fp = fopen("datos", "wb");
    if (fp == NULL)
    {
        printf("error al abrir el archivo\n");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        tam = fwrite(&p[i],sizeof(p[i]),1,fp);
        if (tam > 0) printf("registro escrito\n");
    }
}

void despliegaDatos(struct videoJ q[MAX], int n)
{
     int i;
     printf("\t   clave  nombre   tipo     precio    descuento\n");
     for(i=0; i<n; i++)
     {
         desplegar(q[i]);
     }
}

void desplegar(struct videoJ q)
{
    printf("\n%15s %7s %6s %9s %9s\n",
           q.nombre,q.nombre,q.tipo,q.precio,q.descuento);
}

struct videoJ leer()
{
    struct videoJ Gamer;
    printf("clave: ");
    fgets(Gamer.clave);
    printf("nombre: ");
    fgets(Gamer.nombre);
    printf("tipo: ");
    fgets(Gamer.tipo);
    printf("precio: ");
    fgets(Gamer.precio);
    printf("descuento: ");
    fgets(Gamer.descuento);
    getchar(); /* lee enter */
    return (Gamer);
}

int menu()
{
    int opc;
    printf("\nVIDEOJUEGOS \n");
    printf("1. Lectura de datos\n");
    printf("2. Lectura de per desde archivo\n");
    printf("3. Escritura de videojuego a un archivo\n");
    printf("4. Consulta de un videojuego disponibles\n");
    printf("5. Busca un videojuego\n");
    printf("6. Modifica info de un videojuego\n");
    printf("7. Alta de un nuevo videojuego\n");
    printf("8. Baja de un videojuego \n");
    printf("0. Terminar\n");
    printf("Selecciona opción: \n");
    scanf("%d",&opc);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opc);
}

int menu_contacto(){
    int opci;
    printf("\nElije el la opcion a editar\n");
    printf("1. nombre\n");
    printf("2. tipo\n");
    printf("3. precio\n");
    printf("4. descuento\n");
    printf("0. Terminar\n");
    printf("Selecciona opción: \n");
    scanf("%d",&opci);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opci);
}


int main ( )
{
        Gamer p[MAX];
        int n,i, opcion;
        scanf("%d",&n);    
    do
    {
        opcion = menu();   
        switch(opcion)
        {
            case 1: leeTeclado(p,n);
                    break;
            case 2: leeDatos(p,n);
                    break;
            case 3: escribeDatos(p,n);
                    break;
            case 4: despliegaDatos(p,n);
                    break;
            case 5: desplegar(busca(p,n));
			        break;
			case 6: desplegar(modificar(p,n,menu_contacto));
			        break;
            case 7: alta(p,&n);
                    break;
            case 8: baja(p,n);
                    break;
            default: printf("Opción invalida %d\n", opcion);
        }
    } while (opcion != 0);
        return 0;
}

void baja(Gamer q[MAX], int n)
{
	int i,a;
    a=busca_conint(q,n);
    Gamer eq;
    for(i=a;i<n;i++){
    	q[i]=q[i+1];
    }
	n=n-1;		
}

int busca_conint(struct videoJ q[MAX], int n )
{
    int i;
    char clave[35];
    Gamer eq;
    printf("Nombre del videojuego que deseas eliminar: ");
    gets(clave);
    for(i=0;i<n;i++)
    {
        if (strcmp(clave,q[i].clave) == 0) //iguales
            return(i);
    }
    return(-1);
}

Gamer busca(struct videoJ q[MAX], int n )
{
    int i;
    char clave[35];
    Gamer eq;
    printf("Nombre del videojuego que deseas buscar: ");
    scanf("%s",clave);
    for(i=0;i<n;i++)
    {
        if ( strcmp(clave,q[i].clave) == 0) //iguales
            return(q[i]);
    }
}

Gamer modificar(struct videoJ q[MAX],int n,int menu_contacto())
{
    int opcion,i;
	char clave1[35];
	char nombre1[35];
	char tipo1[20];
	char precio1[7];
	char descuento1[10];
    Gamer eq;
	printf("Nombre del videojuego que deseas editar: ");
    scanf("%s",clave1); 
     do
     {
        opcion= menu_contacto();  
        //Aqui van las funciones 
        switch(opcion)
        {
            case 1:     
            	    printf("Introduce el nombre correcto: ");
			        gets(nombre1);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(clave1,q[i].clave) == 0){
                          strcpy(q[i].nombre,nombre1);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 2: 
			        printf("Introduce la clasificacion correcta: ");
			        gets(tipo1); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(clave1,q[i].clave) == 0){
                          strcpy(q[i].tipo,tipo1);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 3: 
			        printf("Introduce el precio correcto: ");
			        gets(precio1);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(clave1,q[i].clave) == 0){
                          strcpy(q[i].precio,precio1);
                      	  return(q[i]);
					  }
                    }
                break;
            case 4: 
			        printf("Introduce el descuento que hay para el videojuego : ");
			        gets(descuento1); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(clave1,q[i].clave) == 0){
                          strcpy(q[i].descuento,descuento1);
                      	  return(q[i]);
					  }
                    }
                break;
            default: printf("Opción invalida %d\n", opcion);
        }
    } while (opcion != 0);
}

