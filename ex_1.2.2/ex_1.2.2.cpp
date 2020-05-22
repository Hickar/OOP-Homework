#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

/* Создать объект, который обрабатывает массив целых чисел не более 10 элементов.
 * Количество элементов определяется в момент конструирования объекта.
 * Объект обладает следующей функциональностью:
 *  – считывает элементы массива;
 *  – выводит элементы массива;
 *  – разворачивает последовательность элементов массива;
 * Написать программу, которая:
 *  1. Создаёт объект и в конструкторе считывает количество элементов массива;
 *  2. Считывает элементы массива;
 *  3. Выводит значения элементов массива согласно исходной последовательности;
 *  4. Разворачивает элементы массива;
 *  5. Выводит значения элементов массива согласно их новому порядку.
 *
 *  Входные данные:
 *      Первая строка: целое число в десятичном формате.
 *      Вторая строка: последовательность целых чисел в десятичном формате,
 *      разделённых пробелом.
 *
 *  Выходные данные:
 *      Первая строка: N = количество элементов.
 *      Вторая строка (исходный порядок следования элементов):
 *      целочисленные значения элементов массива, каждое значение занимает 5 позиций.
 *      Третья строка (обратный порядок следования элементов):
 *      целочисленные значения элементов массива, каждое значение занимает 5 позиций.
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

class ArrayReversingObject {
public:
    ArrayReversingObject() {
        std::string input;
        getline(std::cin, input);
        arraySize = stoi(input);

        getline(std::cin, input);
        array = split(input, arraySize, ' ');

        printArray();
        reverseArray();
        printArray();
    }

    void reverseArray() {
        int temp,
            start = 0,
            end = arraySize - 1;
        while (start < end) {
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }

private:
    int* array;
    int arraySize;

    void printArray() {
        for (int i = 0; i < arraySize; i++) {
            std::cout << std::setw(5) << array[i];
        }
    }
};

int main() {
    try {
        ArrayReversingObject arrayReverser;
    } catch (const std::string *msg) {
        std::cerr << msg;
    }
}