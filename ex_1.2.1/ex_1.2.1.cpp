#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

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
    Triangle(double side1, double side2, double side3) {
        sideA = side1;
        sideB = side2;
        sideC = side3;
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
    Triangle triangle(stod(sides[0]), stod(sides[1]), stod(sides[2]));

    printf("Периметр: %.3f\nПлощадь: %.3f", triangle.getPerimeter(), triangle.getArea());
    return(0);
}

