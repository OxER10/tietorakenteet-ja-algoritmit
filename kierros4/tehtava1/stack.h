#ifndef STACK_H
#define STACK_H

const int maxstack = 10;

typedef char Stack_entry;

enum Error_code {success, overflow, underflow};

class Stack {
public:
    Stack();
    Error_code pop();
    Error_code push(const Stack_entry &item);
    Error_code top(Stack_entry &item) const;
    bool empty() const;
    void clear(); // Reset the stack to be empty.
    bool full() const;  // If the stack is full,
                        // return true; else return false.
    int size() const;   // Return the number of entries
                        // in the stack.
    // c) is declared as a friend
    friend Error_code copy_stack_c(Stack &dest, const Stack &source);
private:
    int count;
    Stack_entry entry[maxstack];
};

// a) and b) are functions, not methods as is said on assingment
Error_code copy_stack_a(Stack &dest, Stack &source);
Error_code copy_stack_b(Stack &dest, Stack &source);

#endif