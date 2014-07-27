#include <iostream>
#include <limits.h>

using namespace std;

struct node {
    node *l;
    node *r;
    int item;
    node() {
        r = NULL;
        l = NULL;
    }
};

bool isBstHelp(node *root, int min, int max) {
    if (root == NULL) return true;
    return (root->item < max and root->item > min) and
        isBstHelp(root->l, min, root->item) and
        isBstHelp(root->r, root->item, max);
}

bool isBst(node *root) {
    if (root == NULL) return true;
    return isBstHelp(root->l, INT_MIN, root->item) and
        isBstHelp(root->r, root->item, INT_MAX);
}

int main() {
    node *root = new node();
    root->item = 9;
    root->l = new node();
    root->l->item = 3;
    root->r = new node();
    root->r->item = 40;
    root->r->r = new node();
    root->r->l = new node();
    root->r->r->item = 50;
    root->r->l->item = 30;
    root->r->r->r = new node();
    root->r->r->r->item = 70;

    cout << isBst(root) << endl;

    return 0;
}
