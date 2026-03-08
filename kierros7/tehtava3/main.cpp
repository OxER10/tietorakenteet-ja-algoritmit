#include <iostream>
#include <string>

// Simple singly-linked node
struct Node {
    int   data;
    Node* next;
};

// Helper to print a node's address and contents
void printNode(const std::string& label, const Node* n) {
    std::cout << label << " @ " << n;
    if (!n) {
        std::cout << " (null)\n";
        return;
    }
    std::cout << " { data=" << n->data << ", next=" << n->next << " }\n";
}

// p0 -> [0] -> [1] -> null
// p1 -> [1]
void A() {
    std::cout << "\n(a)\n";

    Node* n0 = new Node{0, nullptr};
    Node* n1 = new Node{1, nullptr};

    Node* p0 = n0;
    n0->next = n1;
    Node* p1 = n1;

    printNode("p0", p0);
    printNode("p1", p1);
    printNode("node0", n0);
    printNode("node1", n1);

    delete n1;
    delete n0;
}

// p0 -> [0] -> null
// p1 -> [1]
// p2 -> [1]
// [1].next -> [0]
void B() {
    std::cout << "\n(b)\n";

    Node* n0 = new Node{0, nullptr};
    Node* n1 = new Node{1, nullptr};

    Node* p0 = n0;
    Node* p1 = n1;
    Node* p2 = n1;

    n0->next = nullptr;
    n1->next = n0;

    printNode("p0", p0);
    printNode("p1", p1);
    printNode("p2", p2);
    printNode("node0", n0);
    printNode("node1", n1);

    delete n1;
    delete n0;
}

// p0 -> [0] -> [1] -> [2]
// p1 -> [1]
// p2 -> [2]
// [2].next -> [1]   (cycle between 1 and 2)
void C() {
    std::cout << "\n(c)\n";

    Node* n0 = new Node{0, nullptr};
    Node* n1 = new Node{1, nullptr};
    Node* n2 = new Node{2, nullptr};

    Node* p0 = n0;
    Node* p1 = n1;
    Node* p2 = n2;

    n0->next = n1;
    n1->next = n2;
    n2->next = n1;

    printNode("p0", p0);
    printNode("p1", p1);
    printNode("p2", p2);
    printNode("node0", n0);
    printNode("node1", n1);
    printNode("node2", n2);

    n2->next = nullptr;
    delete n2;
    delete n1;
    delete n0;
}

int main() {
    A();
    B();
    C();
    return 0;
}