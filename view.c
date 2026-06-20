#include "header.h"
void view_books(BOOK *head)
{
    printf("\n");

    printf("ID\tTitle\t\tAuthor\t\tQty\n");

    while(head)
    {
        printf("%d\t%s\t\t%s\t\t%d\n",
                head->book_id,
                head->title,
                head->author,
                head->quantity);

        head=head->next;

    }
}
