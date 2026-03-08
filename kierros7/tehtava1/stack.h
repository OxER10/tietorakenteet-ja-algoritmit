#ifndef STACK_H
#define STACK_H

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
    bool full() const;  // Linked stack is only limited by available memory.
    int size() const;   // Return the number of entries in the stack.

    // c) is declared as a friend
    friend Error_code copy_stack_c(Stack &dest, const Stack &source);

private:
    struct Node {
        Stack_entry data;
        Node* next;
    };

    Node* top_node;
    int count;

    Error_code copy_from(const Stack& other);
};

// a) and b) are functions, not methods as is said on assignment
Error_code copy_stack_a(Stack &dest, Stack &source);
Error_code copy_stack_b(Stack &dest, Stack &source);

#endif