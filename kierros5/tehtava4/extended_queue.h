#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "error_code.h"

const int maxqueue = 10;

typedef char Queue_entry;

class Extended_queue {
public:
    Extended_queue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry&);
    Error_code retrieve(Queue_entry&) const;
    bool full() const { return count >= maxqueue; }
    int size() const { return count; }
    void clear();
    Error_code serve_and_retrieve(Queue_entry& item);
    void print_queue();
protected:
    int count;
    int front, rear;
    Queue_entry entry[maxqueue];
};

void introduction();
void help();
char get_command();
bool do_command(char c, Extended_queue& test_queue);

#endif