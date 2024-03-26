#include <iostream>
#include <deque>
using namespace std;
int main() {
    int q;
    deque<long long> q1;
    deque<long long> q_min;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int t;
        cin >> t;
        if (t == 1) {
            long long x;
            cin >> x;
            q1.push_back(x);
            if (j == 0) {
                q_min.push_back(x);
            } else {
                while (!q_min.empty() && q_min.back() >= x) {
                    q_min.pop_back();
                }
                q_min.push_back(x);
            }
        } else if (t == 2) {
            cout << q1.front() << '\n';
            if (!q_min.empty() && q_min.front() == q1.front()) {
                q_min.pop_front();
            }
            q1.pop_front();
        } else if (t == 3) {
            int i;
            cin >> i;
            cout << q1[i - 1] << '\n';
        } else {
            cout << q_min.front() << '\n';
        }
    }
}