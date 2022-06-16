#include <cs50.h>
#include <stdio.h>


void makePyramid(int height);

int main(void)
{
    int height; // Declares int height to be used outside of the do's scope
    do
    {
        height = get_int("Enter the height of the pyramid: "); // Gets user input (Height)
    }
    while (height <= 0 || height > 8);

    makePyramid(height); // Makes the pyramid...

}

void makePyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = i; j < height; j++)
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}