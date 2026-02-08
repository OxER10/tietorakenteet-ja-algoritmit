#include "stack.h"
#include <iostream>

using namespace std;

/* Answers: 
Which of these is easiest to write?: a) is easiest to write as it's only 1 line.
Which will run most quickly if the stack is nearly full?: a) and c) will beacuse they copy only once.
Which will run most quickly if the stack is nearly empty?: Still a) and c).
Which would be the best method if the implementation might be changed?: b) it uses only public interface.
In which could we pass the parameter source as a constant reference?: a) and c) since they don't change the source values.
*/

int main() {
    Stack init;
    init.push('a');
    init.push('b');
    init.push('c');
    Stack copy_a, copy_b, copy_c;
    auto outcome1 = copy_stack_a(copy_a, init);
    auto outcome2 = copy_stack_b(copy_b, init);
    auto outcome3 = copy_stack_c(copy_c, init);
    cout << "Outcome1: " << outcome1 << ", Outcome2: " << outcome2 << ", Outcome3: " << outcome3 << endl;
    Stack_entry x;
    // Verify each stack top
    init.top(x); cout << "init top: " << x << endl;
    copy_a.top(x); cout << "copy_a top: " << x << endl;
    copy_b.top(x); cout << "copy_b top: " << x << endl;
    copy_c.top(x); cout << "copy_c top: " << x << endl;
    return 0;
}