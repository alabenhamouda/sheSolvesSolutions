#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    string name;
    cin >> k >> name;
    if (name.size() > k) {
        // string(name.begin(), name.begin() + k) is calling a string
        // constructor which takes two iterators (pointers) i.e. string(iterator
        // first, iterator last) which copies the sequence of characters in the
        // range [first,last), in the same order.
        cout << string(name.begin(), name.begin() + k) << "..." << endl;
    } else
        cout << name << endl;
    return 0;
}
