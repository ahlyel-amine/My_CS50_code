#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check(char *str);
string replace(char *src, string dst);

int main(int argc, string argv[])
{
    string t;

    if (argc == 2) // make sure that there is only 2 parameter as argument
    {
        if (check(argv[1])) // call for the check function
        {
            return 1;
        }
        t = get_string("plaintext:  "); // get the plaintext
        t = replace(argv[1], t);        // call for the replace function
        printf("ciphertext: %s\n", t); // print result
        return 0;
    }
    printf("Usage: ./substitution key\n"); // print error
    return 1;
}

string replace(char *src, string dst)
{
    int i = 0;
    while (dst[i])
    {
        if (islower(dst[i])) // get the char from the charest
        {
            dst[i] = src[dst[i] - 97] + 32;
        }
        else if (isupper(dst[i])) // get the char from the charest
        {
            dst[i] = src[dst[i] - 65];
        }
        i++;
    }
    return dst;
}

int check(char *str)
{
    int i, c = 0;
    if (!(strlen(str) == 26))
    {
        printf("Key must contain 26 characters.\n"); // print error
        return 1;
    }
    while (c < 26) // translate string to upper case
    {
        if (islower(str[c]))
        {
            str[c] -= 32;
        }
        c++;
    }
    c = 0;
    while (c < 26)
    {
        i = c + 1;
        if (!isalpha(str[c]))// make sure that all character are alphabetic
        {
            printf("string containing characters that is not an alphabetic characters.\n");
            return 1;
        }
        while (i < 26) // make sure that there is one of each character
        {
            if (str[c] == str[i])
            {
                printf("string not containing each letter exactly once.\n");
                return 1;
            }
            i++;
        }
        c++;
    }
    return 0;
}