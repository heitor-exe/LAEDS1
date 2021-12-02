#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *arq;
    char nomeArq[20];
    char mensagem[1000] = {'\0'};

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);

    arq = fopen(nomeArq, "r");

    fscanf(arq, "%s", mensagem);
    fclose(arq);

    //fgets(mensagem, 1000, arq);
    printf("\n--------------------\nMensagem codificada:\n--------------------\n");
    printf("%s\n", mensagem);

    // tamanho da mensagem
    int tam = 0;

    for (int i = 0; mensagem[i] != '\0'; i++)
    {
        tam++;
    }

    // Conversão de binário para decimal
    char bin[10000]; // número binário

    for (int i = 0; i < tam; i++)
    {
        if (mensagem[i] == '0' || mensagem[i] == '1')
        {
            bin[i] = mensagem[i];
        }
    }

    int dec = 0;
    dec = strtol(bin, NULL, 2); // converte binário para decimal

    // Remoção dos números binários no início da mensagem
    for (int i = 0; mensagem[i] != '\0'; i++)
    {
        int j;
        while (mensagem[i] >= '0' && mensagem[i] <= '9')
        {
            for (j = i; mensagem[j] != '\0'; j++)
            {
                mensagem[j] = mensagem[j + 1];
            }
            mensagem[j] = '\0';
        }
    }
    //printf("\nMensagem depois da remoção: %s\n", mensagem);

    // Remover letra intrusa
    int novapos = (dec - 1);
    for (int i = 0; i <= (dec - 1); i++)
    {
        while (mensagem[novapos] != '\0')
        {
            mensagem[novapos] = mensagem[novapos + 1];
            novapos++;
        }
    }

    // Remove permuta de blocos
    int qtdblocos = strlen(mensagem) / 4; // numero de blocos em q a mensagem será dividida
    char guarda1, guarda2;                // guarda os dois valores de cada bloco

    int aux1 = strlen(mensagem);
    int k = 0;

    while (k < qtdblocos * 2)
    {
        guarda1 = mensagem[k];
        guarda2 = mensagem[k + 1];

        mensagem[k] = mensagem[aux1 - 2];
        mensagem[k + 1] = mensagem[aux1 - 1];

        mensagem[aux1 - 2] = guarda1;
        mensagem[aux1 - 1] = guarda2;

        k = k + 4;
        aux1 = aux1 - 4;
    }

    // Remove espelhamento de blocos
    int k1 = 0;
    char aux;

    while (k1 < tam)
    {
        aux = mensagem[k1];
        mensagem[k1] = mensagem[k1 + 1];
        mensagem[k1 + 1] = aux;

        k1 = k1 + 2;
    }

    // Remove cifra de César
    int k2;

    for (k2 = 0; k2 < strlen(mensagem); k2++) // Percorre toda a mensagem
    {
        if (mensagem[k2] == '#') // substitui # pelo espaço
        {
            mensagem[k2] = ' ';
        }
        else if (mensagem[k2] > 69 && mensagem[k2] < 91)
        {
            mensagem[k2] = mensagem[k2] - 5;
        }
        else if (mensagem[k2] >= 65 && mensagem[k2] <= 69)
        {
            mensagem[k2] = mensagem[k2] + 21;
        }

        else if (mensagem[k2] >= 101 && mensagem[k2] <= 122)
        {
            mensagem[k2] = mensagem[k2] - 5;
        }
        else if (mensagem[k2] >= 97 && mensagem[k2] <= 101)
        {
            mensagem[k2] = mensagem[k2] + 21;
        }
    }

    printf("\n----------------------\nMensagem decodificada:\n----------------------\n");
    printf("%s\n", mensagem);

    return 0;
}
