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
    color[0] = 1;
    vector<char> top;
    top.push_back(s[0]);
    bool flag;
    char smallest = 'z'+1;
    for(int i = 1; i < n; ++i) {
        flag = true;
        for(int j = 0; j < top.size(); ++j) {
            if(s[i] >= top[j]) {
                color[i] = j+1;
                top[j] = s[i];
                flag = false;
                break;
            }
        }
        
        if(flag) {
            top.push_back(s[i]);
            color[i] = top.size();
        }
    }

    cout << top.size() << '\n';
    for(int i = 0; i < n; ++i) {
        cout << color[i] << ' ';
    }

    return 0;
}