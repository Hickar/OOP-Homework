#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

/*
    Иерархия наследования

    Описать четыре класса которые последовательно наследуют друг друга, последовательными номерами классов 1,2,3,4.
    Реализовать программу, в которой использовать единственный указатель на объект базового класса (номер класса 1).
    Наследственность реализовать так, что можно было вызвать методы, принадлежащие объекту конкретного класса,
    только через объект данного класса.

    В закрытом разделе каждого класса определены два свойства: строкового типа для наименования объекта и
    целого типа для значения определенного целочисленного выражения.

    Описание каждого класса содержит один параметризированный конструктор с строковым и целочисленным параметром.
    В реализации каждого конструктора объекта определяются значения защищенных свойств:
    -наименование объекта по шаблону: «значение строкового параметра»_«номер класса»;
    -целочисленного свойства значением выражения возведения в степень номера класса целочисленного
    значения параметра конструктора.

    Еще в описании каждого класса определен метод с одинаковым наименованием для всех классов,
    реализующий вывод значений закрытых свойств класса.

    В основной функции реализовать алгоритм:
    1. Вводится идентификатор и натуральное число от 2 до 10.
    2. Создать объект класса 1, используя параметризированный конструктор, которому в качестве аргументов передаются
    введенный идентификатор и натуральное число.
    3. Построчно, для всех объектов согласно наследственности, от объекта базового (класс 1) до
    производного объекта (класса 4) вывести наименование объекта класса и значение целочисленного свойства.

    Входные данные
        Первая строка:
            идентификатор натуральное число

    Выходные данные
        Построчно (четыре строки):
            идентификатор_номер класса значение целочисленного свойства
 */

std::string* split(const std::string &str, int arraySize, const char delimiter) {
    std::string* tokens = new std::string[arraySize];
    int partIndex = 0;
    std::string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        tokens[partIndex] = token;
        partIndex++;
    }
    return tokens;
}

class ClassOne {
public:
    int classNumber = 1;

    ClassOne(std::string name = " ", int number = 0) :name(name), number(number) {
        if (number < 2 || number > 10) throw "Число должно быть в пределах от 2 до 10";
        printPropertiesValues();
    }

    void printPropertiesValues() {
        std::cout << this->name << "_" + std::to_string(classNumber) << " " << pow(number, classNumber) << std::endl;
    }

protected:
    std::string name;
    int number;
};

class ClassTwo : protected ClassOne {
public:
    int classNumber = 2;

    ClassTwo(std::string name = " ", int number = 0) : ClassOne(name, number) {
        printPropertiesValues();
    }

    void printPropertiesValues() {
        std::cout << ClassOne::name << "_" + std::to_string(classNumber) << " " << pow(number, classNumber) << std::endl;
    }
};

class ClassThree : protected ClassTwo {
public:
    int classNumber = 3;

    ClassThree(std::string name, const int number) : ClassTwo(name, number) {
        printPropertiesValues();
    };

    void printPropertiesValues() {
        std::cout << this->name << "_" + std::to_string(classNumber) << " " << pow(number, classNumber) << std::endl;
    }
};

class ClassFour : protected ClassThree {
public:
    int classNumber = 4;

    ClassFour(std::string name = "", const int number = 0) : ClassThree(name, number) {
        printPropertiesValues();
    };

    void printPropertiesValues() {
        std::cout << this->name << "_" + std::to_string(classNumber) << " " << pow(number, classNumber) << std::endl;
    }
};

int main() {
    try {
        std::string input;
        getline(std::cin, input);
        std::string* arguments = split(input, 2, ' ');

        ClassFour objectFour(arguments[0], stoi(arguments[1]));
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
}
