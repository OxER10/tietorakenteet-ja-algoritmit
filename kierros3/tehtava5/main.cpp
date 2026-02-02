#include "extended_stack.h"
#include <iostream>

using namespace std;

void emptyTest(Extended_stack x) {
 cout << "Is stack empy? ";
    if (x.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

void fullTest(Extended_stack x) {
 cout << "Is stack full? ";
    if (x.full()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    Extended_stack s;
    emptyTest(s);
    cout << "Initial size: " << s.size() << endl;
    cout << "Pushing 3 items." << endl;
    s.push('1');
    s.push('2');
    s.push('3');
    cout << "Size after pushes: " << s.size() << endl;
    fullTest(s);
    cout << "Clearing stack." << endl;
    s.clear();
    cout << "Size after clear: " << s.size() << endl;
    emptyTest(s);
    cout << "Filling stack to maxstack." << endl;
    for (int i = 0; i < maxstack; ++i) {
        s.push('X');
    }
    cout << "Size at max: " << s.size() << endl;
    fullTest(s);
    return 0;
}