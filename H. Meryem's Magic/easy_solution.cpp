#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, k;
bool is_prime(int p)
// is_prime tests if p is a prime
{
    int i = 2;
    while (i <= p / 2)

    {
        if (p % i == 0) return false;
        i++;
    }
    return true;
}
void fill(int n = 3000)
// fill will complete the vector v with primes up to n
{
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) v.push_back(i);
    }
}
string handle()
{
    string s = "";
    // if n is even (CASE 1)
    if (n % 2 == 0) {
        for (int i = 0; i < k - 2; i++) {
            s += "2 ";
            n -= 2;
        }

    }
    // if n is odd
    else {

        for (int i = 0; i < k - 3; i++) {
            s += "2 ";
            n -= 2;
        }
        if (k > 2) {
            // CASE 2
            n -= 3;
            s += "3 ";
        }
    }
    return s;
}


int main()
{
    fill();
    cin >> n >> k;
    /*
     * if n<2*k then there can't be any combination of primes that sum
     * to n because 2*k is the smallest sum of any k primes
     */
    if (n < 2 * k) {
        cout << "Impossible\n";
        return 0;
    }
    bool found = false;
    /*
     * handle() will return a string s containing the first
     * k-2 primes if k>2 and will be empty if k==2
     * and it will substract the k-2 primes from n
     */
    string s = handle();


    int i, j;
    // we look for 2 primes that sum to our new n (n after substracting k-2
    // primes )
    for (i = 0; i < v.size(); i++) {
        for (j = i; j < v.size(); j++) {
            if (v[i] + v[j] == n) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (found) {
        cout << s << v[i] << " " << v[j] << endl;
    } else {
        // if in case 3 n-2 is not prime we print impossible
        cout << "Impossible\n";
    }
    return 0;
}
