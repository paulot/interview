// Given bin tree and level output linked list of that level

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    node *left;
    node *right;
    int item;
    node() {
        right = NULL;
        left = NULL;
    }
};

void listFromTree(node *root, int d) {
    queue<node*> states;
    states.push(root);

    while (not states.empty()) {
        if (d == 0) {
            while (not states.empty()) {
                cout << states.front()->item << " ";
                states.pop();
            }
            cout << endl;
            return;
        }
        d--;
        
        int size = states.size();
        for (int i = 0; i < size; i++) {
            node *state = states.front();
            states.pop();
            // For both left and right add to queue;
            if (state->left != NULL)
                states.push(state->left);
            if (state->right != NULL)
                states.push(state->right);
        }
    }
    cout << "No Solution" << endl;
    return ;
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

    listFromTree(root, 0);

    return 0;
}
