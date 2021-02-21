#include <iostream>

using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int op = 0;
    while (b <= a) {
        b *= 2;
        op++;
    }
    while (c <= b) {
        c *= 2;
        op++;
    }
    if (op <= k) {
        cout << "You tricked us!" << endl;
    } else {
        cout << "Oh no!" << endl;
    }
    return 0;
}
