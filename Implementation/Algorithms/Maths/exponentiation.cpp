#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long power(long long a, unsigned long long n, long long p = MOD) {
    long long res = 1;
    // n %= p; // Only if p is prime
    while(n) {
        if(n & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}

int main() {
    long long a, b;

    cin >> a >> b;

    cout << power(a, b) << '\n';;

    return 0;
}