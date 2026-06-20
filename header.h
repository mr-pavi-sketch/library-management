#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct book
{
    int book_id;
    char title[50];
    char author[50];
    int quantity;

    struct book *next;
}BOOK;

typedef struct issue
{
    int issue_id;

    int book_id;
    int user_id;

    char user_name[50];

    char issue_date[20];
    char due_date[20];
    char return_date[20];

    int returned;

    struct issue *next;
}ISSUE;

void add_book(BOOK **);
void update_book(BOOK *);
void remove_book(BOOK **);
void search_book(BOOK *);
void view_books(BOOK *);

void issue_book(BOOK *,ISSUE **);
void return_book(BOOK *,ISSUE *);
void list_issued_books(BOOK *,ISSUE *);

void save_books(BOOK *);
void save_issues(ISSUE *);

void load_books(BOOK **);
void load_issues(ISSUE **);

#endif
