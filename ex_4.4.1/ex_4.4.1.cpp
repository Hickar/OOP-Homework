#include <iostream>
#include <string>
#include <sstream>

/*
    Создать базовый класс, содержащий метод наименованием in_out без параметров. Метод организует ввод исходных данных:
    размерности целочисленного массива и значений элементов целочисленного массива.

    На базе базового класса создать производный класс 1 содержащий метод целого типа наименованием func.
    Метод от значения первого элемента целочисленного массива последовательно вычитает значения остальных элементов.
    Полученный результат возвращает.

    На базе класса 1 создать производный класс 2 содержащий метод целого типа наименованием func. Метод суммирует
    элементы целочисленного массива. Полученный результат возвращает.

    На базе класса 2 создать производный класс 3 содержащий метод наименованием in_out баз параметров
    для вывода исходных данных и вычисленных значений.

    В основной программе использовать один указатель на объект класса и один объект.

    В основной программе реализовать алгоритм:
    1. Объявить указатель на объект класса.
    2. Создать объект оператором new.
    3. Ввод исходных данных: размерности целочисленного массива и значений элементов данного массива.
    4. Вычисление значение вычитания от первого элемента массива всех остальных.
    5. Вычисление суммы элементов массива.
    6. Вывод полученных результатов.

    Входные данные
        Первая строка:
            размерность целочисленного массива
            (Размерность массива натуральное число больше или равно 1 и меньше или равно 100).
        Вторая строка:
            последовательность целых чисел
            (Количество целых чисел равно размерности массива и разделены пробелами.
            Значение каждого числа принадлежит интервалу [-100, 100]).

    Выходные данные
        Первая строка:
            Array dimension: размерность целочисленного массива
        Вторая строка:
            The original array:последовательность целых чисел
            (Для вывода каждого числа выделяется поле из 5 позиции).
        Третья строка:
            Min: значение вычитания из первого элемента массива всех остальных
        Четвертая строка:
            Sum: значение суммы элементов массив
 */

int* split(const std::string &str, int arraySize, const char delimiter) {
    int* tokens = new int[arraySize];
    int currentIndex = 0;
    std::string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        if (stoi(token) < -100 || stoi(token) > 100) {
            throw "Числа должны быть в интервале от -100 до 100";
        }
        tokens[currentIndex] = stoi(token);
        currentIndex++;
    }
    if (currentIndex != arraySize) {
        throw "Не совпадает ранее указанный размер массива с его фактическим";
    }
    return tokens;
}

int digitsCount(int num) {
    int digitsCount = 0;
    while (true) {
        num /= 10;
        digitsCount++;
        if (num == 0) break;
    }
    return digitsCount;
}

void printArray(int* array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        int spacesCount = 5 - digitsCount(array[i]);
        printf("%i", array[i]);
        for (int i = 0; i < spacesCount; i++) {
            printf(" ");
        }
    }
    printf("\n");
}

class Base {
public:
    void in_out() {
        std::string input;
        getline(std::cin, input);
        arraySize = stoi(input);

        getline(std::cin, input);
        array = split(input, arraySize, ' ');
        printArray(array, arraySize);
    }

    int* array;
    int arraySize;
};

class SubClassOne : public Base {
public:
    int func(int* array, int arraySize) {
        int result = array[0];
        for (int i = 1; i < arraySize; i++) {
            result -= array[i];
        }
        return result;
    }
};

class SubClassTwo : public SubClassOne {
public:
    int func(int* array, int arraySize) {
        int result = 0;
        for (int i = 0; i < arraySize; i++) {
            result += array[i];
        }
        return result;
    }
};

class SubClassThree : public SubClassTwo {
public:
    void in_out() {
        Base::in_out();
        printf("Min: %i\n", SubClassOne::func(array, arraySize));
        printf("Sum: %i\n", SubClassTwo::func(array, arraySize));
    }
};

int main() {
    try {
        auto someObject = new SubClassThree();
        someObject->in_out();
        delete someObject;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
}


