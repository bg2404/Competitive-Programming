#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int p, q, r;
    cin >> p >> q >> r;
    // cout << 1 << ' ';
    int x = p;
    vector<int> rv;
    set<int> rs;
    for(int i = 0; i < r; ++i) {
        x = x % r;
        if(!rs.count(x)) {
            rv.push_back(x);
            rs.insert(x);
            x = x * p;
        } else {
            break;
        }
    }
    int w = rv.size();
    int fac = 1;
    for(int i = 1; i <= q; ++i) {
        fac = (fac * i) % w;
    }
    if(fac == 0) {
        fac = w-1;
    } else {
        --fac;
    }
    cout << rv[fac] << ' ';
    return 0;
}