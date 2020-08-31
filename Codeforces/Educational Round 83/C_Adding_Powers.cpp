#include<bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<long long> power;
        long long n, k;
        cin >> n >> k;
        long long num = 1;
        for(long long i = 0; num < 10000000000000000; ++i) {
            power.push_back(num);
            num *= k;
        }
        if(num >= 10000000000000000) {
            power.push_back(num);
        }
        debug(n, k);
        debug(power);
        bool used[100];
        memset(used, false, sizeof(used)); 
        long long a[n];
        bool pos = true;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            while(a[i] > 0 && pos) {
                int index = (lower_bound(power.begin(), power.end(), a[i]+1) - 1 - power.begin());
                if(!used[index]) {
                    a[i] -= power[index];
                    used[index] = true;
                } else {
                    pos = false;
                    break;
                }
            }
        }

        if(pos) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }
    return 0;
}