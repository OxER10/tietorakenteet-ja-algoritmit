#include "stack.h"
#include <iostream>

using namespace std;

int main() 
/*  Pre: The user supplies an integer n and n decimal numbers.
    Post: The numbers are printed in reverse order.
    Uses: The STL class stack and its methods */
{
    Stack s;
    Stack_entry top_item;
    long value;
    bool hasPrev = false;
    long prev = 0;
    cout << "Enter increasing sequence of integers."
    << endl
    << "Input ends when a value <= its predecessor is read."
    << endl;
    while (cin >> value) {
        if (hasPrev && value <= prev) {
            break;
        }
        if (s.push(value) == overflow) {
            cout << "Error: stack overflow" << endl;
            return 1;
        }
        prev = value;
        hasPrev = true;
    }
    while (!s.empty()) {
        s.top(top_item);
        s.pop();
        cout << top_item << " ";
    }
    cout << endl;
    return 0;
}