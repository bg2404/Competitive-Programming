#include<bits/stdc++.h>

using namespace std;

int getFirstAsterickPos(string s) {
    int i = 0;
    for(auto c: s) {
        if(c == '*') {
            return i;
        }
        ++i;
    }
    return -1;
}

int getLastAsterickPos(string s) {
    for(int i = s.size()-1; i >= 0; --i) {
        if(s[i] == '*') {
            return i;
        }
    }
    return -1;
}

bool isPrefix(string a, string b) {
    for(int i = 0; i < a.size() && i < b.size(); ++i) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool isSuffix(string a, string b) {
    for(int i = 0; i < a.size() && i < b.size(); ++i) {
        if(a[a.size()-i-1] != b[b.size()-i-1]) {
            return false;
        }
    }
    return true;
}

string getMiddleString(string s, int a, int b) {
    int i = 0;
    for(int j = a; j <= b; ++j) {
        if(s[j] == '*') {
            continue;
        }
        s[i+a] = s[j];
        ++i;
    }
    return s.substr(a, i);
}

void solve() {
    int N, fpos, lpos;
    cin >> N;
    vector<string> P(N), pre(N), suf(N), mid(N);
    string mPre = "", mSuf = "";
    for(int i = 0; i < N; ++i) {
        cin >> P[i];
        fpos = getFirstAsterickPos(P[i]);
        if(fpos == -1) {
            cout << "*\n";
            return;
        }
        pre[i] = P[i].substr(0, fpos);
        if(fpos > mPre.size()) {
            mPre = pre[i];
        }
        lpos = getLastAsterickPos(P[i]);
        if(lpos == -1) {
            cout << '\n';
            return;
        }
        suf[i] = P[i].substr(lpos+1, P[i].size() - lpos - 1);
        if(suf[i].size() > mSuf.size()) {
            mSuf = suf[i];
        }
        mid[i] = getMiddleString(P[i], fpos+1, lpos-1);
    }
    for(int i = 0; i < N; ++i) {
        if(!isPrefix(mPre, pre[i])) {
            cout << "*\n";
            return;
        }
    }
    for(int i = 0; i < N; ++i) {
        if(!isSuffix(mSuf, suf[i])) {
            cout << "*\n";
            return;
        }
    }
    
    cout << mPre;
    for(int i = 0; i < N; ++i) {
        cout << mid[i];
    }
    cout << mSuf << '\n';
    
}

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}