#include <iostream>
#include <deque>
using namespace std;
int main() {
    long long q, c, x, ans;
    cin >> q;
    deque<long long> cnt;
    deque<long long> val;
    for (int i = 0; i < q; ++i) {
        int t;
        ans = 0;
        cin >> t;
        if (t == 1) {
            cin >> x >> c;
            cnt.push_back(c);
            val.push_back(x);
        } else {
            cin >> c;
            while (c > 0) {
                if (c < cnt.front()) {
                    ans += c * val.front();
                    cnt.front() -= c;
                    break;
                } else if (c == cnt.front()) {
                    ans += c * val.front();
                    cnt.pop_front();
                    val.pop_front();
                    break;
                } else {
                    ans += cnt.front() * val.front();
                    c -= cnt.front();
                    cnt.pop_front();
                    val.pop_front();
                }
            }
            cout << ans << '\n';
        }
    }
}