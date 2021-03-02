/*
En la empresa MANGOBAJITO, S.A., se tiene un sistema de identificación del personal
que consta de un código generado a partir de los datos personales del trabajador, los cuales son: CEDULA, NOMBRE,
SEXO (Masculino=1 Femenino=2) y EDAD.
Para determinar el código correspondiente al trabajador se usa la siguiente regla:
Se toma como primer digito el sexo del trabajador,
seguidamente se le anexa cuatro dígitos que corresponden a los dígitos impares de la Cédula,
en caso de tener más de cuatro dígitos impares se toman los dígitos cuya posición en la Cédula es la más significativa,
y de no tener cuatro dígitos impares se completan los cuatro dígitos necesarios con ceros.
Por último se agrega la edad, por lo que, ya que todos los trabajadores son mayores de edad, el código formado contiene siempre siete (7) dígitos.
Ej:
CEDULA NOMBRE SEXO EDAD CODIGO
11242566 PEDRO PEREZ 1 25 1115025
12345678 JUAN LOPEZ 1 28 1135728
11555312 MARIA DIAZ 2 23 2115523

1) Desarrolle la función que dados por parámetros la estructura que contiene los datos de nombre, cedula, edad y sexo de una persona,
genere y guarde en un arreglo los códigos y la información correspondiente a cada persona.
2) Función de generación del código del personal (7 ptos)
3) Función de llenado e impresión del arreglo de estructura (3ptos)
 */
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

typedef struct{

int CEDULA[100], SEXO[100], EDAD[100];
char NOMBRE[100][50], CODIGO[100][10];

}personal;

personal Empleados[1000];

int N = 0, i = 0, aux = 0, j, z, cedulaAux, arregloAux[100], ci = 0, vectorImp[100][100], y, aux2 = 0;
int sexoAux = 0, edadAux = 0;



void llenado(int i, int N, personal *p); //Llena CEDULA --> NOMBRE --> SEXO --> EDAD ---> CODIGO
void salida(int i, int N); //salida CEDULA --> NOMBRE --> SEXO --> EDAD ---> CODIGO
void Codigo(int i, personal *p); //Genera el Código

int main(){

  printf("Introduzca el numero de empleados: ");
    scanf("%d", &N);
    llenado(i, N, Empleados);
    salida(i, N);

}

void llenado(int i, int N, personal *p){ //Llena CEDULA --> NOMBRE --> SEXO --> EDAD.


  for(i = 0; i < N; i++){

    cedulaAux = 0;
    z = 0;
    aux2 = 0;
    ci = 0;

    printf("\n\nIntroduzca CEDULA para #%d: ", i+1);
      scanf("%d", &cedulaAux);

      *p[i].CEDULA = cedulaAux;

      while(cedulaAux > 0){ //FASE 1: SEPARAR DÍGITOS Y GUARDAR EN UN ARREGLO.
        aux = cedulaAux % 10;
        arregloAux[z] = aux;
        cedulaAux /= 10;
        z++;
      }

      for(j = z-1; j > -1; j--){ //FASE 2: REORDENAR Y BUSCAR IMPARES.
        if(arregloAux[j] % 2 != 0){ ci+=1; vectorImp[i][ci-1] = arregloAux[j]; }
        arregloAux[j] = 0;
      }

      for(y = 0; y < 4; y++){ //FASE 3: CONVERTIR ARREGLO A DÍGITO Y PASARLO AL VECTOR RESULTANTE.
        aux2 = 10 * aux2 + vectorImp[i][y];


      }

    printf("Introduzca NOMBRE para #%d: ", i+1);
      scanf("%s", &p[i].NOMBRE);


SEX:printf("Introduzca SEXO para #%d (Masculino=1 Femenino=2): ", i+1);
      scanf("%d", &sexoAux);

      if(sexoAux < 1 || sexoAux > 2){
        printf("\nRESPUESTA INVALIDA\n");
        goto SEX;
      }

	  *p[i].SEXO = sexoAux;

    printf("Introduzca EDAD para #%d: ", i+1);
      scanf("%d", &edadAux);
    *p[i].EDAD = edadAux;

      Codigo(i, Empleados);

  }



}

  void salida(int i, int N){ //salida CEDULA --> NOMBRE --> SEXO --> EDAD.

    for(i = 0; i < N; i++){

      printf("\n\n\n-CEDULA #%d: %d", i+1, *Empleados[i].CEDULA);
      printf("\n-NOMBRE #%d: %s", i+1, *Empleados[i].NOMBRE);
      printf("\n-SEXO #%d: %d", i+1, *Empleados[i].SEXO);
      printf("\n-EDAD #%d: %d", i+1, *Empleados[i].EDAD);
      printf("\n-CODIGO #%d: %s", i+1, *Empleados[i].CODIGO);

    }

}

void Codigo(int i, personal *p){ //Genera el Código
  snprintf(*p[i].CODIGO, sizeof(*p[i].CODIGO), "%d%d%d", sexoAux, aux2, edadAux);
}
