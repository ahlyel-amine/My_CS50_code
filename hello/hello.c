#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? "); // getting name
    printf("hello, %s\n", name); // print the name in screen
}