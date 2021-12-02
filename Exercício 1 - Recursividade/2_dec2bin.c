//  Autor: Heitor Vieira Macedo
//            2021

#include <stdio.h>

void dec2bin(int dec)
{
    if (dec / 2 == 0) // Se a divisão for exata
    {
        printf("Resultado: %d", dec % 2); // o resultado será o resto da divisão por 2.

        //printf("if\n");   -> print de teste
    }
    else // Caso contrário, chamamos a função novamente
    {
        dec2bin(dec / 2);      // chamamos a função com o valor da divisão de dec por 2.
        printf("%d", dec % 2); // print do resto da divisão de dec por 2.

        //printf("else\n"); -> print de teste

        // essa recursão vai ir acumulando os números correspondentes
        // às divisões e seus restos até formar um número binário completo.
    }
}

int main()
{
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    dec2bin(num);
    printf("\n");

    return 0;
}
