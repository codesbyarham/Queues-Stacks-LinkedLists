#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* make(int val) {
    Node* node = new Node();
    node->data = val;
    node->next = NULL;
    return node;
}

Node* add(Node* head, int val) {
    Node* node = make(val);
    if (head == NULL) return node;
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
    return head;
}

void show(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* sort(Node* head) {
    if (head == NULL) return head;
    bool swapped;
    Node* last = NULL;
    do {
        swapped = false;
        Node* temp = head;
        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
    return head;
}

int main() {
    Node* head = NULL;
    head = add(head, 5);
    head = add(head, 1);
    head = add(head, 4);
    head = add(head, 2);
    head = add(head, 3);

    cout << "Unsorted: ";
    show(head);

    head = sort(head);

    cout << "Sorted:   ";
    show(head);

    return 0;
}
