#ifndef BST_H
#define BST_H

typedef struct {
    char title[100];
    char author[100];
    int isAvailable;
} Book;

typedef struct TreeNode {
    Book book;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *createNode(Book book);
TreeNode *insert(TreeNode *root, Book book);
TreeNode *search(TreeNode *root, char *title);
void displayBooks(TreeNode *root);
TreeNode *deleteNode(TreeNode *root, char *title);

#endif
