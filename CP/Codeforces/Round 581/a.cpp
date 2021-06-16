#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    unsigned int n = s.size();
    bool flag = false;
    for(unsigned int i = 1; i < n; ++i) {
        if(s[i] =='1') {
            flag = true;
            break;
        }
    }

    int ans = n/2 + ((n&1)?flag:0);
    cout << ans;
    return 0;
}