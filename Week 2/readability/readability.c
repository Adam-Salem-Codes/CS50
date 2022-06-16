#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calculateAlgorithm();
string prompt();
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //index = 0.0588 * L - 0.296 * S - 15.8

    string text = prompt(); // Prompts user for input.
    int grade = calculateAlgorithm(text); // Gets result from algorithm.

    if (grade >= 1 && grade <= 16) // If it's greater than 1 and less than 16.
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1) // If the grade level is less than 1.
    {
        printf("Before Grade 1\n");
    }
    if (grade > 16) // If the grade level is higher than 16.
    {
        printf("Grade 16+\n");
    }

}



int count_sentences(string text)
{
    int index = 0;

    int length = strlen(text);

    int amount_of_sentences = 0;
    while (index < length)
    {
        if (text[index] == '.' || text[index] == '!' || text[index] == '?')
        {
            amount_of_sentences++;
        }

        index++;
    }
    return amount_of_sentences;
}
int count_words(string text)
{
    int index = 0;

    int length = strlen(text);

    int amount_of_words = 0;
    while (index < length)
    {
        if (isspace(text[index]))
        {
            amount_of_words++;
        }

        index++;
    }
    return amount_of_words;
}
int count_letters(string text)
{

    int index = 0;

    int length = strlen(text);

    int amount_of_letters = 0;
    while (index < length)
    {
        if (isalpha(text[index]) && isspace(text[index]) == false)
        {
            amount_of_letters++;
        }
        index++;
    }

    return amount_of_letters;

}

string prompt()
{
    return get_string("Text: ");
    // Returns users input (probably shouldn't have made this a seperate function)
}
int calculateAlgorithm(string text)
{
    //index = 0.0588 * L - 0.296 * S - 15.8
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    words++; // Adds one to the amount of words.

    float L = ((float) letters * 100) / (float) words; // Calculating the average.
    float S = ((float) sentences * 100) / (float) words; // Calculating the average.

    float grade_level = 0.0588 * L - 0.296 * S - 15.8; // Algorithm.
    return round(grade_level); // Rounds the result and returns it.
}