#include "inverted.h"

void save_database(hash *HT,F_node *head)
{
    char str[20];
    printf("enter the file where you can save the database:\n");
    while(1)
    {
        scanf("%19s",str);
        char *p=strchr(str,'.');
        if(p==NULL || strcmp(p,".txt"))
        {
            printf("not a valid file,enter again\n");
            continue;
        }
        break;
    }
    FILE *fp=fopen(str,"w");
    fprintf(fp,"%s\n","#index;word;filecount;filename;wordcount;#");
    for(int i=0;i<27;i++)
    {
        if(HT[i].H_link)
        {
            M_node *mtemp=HT[i].H_link;
            while(mtemp)
            {
                fprintf(fp,"#%d;%s;%d;",i,mtemp->word,mtemp->file_count);
                S_node *stemp=mtemp->sub_link;
                while(stemp)
                {
                    fprintf(fp,"%s;%d;",stemp->filename,stemp->word_count);
                    stemp=stemp->sub_link;
                }
                mtemp=mtemp->main_link;
                fprintf(fp,"#\n");
            }
        }
    }
    fclose(fp);
    printf("    [database saved successfully]\n");
}   
