#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string getPlainText();
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    if (argc != 2) // If the number of commands isn't 2 than we know it's been inputed incorrectly.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)// Loop
    {
        if (!isdigit(argv[1][i])) // Loops over the first argument checking if there is a letter.
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }


    }


    int key = atoi(argv[1]); // Converts the first argument into an integer.

    string plainText = getPlainText(); // Gets the text to be encrypted.

    int length = strlen(plainText); // Gets the length of the plain text

    int index = 0; // How many times the upcoming while loop has run.

    char output[length];

    while (index < length)
    {
        // Checking if the character is in the alphabet and not a special character.
        if (isalpha(plainText[index]))
        {
            if (isupper(plainText[index])) // Checking if the letter is upper case.
            {
                output[index] = toupper(rotate(plainText[index], key));
            }
            else
            {
                // If it's not upper case we don't need to preserve anything.
                output[index] = rotate(plainText[index], key);
            }
        }
        else
        {
            output[index] = plainText[index];
            // If it's not in the alphabet than it's a special character and
            // we can just add it to the new character array.
        }

        index++; // Increases how many time the loop has been run.
    }
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", output[i]); // Prints the result to the console.
    }
    printf("\n");
    return 0;
}

string getPlainText()
{
    string plaintext = get_string("Plain text: "); // Prompts user for the text to be encrypted.
    return plaintext; // Returns that text.
}

char rotate(char letter, int key)
{
    // Rotates the chars to encrypt them.
    if (isupper(letter)) // Checking if the letter is upper case.
    {
        return (char)(letter + key - 65) % 26 + 65;
    }
    return (char)(letter + key - 97) % 26 + 97;
}