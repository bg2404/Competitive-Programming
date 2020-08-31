#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    int s;
    cin >> s;
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(s-1);
    while(!q.empty()) {
        int c = q.front();
        if(a[c] == 0) {
            cout << "Yes\n";
            return;
        }
        q.pop();
        if(c - a[c] >= 0) {
            if(!visited[c-a[c]]) {
                visited[c-a[c]] = true;
                q.push(c - a[c]);
            }
        }
        if(c + a[c] < n) {
            if(!visited[c+a[c]]) {
                visited[c+a[c]] = true;
                q.push(c + a[c]);
            }
        }
    }
    cout << "No\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}