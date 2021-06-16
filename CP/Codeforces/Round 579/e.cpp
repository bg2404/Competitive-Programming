#include<bits/stdc++.h>

using namespace std;

int found[150001];

int main() {
    found[0] = 1;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int count = 0;
    sort(a, a+n);
    for(int i = 0; i < n; ++i) {
        if(!found[a[i]-1]) {
            found[a[i]-1] = 1;
            count++;
        } else if(!found[a[i]]) {
            found[a[i]] = 1;
            count++;
        } else if(!found[a[i]+1]) {
            found[a[i]+1] = 1;
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}