//Realice el examen usando estructuras (struct) en C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3


typedef struct{

    int Clave;
    char Nombre[100];
    float Estatura;
    float Sueldo;

    }empleado;

void captura(empleado a[N]);
void orden(empleado a[N]);
void impresion(empleado a[N]);
int empleadoAlto(empleado a[N]);

int main(){

    empleado a[N];
    int posicion;


    captura(a);
    orden(a);
    impresion(a);

    posicion=empleadoAlto(a);
    printf("\nLa posicion del empleado mas alto es %d,de Clave: %d ,de Nombre: %s, de Altura: %f, y de Sueldo: %f",posicion+1,a[posicion].Clave,a[posicion].Nombre,a[posicion].Estatura,a[posicion].Sueldo);

}

void captura(empleado a[N]){

    int i;
    for ( i = 0; i < N; i++)
    {
        printf("Clave: ");
        scanf("%d",&a[i].Clave);

        printf("Nombre: ");
        scanf("%s",a[i].Nombre);

        printf("Estatura: ");
        scanf("%f",&a[i].Estatura);

        printf("Sueldo: ");
        scanf("%f",&a[i].Sueldo);

    }

}

void orden(empleado a[N]){

    int i,pos;
    int aux;

   for ( i = 0; i < N; i++)
    {

        for(pos=i;pos<N;pos++){

            if(a[i].Estatura<a[pos].Estatura){

                    aux=a[i].Estatura;
                    a[i].Estatura=a[pos].Estatura;
                    a[pos].Estatura=aux;

                    aux=a[i].Sueldo;
                    a[i].Sueldo=a[pos].Sueldo;
                    a[pos].Sueldo=aux;

                    aux=a[i].Clave;
                    a[i].Clave=a[pos].Clave;
                    a[pos].Clave=aux;

                    char temporal[100];
                    memcpy(temporal, a[i].Nombre, 100);
                    memcpy(a[i].Nombre, a[pos].Nombre,100);
                    memcpy(a[pos].Nombre, temporal, 100);

            }

        }

    }
    }

void impresion(empleado a[N]){

    int i;

        printf("Clave ");
        printf("Nombre ");
        printf("Estatura ");
        printf("Sueldo ");

    for ( i = 0; i < N; i++)
    {


        printf("\nEmpleado %d: \n",i+1);

        printf("%d     ",a[i].Clave);
        printf("%s      ",a[i].Nombre);
        printf("%f ",a[i].Estatura);
        printf("%f",a[i].Sueldo);

    }

}
int empleadoAlto(empleado a[N]){

    int i;
    int M=a[0].Estatura;
    int pos=0;

    for(i=0;i<N;i++){

        if(M<a[i].Estatura){
            M=a[i].Estatura;
            pos=i;
        }

    }

    return pos;

}
