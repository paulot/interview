#include <iostream>

using namespace std;

typedef struct llist {
    int node;
    llist *next;

} llist;

bool hasLoop(llist *root) {
    if (root == NULL)
        return false;
    llist *fast = root, *slow = root;

    while (true) {
        if (fast->next == NULL or fast->next->next == NULL)
            return false;
        else
            fast = fast->next;
        if (fast == slow)
            return true;
        else
            fast = fast->next;
        if (fast == slow)
            return true;
        slow = slow->next;
    }
}


int main() {
    llist root;
    root.node = 9;
    llist *ptr = &root;
    for (int i = 0; i < 20; i++) {
        llist bla;
        ptr->next = &bla;
        bla.node = i;
        cout << ptr->node << " ";
        ptr = ptr->next;
    }
    ptr->next = NULL;
    cout << endl;
    cout << hasLoop(&root) << endl;
    ptr->next = &root;
    cout << hasLoop(&root) << endl;
    ptr->next = ptr;
    cout << hasLoop(&root) << endl;
    ptr->next = root.next->next->next->next;
    cout << hasLoop(&root) << endl;
    cout << root.node << endl;
}
