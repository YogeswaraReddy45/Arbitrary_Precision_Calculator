#include "inverted.h"

int create_database(hash *HT, F_node *head)
{
    FILE *fp;
    while(head)
    {
        fp=fopen(head->f_name,"r");
        char buf[25];
        while(fscanf(fp,"%24s",buf)!=-1)
        {
           int i=get_index(buf);
           if(insert_hashtable(&HT[i],buf,head->f_name))
           return INSERTION_FAILURE;
        }
        fclose(fp);
        head=head->link;
    }
    return SUCCESS;
}
int get_index(char *word)
{
    char ch =word[0];
    if(ch>=65 && ch<=90)
    return ch -'A';
    else if(ch>=97 && ch <=122)
    return ch-'a';
    else
    return 26;
}
int insert_hashtable(hash *HT,char *word,char *file_name)
{
    if(HT->H_link==NULL)
    {
        M_node *node1=create_mnode(word);
        if(node1==NULL)
        return INSERTION_FAILURE;
        S_node *node2=create_snode(file_name);
        if(node2==NULL)
        return INSERTION_FAILURE;
        node1->sub_link=node2;
        HT->H_link=node1;
        return SUCCESS;
    }
    M_node *mtemp=HT->H_link,*mprev=NULL;
    while(mtemp)
    {
        if(!strcmp(mtemp->word,word))
        {
            S_node *stemp=mtemp->sub_link,*sprev=NULL;
            while(stemp)
            {
                if(!strcmp(stemp->filename,file_name))
                {
                    stemp->word_count++;
                    return SUCCESS;
                }
                sprev=stemp;
                stemp=stemp->sub_link;
            }
            stemp=create_snode(file_name);
            if(stemp==NULL)
            return INSERTION_FAILURE;
            sprev->sub_link=stemp;
            mtemp->file_count++;
            return SUCCESS;
        }
        mprev=mtemp;
        mtemp=mtemp->main_link;
    }
    M_node *node1=create_mnode(word);
    if(node1==NULL)
    return INSERTION_FAILURE;
    S_node *node2=create_snode(file_name);
    if(node2==NULL)
    return INSERTION_FAILURE;
    node1->sub_link=node2;
    mprev->main_link=node1;
    return SUCCESS;
}
S_node *create_snode(char *file_name)
{
    S_node *node=malloc(sizeof(S_node));
    if(node!=NULL)
    {
        node->word_count=1;
        strcpy(node->filename,file_name);
        node->sub_link=NULL;
    }
    return node;
}
M_node *create_mnode(char *word)
{
    M_node *node=malloc(sizeof(M_node));
    if(node!=NULL)
    {
        node->file_count=1;
        strcpy(node->word,word);
        node->sub_link=NULL;
        node->main_link=NULL;
    }
    return node;
}