#include "inverted_search.h"

void save_database( Wlist *head[])
{
  //read a filename from the user
	char file_name[FNAME_SIZE];
	printf("Enter the filename : ");
	scanf("%s" , file_name);
    printf("\n");

	//open the file on write mdoe
	FILE *fptr = fopen(file_name , "w");

	//traverse though the hashtable
	for(int i = 0 ; i < 27 ; i++)
	{
		if(head[i] != NULL )
		{
			write_databasefile(head[i] , fptr);
		}
	}
    printf("-----------------------------------------------------------------\n");
	printf("                  Save Database is Successful                     \n");
    printf("-----------------------------------------------------------------\n");
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    Wlist *current = head;

    // Traverse the main linked list
    while (current != NULL)
    {
        // Write the word and its file count to the backup file
        fprintf(databasefile, "[index] word is [%s] : file count is [%d] :\n", current->word, current->file_count);

        // Traverse the link table for each word
        Ltable *subnode = current->Tlink;

        while (subnode != NULL)
        {
            // Write the filename and word count
            fprintf(databasefile, "--> filename is [%s] : word count is [%d]\n", subnode->file_name, subnode->word_count);
            // Move to the next file
            subnode = subnode->table_link;
        }
        // Add the `#`
        fprintf(databasefile, "#\n\n");
        
        // Move to the next word in main 
        current = current->link;
    }
}