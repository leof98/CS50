#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int LETRAS[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 115, 116, 117, 118, 119, 120, 121, 122};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 == score2) 
    {
        printf("Tie!\n");
    }
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    int n = 0;
    int soma = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        n = tolower(word[i]); // Handle both uppercase and lowercase letters
        for (int j = 0; j < 26; j++)
        {
            if (n == LETRAS[j])
            {
                soma += POINTS[j]; // Return the numbers of points for the word
            }
            else
            {
                soma += 0;
            }
        }
        n = 0;
    }
    return (soma);
}