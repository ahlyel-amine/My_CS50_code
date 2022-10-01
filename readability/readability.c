#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_grade(int nbr_letters, int nbr_words, int nbr_sentences);

int main(void)
{
    string text;
    int grade;
    int nbr_words, nbr_sentences, nbr_letters;
    // Get input Text
    text = get_string("Text: ");
    // Get number of letters
    nbr_letters = count_letters(text);
    // Get number of words
    nbr_words = count_words(text);
    // Get number of sentences
    nbr_sentences = count_sentences(text);
    // Count grade
    grade = count_grade(nbr_letters, nbr_words, nbr_sentences);
    // Print result
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %d\n", grade);
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int count_grade(int nbr_letters, int nbr_words, int nbr_sentences)
{
    double L, S, index;

    L = (double)(nbr_letters * 100) / nbr_words;
    S = (double)(nbr_sentences * 100) / nbr_words;
    index = (double)(0.0588 * L) - (0.296 * S) - 15.8; // Count Grade by Coleman-Liau formula
    return round(index);
}

int count_sentences(string text)
{
    int i, c, nbr_sentences;

    nbr_sentences = i = 0;
    while (i < strlen(text))  // Count number of sentences
    {
        if ((text[i] == '.' || text[i] == '?' || text[i] == '!')
            && (text[i - 1] != '.' && text[i - 1] != '?' && text[i - 1] != '!')
            && !(isspace(text[i]) && isspace(text[i - 1])))
        {
            nbr_sentences++;
        }
        i++;
    }
    return nbr_sentences;

}

int count_words(string text)
{
    int i, is_space, nbr_words, end_word;

    nbr_words = is_space = i = end_word = 0;
    while (isalpha(text[i]) || !isspace(text[i])) // count first word and skip it
    {
        i++;
    }
    nbr_words++;
    while (i < strlen(text)) // count the rest of words
    {
        if (isspace(text[i]))    // skip spaces
        {
            i++;
            is_space = 1;
        }
        while (isalpha(text[i])) //skip alphab
        {
            i++;
            end_word = 1;
        }
        while (!isalpha(text[i]) && !isspace(text[i])) // skip other chars
        {
            i++;
        }
        if (is_space && end_word) // if we have allredy skip an alpha and space increment nbr of words
        {
            nbr_words++;
            end_word = is_space = 0;
        }
    }
    return nbr_words;
}

int count_letters(string text)
{
    int i = 0;
    int nbr_letters = 0;

    while (i < strlen(text)) // Count number of letters
    {
        if (isalpha(text[i]))
        {
            nbr_letters++;
        }
        i++;
    }
    return nbr_letters;
}