#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
/*  Pre: The user supplies an integer n and n decimal numbers.
    Post: The numbers are printed in reverse order.
    Uses: The STL class stack and its methods */
{
    string item;
    Stack s;
    Stack_entry top_char;
    cout << "Type a line"
    << endl
    << "The characters will be printed in reverse order."
    << endl;
    getline(cin, item);
    for (char c : item) {
        if (s.push(c) == overflow) {
            cout << "Error: stack overflow" << endl;
            return 1;
        }
    }
    cout << endl;
    while (!s.empty()) {
        s.top(top_char);
        s.pop();
        cout << top_char;
    }
    cout << endl;
    return 0;
}