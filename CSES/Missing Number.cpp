//https://cses.fi/problemset/task/1083
#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    int x;
    cin >> n;
    long long s = n * ( n + 1 ) / 2;
    while(--n) {
        cin >> x;
        s -= x;
    }
    cout << s << '\n';
    return 0;
}