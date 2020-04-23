#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool isNumber(std::string &str) {
    bool isNumber = true;
    try {
        stoi(str);
    } catch (std::exception &e) {
        isNumber = false;
    }
    return isNumber;
}

struct Token {
    std::string value;
    std::string type;
    Token(std::string &token) {
        value = token;
        if (isNumber(value)) {
            type = "number";
        } else if (value == "+" || value == "-" || value == "*" || value == "%") {
            type = "operator";
        } else {
            throw "Неправильные аргументы!";
        }
    }
};

std::vector<Token> split(const std::string &str, const char delimiter) {
    std::vector<Token> tokens;
    std::string substr;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, substr, delimiter)) {
        tokens.push_back(Token(substr));
    }
    return tokens;
}

class Calculator {
public:
    Calculator() {}

    void calculate(std::vector<Token> &Tokens) {
        if (Tokens[0].type == "number") {
            x = stoi(Tokens[0].value);
            y = stoi(Tokens[2].value);
            operation = Tokens[1].value[0];
        } else if (Tokens[0].type == "operator") {
            x = result;
            y = stoi(Tokens[1].value);
            operation = Tokens[0].value[0];
        }

        switch (operation) {
            case '+':
                result = x + y;
                break;
            case '-':
                result = x - y;
                break;
            case '*':
                result = x * y;
                break;
            case '%':
                result = x % y;
                break;
        }

        operationsCounter++;
        if (operationsCounter % 3 == 0) {
            printf("%i\n", result);
        }
    }

private:
    int x = 0, y = 0, result = 0, operationsCounter = 0;
    char operation;
};

int main() {
    std::string input;
    std::vector<Token> expressionItems;
    try {
        Calculator calc;
        while (true) {
            getline(std::cin, input);
            if (input == "C" || input == "c") break;

            expressionItems = split(input, ' ');
            calc.calculate(expressionItems);
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}