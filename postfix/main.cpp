#include "stack.h"
#include "postfix.h"

int main()
/*  Post:   The program has executed simple arithmetic commands entered by the user.
    Uses:   The class Stack and functions introduction, instructions, do command,
            and get command. */
{
    Stack stored_numbers;
    introduction();
    instructions();
    while (do_command(get_command(), stored_numbers));
}