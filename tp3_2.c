#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Semill aleatoria
    srand(time(NULL));

    // Matriz estática
    int matriz[5][12];

    /* a.- Cargue dicha matriz con valores aleatorios 
    entre 10000 y 50000. */
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = 10000 + rand () % 40001;
        }
    }
    
    /* b.- Muestre por pantalla los valores cargados */
    for (int i = 0; i < 5; i++)
    {
        printf("_____Anio %d_____:\n", i + 1);
        for (int j = 0; j < 12; j++)
        {
            printf("Mes %d: $%d ", j + 1, matriz[i][j]);
        }
        printf("\n\n");
    }
    
    /* c.- Saque el promedio de ganancia por año
    y muestrelos por pantalla */
    float totalAnio, promedioAnio;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            totalAnio += matriz[i][j];
        }
        promedioAnio = totalAnio / 12;
        printf("Promedio Anio %d: $%.2f", i + 1, promedioAnio);
        printf("\n\n");
    }

    /* d.-  Obtenga el valor máximo y el valor mínimo obtenido 
    informando el "año" y el "mes" de cuándo ocurrió.*/
    int valorMax = matriz[0][0], valorMin = matriz[0][0], anioMax, anioMin, mesMax, mesMin;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (valorMax < matriz[i][j])
            {
                valorMax = matriz[i][j];
                anioMax = i + 1;
                mesMax = j + 1;
            }
            
            if (valorMin > matriz[i][j])
            {
                valorMin = matriz[i][j];
                anioMin = i + 1;
                mesMin = j + 1;
            }
        }
    }

    printf("Valor maximo es $%d obtenido en el Anio %d mes %d\n\n", valorMax, anioMax, mesMax);
    printf("Valor minimo es $%d obtenido en el Anio %d mes %d\n\n", valorMin, anioMin, mesMin);

    return 0;
}