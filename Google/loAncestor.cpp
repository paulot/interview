#include <iostream>

using namespace std;

struct node {
    node *left;
    node *right;
    int item;
    node() : left(NULL), right(NULL) {}
};

int lowAncestor(node *root, node *first, node *second) {
    if (root == NULL) return 0;
    if (root == first or root == second) return 1 + lowAncestor(root->right, first, second) + 
        lowAncestor(root->left, first, second);

    int left = lowAncestor(root->left, first, second);
    int right = lowAncestor(root->right, first, second);

    if (left == 2) {
        cout << root->left->item << endl;
        return -1;
    } else if (right == 2) {
        cout << root->right->item << endl;
        return -1;
    } else if (right + left == 2) {
        cout << root->item << endl;
        return -1;
    }
    return left + right;
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

    lowAncestor(root, root->right, root->right->right);

    return 0;
}

