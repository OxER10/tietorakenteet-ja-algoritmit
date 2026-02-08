#include <stack>
#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n < 0) n = -n;
    if (n < 2) return 0;

    stack<long long> factors;

    while (n % 2 == 0) {
        factors.push(2);
        n /= 2;
    }

    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factors.push(d);
            n /= d;
        }
    }

    if (n > 1) factors.push(n);

    while (!factors.empty()) {
        cout << factors.top() << " ";
        factors.pop();
    }
}