/*
Dado los datos de unos estudiantes (nombre; edad; carnet y nota) de una clase en particular de una universidad, obtener El porcentaje de estudiantes con una nota mayor a 15, Estudiante con menor nota. Use estructuras
a) Función donde calcula e imprime el Estudiante con menor nota. (3 ptos)
b) Función donde calcula el porcentaje de estudiantes con una nota mayor a 15
(4 ptos)
c) Función donde llena y imprime el arreglo de estructura (3 ptos) */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int n, i, j, total = 0, k;
float notaAux[100], m = 0.0f, mayor = 0.0f, menor = 0.0f;

typedef struct
 {
   int edad[100];
  char nombre[100][50];
  char carnet[100][50];
  float nota[100];

 }estudiante;

 estudiante registroEstudiante[100];

void registro(int i, int n, estudiante *p); //Llena los vectores con lo datos de los estudiantes y saca el porcentaje de aquellos con nota mayor a 15.
void NotaMenor(int i, int n); //Funcion para determinar la nota menor entre los estudiantes.
void impresion(int i, int n); //Funcion de salida.

push();
int main(){

	printf("Indique la cantidad de estudiantes: ");
  	scanf("%d", &n);
	registro(i, n, registroEstudiante);
	NotaMenor(i, n);
	impresion(i, n);
}

  void registro(int i, int n, estudiante *p){



  for(i = 0; i < n; i++){

   printf("\nNombre #%d: ", i+1);
   scanf("%s", &p[i].nombre);

   printf("Carnet #%d: ", i+1);
   scanf("%s", &p[i].carnet);

   printf("Edad #%d: ", i+1);
   scanf("%d", &p[i].edad);

   printf("Nota #%d: ", i+1);
   scanf("%f", &notaAux[i]);
   *p[i].nota = notaAux[i];
   total+=notaAux[i];
     }



   for(i = 0; i < n; i++)
   {
     if(notaAux[i]>15){
       mayor+=1;   }
   }

     m = (mayor/n)*100.0f;
     printf("\n Porcentaje de alumnos con nota mayor a 15: %0.2f ", m);
   }


   void NotaMenor(int i, int n){

   menor = notaAux[0];
   for( i = 1 ; i < n; i ++){

     if(notaAux[i] < menor){ menor = notaAux[i]; k = i; }

    }

   }

   void impresion(int i, int n){

    for(i = 0; i < n; i++){

    	printf("\n\n-Estudiante: %s", *registroEstudiante[i].nombre);
    	printf("\n-Carnet: %s", *registroEstudiante[i].carnet);
    	printf("\n-Edad: %d", *registroEstudiante[i].edad);
    	printf("\n-Nota: %0.2f", *registroEstudiante[i].nota);

        }
       printf("\n\nLa menor nota es de: %s con %0.2f", *registroEstudiante[k].nombre, menor);
   }
