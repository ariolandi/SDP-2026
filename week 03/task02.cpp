#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

// помощна структура, съдържаща трите стека
struct Hanoi {
    std::stack<int> source, auxiliary, destination;

    Hanoi() {
        source = std::stack<int>();
        auxiliary = std::stack<int>();
        destination = std::stack<int>();
    }
};

// source -> reception; auxiliary -> cart; destination -> automobile
const int RECEPTION_TO_CART = 1;
const int RECEPTION_TO_AUTO = 2;
const int CART_TO_AUTO = 3;
const int AUTO_TO_CART = 4;
const int AUTO_TO_RECEPTION = 5;
const int CART_TO_RECEPTION = 6;

// реалното преместване и извеждане на кода на действието
void move(std::stack<int>& from, std::stack<int>& to, const int code) {
    int book = from.top();
    from.pop();
    to.push(book);
    std::cout << code << " " << book << std::endl;
}

// преместване между два стека
void moveBetween(std::stack<int>& first, std::stack<int>& second, const int firstToSecond, const int secondToFirst) {
    // ако единият е празен, то преместването се извършва от другия към празния
    if(second.empty()) {
        move(first, second, firstToSecond);
        return;
    }
    if(first.empty()) {
        move(second, first, secondToFirst);
        return;
    }

    // ако никой един от двата не е празен
    // преместването е възможно от по-малък към по-голям елемент
    int x = second.top();
    int y = first.top();
    if (x < y) move(second, first, secondToFirst);
    else move(first, second, firstToSecond);
} 

// редица помощни функции
void receptionToCart(Hanoi& tower) {
    moveBetween(tower.source, tower.auxiliary, RECEPTION_TO_CART, CART_TO_RECEPTION);
}

void receptionToAutomobile(Hanoi& tower) {
    moveBetween(tower.source, tower.destination, RECEPTION_TO_AUTO, AUTO_TO_RECEPTION);
}

void cartToAutomobile(Hanoi& tower) {
    moveBetween(tower.auxiliary, tower.destination, CART_TO_AUTO, AUTO_TO_CART);
}

// решаване на проблема за ханойските кули
void solve(Hanoi& hanoiTowers) {
    // ако елементите са N на брой, то необходимите ходове са точно 2^N - 1
    const int n = hanoiTowers.source.size();
    const int m = std::pow(2, n) - 1;

    // ако броят на елементите е нечетно число, то:
    // - първото преместване е между началния стълб и крайния
    // - второто преместване е между началния стълб и помощния
    // - третото преместване е между помощния стълб и крайния
    // ако броят на елементите е четно число, то помощния и крайния стълб се разменят
    if (n % 2) {
        for (int i = 0; i < m; i += 3) {
            receptionToAutomobile(hanoiTowers);
            receptionToCart(hanoiTowers);
            cartToAutomobile(hanoiTowers);
        }   
    } else {
        for (int i = 0; i < m; i += 3) {
            receptionToCart(hanoiTowers);
            receptionToAutomobile(hanoiTowers);
            cartToAutomobile(hanoiTowers);
        }
    }
}


int main() 
{
    int n;
    Hanoi hanoiTowers;

    std::cin >> n;
    for (int i = n; i > 0; i--) {
        hanoiTowers.source.push(i);
    }

    solve(hanoiTowers);

    return 0;
}