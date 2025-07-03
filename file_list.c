#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
	int i = 1, empty ,ret_val;
	while( argv[i] != NULL )
	{ 
		empty = isFileEmpty(argv[i]);

		if( empty == FILE_NOTAVAILABLE)
		{
			printf("\n");
			printf("File : %s is not available\n" , argv[i]);
	   		printf("Hence we are not adding that file\n");
			printf("\n");
			i++;
			continue;
		}
		else if ( empty == FILE_EMPTY)
		{
			printf("\n");
	    	printf("File ; %s is not having contents in it\n" , argv[i]);
	    	printf("Hence we are not adding that file\n");
			printf("\n");
			i++;
			continue;
		}
		else
		{
			//file is a valid file
			 ret_val = to_create_list_of_files(f_head , argv[i]);
			 if( ret_val == SUCCESS)
			 {
				printf("Successfull: inserting the file %s into file Linked List \n", argv[i]);
			 }
			 else if( ret_val == REPEATATION)
			 {
				printf("The file %s is repeated, hence we are not adding the file to Linked List \n", argv[i]);
			 }
			 else
			 {
				 printf("Failure\n");
			 }
			 i++;
			 continue;
		}
	}
}
 
//this fun() is used to check the file availability and check for file content
int isFileEmpty(char *filename)
{
	FILE *fptr = fopen(filename , "r" );

	//check file is present or not
	if( fptr == NULL)
	{
		// Return File is not avaible in directory
		return FILE_NOTAVAILABLE;
	}

	//check for the content
	fseek(fptr , 0 , SEEK_END);
	if( ftell(fptr) == 0 )
	{
		fclose(fptr);
		// Return file is empty
		return FILE_EMPTY;
	}
	else
	{
		fclose(fptr);
		return SUCCESS;
	}
}
int to_create_list_of_files( Flist **f_head , char *name)
{
	// Create a new node
    Flist *new = malloc(sizeof(Flist));
    // Check if the allocation fails
    if (new == NULL)
    {
        return FAILURE;  
    }

    // Initialize the link and char part
    strcpy(new->file_name, name);
    new->link = NULL;

    // If the list is empty, make the new node the head
    if (*f_head == NULL)
    {
        *f_head = new;
        return SUCCESS;
    }

    // Declare temp variable 
    Flist *temp = *f_head;
    
    // Traverse through the list 
    while (temp != NULL)
    {
		// check for duplicate
        if (strcmp(temp->file_name, name) == 0)
        {
            return REPEATATION;  // Duplicate file found
        }
		// move to next node
        temp = temp->link;
    }

    temp = *f_head;
	// traverse to the last node to insert the new node
    while (temp->link != NULL)
    {
        temp = temp->link; 
    }
    // Add the new node at the end of the list
    temp->link = new;
    return SUCCESS;
}
