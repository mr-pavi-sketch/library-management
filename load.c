
#include "header.h"
void load_books(BOOK **head)
{
    FILE *fp=fopen("books.txt","r");

    if(fp==NULL)
        return;

    BOOK *new,*temp;

    while(1)
    {
        new=malloc(sizeof(BOOK));

        if(fscanf(fp,"%d|%49[^|]|%49[^|]|%d\n",
                  &new->book_id,
                  new->title,
                  new->author,
                  &new->quantity)!=4)
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
