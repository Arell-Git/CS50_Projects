#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int compute_score(string word);


int main(void)
{
    // Get input words from both players

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int compute_score(string word)
{

    int length = strlen(word); //Gets word length
    int score = 0;
    int ASCII; //Gets ASCII value
    int arraydig; //Gets POINTS array digit

    for (int scr = 0; scr < length; scr++)
    {

//Checks if lowercase then gets int value of "scr" digit of word

        if (islower(word[scr]))
        {
            ASCII = toupper(word[scr]);
            arraydig = ASCII - 65;
        }
        else if (isupper(word[scr]))
        {
            ASCII = word[scr];
            arraydig = ASCII - 65;
        }

//Adds each associated POINT array value together

        if ((ASCII >= 65 && ASCII <= 90) || (ASCII >= 97 && ASCII <= 122))
        {
            score = score + POINTS[arraydig];
            ASCII = 0;
        }
    }

    return score;

}

