#include "header.h"
void issue_book(BOOK *bhead,ISSUE **ihead)
{
    int bid;

    printf("Book ID : ");
    scanf("%d",&bid);

    BOOK *book=bhead;

    while(book)
    {
        if(book->book_id==bid)
            break;

        book=book->next;
    }

    if(book==NULL)
    {
        printf("Book Not Found\n");
        return;
    }

    if(book->quantity<=0)
    {
        printf("No Copies Available\n");
        return;
    }

    ISSUE *new=malloc(sizeof(ISSUE));

    printf("Issue ID : ");
    scanf("%d",&new->issue_id);

    printf("User ID : ");
    scanf("%d",&new->user_id);

    printf("User Name : ");
    scanf(" %[^\n]",new->user_name);

    new->book_id=bid;

    time_t t=time(NULL);

    struct tm *tm=localtime(&t);

    strftime(new->issue_date,20,"%d-%m-%Y",tm);

    t+=7*24*60*60;

    tm=localtime(&t);

    strftime(new->due_date,20,"%d-%m-%Y",tm);

    strcpy(new->return_date,"Not Returned");

    new->returned=0;

    new->next=*ihead;
    *ihead=new;

    book->quantity--;

    printf("Book Issued Successfully\n");
}
