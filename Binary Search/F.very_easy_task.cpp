#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    // первый лист можно напечатать только на 1 ксероксе
    n--;
    // мы ищем минимум, поэтому ответ будет лежать в right
    int left = -1;  // -1 точно не ответ, а вот 0 мб ответ
    int right = 2e9;  // за это время точно напечатаем (следует из ограничений на входные данные)
    while (left + 1 < right) {
        int m = (left + right) / 2;
        if (m / x + m / y >= n)
            right = m;
        else
            left = m;
    }
    cout << right + min(x, y);
    return 0;
}