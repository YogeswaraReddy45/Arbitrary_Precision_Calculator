#include "inverted.h"
#include<unistd.h>
int flag1;
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Provide minimum arguments\n");
		return FAILURE;
	}
	F_node *head = NULL;
    hash HT[27];
	for(int i=0;i<27;i++)
	{
		HT[i].index=i;
		HT[i].H_link=NULL;
	}
	for(int i=1;i<argc;i++)
	{
		if(validate_files(&argv[i],&head)==INSERTION_FAILURE)
		{
			printf("Insertion failure\n");
			return INSERTION_FAILURE;
		}
	}
	if(print_filenames(head))
	{
		printf("Not a single valid text file is provided\n");
		return SUCCESS;
	}
    int option;
	int flag=1;
    do
    {
	printf("Select your choice among following operations:\n1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n\nEnter your choice : ");

	scanf("%d", &option);
	switch (option)
	{
	    case 1:
		if(flag)
		{
			if(create_database(HT, head)==INSERTION_FAILURE)
			{
				printf("Insertion failure\n");
				return INSERTION_FAILURE;
			}
			printf("	[Data base created successfully]\n");
			flag=0;
		}
		else
		{
			printf("	[Data base has been already created]\n");
		}
		break;

	    case 2:
		if(flag==0 ||flag1)
		display_database(HT);
		else
		{
			printf("	[Data base is not created]\n");
		}
		break;

	    case 3:
		if(flag==0)
		save_database(HT,head);
		else
		{
			printf("	[Data base is not created]\n");
		}
		break;
	    case 4:
		if(flag==0)
		search_database(HT);
		else
		{
			printf("	[Data base is not created]\n");
		}
		break;

	    case 5:
		if(flag)
		{
			flag1=1;
			if(update_database(HT, &head)==INSERTION_FAILURE)
			{
				printf("Insertion failure\n");
				return INSERTION_FAILURE;
			}
		}
		else
		{
			printf("	[Data base has been already created]\n");
		}	
		break;

	    case 6:
		if(flag==0)
		{
			printf("Before quitting,do you want to save the database or not? y:n\n");
			char ch;
			while(1)
			{
				scanf(" %c",&ch);
				if(ch=='y')
				{
					save_database(HT,head);
					break;
				}
				else if(ch=='n')
				{
					printf("Chill !!,nothing changed\n");
					break;
				}
				printf("Invalid input\n");
			}
		}
		printf("[Terminating..]\n");
		sleep(1);
		break;

	    default:
		printf("INFO : Please enter the valid option\n");
	}
    }while( option != 6 );

    return 0;
}
