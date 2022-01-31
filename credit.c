#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long nCartao;
    long digitos = 0;
    long nDigitos = 0;
  
    // Prompt for input
    do
    {
        nCartao = get_long("Informe o número do cartão: ");
    }
    while (nCartao <= 0);
    
    digitos = nCartao;

    // Calculate Checksum
    while (digitos > 0)
    {
        digitos = round(digitos / 10);
        nDigitos++;
    }
    
    // Checksum's algorithm
    int nAtual;
    int parTotal = 0;
    int imparTotal = 0;
    int nPar = 0;
    int iniciaisCartao = 0;
    
    while (nCartao > 0)
    {
        nAtual = nCartao % 10;
        nPar++;
        nCartao = nCartao / 10;
        
        if (nPar % 2 == 0)
        {
            nAtual = nAtual * 2;
            if (nAtual >= 10)
            {
                nAtual = (nAtual % 10) + (nAtual / 10);
                parTotal = parTotal + nAtual;
            }
            else
            {
                parTotal = parTotal + nAtual;
            }
        }
        else
        {
            imparTotal = imparTotal + nAtual;
        }
        
        // Starting digits
        if (nCartao < 100 && nCartao >= 10)
        {
            iniciaisCartao = nCartao;
        }
    }
    
    // Checking for card length and starting digits
    if (((parTotal + imparTotal) % 10) == 0 && nDigitos >= 12 && nDigitos <= 16)
    {

        // print AMEX, MASTERCARD, VISA or INVALID
        if (iniciaisCartao == 34 || iniciaisCartao == 37)
        {
            printf("AMEX\n");
        }
        else if (iniciaisCartao >= 51 && iniciaisCartao <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (iniciaisCartao / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
        
    }
    else
    {
        printf("INVALID\n");
    }
}

// 31/01/22