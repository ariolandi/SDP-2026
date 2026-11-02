#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
void add(std::queue<int>& q, const size_t& task){
    q.push(task);
}

void front(std::queue<int>& q){
    if(q.empty()){
        std::cout << "No job for Anya!" << std::endl;
    } else {
    std::cout << q.front() << std::endl;
    q.pop();
    }
}

void reverse(std::queue<int>& q){
    std::stack<int> s;
    if(q.empty()){
        return;
    } else {
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }}
}
void back(std::queue<int>& q){
    if(q.empty()){
        std::cout << "No job for Anya!" << std::endl;
    } else {
    reverse(q);
    std::cout << q.front() << std::endl;
    q.pop();
    reverse(q);
    }
}

void input_tasks(std::queue<int>& q, const size_t& n){
    //std::cout << n <<std::endl;
    for(size_t i = 0; i < n; ++i){
        std::string command;
        std::cin >> command;

        if( command == "add"){
            int task;
            std::cin >> task;
            add(q, task);
               // std::cout << "---" <<std::endl;

        } else if(command == "front"){
            front(q);
                            //std::cout << "---" <<std::endl;

        } else if(command == "reverse"){
            reverse(q);
                            //std::cout << "---" <<std::endl;

        } else if(command == "back"){
            back(q);
                            //std::cout << "---" <<std::endl;

        }
    }
}

int main(){
    std::queue<int> q;
    size_t n;
    std::cin >> n;
    input_tasks(q, n);


    //???????
    // 3
    //     add 93

    //     front
    // 93

    // 3
    //     add 93 front back

    // 93
    // No job for Anya!
    return 0;
}
