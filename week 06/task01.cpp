#include <iostream>
#include <list>

template <typename T>
struct Tree {
    T value;
    std::list<Tree<T>> children;

    Tree(const T& value): value(value) {}

    void addChild(const Tree<T>& child) {
        children.push_back(child);
    }

    void addChild(const T& childValue) {
        Tree<T> child(childValue);
        addChild(child);
    }
};

int main() {


    return 0;
}
