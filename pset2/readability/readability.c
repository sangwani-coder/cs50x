//cs50 problem set 2 Readability
// program design Peter Z

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(int L);
int count_words(int W);
int count_sentence(int S);
int letter_count;
int word_count = 1;
int sentence_count;
string text;

int main()

{
    //getting user input
    int count_l;  // local variable
    int count_w;  // local variable
    int count_s;  // local variable
    text = get_string("Text: ");

//calling functions
    count_l = count_letters(letter_count); //calling letter function
    count_w = count_words(word_count); // calling word function
    count_s = count_sentence(sentence_count); // calling word function

    //coleman-liau index
    float average_letters = (((float) count_l / (float) count_w) * 100);
    float average_sentences = (((float) count_s / (float) count_w) * 100);

    float index = (0.0588 * average_letters - 0.296 * average_sentences - 15.8);

    int grade = round(index);

    //output
    if (grade < 1)

    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}


//letter counting function
int count_letters(int L)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count++;
        }
    }
    return letter_count;
}

//word counting function
int count_words(int W)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

//sentence counting function
int  count_sentence(int S)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}




