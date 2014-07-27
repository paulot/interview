#include <iostream>

using namespace std;

struct node { int i; node *l, *r; };

bool isBst(node * r) {
    bool ret = true;
    if (r->l != NULL)
        if (r->l->i < r->i)
            ret &= isBst(r->l);
        else
            return false;
    if (r->r != NULL)
        if (r->r->i > r->i)
            ret &= isBst(r->r);
        else
            return false;
    return ret;
}

int main() {
    node *root = new node();
    root->i = 9;
    root->l = new node();
    root->l->i = 3;
    root->r = new node();
    root->r->i = 60;
    root->r->r = new node();
    root->r->l = new node();
    root->r->r->i = 90;
    root->r->l->i = 50;
    root->r->r->r = new node();
    root->r->r->r->i = 100;

    cout << isBst(root) << endl;
    return 0;
}
