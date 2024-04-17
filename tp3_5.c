/*  Modifique el ejercicio nro 3 para que,
en lugar de ingresar un número fijo de nombres,
el usuario pueda indicar previamente la cantidad de 
nombres que ingresará a continuación. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Variable auxiliar
    char *buff = (char *)malloc(100 * sizeof(char));

    // Creo el arreglo de forma dinámica
    int cantNombres;
    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantNombres);

    char **nombres = (char **)malloc(cantNombres * sizeof(char *));

    // Cargo la cantidad de cantNombres nombres
    for (int i = 0; i < cantNombres; i++)
    {
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", buff);
        *(nombres + i) = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(*(nombres + i), buff);
    }

    // Muestro por pantalla los nombres
    for (int i = 0; i < cantNombres; i++)
    {
        printf("Nombre %d:", i + 1);
        puts(*(nombres + i));
    }

    // Libero memoria asignada dinámicamente
    free(buff);

    for (int i = 0; i < cantNombres; i++)
    {
        free(*(nombres + i)); // Libero cada puntero dentro de nombres
    }

    free(nombres); // Y aquí libero nombres como tal

    return 0;
}