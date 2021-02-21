#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = numeric_limits<ll>::max();

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
    ll prefix[n + 1];
    prefix[0] = 0;
    for (ll i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    ll step = n / 2;
    ll k = 0;
    while (step > 0) {
        if (minimumSum(prefix, n, k + step) < s) {
            k += step;
        } else
            step /= 2;
    }
    if (k == n) {
        cout << "impossible\n";
    } else
        cout << k + 1 << endl;
    return 0;
}
