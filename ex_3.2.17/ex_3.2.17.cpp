#include <iostream>
#include <string>

/* Создать объект, который обладает следующей функциональностью:
 *  – В конструкторе вводит количество элементов целочисленного массива;
 *  – В конструкторе создаёт целочисленный массив заданным количеством элементов;
 *  – Конструктор определяет значения элементов массива. Значение каждого элемента
 * равно квадрату индекса элемента
 *  – Выводит значения элементов массива в обратном порядке
 *
 * Необходимые свойства объекта определяются разработчиком.
 * Количество элементов массива принадлежит интервалу от 5 до 20.
 *
 * Написать программу, которая:
 *  1. Создаёт объект посредством оператора "new";
 *  2. Выводит значения элементов массива в обратном порядке;
 *  3. Удаляет объект посредством оператора "delete".
 *
 *  Входные данные:
 *      Первая строка: целое число в десятичном формате.
 *
 *  Выходные данные:
 *      Первая строка:
 *      целочисленные значения элементов массива в десятеричном формате,
 *      каждое значение занимает 5 позиций.
 */

bool isNumber(std::string number) {
    bool isNumber = false;
    try {
        stoi(number);
        isNumber = true;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return isNumber;
}

int* generateArray(int arraySize) {
    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        array[i] = i * i;
    }
    return array;
}

class ArrayReversingObject {
public:
    ArrayReversingObject() {
        std::string input;
        getline(std::cin, input);
        arraySize = stoi(input);
        if (arraySize < 5 || arraySize > 20) throw "Размер должен быть в пределах от 5 до 20";

        array = generateArray(arraySize);

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
            int spacesCount = 5 - digitsCount(array[i]);
            printf("%i", array[i]);
            for (int i = 0; i < spacesCount; i++) {
                printf(" ");
            }
        }
        printf("\n");
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
};

int main() {
    try {
        auto arrayReverser = new ArrayReversingObject();
        delete arrayReverser;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }
}