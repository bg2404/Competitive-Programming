#include<bits/stdc++.h>
#define N 6000001
#define MOD 1000000000000000003
using namespace std;

struct Trie {
    bool end;
    Trie *next[3];
    Trie() {
        end = false;
        next[0] = next[1] = next[2] = NULL;
    }
};

void insertString(Trie* root, const string &s) {
    Trie* cur = root;
    for(int i = 0; i < s.length(); ++i) {
        if(!cur->next[s[i]-'a']) {
            cur->next[s[i]-'a'] = new Trie();
        }
        cur = cur->next[s[i]-'a'];
    }
    cur->end = true;
}

bool search(Trie* root, const string &s, int idx, bool changed) {
    if(root == NULL) {
        return false;
    }
    if(idx == s.length()) {
        return root->end && changed;
    }
    if(changed) {
        return search(root->next[s[idx]-'a'], s, idx + 1, changed);
    }
    bool found = false;
    for(char c = 'a'; c < 'd' && !found; ++c) {
        found = search(root->next[c-'a'], s, idx+1, c != s[idx]);
    }
    return found;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    cin >> n >> m;
    Trie *root = new Trie();
    for(int i = 0; i < n; ++i) {
        cin >> s;
        insertString(root, s);

    }
    while(m--) {
        string s;
        cin >> s;
        if(search(root, s, 0, false)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}