#include <iostream>
#include <queue>
#include <stack>

bool find(int x, std::queue<int>& q, std::stack<int>& s) {
    if (!s.empty() && s.top() == x) {
        s.pop();
        return true;
    } 

    while (!q.empty()) {
        int y = q.front();
        q.pop();

        if (y == x) {
            return true;
        }

        s.push(y);
    }

    return false;
}

int main() {
    std::queue<int> q;
    std::stack<int> s;

    size_t n;

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        q.push(x);
    }

    bool possibleToArrange = true;
    for (int i = 1; i <= n && possibleToArrange; ++i) {
        possibleToArrange = find(i, q, s);
    }

    std::cout << (possibleToArrange ? "yes" : "no") << std::endl;

    return 0;
}