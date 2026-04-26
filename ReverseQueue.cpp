#include <iostream>
using namespace std;

int q[100], front = -1, rear = -1;
int q2[100], front2 = -1, rear2 = -1;
int q3[100], front3 = -1, rear3 = -1;

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

void enq3(int val) {
    if (front3 == -1) front3 = 0;
    q3[++rear3] = val;
}

int deq3() {
    int val = q3[front3];
    if (front3 == rear3) { front3 = rear3 = -1; }
    else front3++;
    return val;
}

bool emp3() {
    return front3 == -1;
}

int main() {
    enq(1);
    enq(2);
    enq(3);
    enq(4);
    enq(5);

    int temp[100], n = 0;

    cout << "Original: ";
    while (!emp()) {
        temp[n] = deq();
        cout << temp[n];
        if (n < 4) cout << ", ";
        n++;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
        enq(temp[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            enq2(deq());
        enq3(deq());
        while (!emp2())
            enq(deq2());
    }

    while (!emp3())
        enq(deq3());

    cout << "Reversed: ";
    int i = 0;
    while (!emp()) {
        cout << deq();
        if (++i < n) cout << ", ";
    }
    cout << endl;

    return 0;
}
