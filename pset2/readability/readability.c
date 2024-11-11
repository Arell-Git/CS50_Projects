#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

//Calculate Grade Level
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

//Print Grade Level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Calculate letter count
int count_letters(string text)
{
    int length = strlen(text);
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        int ascii = text[i];
        if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
        {
            letters++;
        }
    }
    return letters;
}

//Calculate word count
int count_words(string text)
{
    int words = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        int ascii = text[i];
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words + 1;
}

//Calculate sentance count
int count_sentences(string text)
{
    int sentences = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        int ascii = text[i];
        if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63))
        {
            sentences++;
        }
    }
    return sentences;
}


