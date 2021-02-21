#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 0;
    while (n > 0) {
        ret +=
            n /
            5;  // count the number of multiples of 5 that smaller or equal to n
        n /= 5; // we have to divide n by 5 so that in the next iteration we
                // count the multiples of the next power of 5 (25, 125, ...)
    }
    cout << ret << endl;
    return 0;
}
