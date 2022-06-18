#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string calcCipher();
int checkDuplicates(string text);

int main(int argc, string argv[])
{
    if (argc != 2) // If there are too many or too little arguments than return an error.
    {
        printf("Usage: ./caesar key\n");
        return 1; // Returns error code 1.
    }
    string key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
        if (!isalpha(key[i])) // Checking if any other the characters aren't in the alphabet
        {
            printf("Invalid characters...\n");
            // If any of them aren't in the alphabet then we know it's invaild.
            return 1; // Returns error code 1.
        }
    }

    if (strlen(argv[1]) != 26) // Checking if the key is 26 characters long...
    {
        printf("Key must contain 26 characters.\n");
        return 1; // Returns error code 1.
    }

    if (checkDuplicates(key) == 1) // Checking for duplicates...
    {
        printf("Invalid key...\n");
        return 1; // Returns error code 1.
    }






    string input = get_string("plaintext: "); // Get's the user input.

    string solved = calcCipher(input, key); // Calculates the substitution cipher.

    printf("ciphertext: %s\n", solved); // Prints out the completed anwser to the substitution cipher...

    return 0; // Returns success code 0.
}

int checkDuplicates(string text)
{

    int x;
    int index = 0;
    const int length = strlen(text);
    while (index < length)
    {
        x = 1;
        for (int k = index + 1; k < length; k++)
        {
            if (text[index] == text[k] && text[index] != ' ')
            {
                x++;
                text[k] = '0';
            }
        }
        if (x > 1 && text[index] != '0')
        {
            return 1;
        }
        index++;
    }



    return 0;
}

string calcCipher(string text, string key)
{
    int index = 0;
    string ciphertext = text;
    while (text[index] != '\0') // Checks if we are at the end of the string if we aren't then run the loop
    {
        if (isalpha(text[index])) // Checking if the character at the index is in the alphabet.
        {
            if (isupper(text[index])) // Checks if the character is uppercase.
            {
                ciphertext[index] = key[text[index] - 'A'];
            }

            else
            {
                // If it wasn't than just make it lower case by default.
                ciphertext[index] = tolower(key[text[index] - 'a']);
            }
        }
        else
        {
            ciphertext[index] = text[index];
            // If it's not in the alphabet than just add it to the final result. No further manipulation needed.
        }

        index++;
    }
    return ciphertext;
}