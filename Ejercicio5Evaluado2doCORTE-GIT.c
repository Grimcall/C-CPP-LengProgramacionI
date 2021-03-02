/*

Declarar una estructura, que consista de tres miembros, un número del libro (un entero),
código del libro (un arreglo de 8 caracteres) y el precio del libro (un valor float).
Escriba una función que tome como entrada 10 libros y otra  muestre los detalles de los mismos. Use punteros.
2. Typedef struct {
                       Int dd,mm,yy ;

                        }FECHA;
Typedef struct {
                            Int  idno;
                            char  nombre[40];
                            FECHA  ddn;
                            float  salario;
                            int dependientes;
                        }EMPLEADOS;


*/
#include <stdio.h>


typedef struct{ // Int. Estructura 01

  int dd, mm, yy;

}FECHA; // Fin. Estruct 01.

typedef struct{ //Init. Estruct. 02

  int idno[1000], dependientes[1000];
  char nombre[1000][40];
  FECHA ddn;
  float salario[1000];

}EMPLEADOS; //Fin. Estruct. 02.

EMPLEADOS entEmpleados[1000];

int n, i;
float incremento[1000];

void entrada(EMPLEADOS *p);
void entrada(EMPLEADOS *p){ //Init Funcion

  float sueldoBase;

  printf("Indique el numero de empleados : ");
    scanf("%d", &n);
  printf("Indique el sueldo de estos empleados: ");
    scanf("%f", &sueldoBase);



  for(i = 0; i < n ; i++){ //Init Ciclo

    *p[i].dependientes = i;

    printf("Indique el ID del empleado #%d: ", i+1 );
      scanf("%d", &p[i].idno);
    printf("Indique el nombre del empleado: " );
      scanf("%s", &p[i].nombre);
    printf("Indique su fecha de entrada(dd-mm-yy): ");
      scanf("%d-%d-%d", &p[i].ddn.dd, &p[i].ddn.mm, &p[i].ddn.yy );
    printf("Indique su porcentaje de incremento(%): ");
      scanf("%f", &incremento[i]);
    printf("\n");

      *p[i].salario = sueldoBase + ((sueldoBase/100)*incremento[i]);
  } //Fin Ciclo

} //Fin Funcion

void salida();
void salida(){ //Init Funcion

    for(i = 0; i < n ; i++){ //Init Ciclo.

      printf("\n-NRO ENTRADA: %d", *entEmpleados[i].dependientes);
      printf("\n-ID: %d\n", *entEmpleados[i].idno );
      printf("-NAME: %s\n", *entEmpleados[i].nombre);
      printf("-FECHA: %d-%d-%d\n", entEmpleados[i].ddn.dd, entEmpleados[i].ddn.mm, entEmpleados[i].ddn.yy);
      printf("-INCREMENTO: %0.3f %\n", incremento[i]);
      printf("-NUEVO SUELDO: %0.3f\n", *entEmpleados[i].salario);

  } //Fin Ciclo.

} //Fin Funcion



main(){


  entrada(entEmpleados);
  salida();
}
