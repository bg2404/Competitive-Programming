//https://cses.fi/problemset/task/1068

#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    while(n != 1) {
        printf("%lld ", n);
        n = (n & 1) ? 3*n + 1: n >> 1;
    }
    printf("%lld\n", n);
    return 0;
}