#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/bst.h"

// Function to create a new tree node
TreeNode *createNode(Book book) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->book = book;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a book into the BST
TreeNode *insert(TreeNode *root, Book book) {
    if (root == NULL) 
        return createNode(book);
    
    if (strcmp(book.title, root->book.title) < 0)
        root->left = insert(root->left, book);
    else if (strcmp(book.title, root->book.title) > 0)
        root->right = insert(root->right, book);
    
    return root;
}

// Function to search for a book in the BST
TreeNode *search(TreeNode *root, char *title) {
    if (root == NULL || strcmp(root->book.title, title) == 0)
        return root;
    
    if (strcmp(title, root->book.title) < 0)
        return search(root->left, title);
    
    return search(root->right, title); 
}

// Function to display books in the BST in sorted order
void displayBooks(TreeNode *root) {
    if (root != NULL) {
        displayBooks(root->left);
        printf("Title: %s, Author: %s, Available: %s\n", root->book.title, root->book.author, root->book.isAvailable ? "Yes" : "No");
        displayBooks(root->right);
    }
}

// Function to delete a book from the BST
TreeNode *deleteNode(TreeNode *root, char *title) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(title, root->book.title) < 0)
        root->left = deleteNode(root->left, title);
    else if (strcmp(title, root->book.title) > 0)
        root->right = deleteNode(root->right, title);
    else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        root->book = temp->book;
        root->right = deleteNode(root->right, temp->book.title);
    }
    return root;
}
