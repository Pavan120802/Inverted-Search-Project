#include "inverted_search.h"
int insert_at_last(Wlist **head, data_t *data)
{
     //create the node
	Wlist * new  = malloc(sizeof(Wlist));
    if( new == NULL )
	return FAILURE;

    //update the filecount, word tlink and link part
    new -> file_count = 1 ;
    strcpy(new -> word , data);
    new -> Tlink = NULL;
    new -> link = NULL;

    //call fun() to create and update sub node 
    update_link_table(&new);
    if( *head == NULL )
    {
		*head = new;
		return SUCCESS;
    }
    //insert at last
    Wlist *temp = *head;
    //traverse though the node
    while( temp -> link != NULL)
    {
    	temp = temp -> link;
    }
    temp -> link = new ;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
	//craete sub node
	Ltable *new = malloc(sizeof(Ltable));
	if( new == NULL)
		return FAILURE;
	//update the fields
	new -> word_count = 1;
	strcpy(new -> file_name , fname);
	new -> table_link = NULL;
	(*head) -> Tlink = new;
}	   
