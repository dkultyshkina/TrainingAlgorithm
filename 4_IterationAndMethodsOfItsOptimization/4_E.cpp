/*
Решение задачи по выводу всех правильных скобочных последовательностей из круглых и квадратных заданной длины в лексикографическом порядке
*/
#include <iostream>
#include <string>
#include <stack>

void PrintStr(std::string& str) {
    std::cout << str << "\n";
}

char Check(std::stack<char>& st, std::string& str) {
    if (st.empty()) {
        return ' ';
    }
    else {
        char bracket = st.top();
        if (bracket == '(') {
            str.push_back(')');
        } 
        if (bracket == '[') {
            str.push_back(']');
        }
        st.pop();
        return bracket;
    }
    return ' ';
}


void Generation(int N, int left, int right, std::string& str, std::stack<char>& st) {
    if (left == N && right == N) {
        PrintStr(str);
    }
    else {
        if (left < N) {
            str.push_back('(');
            st.push('(');
            Generation(N, left + 1, right, str, st);
            str.pop_back();
            st.pop();

            str.push_back('[');
            st.push('[');
            Generation(N, left + 1, right, str, st);
            str.pop_back();
            st.pop();
        }
        if (left > right) {
            char bracket = Check(st, str);
            Generation(N, left, right + 1, str, st);
            str.pop_back();
            st.push(bracket);
        }
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    if (N == 0 || N % 2 != 0) {
        std::cout << "";
        return 0;
    }
    std::string str = "";
    std::stack<char> st;
    Generation(N/2, 0, 0, str, st);
    return 0;
}
