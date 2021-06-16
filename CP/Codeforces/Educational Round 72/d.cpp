#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long fac[300010];
int rep_a[300010];
int rep_b[300010];
vector<int> rep_a_b;
long long MOD = 998244353;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
  	if(a.second == b.second) {
        return a.first < b.first;
    }
	return (a.second < b.second); 
}

void init() {
    fac[0] = 1;
    for(int i = 1; i <= 300000; ++i) {
        fac[i] = (fac[i-1]*i) % MOD;
    }
}

int main() {
    init();
    int n;
    cin >> n;
    vector<pair<int,int>> s,t;
    int a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        s.push_back(make_pair(a,b));
    }
    sort(s.begin(), s.end());
    t = s;
    rep_a[s[0].first] = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i].first == s[i-1].first) {
            rep_a[s[i].first]++;
        } else {
            rep_a[s[i].first] = 1;
        }
    }

    int count = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i] == s[i-1]) {
            count++;
        } else {
            rep_a_b.push_back(count);
            count = 1;
        }
    }
    rep_a_b.push_back(count);

    sort(s.begin(), s.end(),sortbysec);
    rep_b[s[0].second] = 1;
    for(int i = 0; i < n; ++i) {
        if(s[i].second == s[i-1].second) {
            rep_b[s[i].second]++;
        } else {
            rep_b[s[i].second] = 1;
        }
    }
    long long cnt1 = 1, cnt2 = 1, cnt12 = 1;
    for(int i = 0; i <= n; ++i) {
        cnt1 = (cnt1 * fac[rep_a[i]]) % MOD;
        cnt2 = (cnt2 * fac[rep_b[i]]) % MOD;
    }
    for(int i = 0; i < rep_a_b.size(); ++i) {
        cnt12 = (cnt12 * fac[rep_a_b[i]]) % MOD;
    }

    if(t != s) {
        cnt12 = 0;
    }

    cout << ((fac[n] - cnt1 - cnt2 + cnt12) % MOD + MOD ) % MOD << '\n';
    return 0;
}