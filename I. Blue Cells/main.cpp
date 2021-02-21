#include <iostream>

using namespace std;

int main() {
    int r, c, x, y;
    cin >> r >> c >> x >> y;
    // actually which rows and columns you choose to be colored blue doesn't
    // really matter all what matters is the number of rows and columns to be
    // colored (i.e. x and y) so we can choose the last x rows and the last y
    // columns
    cout << (r - x) * (c - y) << endl;
    return 0;
}
