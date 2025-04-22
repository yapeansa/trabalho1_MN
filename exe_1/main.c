#include <stdio.h>

// Contando número de bits na mantissa para números em ponto flutuante (float)
int contarBitsFloat()
{
    float um = 1.0f;
    float epsilon = 1.0f;
    int contador = 0;

    while ((um + epsilon / 2.0f) > um)
    {
        epsilon = epsilon / 2.0f;
        contador++;
    }

    return contador + 1;
}

// Contando número de bits na mantissa para números em ponto flutuante (caso double)
int contarBitsDouble()
{
    double um = 1.0;
    double epsilon = 1.0;
    int contador = 0;

    while ((um + epsilon / 2.0) > um)
    {
        epsilon = epsilon / 2.0;
        contador++;
    }

    return contador + 1;
}

int main(void)
{
    int bits_float = contarBitsFloat();
    int bits_double = contarBitsDouble();

    printf("Contagem do número de bits considerados na mantissa de números em ponto flutuante (float): %d.\n", bits_float);
    printf("Contagem do número de bits considerados na mantissa de números em ponto flutuante (double): %d.\n", bits_double);

    return 0;
}
