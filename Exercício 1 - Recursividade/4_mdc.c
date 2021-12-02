#include <stdio.h>

int mdc(int a, int b)
{
    if(b == 0)
        return a;
    
    else
        return mdc(b, a%b);
}

int main()
{
    int num1, num2;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("Resultado: %d\n", mdc(num1, num2));

    return 0;
}
