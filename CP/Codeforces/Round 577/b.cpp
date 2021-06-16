#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 2) {
        cout << "NO\n";
    } else {
        long long max_ele = *max_element(a.begin() , a.end());
        if(max_ele <= sum / 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}