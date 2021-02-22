#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = numeric_limits<ll>::max();

/*
 * function that takes the prefix sum array and the integer k and returns the
 * minimum sum of k consecutive elements from the original array arr
 */
ll minimumSum(ll *prefix, ll n, ll k) {
    if (k > n) {
        return INF;
    }
    ll ret = INF;
    for (ll i = 1; i <= n - k + 1; i++) {
        ret = min(ret, prefix[i + k - 1] - prefix[i - 1]);
    }
    return ret;
}

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // calculating the prefix sum array
    // initialize prefix[0] to 0 to make calculations easier without checking
    // for boundary cases
    ll prefix[n + 1];
    prefix[0] = 0;
    for (ll i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    // binary search over k
    ll step = n / 2;
    ll k = 0;
    while (step > 0) {
        if (minimumSum(prefix, n, k + step) < s) {
            // if k + step is not valid we add step to k so that in the next
            // iteration we start our search from there
            k += step;
        } else
            // if k + step was valid we divide step by 2 to check if there is a
            // smaller valid k
            step /= 2;
    }
    // when the loop exits the variable k holds the maximum invalid k
    // i.e. the maximum integer k such that there are some k consecutive
    // elements whose sum is lower than s.
    // if k is equal to n that means even n is invalid: the sum of the whole
    // array is lower than s
    if (k == n) {
        cout << "impossible\n";
    } else
        // else we print k + 1 because k is the max invalid integer, therefore k
        // + 1 must be the smallest valid integer
        cout << k + 1 << endl;
    return 0;
}
