## STL String

#### Дефиниция

Последователна хомогенна структура от данни, дефинираща низ с променлива дължина. 

- библиотека string
- std::string


#### Основни операции
- присвояване
```c++
std::string str = "abba";
```
- сравнение
```c++
str1 == str2
```
- въвеждане
```c++
std::cin >> str;
getline(cin, str);
getline(cin, str, delimiter);
```
- размер
```c++
str.size();
str.lenght();
```
- замяна на символи
```c++
str.replace(position, n, otherStr); // заменя N символа, започвайки от позиция position, с otherStr
str.replace(position, n, otherStr, m); // заменя N символа, започвайки от позиция position, с първите M символа от otherStr
```
- подниз
```c++
str.substr(position); // връща подниза, започващ от position
str.substr(position, n); // връща първите N символа от подниза, започващ от position
```
- търсене
```c++
str.find(substr); // връща позицията на първото срещане на substr
```