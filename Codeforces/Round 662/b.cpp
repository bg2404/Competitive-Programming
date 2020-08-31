#include<bits/stdc++.h>

using namespace std;

vector<int> cnt(100001, 0);

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> m4, m2;
    for(int &i: a) {
        cin >> i;
        ++cnt[i];
        if(cnt[i] > 0 && cnt[i] % 4 == 0) {
            m4.insert(i);
            m2.erase(i);
        } else if(cnt[i] % 4 == 2) {
            m2.insert(i);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        char op;
        int p;
        cin >> op >> p;
        if(op == '+') {
            ++cnt[p];
            if(cnt[p] % 4 == 0) {
                m4.insert(p);
                m2.erase(p);
            } else if(cnt[p] % 4 == 2) {
                m2.insert(p);
            }
        } else {
            --cnt[p];
            if(cnt[p] % 4 == 3) {
                m4.erase(m4.find(p));
                m2.insert(p);
            } else if(cnt[p] % 4 == 1) {
                m2.erase(p);
            }
        }
        // cout << m4.size() << ' ' << m2.size() << ' ';
        if(m4.size() > 1 || (m4.size() > 0 && m2.size() > 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}