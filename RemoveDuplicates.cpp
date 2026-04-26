#include <iostream>
using namespace std;

int q[100], front = -1, rear = -1;
int q2[100], front2 = -1, rear2 = -1;
int seen[100], count = 0;

void enq(int val) {
    if (front == -1) front = 0;
    q[++rear] = val;
}

int deq() {
    int val = q[front];
    if (front == rear) { front = rear = -1; }
    else front++;
    return val;
}

bool emp() {
    return front == -1;
}

void enq2(int val) {
    if (front2 == -1) front2 = 0;
    q2[++rear2] = val;
}

int deq2() {
    int val = q2[front2];
    if (front2 == rear2) { front2 = rear2 = -1; }
    else front2++;
    return val;
}

bool emp2() {
    return front2 == -1;
}

bool exists(int val) {
    for (int i = 0; i < count; i++)
        if (seen[i] == val) return true;
    return false;
}

int main() {
    enq(3);
    enq(1);
    enq(4);
    enq(3);
    enq(4);
    enq(2);
    enq(1);

    cout << "Original: 3, 1, 4, 3, 4, 2, 1" << endl;

    while (!emp()) {
        int val = deq();
        if (!exists(val)) {
            seen[count++] = val;
            enq2(val);
        }
    }

    cout << "No duplicates: ";
    int i = 0;
    while (!emp2()) {
        cout << deq2();
        if (++i < count) cout << ", ";
    }
    cout << endl;

    return 0;
}
