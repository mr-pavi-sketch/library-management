
#include "header.h"

void save_issues(ISSUE *head)
{
    FILE *fp=fopen("issued.txt","w");

    if(fp==NULL)
        return;

    while(head)
    {
        fprintf(fp,
        "%d|%d|%d|%s|%s|%s|%s|%d\n",
        head->issue_id,
        head->book_id,
        head->user_id,
        head->user_name,
        head->issue_date,
        head->due_date,
        head->return_date,
        head->returned);

        head=head->next;
    }

    fclose(fp);
}
