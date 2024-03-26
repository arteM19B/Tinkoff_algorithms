#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main() {
    string s;
    int first, two;
    vector<int> stack;
    getline(cin, s);
    stringstream ss(s);
    char c;
    while (ss >> c)
        if ('0' <= c && c <= '9') {
            stack.push_back(c - '0');
        } else if (c == '+') {
            two = stack.back();
            stack.pop_back();
            first = stack.back();
            stack.pop_back();
            stack.push_back(first + two);
        } else if (c == '-') {
            two = stack.back();
            stack.pop_back();
            first = stack.back();
            stack.pop_back();
            stack.push_back(first - two);
        } else if (c == '*') {
            two = stack.back();
            stack.pop_back();
            first = stack.back();
            stack.pop_back();
            stack.push_back(first * two);
        }
    cout << stack.back();
}