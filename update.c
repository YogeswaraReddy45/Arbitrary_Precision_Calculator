#include "inverted.h"

int update_database(hash *HT, F_node **head)
{ 
    char str[25];
    printf("Enter the backup file.txt:\n");
    FILE *fp;
    while(1)
    {
        scanf("%24s",str);
        char *p=strrchr(str,'.');
        if(p==NULL)
        {
            printf("\t[No file extension]\n");
            continue;
        }
        if(p==str)
        {
            printf("\t[File name itself should not be extension]\n");
            continue;
        }
        if(strcmp(p,".txt"))
        {
            printf("\t[File extension is not matched]\n");
            continue;
        }
        fp=fopen(str,"r");
        if(fp==NULL)
        {
            printf("\t[File not exist in the current directory]\n");
            continue;
        }
        char ch=getc(fp);
        fseek(fp,0,SEEK_END-2);
        char ch2=getc(fp);
        if(ch!='#' || ch2!='#')
        {
            printf("\t[Not a valid backup file]\n");
            continue;
        }
        break;
    }
    rewind(fp);
    fseek(fp,43,SEEK_SET);
    int fcount,index;char word[25];
    while(fscanf(fp,"#%d;%[^;];%d;",&index,word,&fcount)!=EOF)
    {
        int wcount;char fname[25];
        for(int i=0;i<fcount;i++)
        {
            fscanf(fp,"%[^;];%d;",fname,&wcount);
            F_node *temp=*head;
            if(!check_duplicates(*head,fname))
            {
               if(insert_last(head, fname)==INSERTION_FAILURE)
                return INSERTION_FAILURE; 
            }
            if(insert_hashtable(&HT[index],word,fname))
            return INSERTION_FAILURE;
        }
        fscanf(fp,"#\n");
    }
    fclose(fp);
    print_filenames(*head);
    return SUCCESS;
}