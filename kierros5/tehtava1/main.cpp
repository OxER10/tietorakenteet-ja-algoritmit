#include "extended_queue.h"

int main() {
    Extended_queue test_queue;
    introduction();
    while (do_command(get_command(), test_queue)) {}
    return 0;
}
