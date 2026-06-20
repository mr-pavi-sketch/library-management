
#include "header.h"
void load_issues(ISSUE **head)
{
    FILE *fp=fopen("issued.txt","r");

    if(fp==NULL)
        return;

    ISSUE *new,*temp;

    while(1)
    {
        new=malloc(sizeof(ISSUE));

        if(fscanf(fp,
        "%d|%d|%d|%49[^|]|%19[^|]|%19[^|]|%19[^|]|%d\n",
        &new->issue_id,
        &new->book_id,
        &new->user_id,
        new->user_name,
        new->issue_date,
        new->due_date,
        new->return_date,
        &new->returned)!=8)
        {
            free(new);
            break;
        }

        new->next=NULL;

        if(*head==NULL)
            *head=new;
        else
        {
            temp=*head;

            while(temp->next)
                temp=temp->next;

            temp->next=new;
        }
    }

    fclose(fp);
}
