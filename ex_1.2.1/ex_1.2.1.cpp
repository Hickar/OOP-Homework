#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

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

std::vector<std::string> split(const std::string &str, const char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

class Triangle {
private:
    float sideA, sideB, sideC;

public:
    Triangle(float a, float b, float c) {
        if (a + b > c && a + c > b && b + c > a) {
            sideA = a;
            sideB = b;
            sideC = c;
        } else {
            throw std::exception();
        }
    }
    float getPerimeter() {
        return (sideA + sideB + sideC);
    }
    float getArea() {
        float semiPerimeter = (sideA + sideB + sideC) / 2;
        return std::sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
    }
};

int main() {
    std::string input;
    getline(std::cin, input);

    std::vector<std::string> sides = split(input, ' ');
    try {
        Triangle triangle(stof(sides[0]), stof(sides[1]), stof(sides[2]));
        std::cout << "P = " << std::setprecision(3) << triangle.getPerimeter() << std::endl;
        std::cout << "S = " << std::setprecision(3) << triangle.getArea();
    } catch (std::exception &e) {
        std::cout << "Такого треугольника не существует";
    }

    return(0);
}

