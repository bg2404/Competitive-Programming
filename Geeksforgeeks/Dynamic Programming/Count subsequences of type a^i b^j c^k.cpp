#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long

using namespace std;

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        string S;
        cin >> S;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == 'a') {
                a = 2*a + 1;
            } else if(S[i] == 'b') {
                b = a + 2*b;
            } else {
                c = b + 2*c;
            }
        }
        cout << c << '\n';
    }
    return 0;
}