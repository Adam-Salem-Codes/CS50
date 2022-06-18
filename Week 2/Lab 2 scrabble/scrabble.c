#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int getposition(char letter);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2) // If player 1's score is high than player 2's than player one won.
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1) // If player 2's score is high than player 1's than player two won.
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2) // If the scores are equal than they tied.
    {
        printf("Tie!\n");
    }

    return 0; // Returns exit status 0 (Success)!
}
int getposition(char letter)
{
    if (isupper(letter)) // Checking if the letter is uppercase to get the index correctly.
    {
        return (int) letter - 'A';
        // I don't add one to this because we are working with arrays,
        // So it being off by one is actually correct.
    }
    return (int) letter - 'a';
}
int compute_score(string word)
{
    int result = 0;

    int length = strlen(word);
    int indices[length];

    for (int i = 0; i < length; i++) // Loops through the char array (string text).
    {
        if (isalpha(word[i])) // Checking if the letter is in the alphabet.
        {
            indices[i] = getposition(word[i]);
            // If it is then set indices at index i to equal to the position of the character at i in words.
        }
    }

    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        {
            result += POINTS[indices[i]]; // Result = result + the amount of points.
        }
    }

    return result; // Returns the amount of points
}
