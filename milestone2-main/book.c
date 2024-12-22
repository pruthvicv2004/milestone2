#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/bst.h"

void insertBook(TreeNode **root) {
    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, 100, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter book author: ");
    fgets(newBook.author, 100, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove trailing newline

    newBook.isAvailable = 1; // By default, the book is available

    *root = insert(*root, newBook);
    printf("Book inserted successfully!\n");
}

void displayMenu() {
    printf("\nLibrary System Menu:\n");
    printf("1. Insert a new book\n");
    printf("2. Search for a book\n");
    printf("3. Delete a book\n");
    printf("4. Display all books\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    TreeNode *root = NULL;
    int choice;
    char searchTitle[100];
    char deleteTitle[100];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume the newline left by scanf

        switch (choice) {
            case 1:
                insertBook(&root);
                break;

            case 2:
                printf("Enter the title of the book to search: ");
                fgets(searchTitle, 100, stdin);
                searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove trailing newline
                TreeNode *result = search(root, searchTitle);
                if (result) {
                    printf("Book found: %s by %s\n", result->book.title, result->book.author);
                } else {
                    printf("Book not found: %s\n", searchTitle);
                }
                break;

            case 3:
                printf("Enter the title of the book to delete: ");
                fgets(deleteTitle, 100, stdin);
                deleteTitle[strcspn(deleteTitle, "\n")] = '\0'; // Remove trailing newline
                root = deleteNode(root, deleteTitle);
                break;

            case 4:
                printf("Books in the library (sorted by title):\n");
                displayBooks(root);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
