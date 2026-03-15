#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

typedef char Queue_entry;
enum Error_code { success, overflow, underflow };

class Queue {
public:
//      standard Queue methods
    Queue();
    bool empty() const;
    Error_code append(const Queue_entry &item);
    Error_code serve();
    Error_code retrieve(Queue_entry &item) const;
//      Safety features for linked structures
    ~Queue();
    Queue(const Queue& original);
    void operator = (const Queue& original);
protected:
    Node *front, *rear;
};

class Extended_queue : public Queue {
public:
    bool full() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};

#endif