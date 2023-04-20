#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node * newNode(int data) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}
struct Node * insert(struct Node * root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else {
        struct Node * cur;
        if (data <= root -> data) {
            cur = insert(root -> left, data);
            root -> left = cur;
        } else {
            cur = insert(root -> right, data);
            root -> right = cur;
        }
        return root;
    }
}
int height(struct Node * root) {
    int leftHeight = - 1, rightHeight = - 1;
    if (root -> left) {
        leftHeight = height(root -> left);
    }
    if (root -> right)
        rightHeight = height(root -> right);
    return fmax(leftHeight, rightHeight) + 1;
}
void printInorder(struct Node * node) {
    if (node == NULL)
        return;
    printInorder(node -> left);
    printf("%d ", node -> data);
    printInorder(node -> right);
}
void printPreorder(struct Node * node) {
    if (node == NULL)
        return;
    printf("%d ", node -> data);
    printPreorder(node -> left);
    printPreorder(node -> right);
}
void printPostorder(struct Node * node) {
    if (node == NULL)
        return;
    printPostorder(node -> left);
    printPostorder(node -> right);
    printf("%d ", node -> data);
}
int main() {
    struct Node * root = NULL;
    int t;
    int data;
    scanf("%d", & t);
    while (t-- > 0) {
        scanf("%d", & data);
        root = insert(root, data);
    }
    printPreorder(root);
    printf("\n");
    printInorder(root);
    printf("\n");
    printPostorder(root);
    return 0;
}
