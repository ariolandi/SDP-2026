#include <iostream>
#include <list>

template <typename T>
std::list<std::list<T>> chunk(const std::list<T>& l, const size_t& k) {
    std::list<std::list<T>> chunked;

    typename std::list<T>::const_iterator it = l.begin();
    while(it != l.end()) {
        std::list<T> c;
        for (size_t j = 0; j < k && it != l.end(); ++j, ++it) {
            c.push_back(*it);
        }

        chunked.push_back(c);
    }

    return chunked;
}

int main() {
    std::list<double> l =  {1, 3, 5, 234, 2.6, 3, 3, 985, -45, 3, 5.01};
    std::list<std::list<double>> chunks = chunk(l, 4);

    std::list<std::list<double>>::iterator i;
    for (i = chunks.begin(); i != chunks.end(); ++i) {
        std::list<double>::iterator j;
        for (j = i->begin(); j != i->end(); ++j) {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
