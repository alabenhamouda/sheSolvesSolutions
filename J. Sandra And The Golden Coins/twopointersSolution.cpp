#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, n, S, sol = 0;
    cin >> n >> S;
    int I[n];
    for (auto &i : I)
        cin >> i;

    int sum = 0, left = 0, right = 0, k = 0;

    while (right < n) {
        if (sum < S) {
            sum += I[right];
            k++;
        } else {
            sum += I[right] - I[left];
            if (sum >= S) {
                left++;
            } else {
                k++;
                sum += I[left];
            }
        }
        right++;
    }
    if (sum < S)
        cout << "impossible" << endl;
    else
        cout << k << endl;
    return 0;
}
