#include<bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector< vector<int> > s(26);
	char ch;
	for(int i = 0; i < n; ++i) {
		cin >> ch;
		s[ch-'a'].push_back(i);
	}

	int m;
	cin >> m;
	while(m--) {
		string t;
		cin >> t;
		int max_len = 0;
		int cnt[26];
		for(int i = 0; i < 26; ++i) { cnt[i] = 0; }

		char ch;
		for(int i  = 0; i < t.size(); ++i) {
			ch = t[i];
			max_len = max(s[ch - 'a'][cnt[ch-'a']++], max_len);
		}

		cout << max_len + 1 << '\n';
	}

	return 0;
}