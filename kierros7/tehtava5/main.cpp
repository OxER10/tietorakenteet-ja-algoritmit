#include "stack.h"
#include <iostream>
using namespace std;

/*
Answers:
(a) is included in test code

(b) If a counter is added, then every method that changes the number of nodes must also update count correctly.

pros over original linked stack:
- size() is O(1) instead of O(n)
- Should be more efficient when size is needed often, as it avoids traversing the stack to count nodes.
cons:
- more to keep track of
- Greater risks of implementation errors
- Counter and node chain can get out of sync, leading to incorrect size reporting.
*/

void print_stack(const char* name, Stack s)
{
    cout << name << " (size=" << s.size() << "): top -> ";
    Stack_entry x;
    while (!s.empty()) {
        s.top(x);
        cout << x;
        s.pop();
        if (!s.empty()) cout << " -> ";
    }
    cout << " -> null\n";
}

int main()
{
    Stack s;
    cout << "Initially: empty=" << boolalpha << s.empty()
         << ", size=" << s.size() << "\n";

    cout << "\nPushing a, b, c...\n";
    s.push('a');
    cout << "size after push a: " << s.size() << "\n";
    s.push('b');
    cout << "size after push b: " << s.size() << "\n";
    s.push('c');
    cout << "size after push c: " << s.size() << "\n";

    Stack_entry x;
    if (s.top(x) == success) {
        cout << "Current top: " << x << "\n";
    }
    print_stack("s", s);

    cout << "\nPopping one item...\n";
    s.pop();
    cout << "size after pop: " << s.size() << "\n";
    if (s.top(x) == success) {
        cout << "New top: " << x << "\n";
    }
    print_stack("s", s);

    cout << "\nTesting copy functions...\n";
    Stack copy_a, copy_b, copy_c;
    auto outcome1 = copy_stack_a(copy_a, s);
    auto outcome2 = copy_stack_b(copy_b, s);
    auto outcome3 = copy_stack_c(copy_c, s);

    cout << "Outcomes: a=" << outcome1
         << ", b=" << outcome2
         << ", c=" << outcome3 << "\n";
    print_stack("original s", s);
    print_stack("copy_a", copy_a);
    print_stack("copy_b", copy_b);
    print_stack("copy_c", copy_c);

    cout << "\nModifying original only (push d)...\n";
    s.push('d');
    print_stack("original s", s);
    print_stack("copy_a", copy_a);
    print_stack("copy_b", copy_b);
    print_stack("copy_c", copy_c);

    cout << "\nClearing original...\n";
    s.clear();
    cout << "After clear: empty=" << s.empty()
         << ", size=" << s.size() << "\n";

    return 0;
}
