#include <iostream>
#include <string>

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
        std::string input;
        getline(std::cin, input);
        this->n = stol(input);
        this->printResults();
    }

    int countDigits(long int number) {
        int N = 0;
        do {
            number /= 10;
            N++;
        } while (number != 0);
        return N;
    }

    void printResults() {
        std::cout << "n = " << n << std::endl;
        std::cout << "N = " << this->countDigits(this->n);
    }

private:
    long int n;
};

int main() {
    DigitsCounter someObject;
}
