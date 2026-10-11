#include <iostream>
#include <stack>
#include <vector>

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


// решение на задача 3 
void generatePrimes(const size_t p, std::vector<int>& primes) {
    for (size_t i = 2; primes.size() < p; ++i) {
        bool isPrime = true;

        for (size_t j = 0; isPrime && j < primes.size(); ++j) {
            if (i % primes[j] == 0) isPrime = false;
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }
}

void print(std::stack<int> s) {
    while(!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    std::cout << std::endl;
}


void serve(std::stack<int>& c, const int prime) {
    std::stack<int> a, b;

    while (!c.empty()) {
        int plate = c.top();
        c.pop();

        if (plate % prime) {
            a.push(plate);
        } else {
            b.push(plate);
        }
    }

    print(b);
    c = a;
}

int main() {
    std::stack<int> c;
    std::vector<int> primes;
    size_t n, p;

    std::cin >> n >> p;
    generatePrimes(p, primes);
    
    /*
    // Извеждане на генерираните прости числа на екрана
    for (size_t i = 0; i < primes.size(); ++i) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
    */

    for (size_t i = 0; i < n; ++i) {
        int plate;
        std::cin >> plate;
        c.push(plate);
    }

    for (size_t i = 0; i < primes.size(); ++i) {
        serve(c, primes[i]);
    }

    print(c);
    
    return 0;
}