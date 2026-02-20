#include "exercise4.h"

Error_code move_stack_to_queue(Stack &s, Extended_queue &q) {
    Stack_entry x;
    Error_code outcome;
    while (!s.empty()) {
        if (s.top(x) != success) return outcome;
        Error_code r = q.append(x);
        if (r != success) return r;
        if (s.pop() != success) return outcome;
    }
    return outcome;
}

Error_code move_queue_to_stack(Extended_queue &q, Stack &s) {
    Stack_entry x;
    Error_code outcome;
    while (!q.empty()) {
        if (q.retrieve(x) != success) return outcome;
        Error_code r = s.push(x);
        if (r != success) return r;
        if (q.serve() != success) return outcome;
    }
    return outcome;
}

Error_code stack_to_stack_preserve(Stack &source, Stack &target) {
    Stack temp;
    Stack_entry x;
    Error_code outcome;
    while (!source.empty()) {
        if (source.top(x) != success) return outcome;
        if (temp.push(x) != success) return outcome;
        if (source.pop() != success) return outcome;
    }
    while (!temp.empty()) {
        if (temp.top(x) != success) return outcome;
        if (target.push(x) != success) return outcome;
        if (temp.pop() != success) return outcome;
    }
    return outcome;
}

Error_code stack_to_stack_reverse(Stack &source, Stack &target) {
    Stack_entry x;
    Error_code outcome;
    while (!source.empty()) {
        if (source.top(x) != success) return outcome;
        Error_code r = target.push(x);
        if (r != success) return r;
        if (source.pop() != success) return outcome;
    }
    return outcome;
}

Error_code reverse_queue(Extended_queue &q) {
    Stack s;
    Stack_entry x;
    Error_code outcome;
    while (!q.empty()) {
        if (q.retrieve(x) != success) return outcome;
        if (s.push(x) != success) return outcome;
        if (q.serve() != success) return outcome;
    }
    while (!s.empty()) {
        if (s.top(x) != success) return outcome;
        Error_code r = q.append(x);
        if (r != success) return r;
        if (s.pop() != success) return outcome;
    }
    return outcome;
}

Error_code reverse_stack(Stack &s) {
    Extended_queue q;
    Stack_entry x;
    Error_code outcome;
    while (!s.empty()) {
        if (s.top(x) != success) return outcome;
        Error_code r = q.append(x);
        if (r != success) return r;
        if (s.pop() != success) return outcome;
    }
    while (!q.empty()) {
        if (q.retrieve(x) != success) return outcome;
        if (s.push(x) != success) return outcome;
        if (q.serve() != success) return outcome;
    }
    return outcome;
}