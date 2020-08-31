#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

template<typename T>
void printVec(vector<T> v) {
    int n = v.size();
    for(int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

template<typename T>
void printArr(T arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

string convertToString(char* a, int size) 
{ 
    int i; 
    string s(a);
    return s; 
} 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        // cout << "Case #" << tc << ": \n";
        int n;
        string s;
        cin >> n >> s;
        int ans = 1;
        string sans = s;

        char min_c = s[0];
        for(int i = 1; i < n; ++i) {
            min_c = min(s[i], min_c);
        }
        for(int i = 1; i < n; ++i) {
            char t[n+1];
            t[n] = '\0';
            if(s[i] != min_c) {
                continue;
            }
            int k = 0;
            for(int j = i; j < n; ++j) {
                t[k++] = s[j];
            }
            if((n & 1) == (i & 1)) {
                for(int j = 0; j < i; ++j) {
                    t[k++] = s[j];
                }
            } else {
                for(int j = i-1; j >= 0; --j) {
                    t[k++] = s[j];
                }
            }
            if(sans > convertToString(t, n)) {
                sans = t;
                ans = i+1;
            }
        }
        
        cout << sans << '\n' << ans << '\n';
    }
    return 0;
}