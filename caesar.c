#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_key(string s);

int main(int argc, string argv[])
{
    
    // Verifica o argumento.
    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    
    // Converte a chave.
    int k = atoi(argv[1]);
    
    // Recebe o texto.
    string pt = get_string("plaintext: ");

    // Imprime o texto cifrado.
    printf("ciphertext: ");

    for (int i = 0, len = strlen(pt); i < len; i++)
    {
        char c = pt[i];
        if (isalpha(c))
        {
            char letra = 'A';
            if (islower(c))
            {
                letra = 'a';
            }
            // Converte as letras e aplica a fórmula.
            printf("%c", (c - letra + k) % 26 + letra);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return (0);
}

// Função que verifica o argumento para o main.
bool check_key(string s)
{
    for (int j = 0, l = strlen(s); j < l; j++)
    {
        if (!isdigit(s[j]))
        {
            return false;
        }
    }
    return true;
}