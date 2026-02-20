#include "stack.h"
#include "extended_queue.h"
#include "exercise4.h"

#include <iostream>
#include <string>

void print_stack(Stack s, const std::string &name) {
    std::cout << name << " (top->bottom): [";
    Stack_entry x;
    bool first = true;
    while (!s.empty()) {
        s.top(x);
        s.pop();
        if (!first) std::cout << " ";
        std::cout << x;
        first = false;
    }
    std::cout << "]\n";
}

void print_queue(Extended_queue q, const std::string &name) {
    std::cout << name << " (front->rear): ";
    q.print_queue();
}

void fill_stack(Stack &s, const std::string &chars) {
    s.clear();
    for (char c : chars) {
        s.push(c);
    }
}

void fill_queue(Extended_queue &q, const std::string &chars) {
    q.clear();
    for (char c : chars) {
        q.append(c);
    }
}

int main() {
    // (a) Stack -> Queue
    {
        Stack s; Extended_queue q;
        fill_stack(s, "abc");
        q.clear();

        std::cout << "(a) move_stack_to_queue\n";
        print_stack(s, "  s before");
        print_queue(q, "  q before");

        Error_code r = move_stack_to_queue(s, q);
        std::cout << "  result: " << (r == success ? "success" : "error") << "\n";
        print_stack(s, "  s after");
        print_queue(q, "  q after");
        std::cout << "\n";
    }

    // (b) Queue -> Stack
    {
        Stack s; Extended_queue q;
        fill_queue(q, "abc");
        s.clear();

        std::cout << "(b) move_queue_to_stack\n";
        print_queue(q, "  q before");
        print_stack(s, "  s before");

        Error_code r = move_queue_to_stack(q, s);
        std::cout << "  result: " << (r == success ? "success" : "error") << "\n";
        print_queue(q, "  q after");
        print_stack(s, "  s after");
        std::cout << "\n";
    }

    // (c) Preserve order Stack -> Stack
    {
        Stack source, target;
        fill_stack(source, "abc");
        fill_stack(target, "xy");

        std::cout << "(c) stack_to_stack_preserve\n";
        print_stack(source, "  source before");
        print_stack(target, "  target before");

        Error_code r = stack_to_stack_preserve(source, target);
        std::cout << "  result: " << (r == success ? "success" : "error") << "\n";
        print_stack(source, "  source after");
        print_stack(target, "  target after");
        std::cout << "  (expect target top->bottom starts with c b a ...)\n\n";
    }

    // (d) Reverse order Stack -> Stack
    {
        Stack source, target;
        fill_stack(source, "abc");
        fill_stack(target, "xy");

        std::cout << "(d) stack_to_stack_reverse\n";
        print_stack(source, "  source before");
        print_stack(target, "  target before");

        Error_code r = stack_to_stack_reverse(source, target);
        std::cout << "  result: " << (r == success ? "success" : "error") << "\n";
        print_stack(source, "  source after");
        print_stack(target, "  target after");
        std::cout << "  (expect target top->bottom starts with a b c ...)\n\n";
    }

    // (e) Reverse queue using local stack
    {
        Extended_queue q;
        fill_queue(q, "abcd");

        std::cout << "(e) reverse_queue\n";
        print_queue(q, "  q before");

        Error_code r = reverse_queue(q);
        std::cout << "  result: " << (r == success ? "success" : "error") << "\n";
        print_queue(q, "  q after");
        std::cout << "  (expect [d c b a])\n\n";
    }

    // (f) Reverse stack using local queue
    {
        Stack s;
        fill_stack(s, "abcd");

        std::cout << "(f) reverse_stack\n";
        print_stack(s, "  s before");

        Error_code r = reverse_stack(s);
        std::cout << "  result: " << (r == success ? "success" : "error") << "\n";
        print_stack(s, "  s after");
        std::cout << "  (expect top->bottom starts with a b c d)\n\n";
        return 0;
    }
}