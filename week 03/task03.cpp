#include <iostream>
#include <queue>
#include <stack>

int main() {
    size_t n;
    int x, y;
    std::queue<int> q;
    std::stack<int> s;
    bool canBeStack = true, canBeQeueue = true;

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> x >> y;

        if (x == 1) {
            q.push(y);
            s.push(y);
        } else if (x == 2 && !q.empty() && !s.empty()) {
            int qy = q.front();
            q.pop();
            int sy = s.top();
            s.pop();

            if (qy != y) {
                canBeQeueue = false;
            }
            if (sy != y) {
                canBeStack = false;
            }
        } 
    }

    if (canBeStack && canBeQeueue) {
        std::cout << "both" << std::endl;
    } else if (canBeStack) {
        std::cout << "stack" << std::endl;
    } else if (canBeQeueue) {
        std::cout << "queue" << std::endl;
    } else std::cout << "nothing" << std::endl;

    return 0;
}