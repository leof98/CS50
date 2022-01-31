#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float troco;
    int moedas = 0;
    
    do
    {
        troco = get_float("Informe o troco: ");
    }
    while (troco < 0);
    
    int centavos = round(troco * 100);

   
    while (centavos >= 1)
    {   
        if (centavos >= 25)
        {
            centavos -= 25;
            moedas++;
        }
    
        else if (centavos >= 10)
        {
            centavos -= 10;
            moedas++;
        }
    
        else if (centavos >= 5)
        {
            centavos -= 5;
            moedas++;
        }
    
        else if (centavos >= 1)
        {
            centavos -= 1;
            moedas++;
        }
    }  
    printf("%i\n", moedas);
}