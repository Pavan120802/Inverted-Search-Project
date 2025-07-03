#include "inverted_search.h"

int main(int argc, char *argv[] )
{
	system("clear");
	Wlist *head[27]={ NULL };
	//validation, check CLA is passed or not
	if( argc <= 1 )
	{ 
		printf("Enter the valid no. of arg\n");
		printf("./a.out file1.exe file2.exe .......\n");
		return 0;
	}	

	//validate the file
	//declare th head pointer for the file node
	Flist *f_head = NULL ;
	//Wlist *head = NULL;
	file_validation_n_file_list(&f_head , argv);
	
	if( f_head  == NULL)
	{
		printf("No files are available in file LL\n");
		printf("Hence the process got terminated\n");
		return 1;
	}
	
	int choice;
	while(1)
	{
		printf("\n");
		// promt the usere to select the options to perform specific operations
		printf("Select your choice among the following to perform the operation: \n");
		printf("1. create database\n");
		printf("2. display database\n");
		printf("3. update database\n");
		printf("4. search\n");
		printf("5. save databse\n");
		printf("6. exit\n");
		printf("Please enter your choice\n");
		scanf("%d",&choice);

		// switch operation
		switch(choice)
		{
			case 1:
				if(create_database(f_head, head) == SUCCESS)
				{
					printf("-------------------------------------------------------------------------\n");
					printf("                     Database Created Successfully                       \n");
					printf("-------------------------------------------------------------------------\n");
				}
				break;
			case 2:
				display_database(head);
				break;
			case 3:
				update_database(head, &f_head);
				break;
			case 4:
				char word[WORD_SIZE];
    			printf("Enter the word to search: ");
    			scanf(" %s", word);
				printf("\n");
				search(head, word);
				break;
			case 5:
				save_database(head);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Please enter the valid choice!\n");
				break;
		
		}
	}
}
