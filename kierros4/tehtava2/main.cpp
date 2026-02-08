#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack test;
    test.push('a');
    test.push('b');
    test.push('c');
    test.push('b');
    cout << "size(test)=" << size(test) << endl;
    test.push('d');
    test.push('e');
    test.push('b');
    test.push('b');
    test.push('a');
    test.push('b');
    cout << "Is full? " << full(test) << endl;
    delete_all(test, 'b');
    cout << "size(test) after delete_all('b') = " << size(test) << endl;
    Stack_entry t;
    if (pop_top(test, t) == success) {
        std::cout << "Popped: " << t << endl;
    }
    cout << "Is full? " << full(test) << endl;
    clear(test);
    cout << "Size after clear:" << size(test) << endl;
}