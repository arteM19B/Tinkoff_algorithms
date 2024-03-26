#include <iostream>
#include <deque>

using namespace std;

//  функция, выравнивающая длины очередей
//  первая половина всегда либо равна второй, либо на 1 длиннее
void rebalanceQueues(deque<int> &firstHalf, deque<int> &secondHalf) {
    while (firstHalf.size() < secondHalf.size()) {
        firstHalf.push_back(secondHalf.front());
        secondHalf.pop_front();
    }
    while (firstHalf.size() > secondHalf.size() + 1) {
        secondHalf.push_front(firstHalf.back());
        firstHalf.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    deque<int> firstHalf;
    deque<int> secondHalf;

    while (n--) {
        char c;
        cin >> c;
        if (c == '-') {
            cout << firstHalf.front() << '\n';
            firstHalf.pop_front();
        } else if (c == '+') {
            int k;
            cin >> k;
            secondHalf.push_back(k);
        } else {
            int k;
            cin >> k;
            firstHalf.push_back(k);
        }
        rebalanceQueues(firstHalf, secondHalf);
    }

    return 0;
}