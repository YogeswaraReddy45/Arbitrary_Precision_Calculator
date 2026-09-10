#include "inverted.h"

void display_database(hash *HT)
{
    printf("-------------------------------------------------------------------------------------\n");
    printf("\nIndex\tWord\t\tFilecount\tFilename\t\tWordcount\n\n");
    printf("-------------------------------------------------------------------------------------\n");
    for(int i=0;i<27;i++)
    {
        if(HT[i].H_link)
        {
            M_node *mtemp=HT[i].H_link;
            while(mtemp)
            {
                printf("%2d\t%-10s\t%2d\t\t",i,mtemp->word,mtemp->file_count);
                S_node *stemp=mtemp->sub_link;
                while(stemp)
                {
                    printf("%-10s\t\t%2d\n\n",stemp->filename,stemp->word_count);
                    if(stemp->sub_link)
                    {
                        printf("\t\t\t\t\t");
                    }
                    stemp=stemp->sub_link;
                }
                mtemp=mtemp->main_link;
            }
        }
    }
    printf("-------------------------------------------------------------------------------------\n");
}
