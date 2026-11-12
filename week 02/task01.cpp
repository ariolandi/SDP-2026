#include <iostream>
#include <queue>

int main() {
    std::queue<size_t> cards;
    size_t n;
    std::cin >> n;

    for (size_t i = 1; i <= n; ++i) {
        cards.push(i);
    }

    do {
        size_t card = cards.front();
        cards.pop();
        if (cards.empty()) {
            std::cout << std::endl << card << std::endl;
        } else {
            std::cout << card << " ";

            cards.push(cards.front());
            cards.pop();
        }
    }while(!cards.empty());

    return 0;
}