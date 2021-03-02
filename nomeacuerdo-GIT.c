/* Diseñar un programa que permita a un usuario introducir los nombres y notas
   de N alumnos dentro de un archivo. Luego de haber sido introducidos, imprimir los contenidos del archivo.
   Utilice archivos de tipo binario.*/
#include <stdio.h>
struct estudiante
{
   char nombre[50];
   int notas;
};
int main(){
    struct estudiante estud1[5], estud2[5];
    FILE *p;
    int i, n;

    p = fopen("notas.txt","wb");

    printf("Cuantos alumnos?: ");
    scanf("%d", &n);

    for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        printf("Introduzca nombre: ");
        gets(estud1[i].nombre);

        printf("Introduzca notas: ");
        scanf("%d", &estud1[i].notas);
    }

    fwrite(estud1, sizeof(estud1), 1, p);
    fclose(p);

    p = fopen("notas.txt", "rb");
    printf("\n\n");
    fread(estud2, sizeof(estud2), 1, p);
    for(i = 0; i < n; ++i)
    {
        printf("--%s: %d\n\n", estud2[i].nombre, estud2[i].notas);
    }
    fclose(p);
    getch();
}
