#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int i, c = 0;
    string t;

    if (argc == 2) // make sure that there is only 2 parameter as argument
    {
        while (argv[1][c])
        {
            if (!isdigit(argv[1][c])) // make sure that there is only digits in the key
            {
                printf("Usage: ./caesar key\n"); // print error
                return 1;
            }
            c++;
        }
        i = atoi(argv[1]); // convert the key to integer
        t = get_string("plaintext:  "); // get the plaintext
        c = 0;
        while (i > 26) // skip digits while it gratter than 26
        {
            i -= 26;
        }
        while (t[c])
        {
            if (islower(t[c]) || isupper(t[c])) // add the key to the  char
            {
                t[c] += i;
                if (!islower(t[c]) && !isupper(t[c])) // if the char is out of the alpha area we bring him back
                {
                    t[c] -= 26;
                }
            }
            c++;
        }
        printf("ciphertext: %s\n", t); // print result
        return 0;
    }
    printf("Usage: ./caesar key\n"); // print error
    return 1;
}