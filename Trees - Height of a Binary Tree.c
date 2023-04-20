#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        struct node *cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

int height(struct node *root) {
    // Write your code here.
    if (root == NULL) {
        return -1;
    }
    return 1 + fmax(height(root->left), height(root->right));
}

int main(void) {
    int t;
    scanf("%d", &t);
    struct node *root = NULL;
    while (t-- > 0) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    int heightOfTree = height(root);
    printf("%d", heightOfTree);
    return 0;
}
