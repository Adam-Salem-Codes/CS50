#include <cs50.h>
#include <stdio.h>


void makePyramid(int height);


int main(void)
{
    int height; // Declares height so you can use it outside of the scope of the do loop.

    do
    {
        height = get_int("Enter the height of the pyramid."); // Gets user input (Height)
    }
    while (height <= 0 || height > 8); // Re-runs the loop if height isn't less than or equal to 0.

    makePyramid(height); // Makes the pyramid (Calls makePyramid function).

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
        printf("  ");


        for (int y = 1; y <= i; y++)
        {
            printf("#");
        }
        printf("\n");// Adds new layer to pyramid. (newline)

    }




}