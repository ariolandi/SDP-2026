#include <iostream>
#include <list>

template <typename T>
std::list<T> unique(const std::list<T>& l) {
    std::list<T> u;

    typename std::list<T>::const_iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        typename std::list<T>::const_iterator j;
        bool findValue = false;

        for (j = u.begin(); j != u.end() && !findValue; ++j) {
            findValue = *j == *it;
        }

        if (!findValue) {
            u.push_back(*it);
        }
    }

    return u;
}

template <typename T>
std::list<T> flatten(const std::list<std::list<T>>& l) {
    std::list<T> f;

    typename std::list<std::list<T>>::const_iterator it;
    for (it = l.begin(); it != l.end(); ++it) {

        typename std::list<T>::const_iterator j;
        std::list<T> insideL = *it;
        
        for (j = insideL.begin(); j != insideL.end(); ++j) {
            f.push_back(*j);
        }
    }

    return f;
}

template <typename T>
std::list<T> flatten_unique(const std::list<std::list<T>>& l) {
    return unique(flatten(l));
}


int main() {
    std::list<std::list<int>> l = {{1, 3, 1}, {}, {2}, {3, 3, 56, -1}};
    std::list<int> k = flatten_unique(l);

    std::list<int>::iterator it;
    for (it = k.begin(); it != k.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
