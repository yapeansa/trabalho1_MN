#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para o cálculo do fatorial de um número
int fat(int k)
{
    int fat = 1;

    if (k == 0 || k == 1)
        return fat;

    for (int j = k; j >= 2; j--)
        fat *= j;

    return fat;
}

// Função que aproxima numericamente a função exponencial
float euler(int x, int n)
{
    float ans = 0.0;

    for (int i = n; i >= 0; i--)
        ans += pow(x, i) / ((float)fat(i));

    return ans;
}

int main(void)
{
    // Variáveis para os cálculos de aproximação e para o cálculo dos erros absolutos e relativos
    float aprox, real, err_abs, err_rel;
    // Conjunto de valores, armazenados em um vetor, a serem avaliados pelas funções aproximadas
    int valor[] = {-20, -10, -2, -1, 1, 2, 10, 20};

    for (int k = 0; k < 8; k++)
    {
        // Para a função aproximada avaliada em valores maiores ou iguais a zero
        if (valor[k] >= 0)
        {
            aprox = euler(valor[k], 16);
            real = exp(valor[k]);
        }
        // Caso contrário, adotamos a seguinte regra para avaliar em valores negativos
        else
        {
            aprox = 1.0 / euler(-valor[k], 16);
            real = 1.0 / exp(-valor[k]);
        }

        // Exibindo na tela os valores avaliados
        printf("Resultado original de e^{%d}: %f.\n", valor[k], real);
        printf("Resultado aproximado para e^{%d}: %f.\n", valor[k], aprox);

        // Cálculos dos erros absolutos e relativos (em porcentagem), respectivamente
        err_abs = aprox - real;
        err_rel = 100 * (err_abs / real);

        // Exibindo na tela os valores dos erros absolutos e relativos, respectivamente
        printf("Erro absoluto: %f - %f = %f.\n", aprox, real, err_abs);
        printf("Erro relativo: %f.\n\n", err_rel);
    }

    return 0;
}
