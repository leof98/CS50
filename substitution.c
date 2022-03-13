#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool key_check(string s);
bool repetido(string s);
bool erro(string s);
int main(int argc, string argv[])
{
   
    // VALIDATE KEY
    if (argc != 2)
    {
        printf("Usage: ./substituion KEY\n");
        return (1);
    }
    
    int digitos = strlen(argv[1]);
    if (digitos != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
        
    if (!key_check(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return (1);
    }

    int c = 0;
    bool erro;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                c++;
            }
        }
        if (c > 1)
        {
            erro = true;
        }
        c = 0;
        if (erro)
        {
            printf("Key must not contain repeated characters.\n");
            return (1);
        }
    }

    // GET KEY
    string key = argv[1];
    
    // GET PLAINTEXT
    string text = get_string("plaintext: ");

    // PRINT CIPHERTEXT
    printf("ciphertext: ");
    
    // ENCIPHER
    for (int k = 0, n = strlen(text); k < n; k++)
    {   
        char figura = text[k];
        if (isalpha(figura))
        {
            int a = tolower(figura) - 97;
            if (islower(figura))
            {
                printf("%c", tolower(argv[1][a]));
            }
            if (isupper(figura))
            {
                printf("%c", toupper(argv[1][a]));
            }
        }
        else 
        {
            printf("%c", text[k]);
        }
    }
    printf("\n");
    return (0);
}

bool key_check(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return (false);
        }
    }
    return (true);
}