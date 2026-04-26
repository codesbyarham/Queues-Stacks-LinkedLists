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

int len(Node* head) {
    int count = 0;
    while (head != NULL) { count++; head = head->next; }
    return count;
}

int sum(Node* head) {
    int total = 0;
    while (head != NULL) { total += head->data; head = head->next; }
    return total;
}

bool palin(Node* head) {
    int size = len(head);
    int arr[100];
    int i = 0;
    Node* temp = head;
    while (temp != NULL) { arr[i++] = temp->data; temp = temp->next; }
    for (int j = 0; j < size / 2; j++)
        if (arr[j] != arr[size - 1 - j]) return false;
    return true;
}

int checkIfWon(Node* head) {
    bool pal  = palin(head);
    bool four = (len(head) == 4);
    bool big  = (sum(head) >= 20);

    if (pal && four && big) return 3000;
    if (pal)                return 2000;
    if (four && big)        return 1000;
    return 0;
}

int main() {
    Node* ticket = NULL;
    ticket = add(ticket, 4);
    ticket = add(ticket, 2);
    ticket = add(ticket, 1);
    ticket = add(ticket, 2);
    ticket = add(ticket, 4);
    cout << "4->2->1->2->4    : Rs. " << checkIfWon(ticket) << endl;

    ticket = NULL;
    ticket = add(ticket, 5);
    ticket = add(ticket, 6);
    ticket = add(ticket, 5);
    ticket = add(ticket, 7);
    cout << "5->6->5->7       : Rs. " << checkIfWon(ticket) << endl;

    ticket = NULL;
    ticket = add(ticket, 9);
    ticket = add(ticket, 1);
    ticket = add(ticket, 1);
    ticket = add(ticket, 9);
    cout << "9->1->1->9       : Rs. " << checkIfWon(ticket) << endl;

    ticket = NULL;
    ticket = add(ticket, 2);
    ticket = add(ticket, 1);
    ticket = add(ticket, 1);
    ticket = add(ticket, 7);
    ticket = add(ticket, 1);
    ticket = add(ticket, 8);
    cout << "2->1->1->7->1->8 : Rs. " << checkIfWon(ticket) << endl;

    return 0;
}
