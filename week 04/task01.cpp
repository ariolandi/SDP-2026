#include <iostream>
#include <forward_list>

template <typename T>
void reverse(std::forward_list<T>& list) {
    std::forward_list<T> reversed;

    while(!list.empty()){
        reversed.push_front(list.front());
        list.pop_front();
    }

    list = reversed;
}

// ---------------------------------

std::forward_list<int>::iterator position(std::forward_list<int>& list, size_t pos) {
    std::forward_list<int>::iterator it = list.begin();
    
    for (size_t i = 0; i < pos; ++i) {
        ++it;
        if (it == list.end()) {
            it = list.begin();
        }
    }

    return it;
}

void move(std::forward_list<int>& list, std::forward_list<int>::iterator& it, size_t pos) {
    if (it == list.end()) {
        it = list.begin();
        pos --;
    }
    
    for (size_t i = 0; i < pos; ++i) {
        ++it;
        if (it == list.end()) {
            it = list.begin();
        }
    }
}

void erase(std::forward_list<int>& list, std::forward_list<int>::iterator& it) {
    if (it == list.begin()) {
        list.pop_front();
        it = list.end();
    } else {
        std::forward_list<int>::iterator p = list.begin();
        while (std::next(p) != it) {
            ++p;
        }
        list.erase_after(p);
        it = p;
    }
}

int main() {
    std::forward_list<int> knights;
    size_t n;
    int k;
    std::cin >> n;
    int firstKnight = (((n % 2) * 4 + 8) / 2) % n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> k;
        knights.push_front(k);
    }

    reverse(knights);

    std::forward_list<int>::iterator it = position(knights, firstKnight);
    int steps = *it;

    do {
        move(knights, it, steps);
        steps = *it;
        erase(knights, it);        

    } while(!knights.empty());

    std::cout << steps << std::endl;

    return 0;
}
