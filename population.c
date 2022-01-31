#include <stdio.h>
#include <cs50.h>

int main()
{
    int vInicial = 0;
    int vFinal = 0;
    
    // Solicite o valor inicial ao usuário.
    do 
    {   
        vInicial = get_int("Informe a população inicial (mínimo: 9): ");
    }
    while (vInicial < 9);
    
    // Solicite o valor final ao usuário.
    do
    {
        vFinal = get_int("Informe a população final: ");
    }
    while (vFinal <= vInicial);

    // Calcule o número de anos até o limite.
    int anos = 0;
    int total = vInicial;
    while (total < vFinal)
    {
        total = total + ((total / 3) - (total / 4));
        anos++;
    }

    // Imprima o número de anos.
    printf("Anos: %i\n", anos);
}
// 31/01/22