#include "stack.h"

#include <iostream>

using namespace std;

/* Answers:
Program works like before
*/

int main()
{
    Stack init;
    init.push('a');
    init.push('b');
    init.push('c');

    Stack copy_a, copy_b, copy_c;
    auto outcome1 = copy_stack_a(copy_a, init);
    init.push('d');
    auto outcome2 = copy_stack_b(copy_b, init);
    auto outcome3 = copy_stack_c(copy_c, init);

    cout << "Outcome1: " << outcome1
         << ", Outcome2: " << outcome2
         << ", Outcome3: " << outcome3 << endl;

    Stack_entry x;
    init.top(x);
    cout << "init top: " << x << endl;
    copy_a.top(x);
    cout << "copy_a top: " << x << endl;
    copy_b.top(x);
    cout << "copy_b top: " << x << endl;
    copy_c.top(x);
    cout << "copy_c top: " << x << endl;

    return 0;
}