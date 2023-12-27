/*
Решение задачи правильной скобочной последовательности - удовлетворяет ли введенная строка данному условию?  
*/

#include <iostream>
#include <stack>
#include <string>

void CheckStack(std::stack<char>* st, char input) {
    if (!(*st).empty()) {
        if (((*st).top() + 2)== input || ((*st).top() + 1) == input) {
            (*st).pop();
        }
        else {
            (*st).push(input);
        }
    }
    else {
        (*st).push(input);
    }
}

int main()
{
    std::string input;
    std::cin >> input;
    std::stack<char> st;
    for (size_t i = 0; i < input.length(); ++i) {
        CheckStack(&st, input[i]);
    }
    if (st.empty()) {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }
    return 0;
}

