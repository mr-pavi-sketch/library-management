
#include "header.h"
void search_book(BOOK *head)
{
    int choice;

    printf("A. By Book ID\n");
    printf("B. By Book Name\n");
    printf("C. By Author Name\n");

    scanf("%d",&choice);

    if(choice==1)
    {
        int id;

        printf("Enter ID : ");
        scanf("%d",&id);

        while(head)
        {
            if(head->book_id==id)
            {
                printf("%d %s %s %d\n",
                head->book_id,
                head->title,
                head->author,
                head->quantity);
            }

            head=head->next;
        }
    }
}
