#include <iostream>
#include <string>
#include <sstream>

/*
    Создать объект первого типа, у которого одно целочисленное свойство.
    Значение данного свойства определяется посредством
    параметризированного конструктора. Создать объект второго типа,
    у которого две целочисленные свойства. Значение данных свойств определяется
    посредством метода объекта. Реализовать дружественную функцию,
    которая находит максимальное значение полей объекта первого типа и полей объекта второго типа.

    Написать программу:
    1. Вводит значение для поля объекта первого типа.
    2. Создает объект первого типа.
    3. Вводит значения полей для полей объекта второго типа.
    4. Создает объект второго типа.
    5. Определяет значения полей объекта второго типа.
    6. Определяет максимальное значение полей, созданных двух объектов разного типа посредством дружественной функции.
    7. Выводит полученный результат.

    Входные данные
        Первая строка:
            целое число в десятичном формате
        Вторая строка:
            целое число в десятичном формате˽целое число в десятичном формате

    Выходные данные
        Первая строка, с первой позиции:
            max = целочисленное значение в десятеричном формате
 */

bool isNumber(std::string &str) {
    bool isNumber = true;
    try {
        stoi(str);
    } catch (std::exception &e) {
        isNumber = false;
        throw std::string("Это не число: " + str);
    }
    return isNumber;
}

int* split(const std::string &str, int arraySize, const char delimiter) {
    int* tokens = new int[arraySize];
    int partIndex = 0;
    std::string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        if (isNumber(token)) {
            tokens[partIndex] = stoi(token);
            partIndex++;
        }
    }
    if (partIndex != arraySize) {
        throw std::string("Не совпадает ранее указанный размер массива с его фактическим");
    }
    return tokens;
}

class TypeOne;
class TypeTwo;

class TypeOne {
public:
    TypeOne(){};
    void setNumber(int num) {
        number = num;
    }

    friend void compareNumbersOfTwoObjects(TypeOne fObject, TypeTwo sObj);

private:
    int number;
};

class TypeTwo {
public:
    TypeTwo(){};

    void setNumbers(std::string &input) {
        int* numbers = new int[2];
        numbers = split(input, 2, ' ');
        this->fNumber = numbers[0];
        this->sNumber = numbers[1];
    }

    friend void compareNumbersOfTwoObjects(TypeOne fObject, TypeTwo sObj);

private:
    int fNumber, sNumber;
};


int max(int numbers[], int arraySize) {
    int maxNumber = numbers[0];
    for (int i = 0; i < arraySize; i++) {
        if (numbers[i] > maxNumber) {
            maxNumber = numbers[i];
        }
    }
    return maxNumber;
}

void compareNumbersOfTwoObjects(TypeOne fObject, TypeTwo sObject) {
    int numsArray[3];
    numsArray[0] = fObject.number;
    numsArray[1] = sObject.fNumber;
    numsArray[2] = sObject.sNumber;
    std::cout << "max = " << max(numsArray, 3);
}

int main() {
    std::string input;
    TypeOne firstObject;
    TypeTwo secondObject;

    getline(std::cin, input);
    if (isNumber(input)) {
        firstObject.setNumber(stoi(input));
    }

    getline(std::cin, input);
    secondObject.setNumbers(input);

    compareNumbersOfTwoObjects(firstObject, secondObject);

    return 0;
}
