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

    // char *V[]
    char *nombres[5];

    // Cargo los 5 nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buff);
        *(nombres + i) = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(*(nombres + i), buff);
    }

    // Muestro por pantalla los nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: ", i + 1);
        puts(*(nombres + i));
    }

    // Libero memoria asignada dinámicamente
    free(buff);
    
    for (int i = 0; i < 5; i++)
    {
        free(nombres + i);
    }

    return 0;
}