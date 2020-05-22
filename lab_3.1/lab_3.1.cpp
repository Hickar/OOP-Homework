#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
    Л3.1
    Задача

    Разработать программу (систему) с использованием объектов:
        – Один объект класса cl_application;
        – множества объектов принадлежащим 4-м разным классам наследованных от cl_base.

    Разработать программу, которая строит следующее дерево иерархии объектов:
        root
            ob_1
                ob_2
                    ob_3
                    ob_4
                ob_5
            ob_6
            ob_7
                ob_8

    Каждый объект может принадлежать любому из 4-х классов. Необходимо задействовать объекты всех классов.
    Расширить функционал базового класса cl_base методом, который выводит на экран дерево иерархии объектов как показано в постановке задачи.
    Отступ каждого уровня иерархии 4 пробела.

    Программа должна:
    1. Строить заданную иерархию объектов.
    2. Выводить дерево иерархии объектов.
    Входные данные
    Отсутствуют

    Выходные данные
        root
            ob_1
                ob_2
                    ob_3
                    ob_4
                ob_5
            ob_6
            ob_7
                ob_8
 */

class cl_base {
public:
    cl_base(std::string name = " ") :name(name) {}

    std::string getName() {
        return this->name;
    }

    void setChild(cl_base* parentNode, cl_base* childNode) {
        parentNode->childrenNodeList.push_back(childNode);
    }

    void printTree() {
        std::cout << this->getName() << std::endl;
        if (!this->childrenNodeList.empty()) {
            for (cl_base* child : this->childrenNodeList) {
                std::cout << "    ";
                child->printTree();
            }
        }
    }

    cl_base* findNode(std::string name) {
        cl_base* nodeToRetrieve = nullptr;

        if (this->getName() == name) {
            nodeToRetrieve = this;
        } else {
            for (cl_base* child : childrenNodeList) {
                if (child->getName() == name) {
                    nodeToRetrieve = child;
                } else {
                    nodeToRetrieve = child->findNode(name);
                }
            }
        };

//        if (nodeToRetrieve == nullptr) throw "Parent node is not found: " + name;

        return nodeToRetrieve;
    }

    std::vector<cl_base*> childrenNodeList;

protected:
    std::string name;
};



class cl_one : public cl_base {
public:
    cl_one(std::string name = " ") : cl_base(name) {}
};



class cl_two : public cl_base {
public:
    cl_two(std::string name = " ") : cl_base(name) {}
};



class cl_three : public cl_base {
public:
    cl_three(std::string name = " ") : cl_base(name) {}
};



class cl_four : public cl_base {
public:
    cl_four(std::string name = " ") : cl_base(name) {}
};



cl_base* createRandomClassObject(std::string nodeName) {
    srand(time(0));
    cl_base* someObject;
    int seed = rand() % 4;

    switch (seed) {
        case 0:
            someObject = new cl_one(nodeName);
            break;
        case 1:
            someObject = new cl_two(nodeName);
            break;
        case 2:
            someObject = new cl_three(nodeName);
            break;
        case 3:
            someObject = new cl_four(nodeName);
            break;
        default:
            throw "Randomizer seed is not correct";
    }

    return someObject;
}


class cl_application {
public:
    cl_application() = default;
    static void start() {
        auto* root = createRandomClassObject("root");
        root->setChild(root, createRandomClassObject("ob_1"));
        root->setChild(root->findNode("ob_1"), createRandomClassObject("ob_2"));
        root->setChild(root->findNode("ob_2"), createRandomClassObject("ob_3"));
        root->setChild(root->findNode("ob_2"), createRandomClassObject("ob_4"));
        root->setChild(root->findNode("ob_1"), createRandomClassObject("ob_5"));
        root->setChild(root, createRandomClassObject("ob_6"));
        root->setChild(root, createRandomClassObject("ob_7"));
        root->setChild(root->findNode("ob_7"), createRandomClassObject("ob_8"));

        root->printTree();
    };
};



int main() {
    try {
        cl_application app;
        app.start();
    } catch (const std::string &msg) {
        std::cerr << msg << std::endl;
    }


//    switch (childNodeClassNumber) {
//        case 2:
//            rootNode.setChild(parentNode, new cl_two(childNodeName, childNodeStateID));
//            break;
//        case 3:
//            rootNode.setChild(parentNode,new cl_three(childNodeName, childNodeStateID));
//            break;
//        case 4:
//            rootNode.setChild(parentNode,new cl_four(childNodeName, childNodeStateID));
//            break;
//        default:
//            throw  "Wrong class number";
//    }
}