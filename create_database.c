#include "inverted_search.h"
char *fname;
int create_database(Flist *f_head, Wlist *head[])
{
    // traverse through the file LL
	while ( f_head)
	{
		read_datafile(f_head, head , f_head -> file_name);
		f_head = f_head -> link;
	}
    return SUCCESS;
}

Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    FILE *fptr = fopen(filename, "r");
    char word[WORD_SIZE];
    fname = filename;

    int flag = 1;
    int index;

    while (fscanf(fptr, " %s", word) != EOF)
    {
        index = (tolower(word[0]) % 97);

        // non-alphabetical characters
        if (!(index >= 0 && index <= 25))
            index = 26;
        flag = 1; 

        if (head[index] == NULL)
        {
            insert_at_last(&head[index], word);
        }
        else
        {
            Wlist *temp = head[index];
            while (temp != NULL)
            {
                if (strcmp(temp->word, word) == 0) // Word found
                {
                    // Only update count for this file
                    update_word_count(&temp, filename);
                    flag = 0; // Word exists
                    break;
                }
                temp = temp->link;
            }
            // New word found
            if (flag == 1) 
            {
                insert_at_last(&head[index], word);
            }
        }
    }
    fclose(fptr);
    return *head;
}

int update_word_count(Wlist **head, char *file_name)
{
    // Traverse through the sub-node
    Ltable *temp = (*head)->Tlink;

    while (temp != NULL)
    {
        // Check if the filenames are the same
        if (strcmp(temp->file_name, file_name) == 0)
        {
            // Increment the word count
            temp->word_count++;
            return SUCCESS; 
        }
        // Move to the next sub-node
        temp = temp->table_link; 
    }

    // If the filename does not exist in the sub-node list
    // Increment the file count in the main node
    ((*head)->file_count)++;

    // Create a new sub-node
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
        return FAILURE; // Memory allocation failure

    // Update the fields of the new sub-node
    new->word_count = 1;
    strcpy(new->file_name, file_name);
    new->table_link = NULL;

    // Insert at last of subnode
    if ((*head)->Tlink == NULL)
    {
        // set the new node as the first sub-node
        (*head)->Tlink = new; 
    }
    else
    {
        temp = (*head)->Tlink;
        while (temp->table_link != NULL)
        {
            temp = temp->table_link;
        }
        temp->table_link = new;
    }
    return SUCCESS; 
}

