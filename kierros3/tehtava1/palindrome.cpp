#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main() 
/*  Pre: The user supplies an integer n and n decimal numbers.
    Post: The numbers are printed in reverse order.
    Uses: The STL class stack and its methods */
{
    string item, reversed;
    stack<char> character; // declares and initializes a stack of characters
    cout << "Type a line"
    << endl
    << "The characters will be printed in reverse order."
    << endl;
    getline(cin, item);
    for (char c : item) {
        character.push(c);
    }
    cout << endl;
    while (!character.empty()) {
        reversed.push_back(character.top());
        character.pop();
    }
    cout << reversed << endl;
    if (item == reversed) {
        cout << "Line IS a palindrome." << endl;
    } else {
        cout << "Line is NOT a palindrome." << endl;
    }
    cout << endl;
    return 0;
}