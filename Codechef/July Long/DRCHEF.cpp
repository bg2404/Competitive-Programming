#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<long long> infected, population(n);
    for(long long i = 0; i < n; ++i) {
        cin >> population[i];
    }
    sort(population.begin(), population.end());
    infected = population;
    int done = 0;
    while(done )
}

int main() {
    long long t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}