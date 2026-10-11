#include <iostream>
#include <stack>

// въвеждане на N на брой елемента в стека
template <typename T>
void input(size_t& n, std::stack<T>& s) {
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        T value;
        std::cin >> value;
        s.push(value);
    }
}

// печата стека от върха към дъното без да го разрушава
// това се постига чрез подаване на копие
template <typename T>
void print(std::stack<T> s) {
    while(!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    std::cout << std::endl;
}

// обръщкане на поредността на елементите в стека
template <typename T>
void reverse(std::stack<T>& s) {
    std::stack<T> tmp;

    while(!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }

    s = tmp;
}


// решение на задача 2 
bool killFlowers(std::stack<int>& flowers) {
    if(flowers.empty()) {
        return false;
    }

    bool hasDeadFlowers = false;
    std::stack<int> aliveFlowers;

    int currentFlower = flowers.top();
    flowers.pop();

    while(!flowers.empty()) {
        int nextFlower = flowers.top();

        if (currentFlower > nextFlower) {
            hasDeadFlowers = true;
        } else {
            aliveFlowers.push(currentFlower);
        }

        flowers.pop();
        currentFlower = nextFlower;
    }
    aliveFlowers.push(currentFlower);

    // print(aliveFlowers)
    reverse(aliveFlowers);
    flowers = aliveFlowers;

    return hasDeadFlowers;
}

int main() {
    std::stack<int> s;
    size_t n;

    // std::cout << "Empty? " << s.empty() << std::endl;
    // std::cout << s.top() << std::endl;


    input(n, s);

    // std::cout << "Empty? " << s.empty() << std::endl;
    // std::cout << s.top() << std::endl;

    // print(s);
    // reverse(s);
    // print(s);

    bool hasDeadFlowers = killFlowers(s);
    int days = 0;

    while(hasDeadFlowers) {
        hasDeadFlowers = killFlowers(s);
        days++;
    }

    print(s);
    std::cout << "Days: " << days << std::endl;
    
    return 0;
}