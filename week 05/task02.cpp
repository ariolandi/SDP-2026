#include <iostream>

template <typename T>
struct Node{
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value): value(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
void clear(Node<T>*& l) {
    while (l != nullptr) {
        Node<T>* next = l->next;
        delete l;
        l = next;
    }
}

template <typename T>
void push_back(const T& value, Node<T>*& l) {
    Node<T>* new_element = new Node<T>(value);

    if (l == nullptr) {
        l = new_element;
        return;
    }

    Node<T>* current = l;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_element;
    new_element->prev = current;
}

template <typename T>
void erase(Node<T>*& l) {
    if (l == nullptr) {
        return;
    }

    if (l->prev == nullptr) {
        Node<T>* next = l->next;
        next->prev = nullptr;
        delete l;
        l = next;
        return;
    }

    if (l->next == nullptr) {
        Node<T>* prev = l->prev;
        prev->next = nullptr;
        delete l;
        l = prev;
        return;
    }

    Node<T>* next = l->next;
    Node<T>* prev = l->prev;
    next->prev = prev;
    prev->next = next;
    delete l;
    l = next;
}

// -------

void dryPlants(Node<std::pair<size_t, int>>*& plants) {
    Node<std::pair<size_t, int>>* current = plants;
    while (current != nullptr) {
        current->value.second++;
        current = current->next;
    }
}

void waterPlant(const size_t& position, Node<std::pair<size_t, int>>*& plants) {
    Node<std::pair<size_t, int>>* current = plants;
    while (current != nullptr) {
        if(current->value.first == position) {
            current->value.second = 0;
        }
        current = current->next;
    }
}

void removePlants(Node<std::pair<size_t, int>>*& plants, const int& dryness) {
    Node<std::pair<size_t, int>>* current = plants;
    while (current != nullptr) {
        if(current->value.second == dryness) {
            erase(current);
        } else {
            current = current->next;
        }
        
    }
}

void print(Node<std::pair<size_t, int>>* plants) {
    Node<std::pair<size_t, int>>* current = plants;
    while (current != nullptr) {
        current = current->next;
    }
}

size_t size(Node<std::pair<size_t, int>>* plants) {
Node<std::pair<size_t, int>>* it = plants;
    size_t n = 0;
    while(it != nullptr) {
        n++;
        it = it->next;
    }

    return n;
}


int main() {
    Node<std::pair<size_t, int>>* l = nullptr;
    size_t n, m;
    std::cin >> n >> m;
    for (size_t i = 0; i < n; ++i) {
        std::pair<size_t, int> p(i+1, 0);
        push_back(p, l);
    }

    // each day
    for (size_t j = 0; j < m; ++j) {
        dryPlants(l);
        print(l);

        // watering
        size_t drops;
        std::cin >> drops;
        for (size_t i = 0; i < drops; ++i) {
            size_t x;
            std::cin >> x;

            waterPlant(x, l);
        }

        removePlants(l, 3);
        std::cout << "Current size: " << size(l) << std::endl;
    }
    
    

    std::cout << size(l) << std::endl;

    clear(l);

    return 0;
}