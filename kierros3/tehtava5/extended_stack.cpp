#include "extended_stack.h"

Extended_stack::Extended_stack()
/*  Pre:    None.
    Post:   The stack is initialized to be empty. */
{
    count = 0;
}

Error_code Extended_stack::pop()
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

Error_code Extended_stack::push(const Stack_entry &item)
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

Error_code Extended_stack::top(Stack_entry &item) const
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

bool Extended_stack::empty() const
/*  Pre:    None.
    Post:   If the Stack is empty, true is returned. Otherwise false is returned. */
{
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}

void Extended_stack::clear() {
    count = 0;
}

bool Extended_stack::full() const {
    return (count >= maxstack);
}

int Extended_stack::size() const {
    return count;
}