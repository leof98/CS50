#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int altura;
    do
    {
        altura = get_int("Altura: ");  
    }
    while (altura < 1 || altura > 8);


    for (int linha = 0; linha < altura; linha++)
    {
        for (int coluna = 0; coluna < altura; coluna++)
        {
            if (linha + coluna < altura - 1)  // Verificação dos espaços para alinhamento dos blocos.
            {
                printf(" ");  
            }
            else 
            {
                printf("#");   
            }
        }
        printf("  ");
        
        // Impressão da segunda pirâmide
        for (int coluna = 0; coluna < altura; coluna++)
        {
            if (linha >= coluna)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}