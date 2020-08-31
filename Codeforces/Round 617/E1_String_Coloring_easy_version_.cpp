#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long 

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    char s[n];
    char c;
    int color[n];
    for(int i = 0; i < n; ++i) {
        cin >> c;
        s[i] = c;
    }
    color[0] = 0;
    char top = s[0];
    char latest = '0';
    bool pos = true;
    for(int i = 1; i < n; ++i) {
        if(s[i] >= top) {
            color[i] = 0;
            top = s[i];
        } else {
            if(s[i] < latest) {
                pos = false;
                break;
            } else {
                color[i] = 1;
                latest = s[i];
            }
        }
    }
    
    if(pos) {
        cout << "YES\n";
        for(int i = 0; i < n; ++i) {
            cout << color[i];
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}