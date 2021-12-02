#include <stdio.h>

int mult(int base, int exp)
{
    int res;
    if (exp == 0) // Todo numero elevado a zero é um.
    {
        res = 1;
    }
    else if (exp == 1) // Todo número elevado a 1 é ele mesmo.
    {
        res = base;
    }
    else // Preciso recorrer ao ultimo numero para encontrar o próximo
    {
        exp--;                         // O expoente deverá ser o anterior.
        base = base * mult(base, exp); // O número será a base vezes a potência anterior.
        res = base;
    }
    return res;
}

int main()
{
    int base, exp;

    printf("Digite a base e o expoente inteiros: ");
    scanf("%d %d", &base, &exp);

    printf("Resultado: %d\n", mult(base, exp));

    return 0;
}
