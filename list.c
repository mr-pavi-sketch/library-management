
#include "header.h"
void list_issued_books(BOOK *bhead,ISSUE *head)
{
    printf("\n");

    printf("IssueID\tBookID\tUserID\tUserName\tIssueDate\tDueDate\tReturnDate\n");

    while(head)
    {
        printf("%d\t%d\t%d\t%s\t%s\t%s\t%s\n",
                head->issue_id,
                head->book_id,
                head->user_id,
                head->user_name,
                head->issue_date,
                head->due_date,
                head->return_date);

        head=head->next;
    }
}
