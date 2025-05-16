#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int var1, var2, bebida, acum, bebida2, acum2, pueblo;
    int max = 0;  
    int max2 = 0;
    int max3 = 0;
    int arr[100][8]; 
    //nombre[8][12] = {"Natural", "Refresco", "Vino", "Cerveza", "Whisky", "Licores", "Energeticos", "Combinados"};
    int total[8] = {0,0,0,0,0,0,0,0};
    int total2[8] = {0,0,0,0,0,0,0,0};
    int total3[100];

    //Inicializar matriz
    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 8; j++)
        {
            arr[i][j] = 0;
        }
    }
    printf("Se inicializo la matriz de forma correcta.\n");

    //Llenar la matriz con información
    for(i = 0; i <= 99; i++)
    {
        printf("Dame la bebida correspondiente del pueblo %d: ", i);
        scanf("%d", &var1);
        while(var1 != -1)
        {
            printf("Dame la cantidad en litros: ");
            scanf("%d", &var2);
            arr[i][var1] = var2;
            printf("Dame otra bebida: ");
            scanf("%d", &var1);
        }

    }

    //Determinar cual es la bebida mas consumida entre los pueblos
    for(j = 0; j <= 7; j++)
    {
        for(i = 0; i <= 99; i++);
        {
            total[j] = total[j] + arr[i][j];
        }
    }

    for(i = 0; i < 8; i++)
    {
        if(max < total[i])
        {
            max = total[i];
            bebida = i;
        }
    }
    printf("La bebida %d es la bebida que mas se consume con %d litros.\n",
            bebida, max);
    
    //Bebida mas consumida
    for(i = 0; i < 8; i++)
    {
        acum = 0;
        if(i != 1 || i != 6)
        {
            for(j = 0; j < 100; j++)
            {
                acum = acum + arr[j][i];
            }
            total2[i] = acum;
        }
    }

    for(i = 0; i < 8; i++)
    {
        if(max2 < total2[i])
        {
            max2 = total2[i];
            bebida2 = i;
        }
    }
    printf("La bebida %d es la mas consumida con %d litros.\n", bebida2, max2);

    //Pueblo que bebe mas alcohol en total
    for(i = 0; i < 100; i++)
    {
        total3[i] = 0;
    }

    for(i =0; i < 100; i++)
    {
        acum2 = 0;
        for(j = 0; j < 8; j++)
        {
            if(j != 1 || j !=6)
            {
                acum2 = acum2 + arr[i][j];
            }
            
        }
        total3[i] = acum2;
    }

    for(i = 0; i < 100; i++)
    {
        if(max3 < total3[i])
        {
            max3 = total3[i];
            pueblo = i;
        }
    }
    printf("El pueblo %d comsume mas alcohol con %d litros.", pueblo, max3);
    return 0;
    
}
