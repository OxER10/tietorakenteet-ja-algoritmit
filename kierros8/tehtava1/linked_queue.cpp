#include "linked_queue.h"

Queue::Queue( )
/*Post: The Queue is initialized to be empty. */
{
    front = rear = nullptr;
}

bool Queue::empty() const {
/*Post: Returns true if the Queue is empty, otherwise false. */
    return front == nullptr;
}

Error_code Queue::append(const Queue_entry &item)
/*Post: Add item to the rear of the Queue and return a code of success or
        return a code of overflow if dynamic memory is exhausted */
{
    Node* new_rear = new Node(item);
    if (new_rear == nullptr) return overflow;
    if (rear == nullptr) front = rear = new_rear;
    else {
        rear->next = new_rear;
        rear = new_rear;
    }
    return success;
}

Error_code Queue::serve()
/*Post: Remove front item from the Queue and return a code of success or
        return a code of underflow if the Queue is empty. */
{
    if (front == nullptr) return underflow;
    Node* old_front = front;
    front = old_front->next;
    if (front == nullptr) rear = nullptr;
    delete old_front;
    return success;
}

Error_code Queue::retrieve(Queue_entry &item) const
/*Post: The front item is copied to item and a code of success is returned or
        a code of underflow is returned if the Queue is empty. */
{
    if (front == nullptr) return underflow;
    item = front->entry;
    return success;
}

Queue::~Queue()
/*Post: The Queue is empty and all dynamic memory has been freed. */
{
    while (front != nullptr) {
        Node* old_front = front;
        front = old_front->next;
        delete old_front;
    }
    rear = nullptr;
}

Queue::Queue(const Queue& original)
/*Post: The Queue is initialized to be a copy of original. */
{
    front = rear = nullptr;
    Node* current = original.front;
    while (current != nullptr) {
        append(current->entry);
        current = current->next;
    }
}

void Queue::operator = (const Queue& original)
/*Post: The Queue is set to be a copy of original. */
{
    if (this == &original) return;

    while (front != nullptr) {
        Node* old_front = front;
        front = old_front->next;
        delete old_front;
    }
    rear = nullptr;

    Node* current = original.front;
    while (current != nullptr) {
        append(current->entry);
        current = current->next;
    }
}