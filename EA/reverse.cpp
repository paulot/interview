#include <iostream>

using namespace std;

struct node {
    node *next;
    int item;
};

node* reverseHelp(node *root, node *prev) {
    if (root == NULL) return prev;
    node *n = root->next;
    root->next = prev;
    reverseHelp(n, root);
}

int main() {
    node root;
    root.item = 9;
    node * r = &root;

    for (int i = 0; i < 10; i++) {
        r->next = new node();
        r->next->item = i;
        r = r->next;
    }
    r = NULL;

    r = &root;
    while (r != NULL) { 
        cout << r->item << " ";
        r = r->next;
    }
    cout << endl;
    
    r = reverseHelp(&root, NULL);
    while (r != NULL) { 
        cout << r->item << " ";
        r = r->next;
    }
    cout << endl;

    return 0;
}

