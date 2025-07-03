#include"inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    //read the filename from the user
    char file_name[FNAME_SIZE];
    printf("Enter the filename: ");
    scanf(" %s",file_name);
    printf("\n");

    //validate the file
    int empty1,ret_val;
    // Check if the file is empty or not available
    empty1 = isFileEmpty(file_name); 

        if (empty1 == FILE_NOTAVAILABLE) 
        {
            printf("File : %s is not available\n", file_name);
            printf("Hence we are not adding that file\n");
        } 
        else if (empty1 == FILE_EMPTY) 
        {
            printf("File : %s is empty\n", file_name);
            printf("Hence we are not adding that file\n");
        } 
        else 
        {
            // File is valid, so insert it into the file linked list
            ret_val = to_create_list_of_files(f_head, file_name);
            if (ret_val == SUCCESS) 
            {
                printf("Successfully inserted the file %s into the file Linked List \n", file_name);
            } 
            else if (ret_val == REPEATATION) 
            {
                printf("The file %s is repeated, hence we are not adding the file to Linked List \n", file_name);
            } 
            else 
            {
                printf("Failure in adding the file %s\n", file_name);
            }
        }

    //traverse through the filename SLL
    //compare the filenames
    while(*f_head)
    {
	    if(strcmp((*f_head) -> file_name , file_name) == 0)
	    {
		    create_database(*f_head , head );
            break;
	    }
	    *f_head = (*f_head) -> link;
    }
}