#include <stdio.h>

int Digitos(int N)
{
    int cont = 1;

    if (N >= 10)
    {
        N = N / 10;
        cont = cont + Digitos(N);
    }

    return cont;
}

int main()
{
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("Resultado: %d\n", Digitos(num));
}
