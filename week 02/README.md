## Опашка

#### Дефиниция

Линейна структура от данни, следваща принципа FIFO (First In - Fist out). Характерно е наличието на пряк достъп единствено до началото (главата) на опашката (head). Всеки новодобавен елемент се добавя в края на опашката (tail). 

```
q = <| x | y | z |<
```

#### Основни операции

- Добавяне на елемент в края на опашката (push)
```
q = <| x | y | z |<   --q.push(w)--> q = <| x | y | z | w |<
```

- Премахване на елемент от началото на опашката (pop)
```
q = <| x | y | z |<   --q.pop()-->   q = <| y | z |<
```

- Достъпване на елемента в нчалото на опашката (front)
```
q = <| x | y | z |<   --q.front()-->  x
```

- Проверка дали опашката е празна (empty)
```
q = <| x | y | z |<   --q.empty()-->  false

p = <|<               --p.empty()-->  true
```

#### STL::queue

```c++
#inlude<iostream>
#include<queue>

int main() {
    std::queue<int> exampleQueue;

    std::cout << exampleQueue.empty() << std::endl;

    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        exampleQueue.push(x);
    }

    std::cout << exampleQueue.empty() << std::endl;
    std::cout << exampleQueue.front() << std::endl;

    exampleQueue.pop();

    std::cout << exampleQueue.front() << std::endl;

    return 0;
}

```

