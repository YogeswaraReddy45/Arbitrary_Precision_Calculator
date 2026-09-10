#include "inverted.h"

void search_database(hash *HT)
{
    char str[30];
    printf("enter the data which you want to search\n");
    scanf("%29s",str);
    int flag=0;
    for(int i=0;i<27;i++)
    {
        if(HT[i].H_link)
        {
            M_node *mtemp=HT[i].H_link;
            while(mtemp)
            {
                if(!strcmp(mtemp->word,str))
                {
                    flag=1;
                    printf("The word %s is present in %d files\n",mtemp->word,mtemp->file_count);
                    S_node *stemp=mtemp->sub_link;
                    while(stemp)
                    {
                        printf("In file:%s %dtimes\n",stemp->filename,stemp->word_count);
                        stemp=stemp->sub_link;
                    }
                }
                mtemp=mtemp->main_link;
            }
        }
    }
    if(flag)
    return;
    printf("no data is found in the record\n");
}
