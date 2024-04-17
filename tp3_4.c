#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} Cliente;

// iv.-
float CostoProducto(Producto Productos);

int main()
{
    // Semilla aleatoria
    srand(time(NULL));

    char *tiposProductos[] =
        {"Galletas",
         "Snack",
         "Cigarrillos",
         "Caramelos",
         "Bebidas"};

    /* i.- Desarrollar una interfaz por consola
    donde se solicite al usuario la cantidad de clientes.*/
    int cantClientes;
    printf("Cuantos clientes desea ingresar?: ");
    scanf("%d", &cantClientes);

    Cliente *CLIENTES = (Cliente *)malloc(cantClientes * sizeof(Cliente));

    /* ii) Solicitar al usuario la carga de los clientes
    creados dinámicamente en el paso anterior. */
    char *buff = (char *)malloc(100 * sizeof(char)); // Variable auxiliar
    for (int i = 0; i < cantClientes; i++)
    {
        CLIENTES[i].ClienteID = i;

        printf("\nIngrese el nombre del cliente con ID %d: ", CLIENTES[i].ClienteID);
        scanf("%s", buff);
        CLIENTES[i].NombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(CLIENTES[i].NombreCliente, buff);

        /* iii.- A medida que se dé de alta cada cliente,
        generar aleatoriamente la cantidad de productos
        asociados al cliente y sus características. */
        CLIENTES[i].CantidadProductosAPedir = 1 + rand() % 5;

        CLIENTES[i].Productos = (Producto *)malloc(CLIENTES[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < CLIENTES[i].CantidadProductosAPedir; j++)
        {
            CLIENTES[i].Productos[j].ProductoID = j;

            CLIENTES[i].Productos[j].Cantidad = 1 + rand() % 10;

            CLIENTES[i].Productos[j].TipoProducto = tiposProductos[rand() % 5];

            CLIENTES[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
        }
    }

    /* v.- Mostrar por pantalla todo lo cargado.
    Incluyendo un total a pagar por cliente
    (sumatoria del costo de todos los productos) */
    float costoFinal = 0;
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nCliente con ID: %d", CLIENTES[i].ClienteID);
        printf("\n\tNombre: %s", CLIENTES[i].NombreCliente);
        printf("\n\tCantidad de productos a pedir: %d", CLIENTES[i].CantidadProductosAPedir);

        for (int j = 0; j < CLIENTES[i].CantidadProductosAPedir; j++)
        {
            printf("\n\tProducto con ID: %d", CLIENTES[i].Productos[j].ProductoID);
            printf("\n\t\tCantidad: %d", CLIENTES[i].Productos[j].Cantidad);
            printf("\n\t\tTipo de producto: %s", CLIENTES[i].Productos[j].TipoProducto);
            printf("\n\t\tPrecio unitario: $%.2f", CLIENTES[i].Productos[j].PrecioUnitario);

            costoFinal += CostoProducto(CLIENTES[i].Productos[j]);
        }

        printf("\n\tCosto final: $%.2f", costoFinal);
        costoFinal = 0;
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }

    // Libero memoria asiganda dinámicamente
    for (int i = 0; i < cantClientes; i++)
    {
        free(CLIENTES + i);
    }

    return 0;
}

/* iv.- Implemente una función que calcule el costo total de un producto.
Esta función debe recibir como parámetro el producto y devolver el resultado
de calcular la Cantidad por el PrecioUnitario. */
float CostoProducto(Producto Productos)
{
    return Productos.Cantidad * Productos.PrecioUnitario;
}