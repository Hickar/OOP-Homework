#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
    Л3.1 Проверка готовности объектов к работе

    Фрагмент методического указания.
    Создание объектов и построение исходного иерархического дерева объектов.
    Система собирается из объектов, принадлежащих определенным классам.
    В тексте постановки задачи классу соответствует уникальный номер.
    Относительно номера класса определяются требования (свойства, функциональность).

    Первоначальная сборка системы (дерева иерархии объектов, программы) осуществляется исходя из входных данных.
    Данные вводятся построчно.

    Первая строка содержит имя корневого объекта (объект приложение). Номер класса корневого объекта 1.
    Корневой объект объявляется в основной программе (main).
    Исходное состояние корневого объекта соответствует его функционированию.

    Далее, каждая строка входных данных определяет очередной объект,
    задает его характеристики и расположение на дереве иерархии. Структура данных в строке:
        «Наименование головного объекта» «Наименование очередного объекта»
        «Номер класса принадлежности очередного объекта» «Номер исходного состояния очередного объекта»

    Ввод иерархического дерева завершается, если наименование головного объекта равно «endtree»
    (в данной строке ввода больше ничего не указывается).

    Готовность объекта характеризуется значением его состояния. Значение состояния - целое число.
    Определены правила для значения состояния:
        0 – объект выключен;
        Отрицательное – объект включен, но не функционирует, обнаружена неисправность. Значение классифицирует характер неисправности.
        Положительное – объект включен, функционирует в штатном режиме. Значение определяет текущее состояние объекта.

    Подчиненные объекты располагаются слева на право относительно голоного, согласно их следованию в исходных данных.
    Исходные данные подготовлены таким образом, что любой головной объект предварительно добавлен в качестве подчиненного.
    Подразумевается, что все объекты имеют уникальные имена.

    Для организации исходя из входных данных создания экземпляров объектов и формирования иерархического дерева, необходимо:
        1. В базовом классе реализовать метод поиска объекта на дереве объектов по его наименованию
        и возврата указателя на него. Если объект не найден, то вернуть нулевой указатель.
        2. В корневом объекте (объект приложения) реализовать метод чтения исходных данных,
        создания объектов и построения исходного дерева иерархии.

    Пример
    Ввод
        app_root
        app_root object_1 3 1
        app_root object_2 2 1
        object_2 object_4 3 -1
        object_2 object_5 3 1
        app_root object_3 3 1
        object_2 object_6 2 1
        object_1 object_7 2 1
        endtree

    Построенное дерево
        app_root
            object_1
                object_7
            object_2
                object_4
                object_5
                object_6
            object_3

    Вывод списка готовности объектов
        The object app_root is ready
        The object object_1 is ready
        The object object_7 is ready
        The object object_2 is ready
        The object object_4 is not ready
        The object object_5 is ready
        The object object_6 is ready
        The object object_3 is ready

    Постановка задачи

    Все сложные электронные, технические средства разного назначения в момент включения выполняют
    опрос готовности к работе составных элементов, индицируя соответствующую информацию на табло, панели или иным образом.

    Построить модель иерархической системы. Реализовать задачу опроса готовности каждого объекта из ее состава и
    вывести соответствующее сообщение на консоль.

    Объект считается готовым к работе:
    1. Создан и размешен в составе системы (на дереве иерархии объектов) согласно схеме архитектуры;
    2. Имеет свое уникальное наименование;
    3. Свойство, определяющее его готовность к работе, имеет целочисленное положительное значение.

    В результате решения задачи опроса готовности объектов,
    относительно каждого объекта системы на консоль надо вывести соответствующую информацию:

    Если свойство определяющее готовность объекта имеет положительное значение:

    The object «наименование объекта» is ready
    иначе
    The object «наименование объекта» is not ready

    Система содержит объекты трех классов, не считая корневого. Номера классов: 2,3,4.

    Входные данные
    Множество объектов, их характеристики и расположение на дереве иерархии.
    Структура данных для ввода согласно изложенному в фрагменте методического указания.

    Выходные данные
        В первой строке вывести
            Test result
        Далее, построчно, согласно следованию объектов на дереве иерархии слева на право и сверху вниз,
        относительно каждого объекта в зависимости от состояния готовности выводиться, если объект готов к работе:
            The object наименование объекта is ready
        Если не готов, то
            The object наименование объекта is not ready
 */

std::vector<std::string> split(const std::string &str, const char delimiter) {
    std::vector<std::string> tokens;
    int currentIndex = 0;
    std::string token;
    std::istringstream tokenStream(str);
    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}



class BaseNode {
    public:
        BaseNode(std::string name = " ", int stateID = 0) :name(name), stateID(stateID) {}

        std::string getName() {
            return this->name;
        }

        void getState() {
            std::string state;
            switch (this->stateID) {
                case 1:
                    state = "ready";
                    break;
                case 0:
                    state = "turned off";
                    break;
                case -1:
                    state = "not ready";
                    break;
                default:
                    throw "Wrong stateID";
            }

            std::cout << "The object " << this->getName() << " is " << state << std::endl;
            if (!childrenNodeList.empty()) {
                for (BaseNode* child : childrenNodeList) {
                    child->getState();
                }
            }
        }

        BaseNode* findNode(std::string name) {
            BaseNode *nodeToRetrieve = nullptr;

            if (this->getName() == name) nodeToRetrieve = this;
            for (BaseNode* child : childrenNodeList) {
                if (child->getName() == name) {
                    nodeToRetrieve = child;
                }
            }
            if (nodeToRetrieve == nullptr) throw "Parent node is not found";

            return nodeToRetrieve;
        }
        std::vector<BaseNode*> childrenNodeList;

    protected:
        std::string name;
        int stateID;
};

class Root : public BaseNode {
    public:
        Root(std::string name = " ", int stateID = 1) : BaseNode(name, stateID) {}

        void setChild(BaseNode* parentNode, BaseNode* childNode) {
            parentNode->childrenNodeList.push_back(childNode);
        }
};



class SubClassTwo : public Root {
    public:
        SubClassTwo(std::string name = " ", int stateID = 0) : Root(name, stateID) {}
};



class SubClassThree : public Root {
    public:
        SubClassThree(std::string name = " ", int stateID = 0) : Root(name, stateID) {}
};



class SubClassFour : public Root {
    public:
        SubClassFour(std::string name = " ", int stateID = 0) : Root(name, stateID) {}
};



int main() {
    std::string input;
    std::vector<std::string> splitInput;

    try {
        getline(std::cin, input);
        Root rootNode(input);

        while (true) {
            getline(std::cin, input);
            if (input == "endtree") break;
            splitInput = split(input, ' ');

            std::string parentNodeName = splitInput[0];
            std::string childNodeName = splitInput[1];
            int childNodeClassNumber = stoi(splitInput[2]);
            int childNodeStateID = stoi(splitInput[3]);

            BaseNode* parentNode = rootNode.findNode(parentNodeName);

            switch (childNodeClassNumber) {
                case 2:
                    rootNode.setChild(parentNode, new SubClassTwo(childNodeName, childNodeStateID));
                    break;
                case 3:
                    rootNode.setChild(parentNode,new SubClassThree(childNodeName, childNodeStateID));
                    break;
                case 4:
                    rootNode.setChild(parentNode,new SubClassFour(childNodeName, childNodeStateID));
                    break;
                default:
                    throw  "Wrong class number";
            }
        }

        std::cout << "Test result" << std::endl;
        rootNode.getState();
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
}