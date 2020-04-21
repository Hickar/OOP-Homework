#include <iostream>
#include <string>

using namespace std;

/* Создать объект, который обрабатывает переменную целого типа максимальной длины.
 * У объекта есть закрытое свойство n целого типа максимальной длины.
 * Объект обладает следующей функциональностью:
 *  – определяет значение свойства n;
 *  – вычисляет количество цифр значения свойства n;
 *  – возвращает количество цифр значения n.
 * Написать программу, которая:
 *  1. Создаёт объект.
 *  2. Вводит значение переменной целого типа.
 *  3. Определяет значение свойства n по значению переменной целого типа.
 *  4. Вычисляет количество цифр свойства n.
 *  5. Выводит значение свойства n.
 *  6. Выводит количество цифр значения свойства n.
 *
 * Входные данные:
 *  Первая строка: целое число в десятичном формате.
 *
 * Выходные данные:
 *  Первая строка:
 *  n = значение свойства n.
 *  Вторая строка:
 *  N = количество цифр свойства n.
 */

class DigitsCounter {
public:
    DigitsCounter() {
       getline(cin, input);
       n = stol(input);
    }

    void countDigits() {
        long int temp = n;
        while (n != 0) {
            n /= 10;
            N++;
        }
        n = temp;
    }

    void printResults() {
        printf("n = %li\nN = %i", n, N);
    }

private:
    string input;
    long int n;
    int N = 0;
};

int main() {
    DigitsCounter someObject;
    someObject.countDigits();
    someObject.printResults();
}
