#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef char *string; // Declaring type string. (Makes my life easier).
typedef uint8_t BYTE; // Declaring type BYTE

#define BLOCK_SIZE 512
int main(int argc, char *argv[])
{
    if (argc != 2) // Checking amount of arguments passed.
    {
        printf("Usage: ./recover FILENAME.EXTENSTION\n"); // Telling the user the correct way to use the program.
        return 1; // Returns error code 1.
    }
    string filename = argv[1]; // Getting filename from console arguments.

    FILE *f = fopen(filename, "r"); // "r" for read access.

    if (f == NULL) // Checking if the initilization failed or not.
    {
        printf("Could not open the requested file..."); // Telling the user opening the file failed.
        return 2; // Returning exit code 2.
    }

    unsigned char b[BLOCK_SIZE]; // Creating the buffer array with BLOCK_SIZE amount of elements.

    int images = 0; // amount of total images.

    FILE *o = NULL; // Creating the output file.

    char *newfilename = malloc(8 * sizeof(char)); // Creating the filenames for the new image files.

    while (fread(b, 1, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        if (b[0] == 0xff && b[1] == 0xd8 && b[2] == 0xff && (b[3] & 0xf0) == 0xe0)
        {
            sprintf(newfilename, "%03i.jpg", images);
            o = fopen(newfilename, "w");
            images++; // incrementing amount of images by 1.
        }
        if (o != NULL) // Checking to see if there was a new file was created.
        {
            fwrite(b, sizeof(char), BLOCK_SIZE, o); // Copying buffer into output file.
        }
    }

    free(newfilename); // Unallocates the memory used for newfilename pointer.
    fclose(o); // Closes the files to avoid memory leaks.
    fclose(f);

    return 0; // Returns success code 0.
}