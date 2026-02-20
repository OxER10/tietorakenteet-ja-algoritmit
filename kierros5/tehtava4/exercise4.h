#ifndef EXERCISE4_H
#define EXERCISE4_H

#include "stack.h"
#include "extended_queue.h"
#include "error_code.h"

// (a) Move all entries from a Stack into a Queue
Error_code move_stack_to_queue(Stack &s, Extended_queue &q);

// (b) Move all entries from a Queue onto a Stack.
Error_code move_queue_to_stack(Extended_queue &q, Stack &s);

// (c) Empty one Stack onto another so that entries keep same relative order.
Error_code stack_to_stack_preserve(Stack &source, Stack &target);

// (d) Empty one Stack onto another so that entries are in reverse order.
Error_code stack_to_stack_reverse(Stack &source, Stack &target);

// (e) Use a local Stack to reverse the order of all entries in a Queue.
Error_code reverse_queue(Extended_queue &q);

// (f) Use a local Queue to reverse the order of all entries in a Stack.
Error_code reverse_stack(Stack &s);

#endif