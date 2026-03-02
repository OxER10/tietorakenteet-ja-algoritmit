#include "postfix.h"
#include <iostream>

using namespace std;

void introduction() {
    cout << "In a PostFix calculator, the operands (numbers, usually)" << endl
    << "are entered before an operation (like addition, subtraction," << endl
    << "multiplication, or division) is specified. The operands are pushed" << endl
    << "onto a stack. When an operation is performed, it pops its operands" << endl
    << "from the stack and pushes its result back onto the stack." << endl << endl;
}

void instructions() {
    cout << "When using PostFix calculator, use only real numbers and operators." << endl
    << "Artihmetic operators are:" << endl
    << "[?]push to stack [=]print top" << endl
    << "[x]exchange top two [s]sum whole stack" << endl
    << "[+] [-] [*] [/]" << endl
    << "[Q]uit." << endl << endl;
}

char get_command() {
    char command;
    bool waiting = true;
    cout << "Select command and press < Enter > :";

    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || 
            command == '=' || 
            command == '+' ||
            command == '-' || 
            command == '*' || 
            command == '/' ||
            command == 'x' || // 2nd increment
            command == 's' || // 3rd increment
            command == 'a' || // 4th increment
            command == 'q') waiting = false;

        else {
            cout << "Please enter a valid command:" << endl
            << "[?]push to stack [=]print top" << endl
            << "[x]exhange top two [s]sum of whole stack [a]average of whole stack" << endl
            << "[+] [-] [*] [/] are arithmetic operations" << endl
            << "[Q]uit." << endl;
        }
    }
    return command;
}

bool do_command(char command, Stack &numbers)
/*  Pre:    The first parameter specifies a valid calculator command.
    Post:   The command specified by the first parameter has been applied to the Stack
            of numbers given by the second parameter. A result of true is returned unless
            command == 'q'.
    Uses:   The class Stack. */
{   
    double p, q;
    switch (command) {
        case '?':
            cout << "Enter a real number: " << flush; cin >> p;
            if (numbers.push(p) == overflow)
                cout << "Warning: Stack full, lost number" << endl; break;
        case '=':
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else cout << p << endl; break;
        case '+':
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(q) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                }
                else {
                    numbers.pop();
                    if (numbers.push(q + p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    }
            } break;
        case '-':
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(q) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                }
                else {
                    numbers.pop();
                    if (numbers.push(q - p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    }
            } break;
        case '*':
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(q) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                }
                else {
                    numbers.pop();
                    if (numbers.push(q * p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    }
            } break;
        case '/':
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(q) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                }
                else {
                    numbers.pop();
                    if (numbers.push(q / p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    }
            } break;
        case 'x': // 2nd increment
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(q) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                }
                else {
                    numbers.pop();
                    if (numbers.push(p) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    if (numbers.push(q) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                    }
            } break;
        case 's': // 3rd increment
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                for (int i = 0; i <= maxstack; i++){
                    if (numbers.top(p) == success) {
                        numbers.pop();
                        q += p;
                    } 
                    else {
                        numbers.push(q);
                        break;
                    }
                }
            } break;
        case 'a': // 4th increment
            if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
            else {
                for (int i = 0; i <= maxstack; i++){
                    if (numbers.top(p) == success) {
                        numbers.pop();
                        q += p;
                    } 
                    else {
                        q /= i;
                        numbers.push(q);
                        break;
                    }
                }
            } break;
        case 'q': cout << "Calculation finished.\n"; return false;
    }
    return true; 
}