#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
    freopen("sort/sort.in", "r", stdin);
    freopen("sort/out.txt", "w", stdout);
    int n;
    cin >> n;
    a = vector<int> (n);
    for(auto &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    for(auto &i: a) {
        cout << i << ' ';
    }
    return 0;
}