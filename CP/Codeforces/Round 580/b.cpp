#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, neg = 0, cost = 0, zero_present = false;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] < 0) {
            cost += (-1 - a[i]);
            neg++;
        } else if(a[i] > 0){
            cost += (a[i] - 1);
        } else {
            zero_present = true;
            cost += 1;
        }
    }
    if((neg&1) & !zero_present) {
        cost += 2;
    }

    cout << cost << '\n';

    return 0;
}