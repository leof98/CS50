#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pede uma altura entre 1 e 8 ao usuario
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Primeira piramide
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < height; column++)
        {
            if (row + column < height - 1) // Alinhamento
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");

        // Segunda pirâmide
        for (int column = 0; column < height; column++)
        {
            if (row >= column)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
