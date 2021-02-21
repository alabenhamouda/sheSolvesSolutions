#include <iostream>

using namespace std;

bool containsDigitSeven(int x, int base) {
    while (x > 0) {
        if (x % base == 7)
            return true;
        x /= base;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        // chech if i does not contain the digit 7 in neither base 10 nor 8
        if (!containsDigitSeven(i, 10) && !containsDigitSeven(i, 8))
            ret++;
    }
    cout << ret << endl;
    return 0;
}
