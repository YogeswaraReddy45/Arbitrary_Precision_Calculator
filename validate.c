#include "inverted.h"
extern int flag1;
int validate_files(char *argv[], F_node **head)
{
    char *p=strrchr(*argv,'.');
    if(p==NULL)
    {
        printf("INFO :  %s => %s\n",*argv,"File without an Extension");
        return FAILURE ;
    }
    if(p==*argv)
    {
        printf("INFO :  %s => %s\n",*argv,"File name itself should not be extension");
        return FAILURE;
    }
    if(strcmp(p,".txt"))
    {       
        printf("INFO :  %s => %s\n",*argv,"File Extension is not matched");
        return FAILURE;
    }
    FILE *fp=fopen(*argv,"r");
    if(fp==NULL)
    {
        printf("INFO :  %s => %s\n",*argv,"File not exist in the current directory");
        return FAILURE;
    }
    int ch=getc(fp);
    if(ch==EOF)
    {
        return FAILURE;
    }
    fclose(fp);
    if(check_duplicates(*head,*argv))
    return FAILURE;
    if(insert_last(head, *argv)==INSERTION_FAILURE)
    return INSERTION_FAILURE;
    return SUCCESS;
}
int insert_last(F_node **head, char *f_name)
{
    F_node *node=malloc(sizeof(F_node));
    if(node==NULL)
    return INSERTION_FAILURE;
    strcpy(node->f_name,f_name);
    node->link=NULL;
    if(*head==NULL)
    {
        *head=node;
        return SUCCESS;
    }
    F_node *temp=*head;
    while(temp->link)
    {
        temp=temp->link;
    }
    temp->link=node;
    return SUCCESS;
}
int check_duplicates(F_node *head, char *f_name)
{
    F_node *temp=head;
    while(temp)
    {
        if(!strcmp(temp->f_name,f_name))
        {
            if(!flag1)
            printf("INFO : %s => %s\n",f_name,"This file is repeated, so it will not store into the list");
            return FAILURE;
        }
        temp=temp->link;
    }
        printf("INFO : Successful: inserting file name %s into file linked list\n",f_name);
    return SUCCESS;
}
int print_filenames(F_node *head)
{
    if(head==NULL)
    return FAILURE;
    printf("Head ->");
    while(head)
    {
        printf(" %s->",head->f_name);
        head=head->link;
    }
    printf(" NULL\n");
    return SUCCESS;
}