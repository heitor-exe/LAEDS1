#include <stdio.h>

int main()
{
    FILE *arq;        // ponteiro para abrir o arquivo.
    char nomeArq[20]; // string com o nome do arquivo.
    int tam1 = 0;     // tamanho do arquivo.
    char linha[1000]; // vetor para armazenar as linhas do arquivo.

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArq);
    arq = fopen(nomeArq, "r"); // abre arquivo para leitura

    int resultado = 0;
    int caixa, fileira;     // variáveis de controle das caixas e fileiras.
    fgets(linha, 100, arq); // lê e salva o conteúdo de cada linha do arquivo

    // matriz que armazenará a orientação das caixas
    int m[tam1][tam1];

    // define tamanho do arquivo até a quebra de linha '\n'.
    for (int i = 0; linha[i] != '\n'; ++i)
    {
        tam1 *= 10;
        tam1 += ((int)linha[i]) - 48;
    }

    // percorre matriz
    for (int i = 0; i < tam1; ++i)
    {
        for (int j = 0; j < tam1; ++j)
        {
            m[i][j] = 0; // inicializa a matriz zerando ela.
        }
    }

    for (int i = 0; i < tam1; ++i)
    {
        // le até 99 caracter de cada linha do arquivo
        fgets(linha, 100, arq); // salva o conteúdo no vetor linha

        for (int j = 0, k = 0, tam2 = 0;; ++k)
        {
            if (linha[k] == '-')
                continue;
            
            // salva todo o conteudo do arquivo em uma matriz
            // removendo espaços e quebras de linha.
            if (linha[k] != ' ' && linha[k] != '\n')
            {
                m[i][j] *= 10;
                m[i][j] += ((int)linha[k]) - 48;
                ++tam2;
            }
            else
            {
                if (linha[k - tam2 - 1] == '-')
                {
                    m[i][j] *= (-1);
                }
                if (linha[k] == '\n')
                {
                    break;
                }
                ++j;
                tam2 = 0;
            }
        }
    }
    for (int i = tam1 - 1; i >= 0; --i)
    {
        for (int j = tam1 - 1, sum = 0; j >= 0; --j)
        {
            sum += m[i][j];

            for (int k = i - 1; k >= 0; --k)
            {
                for (int linha = i - 1; linha >= 0; --linha)
                {
                    sum += m[k][linha];
                }
            }
            if (sum >= resultado || (i == tam1 - 1 && j == tam1 - 1))
            {
                resultado = sum;
                fileira = i;
                caixa = j;
            }
            sum = 0;
        }
    }

    fileira += 1;
    caixa += 1;

    printf("Resposta: fileira %d, caixa %d.\n", fileira, caixa);

    fclose(arq);
    return 0;
}
