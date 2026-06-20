#include "header.h"

int main()
{
    BOOK *book_head=NULL;
    ISSUE *issue_head=NULL;

    load_books(&book_head);
    load_issues(&issue_head);

    int choice;

    while(1)
    {
        printf("\n");
        printf("===================================\n");
        printf("     LIBRARY MANAGEMENT SYSTEM\n");
        printf("===================================\n");

        printf("1. Add New Book\n");
        printf("2. Update Book Details\n");
        printf("3. Remove Book\n");
        printf("4. Search Book\n");
        printf("5. View All Books\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. List Issued Books\n");
        printf("9. Save\n");
        printf("10. Exit\n");

        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_book(&book_head);
                break;

//            case 2:
  //              update_book(book_head);
    //            break;
//
  //          case 3:
    //            remove_book(&book_head);
       //         break;

            case 4:
                search_book(book_head);
                break;

            case 5:
                view_books(book_head);
                break;

            case 6:
                issue_book(book_head,&issue_head);
                break;

            case 7:
                return_book(book_head,issue_head);
                break;

            case 8:
                list_issued_books(book_head,issue_head);
                break;

            case 9:
                save_books(book_head);
                save_issues(issue_head);
                printf("Saved Successfully\n");
                break;

            case 10:
                save_books(book_head);
                save_issues(issue_head);
                exit(0);
        }
    }
}
