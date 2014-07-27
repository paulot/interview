// Find the lowest common ancestor of two nodes

#include <iostream>

using namespace std;

struct node {
    node *left;
    node *right;
    int item;
    node() : left(NULL), right(NULL) {}
};

int loAncestor(node *root, node *first, node *second) {
    if (root == NULL) return 0;
    if (root == first or root == second) return 1 + loAncestor(root->left, first, second) + loAncestor(root->right, first, second);

    int onLeft = loAncestor(root->left, first, second);
    int onRight = loAncestor(root->right, first, second);

    if (onLeft == 2) {
        cout << root->left->item;
        return -1;
    }
    if (onRight == 2) {
        cout << root->right->item;
        return -1;
    }
    if ((onLeft + onRight) == 2) {
        cout << root->item;
        return -1;
    } 
    return onLeft + onRight;
}

int main() {
    node *root = new node();
    root->item = 9;
    root->left = new node();
    root->left->item = 3;
    root->right = new node();
    root->right->item = 6;
    root->right->right = new node();
    root->right->left = new node();
    root->right->right->item = 7;
    root->right->left->item = 2;

    loAncestor(root, root->right, root->right->right);
    cout << endl;

    return 0;
}
