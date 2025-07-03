#include "inverted_search.h"

void search( Wlist *head[], char *word)
{
	// Calculate the index
    int index = (tolower(word[0]) % 97);

    //non-alphabetic characters
    if (!(index >= 0 && index <= 25))
        index = 26;

    // Check if the index is empty
    if (head[index] == NULL)
    {
        printf("Word '%s' not found in the database.\n", word);
        return;
    }

    // Traverse the main linked list at the index
    Wlist *temp = head[index];
    while (temp != NULL)
    {
        // Compare the current word with the input word
        if (strcmp(temp->word, word) == 0)
        {
            // Word found --> print
            printf("-----------------------------------------------------------------\n");
            printf("Word '%s' found in %d file(s):\n", word, temp->file_count);
            Ltable *file = temp->Tlink;

            // Traverse the sub-node list to display file details
            while (file != NULL)
            {
                printf(" --> File: %s, Count: %d\n", file->file_name, file->word_count);
                file = file->table_link;
            }
            return;
        }
        temp = temp->link;
    }

    // If no match is found
    printf("Word '%s' not found in the database.\n", word);
} 