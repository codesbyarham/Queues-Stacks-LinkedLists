#include <iostream>
using namespace std;

int q[100], front = -1, rear = -1;
int stack[100], top = -1;

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

bool qemp() {
    return front == -1;
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

bool semp() {
    return top == -1;
}

bool isOp(int val) {
    return val == -1 || val == -2 || val == -3;
}

int main() {
    enq(-3);
    enq(-2);
    enq(7);
    enq(3);
    enq(2);

    while (!qemp()) {
        int val = deq();
        push(val);

        while (top >= 2) {
            int a  = stack[top];
            int b  = stack[top - 1];
            int op = stack[top - 2];

            if (!isOp(a) && !isOp(b) && isOp(op)) {
                pop(); pop(); pop();
                int result = 0;
                if (op == -1) result = b + a;
                if (op == -2) result = b * a;
                if (op == -3) result = b / a;
                push(result);
            } else {
                break;
            }
        }
    }

    cout << "Result: " << stack[top] << endl;

    return 0;
}
