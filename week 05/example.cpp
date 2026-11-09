#include <iostream>
#include <list>

void f(const std::list<int>& l) {
    std::list<int>::const_iterator it;

    for (it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << std::endl;
    }
}


int main() {
    std::list<int> l, l1;

    size_t n = 5;
    for (size_t i = 0; i < n; ++i) {
        l.push_front(i);
    }

    f(l);

    return 0;
}