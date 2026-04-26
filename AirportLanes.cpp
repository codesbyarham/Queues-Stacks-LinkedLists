#include <iostream>
using namespace std;

int Q[100],  front  = -1, rear  = -1;
int q1[100], front1 = -1, rear1 = -1;
int q2[100], front2 = -1, rear2 = -1;
int q3[100], front3 = -1, rear3 = -1;
int q4[100], front4 = -1, rear4 = -1;

void enq(int val) {
    if (front == -1) front = 0;
    Q[++rear] = val;
}

int deq() {
    int val = Q[front];
    if (front == rear) { front = rear = -1; }
    else front++;
    return val;
}

bool emp() {
    return front == -1;
}

void enq1(int val) { if (front1 == -1) front1 = 0; q1[++rear1] = val; }
void enq2(int val) { if (front2 == -1) front2 = 0; q2[++rear2] = val; }
void enq3(int val) { if (front3 == -1) front3 = 0; q3[++rear3] = val; }
void enq4(int val) { if (front4 == -1) front4 = 0; q4[++rear4] = val; }

void show(int arr[], int f, int r, int name) {
    cout << "q" << name << ": ";
    if (f == -1) cout << "empty";
    else
        for (int i = f; i <= r; i++) {
            cout << arr[i];
            if (i < r) cout << ", ";
        }
    cout << endl;
}

int main() {
    enq(12);
    enq(9);
    enq(5);
    enq(8);
    enq(7);
    enq(6);
    enq(3);
    enq(10);

    while (!emp()) {
        int passport = deq();
        if      (passport % 4 == 0) enq4(passport);
        else if (passport % 3 == 0) enq3(passport);
        else if (passport % 2 == 0) enq2(passport);
        else                        enq1(passport);
    }

    cout << "Q: empty" << endl;
    show(q1, front1, rear1, 1);
    show(q2, front2, rear2, 2);
    show(q3, front3, rear3, 3);
    show(q4, front4, rear4, 4);

    return 0;
}
