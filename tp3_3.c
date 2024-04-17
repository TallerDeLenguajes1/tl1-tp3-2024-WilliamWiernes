/*  Escriba un programa que solicite 5 nombres,
los cargue en un vector de punteros char y una
vez cargados sean listados por pantalla
(Todo implementando reserva dinámica de memoria) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Variable auxiliar
    char *buff = (char *)malloc(100 * sizeof(char));

    // char **V
    char **nombres = (char **)malloc(5 * sizeof(char *));

    // Cargo los 5 nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", buff);
        *(nombres + i) = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(*(nombres + i), buff);
    }

    // Muestro por pantalla los nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d:", i + 1);
        puts(*(nombres + i));
    }

    // Libero memoria asignada dinámicamente
    free(buff);

    for (int i = 0; i < 5; i++)
    {
        free(*(nombres + i)); // Libero cada puntero dentro de nombres
    }

    free(nombres); // Y aquí libero nombres como tal

    return 0;
}