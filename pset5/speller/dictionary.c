// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <strings.h>

int words_in_dict = 0;


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //obtaing hash index
   int index = hash(word);

   node *cursor = table[index];
   while (cursor != NULL)
   {
       if (strcasecmp(cursor->word, word) == 0)
       {
           return true;
       }
       cursor = cursor->next;
   }


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int k = 40;
    unsigned int hash_value = 0;

    for (int i =0; i < strlen(word); i++)
    {

        hash_value = (hash_value * k) + toupper(word[i]);

    }
    return (hash_value % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        printf("failed to open file\n");
        return 1;
    }

    //Read strings from file one at a time
    char word[LENGTH + 1];



    while(fscanf(file, "%s", word) != EOF)
    {
         //Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (!new_node)
        {
            return 1;
        }

         strcpy(new_node->word, word);
         new_node-> next =NULL;


         //Hash word to obtain a hash value
         int index = hash(word);

         //Insert node into hash table at location
         if(table[index]== NULL)
         {
             table[index] = new_node;
         }
         else
         {
             new_node->next = table[index];
             table[index] = new_node;
         }
         words_in_dict++;




    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return words_in_dict;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {

       node *cursor = table[i];
       node*tmp = cursor;

       while( cursor != NULL)
       {
           cursor = cursor-> next;
           free(tmp);
           tmp = cursor;
       }

    }


    return true;
}
