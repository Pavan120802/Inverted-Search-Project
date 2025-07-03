#include "inverted_search.h"

void display_database(Wlist *head[])
{
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("[index]      [word]           [file_count]    [filename(s)]            [wordcount]\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            // Print the data of each node
            print_word_count(head[i]); 
        }
    }
    printf("\n");
}

int print_word_count(Wlist *head)
{
    while (head != NULL)
    {
        // Print the word details
        printf("[%d]          %-10s            %-8d", tolower(head->word[0]) % 97, head->word, head->file_count);

        // Print all sub-nodes 
        Ltable *Thead = head->Tlink;
        while (Thead != NULL)
        {
            printf("    %-20s          %-5d", Thead->file_name, Thead->word_count);
            // Move to the next sub-node
            Thead = Thead->table_link; 
        }
        printf("\n"); 
        // Move to the next main node
        head = head->link; 
    }
    return 0;
}