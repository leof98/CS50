#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Input
    string texto = get_string("Texto: "); 
    
    //Declaração
    int letras = 0;
    int palavras = 1;
    int frases = 0;
    int n = strlen(texto);
    
    //Contagem n de letras, palavras e frases.
    for (int i = 0; i < n; i++)
    {
        if (isalpha(texto[i]))
        {
            letras++;
        }
        else if (isspace(texto[i]))
        {
            palavras++;
        }
        else if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            frases++;
        }
    }
 
    //Coleman-Liau Index
    float l = (float)letras / palavras * 100;
    float s = (float)frases / palavras * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);
    
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}
// 02/02/22