#include <iostream>

/* Создать объект, который сообщает об отработке конструктора и деструктора.
 * У объекта нет свойств и функциональности. Написать программу, которая:
 *  1. Сооздаёт объект.
 *
 * Входные данные:
 * Отсутствуют.
 *
 * Выходные данные:
 *  Первая строка:
 *  Constructor.
 *  Вторая строка:
 *  Destructor.
 */

class SomeObject {
public:
    SomeObject() {
        printf("Constructor\n");
    }

    ~SomeObject() {
        printf("Destructor");
    }
};

int main() {
    SomeObject obj;
    return 0;
}

