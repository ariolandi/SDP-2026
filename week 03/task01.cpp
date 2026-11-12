#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::queue<int> output;
    std::stack<int> s1, s2;

    size_t n;
    std::cin >> n;

    for (size_t i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        output.push(x);
        s1.push(i);
    }

    while(!output.empty()) {
        int x = output.front();
        while (!s1.empty() && s1.top() >= x) {
            s2.push(s1.top());
            s1.pop();
            std::cout << 1;
        }

        while(!s2.empty() && s2.top() < x) {
            s1.push(s2.top());
            s2.pop();
            std::cout << 3;
        }

        std::cout << 2;
        output.pop();
    }

    return 0;
}
