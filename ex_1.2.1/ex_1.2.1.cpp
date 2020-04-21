#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

/* Создать объект "треугольник", который содержит длины сторон треугольника.
 * Длины сторон определяются в момент конструирования объекта. Объект
 * вычисляет периметр и площадь треугольника. Написать программу, которая
 * создаёт треугольника, выводит и периметр и площадь
 *
 * Входные данные: три целых числа, разделённых пробелом.
 *
 * Выходные данные:
 * P = периметр
 * S = площадь
 */

vector<string> split(const string &str, const char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

class Triangle {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c) {
        if (a + b > c && a + c > b && b + c > a) {
            sideA = a;
            sideB = b;
            sideC = c;
        } else {
            throw exception();
        }
    }
    double getPerimeter() {
        return (sideA + sideB + sideC);
    }
    double getArea() {
        double semiPerimeter = (sideA + sideB + sideC) / 2;
        return sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
    }
};

int main() {
    string input;
    getline(cin, input);

    vector<string> sides = split(input, ' ');
    try {
        Triangle triangle(stod(sides[0]), stod(sides[1]), stod(sides[2]));
        printf("P = %.3f\nS = %.3f", triangle.getPerimeter(), triangle.getArea());
    } catch (exception &e) {
        printf("Такого треугольника не существует");
    }

    return(0);
}

