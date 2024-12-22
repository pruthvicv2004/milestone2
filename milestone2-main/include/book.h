#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    int isAvailable;  // 1 for available, 0 for not available
} Book;

#endif
