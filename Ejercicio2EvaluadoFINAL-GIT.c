/*
Considere N personas condenadas que están esperando para ser ejecutadas.
El verdugo, aburrido del método de ejecución decide seguir el método presentado a continuación:
El hace que todas las N personas condenadas se coloquen en círculo, con un entero entre 1 y N exhibidos en su pecho.
La persona con el numero N esta parada al lado de la persona numero 1. Y todas las personas con los números 1,2,3 … .
en su pecho están en un circulo en la dirección de las agujas del reloj.
El verdugo toma un numero aleatorio entre 1 y N , y llama a este elindividuo.
Él entonces dispara a esa persona cuyo número en su pecho coincide con éste.
Él selecciona otro número aleatorio mayor a cero llamado el próximo.
Él cuenta el número próximo de personas vivas en dirección de las agujas del reloj desde elindividuo y
ejecuta la persona cuyo número en su pecho coincide con el número. De esta manera, se mantiene ejecutando a todas las personas.
EL problema consiste en tomar como entrada los números aleatorios elindividuo y próximo e
imprimir la secuencia según la cual las personas serán ejecutadas.
Tendrá un arreglo llamado lista que contendrá el estado inicialmente
todas las entradas del arreglo serán inicializadas en VIVO. Si una persona es ejecutada el valor cambia a MUERTO.
Asuma que lista[k] indica el estado de una persona cuyo número en el pecho es k.
Ejemplo: Si N=5, el individuo es 2 y próximo es 3, la siguiente es una de las posibles secuencias en la cual ellos serán ejecutados :
2,5,4,1,3.

a) Función donde calcula e imprime la secuencia de las personas a ser ejecutadas.(6 puntos)
b) Estructura cíclica, arreglo y función apropiada obligatoria (3 puntos)
c) Función de Impresión correcta de las salidas (1 puntos).

 */
#include <stdio.h>
#include <string.h>

typedef struct{

int aux[1000], secuencia[1000];
char lista[1000][10];

}prisioneros;

prisioneros VICTIMAS[1000];

int N, i, j, elindividuo, proximo, posicion;

void llenadoInicial(int N, prisioneros *p); //Ciclo de llenado para el auxiliar y el listado (Llena lista[] con VIVO).
void VivoOMuerto(int N, prisioneros *p, int i); //Funcion para determinar el estado de los prisioneros (Si están vivos o muertos).
void primeraEjecucion(int N, prisioneros *p, int elindividuo); //Primera ejecucion con elindividuo. Agrega su numero a la secuencia.
void ejecucionesProximas(int N, prisioneros *p, int i); //Ejecuciones con 'proximo' y calculo de secuencia.
void salidaSecuencia(int N); //Salida de secuencia.
void salidaLista(int N, int i); //Salida de lista[].

/* EXPLICACION DE FUNCIONES:
****llenadoInicial: Esta funcion llena un arreglo auxiliar con el valor '1' en cada uno de sus espacios.
****VivoOMuerto: La columna vertebral del programa. Esta funcion compara los valores dentro del arreglo auxiliar y los verifica.
Si uno de esos valores es 0, la funcion guarda su posicion como "k" y cambia ese valor en lista[k] a "MUERTO".
****primeraEjecucion:  Guarda la posicion del aleatorio "elindividuo" como "k" y cambia el valor en el arreglo auxiliar a 0. Guarda la
primera muerte en la secuencia.
****ejecucionesProximas: Genera 'proximo. Como dice el enunciado, el verdugo selecciona un numero aleatorio despues de "elindividuo" y
cuenta en direccion de las agujas del reloj. Esta funcion cumple eso con operaciones aritméticas y además le adjuntamos
condicionales para que en caso de que el numero aleatorio sea mayor a N, se siga moviendo en direccion de las agujas
del reloj.
En adicion a eso, se asegura de que el numero ya no este muerto y tambien guarda la posicion de cada ejecucion.
****salidaSecuencia: Imprime la secuencia de ejecutados.
****salidaLista: Imprime la lista de los prisioneros y si estan vivos o muertos. */
main(){

srand(time(NULL));

  printf("Cuantas victimas hay?: ");
  scanf("%d", &N);

	llenadoInicial(N, VICTIMAS);
	VivoOMuerto(N, VICTIMAS, i);
  salidaLista(N, i);
	printf("\n");

  elindividuo = (rand() % N) + 1; //Numero al azar + 1 para que jamas sea 0. Efectivamente de 1 a N.

	primeraEjecucion(N, VICTIMAS, elindividuo);

for(j = 0; j < N; j++){
	printf("\n");

	VivoOMuerto(N, VICTIMAS, i);
  salidaLista(N, i);

	if(j+1 >= N) { break; } /*Si j+1 supera o iguala a N, el ciclo se rompe. Esto es para evitar un bucle indefinido
                          causa de la condicional en ejecucionesProximas. */

	ejecucionesProximas(N, VICTIMAS, j);
  printf("\n---PULSE UNA TECLA PARA CONTINUAR---\n");
  getch();
  }

  salidaSecuencia(N);
  getch();
  return 0;
} //Fin Main

// FUNCIONES A CONTINUACION --------------------------------------:

void salidaLista(int N, int i){ //Funcion para imprimir y determinar el estado de los prisioneros.

	for(i = 0; i < N; i++){

      printf("\n-#%d: %s", i+1, *VICTIMAS[i].lista);
    }//Fin ciclo
} //Fin funcion



void VivoOMuerto(int N, prisioneros *p, int i){ //Funcion para imprimir y determinar el estado de los prisioneros.

	for(i = 0; i < N; i++){

    if(*p[i].aux == 0){ strcpy(*p[i].lista, "MUERTO"); }
    }//Fin ciclo
} //Fin funcion



void llenadoInicial(int N, prisioneros *p){//Ciclo de llenado para el auxiliar y el listado (Llena lista[] con VIVO).

	for(i = 0; i < N; i++){

	*p[i].aux = 1;

	strcpy(*p[i].lista, "VIVO"); //Llena el listado de "VIVO".
     } //Fin ciclo
} //Fin Funcion




void primeraEjecucion(int N, prisioneros *p, int elindividuo){ //Primera ejecucion con elindividuo. Agrega su numero a la secuencia.

printf("\nLa primera ejecucion 'elindividuo' corresponde a #%d.", elindividuo);


		*p[elindividuo-1].aux = 0; // -1 Para que acapare el espacio adecuado.
		*p[0].secuencia = elindividuo;

} //Fin Funcion.



void ejecucionesProximas(int N, prisioneros *p, int i){ //Ejecuciones con 'proximo' y calculo de secuencia.
	 Repite: proximo = (rand() % N) + 1;


 posicion = elindividuo + proximo; //Segundo auxiliar para guardar la posicion.

if(posicion > N){ posicion = (elindividuo + proximo) - N;	} /*Si es mayor a N, se resta con N para
																														que se mantenga el sentido
																														de las agujas del reloj*/

if(*p[posicion-1].aux == 0){ goto Repite;	} /* Si ya el individuo en la nueva posicion esta muerto, busca otro numero. */

	*p[posicion-1].aux = 0;  /*Busca el espacio dado por la variable 'posicion' y reduce su numero interno a 0.
											     El condicional en VivoOMuerto usara ese dato para cambiar el estado
											     de "VIVO" a "MUERTO".  */

		*p[i+1].secuencia = posicion; //Guarda la posicion del ejecutado.
        printf("\n\nAcaba de ejecutar a #%d.", elindividuo);
				printf("\n'proximo': %d", proximo);
				printf("\nSiguiente ejecucion: #%d\n", posicion);
        elindividuo = posicion; //Guarda la posicion para que las ejecuciones se mantengan correctas.
			} //Fin Funcion



void salidaSecuencia(int N){
    printf("\n\n\nSecuencia de ejecucion: ");
    for(i = 0; i < N; i++){
    printf("#%d, ", *VICTIMAS[i].secuencia);
       } //Fin ciclo
    } //Fin funcion
