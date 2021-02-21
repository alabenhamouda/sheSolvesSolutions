#include <iostream>

using namespace std;

int main() {
    int k, s;
    cin >> k >> s;
    if (k * 5 >= s)
        cout << "Rich!" << endl;
    else
        cout << "Not yet" << endl;
    return 0;
}
