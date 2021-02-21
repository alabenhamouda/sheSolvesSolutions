#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int sum = 0;
    for (; i < n; i++) {
        sum += arr[i];
        if (sum > l)
            break;
    }
    if (sum > l) {
        cout << i << endl;
    } else
        cout << n << endl;
    return 0;
}
