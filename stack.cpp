// write a stack with pop, push, top, min;

#include <iostream>

using namespace std;

struct node {
    node *next;
    node *min;
    int item;
    node() : next(NULL), min(NULL) {}
};

class stack {
    private:
        node *root;

    public:
        stack();

        void push(int i);
        int pop();
        int top();
        int min();
};

stack::stack() {
    root = NULL;
}

void stack::push(int i) {
    node *t = new node;
    t->item = i;
    t->next = root;
    
    if (root != NULL and root->min->item < i) t->min = root->min;
    else t->min = t;
    root = t;
}

int stack::pop() {
    int r = root->item;
    node *d = root;
    root = root->next;
    delete d;
    return r;
}

int stack::top() {
    return root->item;
}

int stack::min() {
    return root->min->item;
}
 
int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(2);
    s.push(2);
    s.push(2);

    for (int i = 0; i < 6; i++) {
        cout << "min: " << s.min() << endl;
        cout << s.pop() << endl;
    }

    return 0;
}
