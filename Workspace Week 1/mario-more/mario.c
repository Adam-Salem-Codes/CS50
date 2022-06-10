#include <cs50.h>
#include <stdio.h>


void makePyramid(int height);


int main(void) {
    int height;
    do {
        height = get_int("Enter the height of the pyramid.");
    }
    while(height <= 0 || height > 8);
    makePyramid(height);

}




void makePyramid(int height) {

    for (int i = 1; i <= height; i++) {

        for (int j = i; j < height; j++) {
            printf(" ");
        }

        for (int k = 1; k <= i; k++) {
            printf("#");
        }
        printf("  ");


        for(int y = 1; y <= i; y++) {
            printf("#");
        }
        printf("\n");

    }




}