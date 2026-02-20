#include <iostream>
#include <queue>
#include <stack>

// FIFO gain = 1000
// LIFO gain = -3000
// FIFO is better in this scenario

int main() {
    std::queue<int> fifo;
    std::stack<int> lifo;

    auto buy = [&](int price) {
        for (int i = 0; i < 100; i++) {
            fifo.push(price);
            lifo.push(price);
        }
    };

    auto sell_fifo = [&](int sell_price) {
        int gain = 0;
        for (int i = 0; i < 100; i++) {
            int cost = fifo.front();
            fifo.pop();
            gain += sell_price - cost;
        }
        return gain;
    };

    auto sell_lifo = [&](int sell_price) {
        int gain = 0;
        for (int i = 0; i < 100; i++) {
            int cost = lifo.top();
            lifo.pop();
            gain += sell_price - cost;
        }
        return gain;
    };

    buy(10);
    buy(30);
    buy(50);

    int fifo_gain = 0;
    int lifo_gain = 0;

    fifo_gain += sell_fifo(20);
    lifo_gain += sell_lifo(20);

    fifo_gain += sell_fifo(30);
    lifo_gain += sell_lifo(30);

    std::cout << "FIFO gain = " << fifo_gain << std::endl;
    std::cout << "LIFO gain = " << lifo_gain << std::endl;
}