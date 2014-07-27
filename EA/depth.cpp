#include <iostream>

using namespace std;

struct node {
    node *left;
    node *right;
    int item;
    node() : left(NULL), right(NULL) {}
};

int max(int a, int b) {
    return a > b ? a : b;
}

int depth (node *root) {
    if (root == NULL) return 0;
    return 1 + max(depth(root->left), depth(root->right));
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
    root->right->right->right = new node();
    root->right->right->right->item = 1;
    cout << depth(root) << endl;

    return 0;
}
