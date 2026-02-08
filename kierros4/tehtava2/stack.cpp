#include "stack.h"

Stack::Stack()
/*  Pre:    None.
    Post:   The stack is initialized to be empty. */
{
    count = 0;
}

Error_code Stack::pop()
/*  Pre:    None.
    Post:   If the Stack is not empty, the top of the Stack is removed. If the Stack is
            empty, an Error code of underflow is returned. */
{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else --count;
        return outcome;
}

Error_code Stack::push(const Stack_entry &item)
/*  Pre:    None.
    Post:   If the Stack is not full, item is added to the top of the Stack. If the Stack is
            full, an Error code of overflow is returned and the Stack is left unchanged. */
{
    Error_code outcome = success;
    if (count >= maxstack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}

Error_code Stack::top(Stack_entry &item) const
/*  Pre:    None.
    Post:   If the Stack is not empty, the top of the Stack is returned in item. If the Stack
            is empty an Error code of underflow is returned. */
{
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}

bool Stack::empty() const
/*  Pre:    None.
    Post:   If the Stack is empty, true is returned. Otherwise false is returned. */
{
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}

void Stack::clear() {
    count = 0;
}

bool Stack::full() const {
    return (count >= maxstack);
}

int Stack::size() const {
    return count;
}

Error_code copy_stack_c(Stack &dest, const Stack &source) {
    if (source.count > maxstack) return overflow;
    dest.count = source.count;
    for (int i = 0; i < source.count; ++i) {
        dest.entry[i] = source.entry[i];
    }
    return success;
}

Error_code copy_stack_a(Stack &dest, Stack &source) {
    dest = source;
    return success;
}

Error_code copy_stack_b(Stack &dest, Stack &source) {
    Error_code outcome = success;
    Stack temp;
    Stack_entry x;
    // Empty source to temp
    while (!source.empty()) {
        outcome = source.top(x);
        if (outcome != success) return outcome;
        outcome = source.pop();
        if (outcome != success) return outcome;
        outcome = temp.push(x);
        if (outcome != success) {
            // Restore source if temp overflows
            while (!temp.empty()) {
                temp.top(x);
                temp.pop();
                source.push(x);
            }
            return outcome;
        }
    }
    // Restore source and fill dest
    while (!temp.empty()) {
        outcome = temp.top(x);
        if (outcome != success) return outcome;
        outcome = temp.pop();
        if (outcome != success) return outcome;
        outcome = source.push(x);
        // If source overflows
        if (outcome != success) return outcome;
        // If dest overflows
        outcome = dest.push(x);
        if (outcome != success) return outcome;
    }
    return success;
}

// Execise 2.
bool full(Stack &s) {
    return s.full();
}

Error_code pop_top(Stack &s, Stack_entry &t) {
    Error_code outcome = s.top(t);
    if (outcome != success) return outcome;
    outcome = s.pop();
    return outcome;
}

void clear(Stack &s) {
    while (!s.empty()) {
        s.pop();
    }
}

int size(Stack &s) {
    return s.size();
}

void delete_all(Stack &s, Stack_entry x) {
    Stack temp;
    Stack_entry item;
    while (!s.empty()) {
        if (s.top(item) == success) {
            s.pop();
            if (item != x) {
                temp.push(item);
            }
        } else {
            break;
        }
    }
    while (!temp.empty()) {
        if (temp.top(item) == success) {
            temp.pop();
            s.push(item);
        } else {
            break;
        }
    }
}