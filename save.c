
#include "header.h"
void save_books(BOOK *head)
{
    FILE *fp=fopen("books.txt","w");

    if(fp==NULL)
    {
        printf("File Open Error\n");
        return;
    }

    while(head)
    {
        fprintf(fp,"%d|%s|%s|%d\n",
                head->book_id,
                head->title,
                head->author,
                head->quantity);

        head=head->next;
    }

    fclose(fp);
}
