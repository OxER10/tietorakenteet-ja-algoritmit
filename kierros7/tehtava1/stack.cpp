#include "stack.h"

#include <new>

Stack::Stack()
/*  Pre:    None.
    Post:   The stack is initialized to be empty. */
    : top_node(nullptr), count(0)
{
}

Error_code Stack::pop()
/*  Pre:    None.
    Post:   If the Stack is not empty, the top of the Stack is removed. If the Stack is
            empty, an Error code of underflow is returned. */
{
    if (top_node == nullptr) {
        return underflow;
    }

    Node* old_top = top_node;
    top_node = top_node->next;
    delete old_top;
    --count;
    return success;
}

Error_code Stack::push(const Stack_entry &item)
/*  Pre:    None.
    Post:   If memory can be allocated, item is added to the top of the Stack.
            Otherwise, an Error code of overflow is returned. */
{
    Node* new_node = new (std::nothrow) Node{item, top_node};
    if (new_node == nullptr) {
        return overflow;
    }

    top_node = new_node;
    ++count;
    return success;
}

Error_code Stack::top(Stack_entry &item) const
/*  Pre:    None.
    Post:   If the Stack is not empty, the top of the Stack is returned in item. If the Stack
            is empty an Error code of underflow is returned. */
{
    if (top_node == nullptr) {
        return underflow;
    }

    item = top_node->data;
    return success;
}

bool Stack::empty() const
/*  Pre:    None.
    Post:   If the Stack is empty, true is returned. Otherwise false is returned. */
{
    return top_node == nullptr;
}

void Stack::clear()
{
    while (top_node != nullptr) {
        Node* old_top = top_node;
        top_node = top_node->next;
        delete old_top;
    }
    count = 0;
}

bool Stack::full() const
{
    return false;
}

int Stack::size() const
{
    return count;
}

Error_code Stack::copy_from(const Stack& other)
{
    if (other.top_node == nullptr) {
        return success;
    }

    // First create the head node.
    top_node = new (std::nothrow) Node{other.top_node->data, nullptr};
    if (top_node == nullptr) {
        return overflow;
    }

    Node* this_cursor = top_node;
    Node* other_cursor = other.top_node->next;

    while (other_cursor != nullptr) {
        this_cursor->next = new (std::nothrow) Node{other_cursor->data, nullptr};
        if (this_cursor->next == nullptr) {
            clear();
            return overflow;
        }
        this_cursor = this_cursor->next;
        other_cursor = other_cursor->next;
    }

    count = other.count;
    return success;
}

Error_code copy_stack_c(Stack &dest, const Stack &source)
{
    return (dest = source, success);
}

Error_code copy_stack_a(Stack &dest, Stack &source)
{
    dest = source;
    return success;
}

Error_code copy_stack_b(Stack &dest, Stack &source)
{
    Error_code outcome = success;
    Stack temp;
    Stack_entry x;

    // Empty source to temp.
    while (!source.empty()) {
        outcome = source.top(x);
        if (outcome != success) {
            return outcome;
        }
        outcome = source.pop();
        if (outcome != success) {
            return outcome;
        }
        outcome = temp.push(x);
        if (outcome != success) {
            // Restore source if a push fails.
            while (!temp.empty()) {
                temp.top(x);
                temp.pop();
                source.push(x);
            }
            return outcome;
        }
    }

    // Restore source and fill dest in original order.
    while (!temp.empty()) {
        outcome = temp.top(x);
        if (outcome != success) {
            return outcome;
        }
        outcome = temp.pop();
        if (outcome != success) {
            return outcome;
        }
        outcome = source.push(x);
        if (outcome != success) {
            return outcome;
        }
        outcome = dest.push(x);
        if (outcome != success) {
            return outcome;
        }
    }

    return success;
}