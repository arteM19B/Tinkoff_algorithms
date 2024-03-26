#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else {
            if (!stack.empty()) {
                if ((stack.back() == '(' && c == ')') || (stack.back() == '[' && c == ']') || (stack.back() == '{' && c == '}')) {
                    stack.pop_back();
                } else {
                    cout << "no";
                    return 0;
                }
            } else {
                cout << "no";
                return 0;
            }
        }
    }
    if (!stack.empty()) {
        cout << "no";
    } else {
        cout << "yes";
    }
}