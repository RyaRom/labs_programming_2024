#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

int evaluateExpression(const std::string &expr) {
    Stack stack;

    for (char c: expr) {
        if (c == ' ') {
            continue;
        }

        if (c == 'T' || c == 'F') {
            if (stack.isEmpty()) {
                stack.push(c);
                continue;
            }

            char top = stack.pop();

            if (top == 'N') {
                stack.push(c == 'T' ? 'F' : 'T');
            } else if (top == 'A') {
                if (!stack.isEmpty()) {
                    char second = stack.pop();
                    stack.push((c == 'T' && second == 'T') ? 'T' : 'F');
                }
            } else if (top == 'X') {
                if (!stack.isEmpty()) {
                    char second = stack.pop();
                    stack.push((c != second) ? 'T' : 'F');
                }
            } else if (top == 'O') {
                if (!stack.isEmpty()) {
                    char second = stack.pop();
                    stack.push((c == 'T' || second == 'T') ? 'T' : 'F');
                }
            } else {
                stack.push(top);
                stack.push(c);
            }
        } else {
            stack.push(c);
        }
    }

    char last;
    while(!stack.isEmpty()) {
       char c = stack.pop();
        if(stack.isEmpty()) {
            last = c;
            break;
        }

        if (c == 'T' || c == 'F') {
            if (stack.isEmpty()) {
                stack.push(c);
                continue;
            }

            char top = stack.pop();

            if (top == 'N') {
                stack.push(c == 'T' ? 'F' : 'T');
            } else if (top == 'A') {
                if (!stack.isEmpty()) {
                    char second = stack.pop();
                    stack.push((c == 'T' && second == 'T') ? 'T' : 'F');
                }
            } else if (top == 'X') {
                if (!stack.isEmpty()) {
                    char second = stack.pop();
                    stack.push((c != second) ? 'T' : 'F');
                }
            } else if (top == 'O') {
                if (!stack.isEmpty()) {
                    char second = stack.pop();
                    stack.push((c == 'T' || second == 'T') ? 'T' : 'F');
                }
            } else {
                stack.push(top);
                stack.push(c);
            }
        } else {
            break;
        }
    }

    return (last == 'T') ? 1 : 0;
}

int lab7_main() {
    std::ifstream inputFile("C:\\Users\\locadm\\CLionProjects\\Suai_labs_programming_2024\\files\\input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(inputFile, expression);
    inputFile.close();
    std::cout << expression << std::endl;

    try {
        int result = evaluateExpression(expression);
        std::cout << "Result: " << (result == 1 ? "True" : "False") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}