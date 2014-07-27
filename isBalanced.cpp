// Check if a tree is balanced or not

#include <iostream>

using namespace std;

struct node {
    node *left;
    node *right;
    int item;
    node() : left(NULL), right(NULL) {}
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int depth(node *root) {
    if (root == NULL) return 0;
    
    return 1 + max(depth(root->left), depth(root->right));
    // return 1 + depth(root->right);
}

bool isBalanced(node *root) {
    int left = depth(root->left);
    int right = depth(root->right);
    return left == right or left + 1 == right or left - 1 == right;
}

node * deepCopy(node *root) {
    if (root == NULL) return NULL;
    node *newRoot = new node();
    newRoot->item = root->item;
    newRoot->left = deepCopy(root->left);
    newRoot->right = deepCopy(root->right);
    return newRoot;
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

    node *nr = deepCopy(root);
    root->item = 1;
    cout << "root: " << root->item << endl;
    cout << "new root: " << nr->item << endl;
    // cout << isBalanced(root) << endl;
    // cout << depth(root) << endl;
    // cout << max(9, 7) << endl;

    return 0;
}
