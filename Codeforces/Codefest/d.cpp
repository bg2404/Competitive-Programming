#include<bits/stdc++.h>

using namespace std;

int main() {
    map<long long, int> m;
    long long n;
    cin >> n;
    for(long long i = 1; i <=n; ++i) {
        long long a = i*(i+1)/2;
        m[a] = i;
    }
    long long s[n+1];
    for(long long i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    long long sum = n*(n+1)/2;
    for(long long i = n; i > 0; --i) {
        sum -= 
    }
    return 0;
}