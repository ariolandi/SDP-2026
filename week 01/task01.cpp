#include <iostream>
#include <stack>
#include <string>

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


// решение на задача 1 

const char opening1 = '(';
const char opening2 = '{';
const char opening3 = '[';

const char closing1 = ')';
const char closing2 = '}';
const char closing3 = ']';

bool isOpening(const char c) {
    return c == opening1 || c == opening2 || c == opening3;
}

bool isClosing(const char c) {
    return c == closing1 || c == closing2 || c == closing3;
}

bool arePair(const char opening, const char closing) {
    return (opening == opening1 && closing == closing1) || 
            (opening == opening2 && closing == closing2) ||
            (opening == opening3 && closing == closing3);
}


bool isBalanced(std::stack<char> brackets) {
    std::stack<char> closingBrackets;

    while(!brackets.empty()) {
        char bracket = brackets.top();
        brackets.pop();

        // при срещната затваряща скоба, тя се записва
        if(isClosing(bracket)) {
            closingBrackets.push(bracket);
        } else if(isOpening(bracket)) {
            // ако няма срещнати неотворени затварящи скоби, то няма как поредицата да е балансирана
            if (closingBrackets.empty()) return false;

            char closingBracket = closingBrackets.top();
            closingBrackets.pop();
            if (!arePair(bracket, closingBracket)) return false;
        } else {
            // в поредицата се съдържа невалиден символ
            std::cout << "Invalid symbol - not a bracket!" << std::endl;
            return false;
        }
    }

    return closingBrackets.empty();
}

int main() {
    std::stack<char> brackets;
    std::string str;
    
    std::cin >> str;

    for (size_t i = 0; i < str.length(); ++i) {
        brackets.push(str[i]);
    }

    std::cout << isBalanced(brackets) << std::endl;

    return 0;
}