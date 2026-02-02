#ifndef STACK_H
#define STACK_H

const int maxstack = 10;

typedef int Stack_entry;

enum Error_code {success, overflow, underflow};

class Stack {
public:
    Stack();
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
private:
    int count;
    Stack_entry entry[maxstack];
};

#endif