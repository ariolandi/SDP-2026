#include <iostream>
#include <list>
#include <queue>

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


template <typename T>
void BFS(const Tree<T>& root) {
    Tree<T> node = root;
    std::queue<Tree<T>> q;
    q.push(node);

    while(!q.empty()) {
        node = q.front();
        q.pop();

        std::cout << node.value << std::endl;

        typename std::list<Tree<T>>::iterator it;
        for (it = node.children.begin(); it != node.children.end(); ++it) {
            q.push(*it);
        }
    }
}

template <typename T>
void DFS(const Tree<T>& root) {
    std::cout << root.value << std::endl;

    typename std::list<Tree<T>>::const_iterator it;
    for (it = root.children.begin(); it != root.children.end(); ++it) {
        DFS(*it);
    }
}

int main() {
    Tree<int> t2(6);
    t2.addChild(9);

    Tree<int> t4(2);
    t4.addChild(t2);
    t4.addChild(7);

    Tree<int> t8(13);
    t8.addChild(14);
    t8.addChild(15);

    Tree<int> t10(11);
    t10.addChild(t8);
    
    Tree<int> t12(8);
    t12.addChild(10);
    t12.addChild(t10);
    t12.addChild(12);

    Tree<int> t13(4);
    t13.addChild(t12);

    Tree<int> t15(1);
    t15.addChild(t4);
    t15.addChild(3);
    t15.addChild(t13);
    t15.addChild(5);

    BFS(t15);

    return 0;
}
