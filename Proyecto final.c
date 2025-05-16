//Abraham Zuñiga
// Proyecto final
//programa en funciones de bebidas alcoholicas mas consumidas en un pueblo.

#include <stdio.h>
#include <stdlib.h>

#define PUEBLOS 5
#define BEBIDAS 8

void inicializarMatriz(int arr[PUEBLOS][BEBIDAS]) 
{
    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            arr[i][j] = 0;
}

void llenarMatriz(int arr[PUEBLOS][BEBIDAS]) 
{
    int var1, var2;
    for (int i = 0; i < PUEBLOS; i++) 
    {
        printf("Dame la bebida correspondiente del pueblo %d (0 a 7, -1 para salir): ", i);
        scanf("%d", &var1);
        while (var1 != -1) 
        {
            if (var1 >= 0 && var1 < BEBIDAS) 
            {
                printf("Dame la cantidad en litros: ");
                scanf("%d", &var2);
                arr[i][var1] = var2;
            } 
                else 
            {
                printf("Bebida inválida. Intenta de nuevo.\n");
            }
            printf("Dame otra bebida (0 a 7, -1 para salir): ");
            scanf("%d", &var1);
        }
    }
}

int bebidaMasConsumida(int arr[PUEBLOS][BEBIDAS]) 
{
    int total[BEBIDAS] = {0};
    int max = 0, bebida = 0;

    for (int j = 0; j < BEBIDAS; j++) 
    {
        for (int i = 0; i < PUEBLOS; i++) 
        {
            total[j] += arr[i][j];
        }
        if (total[j] > max) 
        {
            max = total[j];
            bebida = j;
        }
    }

    printf("La bebida %d es la más consumida con %d litros.\n", bebida, max);
    return bebida;
}

int bebidaAlcoholicaMasConsumida(int arr[PUEBLOS][BEBIDAS]) 
{
    int total[BEBIDAS] = {0};
    int max = 0, bebida = 0;

    for (int i = 0; i < BEBIDAS; i++) 
    {
        if (i != 1 && i != 6) 
        { 
            // Excluye Refresco (1) y Energéticos (6)
            for (int j = 0; j < PUEBLOS; j++) 
            {
                total[i] += arr[j][i];
            }
            if (total[i] > max) 
            {
                max = total[i];
                bebida = i;
            }
        }
    }

    printf("La bebida alcohólica %d es la más consumida con %d litros.\n", bebida, max);
    return bebida;
}

int puebloMasAlcohol(int arr[PUEBLOS][BEBIDAS]) 
{
    int total[PUEBLOS] = {0};
    int max = 0, pueblo = 0;

    for (int i = 0; i < PUEBLOS; i++) 
    {
        for (int j = 0; j < BEBIDAS; j++) 
        {
            if (j != 1 && j != 6) 
            
        { 
            // Excluye Refresco y Energéticos
                total[i] += arr[i][j];
            }
        }
        if (total[i] > max) 
        {
            max = total[i];
            pueblo = i;
        }
    }

    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max);
    return pueblo;
}

int main() 
{
    int arr[PUEBLOS][BEBIDAS];

    inicializarMatriz(arr);
    printf("Se inicializó la matriz de forma correcta.\n");

    llenarMatriz(arr);
    bebidaMasConsumida(arr);
    bebidaAlcoholicaMasConsumida(arr);
    puebloMasAlcohol(arr);

    return 0;
}
