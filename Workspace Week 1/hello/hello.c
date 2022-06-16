#include <stdio.h>
#include <cs50.h>


int main(void)
{
    string name = get_string("What's your name? "); // Asks your name and stores it in a variable

    printf("Hello, %s\n", name); // Says hello (Your name).

}
