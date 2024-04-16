#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // TERMINAR
    // Variable auxiliar
    char *buff;
    buff = (char *)malloc(100 * sizeof(char));

    char **nombres = (char **)malloc(5 * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        nombres[i] = (char *)malloc(strlen(buff) + 1 * sizeof(char));
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buff);
        strcpy(nombres[i], buff);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: %s \n", i + 1, *(nombres + i));
    }
    
    free(buff);
    free(nombres);

    return 0;
}