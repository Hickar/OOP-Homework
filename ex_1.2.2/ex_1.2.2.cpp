#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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
 *      Вторая строка: (исходный порядок следования элементов).
 *      Третья строка: (обратный порядок следования элементов).
 */

vector<int> split(const string &str, const char delimiter) {
    vector<int> tokens;
    string token;
    istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

class ArrayReversingObject {
public:
    ArrayReversingObject() {
        string input;
        getline(cin, input);
        arrSize = stoi(input);

        getline(cin, input);
        arr = split(input, ' ');
        if (arr.size() != arrSize) {
            throw "Фактическое количество элементов в массиве отличается от указаного ранее";
        }
        printArray();
    }

    void reverseArray() {
        int temp,
            start = 0,
            end = arrSize - 1;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        printArray();
    }

private:
    int arrSize;
    vector<int> arr;

    void printArray() {
        for (const int element : arr) {
            printf("%i ", element);
        }
        printf("\n");
    }
};

int main() {
    try {
        ArrayReversingObject arrayReverser;
        arrayReverser.reverseArray();
    } catch (const char *msg) {
        cerr << msg << endl;
    }
}