#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k, cnt = 0, ans = 0;
    cin >> n;
    vector<int> stack1;
    vector<int> stack2;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (i == 0) {
            stack1.push_back(k);
            stack2.push_back(1);
        } else if (k != stack1.back()) {
            if (stack2.back() >= 3) {
                ans += stack2.back();
                cnt = stack2.back();
                for (int j = 0; j < cnt; ++j) {
                    stack2.pop_back();
                    stack1.pop_back();
                }
                if (k == stack1.back()) {
                    stack2.push_back(stack2.back() + 1);
                    stack1.push_back(k);
                } else {
                    stack2.push_back(1);
                    stack1.push_back(k);
                }
            } else {
                stack2.push_back(1);
                stack1.push_back(k);
            }
        } else {
            stack2.push_back(stack2.back() + 1);
            stack1.push_back(k);
        }
    }
    if (stack2.back() >= 3) {
        ans += stack2.back();
    }
    cout << ans;
}