/*
Se desea desarrollar una función en C que genere un conjunto de N números aleatorios entre 0 y 9;
N es el número total de datos. Debe crear un vector de 10 componentes, (10 contadores),
de manera que la primera componente será cuantas veces se generó el aleatorio 1,
la segunda cuantas se generó el aleatorio 2 y así sucesivamente hasta el 10. Use solo funciones con parámetros de entrada

a) Cálculo para determinar la pareja más cercana (6 puntos)
b) Estructura cíclica, arreglo y función obligatoria (3 puntos)
c) Impresión correcta de las salidas, y código fuente comentarizado (1 puntos) */
#include <stdio.h>
int i, N, arreglo[10], j, producto[5], cercana;

void generador(int N, int i); /*Genera una serie de numeros aleatorios entre 0 a 9 con N como límite.*/
int contadores(int x, int i); /* Cuenta las apariciones de cada numero y las guarda en un arreglo.
                                 Se ejecuta dentro de generador.*/
void salidaInicial(int i); /* Imprime las veces que se genero cada numero y el arreglo resultante. */
void emparejamiento(int x); /* Organiza el arreglo resultante en parejas y extrae la posicion de la más cercana. */
void salidaFinal(int arreglo[10], int cercana, int producto[5]); /*Calcula e imprime la pareja mas cercana y su diferencia.*/



main(){

  printf("Introduzca la cantidad de datos a generar: ");
  scanf("%d", &N);
  printf("Numeros generados: ");
    generador(N, i);

  printf("\n\n");

    salidaInicial(i);
    printf("\n\nParejas:\n");
    emparejamiento(j);
    salidaFinal(arreglo, cercana, producto);
getch();
}//Fin Main

 //FUNCIONES:
 //-------------------------------------------------------------------

void generador(int N, int i){
srand(time(NULL));

    for(i = 0; i<N; i++){

      int num = rand() % 10;

        printf(" %d,", num);
        contadores(num, j);

      }// Fin Ciclo.

    }//Fin Funcion


int contadores(int x, int i){

    for(i = 0; i < 10; i++){

      if(i == x){ arreglo[i] += 1; }

      }//Fin Segundo ciclo

} //Fin funcion.

void salidaInicial(int i){

 for(i = 0; i < 10; i++){
     printf("-%d se genero %d veces.\n", i, arreglo[i]);
     } //Fin Ciclo

  printf("\nVector resultante:\n");
  for(i = 0; i < 10; i++){
   printf("(%d) ", arreglo[i]);
 }
}//Fin Funcion


void emparejamiento(int x){


  for(i = 1; i < 10; i+=2){

    printf("(%d,%d) ", arreglo[i-1], arreglo[i]);
    producto[x++] = abs(arreglo[i-1] - arreglo[i]);
          }
  for(i = 0; i < 5; i++){
  if (producto[i] < producto[cercana]) { cercana = i;} }
} //Fin Funcion


void salidaFinal(int arreglo[10], int cercana, int producto[5]){
printf("\n\nPareja mas cercana: (%d,%d) con diferencia de (%d)", arreglo[(cercana*2)], arreglo[(cercana*2)+1], producto[cercana]);
} //Fin Funcion
