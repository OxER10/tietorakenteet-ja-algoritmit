#include "extended_queue.h"
#include <limits>

Extended_queue::Extended_queue() {
    count = 0;
    rear = maxqueue - 1;
    front = 0;
}

bool Extended_queue::empty() const {
    return count == 0;
}

Error_code Extended_queue::append(const Queue_entry& item) {
    if (count >= maxqueue) return overflow;
    count++;
    rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
    entry[rear] = item;
    return success;
}

Error_code Extended_queue::serve() {
    if (count <= 0) return underflow;
    count--;
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
    return success;
}

Error_code Extended_queue::retrieve(Queue_entry& item) const {
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

void Extended_queue::clear() {
    count = 0;
    front = 0;
    rear = maxqueue - 1;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry& item) {
    if (empty()) return underflow;
    item = entry[front];
    return serve();
}

void introduction() {
    std::cout << "Extended_queue -demonstration (Circular queue, max "
              << maxqueue << " front).\n"
              << "Give one command per line. Display help with h." << std::endl;
}

void help() {
    std::cout << "This program allows the user to enter one command" <<std::endl
              << "(but only one) on each input line." << std::endl
              << "the program will serve the front of the queue." << std::endl
              << std::endl
              << " The valid commands are:" << std::endl
              << "A - Append the next input character to the extended queue" << std::endl
              << "S - Serve the front of the extended queue" << std::endl
              << "R - Retrieve and print the front entry." << std::endl
              << "# - The current size of the extended queue" << std::endl
              << "C - Clear the extended queue (same as delete)" << std::endl
              << "P - Print the extended queue" << std::endl
              << "H - This help screen" << std::endl
              << "Q - Quit" << std::endl
              << "Press <Enter> to continue." << std::endl;

    char c;
    do {
        std::cin.get(c);
    } while (c != '\n');
}

char get_command() {
    std::cout << "Command (A/S/R/#/C/P/H/Q): ";
    char c;
    std::cin >> c;
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

void Extended_queue::print_queue() {
    if (empty()) {
            std::cout << "[tyhja]\n";
            return;
        }
        std::cout << "[";
        for (int i = 0; i < count; ++i) {
            int idx = (front + i) % maxqueue;
            std::cout << entry[idx];
            if (i + 1 < count) std::cout << " ";
        }
        std::cout << "]\n";
}


bool do_command(char c, Extended_queue& test_queue) {
    bool continue_input = true;
    Queue_entry x;

    switch (c) {
    case 'a': {
        std::cout << "Give char to add: ";
        std::cin >> x;
        Error_code res = test_queue.append(x);
        if (res == overflow) {
            std::cout << "Error: Queue is full." << std::endl;
        } else {
            std::cout << "Added: " << x << std::endl;
        }
        break;
    }
    case 's': {
        Error_code res = test_queue.serve();
        if (res == underflow) std::cout << "Queue is empty." << std::endl;
        else std::cout << "Front deleted." << std::endl;
        break;
    }
    case 'r': {
        if (test_queue.retrieve(x) == underflow)
            std::cout << "Queue is empty." << std::endl;
        else
            std::cout << "Front entry: " << x << std::endl;
        break;
    }
    case '#': {
        std::cout << "Queue size: " << test_queue.size() << std::endl;
        break;
    }
    case 'c': {
        test_queue.clear();
        std::cout << "Queue emptied." << std::endl;
        break;
    }
    case 'p': {
        std::cout << "Queue: ";
        test_queue.print_queue();
        break;
    }
    case 'h': {
        help();
        break;
    }
    case 'q': {
        std::cout << "Extended_queue-demonstration ends." << std::endl;
        continue_input = false;
        break;
    }
    default:
        std::cout << "Invalid command. See help ('h')." << std::endl;
    }
    return continue_input;
}