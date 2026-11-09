#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> l, l1;

    size_t n = 5;
    for (size_t i = 0; i < n; ++i) {
        l.push_front(i);
    }

    std::forward_list<int>::iterator it;

    for (it = l.begin(); it != l1.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}