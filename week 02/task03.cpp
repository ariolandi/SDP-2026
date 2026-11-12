#include <iostream>
#include <queue>
#include <stack>
#include <string>

template <typename T>
void reverse(std::queue<T>& q) {
    std::stack<T> s;

    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// ---------------------------------------

void getTask(std::queue<int>& tasks) {
    if (tasks.empty()) {
        std::cout << "No job for Anya!" << std::endl;
        return;
    }

    std::cout << tasks.front() << std::endl;
    tasks.pop();
}


int main() {
    std::queue<int> tasks;
    std::string command;

    size_t n;
    int x;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> command;

        if (command == "add") {
            std::cin >> x;
            tasks.push(x);
        } else if (command == "front") {
            getTask(tasks);
        } else if (command == "back") {
            reverse(tasks);
            getTask(tasks);
            reverse(tasks);
        } else if (command == "reverse") {
            reverse(tasks);
        } else {
            std::cout << "Invalid!" << std::endl;
        }
    }


    return 0;
}