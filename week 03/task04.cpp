#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};


template <typename T>
void push(Node<T>*& top, const T& value) {
    Node<T>* newElement = new Node<T>{value, top};

    top = newElement;
}

template <typename T>
void pop(Node<T>*& top) {
    if (top == nullptr) return;
    
    Node<T>* toBeDeleted = top;
    top = top->next;
    delete toBeDeleted;
}


// ---

void splitBy(const std::string& str, const char delimiter, std::vector<std::string>& parts) {
    const size_t size = str.length();
    std::string partition = "";
    bool inPart = false;

    for(size_t i = 0; i < size; ++i) {
        if (str[i] != delimiter) {
            if (!inPart) {
                inPart = true;
                partition = "";
            } 

            partition += str[i];
        } else {
            if (inPart) {
                parts.push_back(partition);
            }
            inPart = false;
        }
    }

    parts.push_back(partition);
}

bool isOperator(const std::string& x) {
    return x == "+" || x == "-" || x == "*" || x == "/";
}

int toNumber(const std::string& str) {
    int n = 0;
    const size_t size = str.length();

    for(size_t i = 0; i < size; ++i) {
        n *= 10;
        n += str[i] - '0';
    }

    return n;
}

void calculate(Node<int>*& numbers, Node<std::string>*& operators) {
        while(operators) {
        std::string op = operators->value;
        pop(operators);

        int y = numbers->value; 
        pop(numbers);
        int x = numbers->value;
        pop(numbers);

        std::cout << "x: " << x << " y: " << y << " " << op << std::endl;


        if(op == "+") {
            x += y;
        } else if (op == "-") {
            x -= y;
        } else if (op == "*") {
            x *= y;
        } else if (op == "/") {
            x /= y;
        }


        push(numbers, x);
    }
}

int main() {
    std::string input;

    // char* -> std::cin.getline(input)
    std::getline(std::cin, input);

    std::cout << input << std::endl;

    std::vector<std::string> parts; 
    splitBy(input, ' ', parts);

    Node<int>* numbers = nullptr;
    Node<std::string>* ops = nullptr;

    for (size_t i = 0; i < parts.size(); ++i) {
        bool isOp = isOperator(parts[i]);
        if (isOp) {
            push(ops, parts[i]);
        } else {
            push(numbers, toNumber(parts[i]));
        }
    }

    calculate(numbers, ops);

    std::cout << numbers->value << std::endl;

    while(numbers) {
        std::cout << numbers->value << std::endl;
        pop(numbers);
    }


    return 0;
}

// 45 2 * 4 - 2 / 3 *