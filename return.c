
#include "header.h"
void return_book(BOOK *bhead,ISSUE *ihead)
{
    int bid,uid;

    printf("Book ID : ");
    scanf("%d",&bid);

    printf("User ID : ");
    scanf("%d",&uid);

    while(ihead)
    {
        if(ihead->book_id==bid &&
           ihead->user_id==uid &&
           ihead->returned==0)
        {
            time_t t=time(NULL);

            struct tm *tm=localtime(&t);

            strftime(ihead->return_date,20,"%d-%m-%Y",tm);

            ihead->returned=1;

            BOOK *b=bhead;

            while(b)
            {
                if(b->book_id==bid)
                {
                    b->quantity++;
                    break;
                }

                b=b->next;
            }

            printf("Book Returned Successfully\n");
            return;
        }

        ihead=ihead->next;
    }

    printf("Record Not Found\n");
}
