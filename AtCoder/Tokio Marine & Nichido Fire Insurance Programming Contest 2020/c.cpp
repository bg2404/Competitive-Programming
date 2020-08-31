#include<bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
    int n, k;
    cin >> n >> k;
    a = vector<int> (n);
    for(int &i: a) {
        cin >> i;
    }
    if(k >= n) {
        for(int i: a) {
            cout << n << ' ';
        }
        cout << '\n';
        return 0;
    }
}