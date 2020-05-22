#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

/*
    Создать базовый класс, содержащий только свойства. На его базе создать производный класс 1 и производный класс 2,
    содержащие только методы. В первом производном классе реализовать метод ввода размерности целочисленного массива.
    Во втором классе реализовать метод упорядочения целочисленного массива по неубыванию и метод вывода массива.

    Посредством множественного наследования классов 1 и 2 создать класс 3. В классе 3 реализовать метод с алгоритмом:
    1. Вызов метода ввода целочисленного массива.
    2. Вызов метода вывода массива.
    3. Вызов метода упорядочения целочисленного массива.
    4. Вызов метода вывода массива.

    Входные данные
    Первая строка:
        размерность целочисленного массива
        (Размерность массива натуральное число больше или равно 1 и меньше или равно 100).
    Вторая строка:
        последовательность целых чисел
    (Количество целых чисел равно размерности массива и разделены пробелами,
    значение каждого числа принадлежит интервалу [-100, 100]).

    Выходные данные
        Первая строка:
            Array dimension: размерность целочисленного массива
        Вторая строка:
            The original array:последовательность целых чисел
            (Для вывода каждого числа выделяется поле из 5 позиции).
        Третья строка:
            An ordered array:последовательность целых чисел
            (Для вывода каждого числа выделяется поле из 5 позиции).
 */

int* split(const std::string &str, int arraySize, const char delimiter) {
    int* tokens = new int[arraySize];
    int partIndex = 0;
    std::string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        tokens[partIndex] = stoi(token);
        if (tokens[partIndex] < -100 || tokens[partIndex] > 100) {
            throw "Числа в элементах массива должны быть в пределах от -100 до 100";
        }
        partIndex++;
    }
    if (partIndex != arraySize) {
        throw "Не совпадает ранее указанный размер массива с его фактическим";
    }
    return tokens;
}

class BaseClass {
public:
    int* array;
    int arraySize;
};

class SubClassOne : public BaseClass {
public:
    void createArray() {
        std::string input;
        getline(std::cin, input);
        arraySize = stoi(input);

        getline(std::cin, input);
        array = split(input, arraySize, ' ');
    }
};

class SubClassTwo : public BaseClass {
public:
    int partition (int *array, int low, int high) {
        long int pivot = array[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (array[j] <= pivot) {
                i++;
                std::swap(array[i], array[j]);
            }
        }
        std::swap(array[i + 1], array[high]);
        return (i + 1);
    }

    void quickSortArray(int *array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSortArray(array, low, pi - 1);
            quickSortArray(array, pi + 1, high);
        }
    }

    void printArray(int* array, int arraySize) {
        for (int i = 0; i < arraySize; i++) {
            std::cout << std::setw(5) << array[i];
        }
    }
};

class SubClassThree : public SubClassOne, public SubClassTwo {
public:
    SubClassThree() {
        SubClassOne::createArray();
        std::cout << "Array dimension: " << SubClassOne::arraySize << std::endl;
        std::cout << "The original array: ";
        SubClassTwo::printArray(SubClassOne::array, SubClassOne::arraySize);

        SubClassTwo::quickSortArray(SubClassOne::array, 0, SubClassOne::arraySize - 1);

        std::cout << "An ordered array: ";
        SubClassTwo::printArray(SubClassOne::array, SubClassOne::arraySize);
    };
    ~SubClassThree() = default;
};

int main() {
    try {
        auto arrayCreator = new SubClassThree();
        delete arrayCreator;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
}
