#include<bits/stdc++.h>

using namespace std;

int a[1000];

int main() {
	int n, m, t, l, r, inp;
	cin >> n >> m;
	for(int z = 0; z < m; ++z) {
		cin >> t >> l >> r;
		l--; r;
		if(t == 1) {
			if(a[l] == m-1) {
				inp = m-1;
			} else {
				inp = m;
			}

			for(int i = l; i < r; ++i) {
				if(a[i] == 0) { a[i] = inp; }
			}
		} else {
			if(a[l] == 0) {
				if(a[l+1] != 0) {
					a[l] = a[l+1] + 1;
				}
				for(int i = l + 2; i < r; ++i) {
					a[i] = m;
				}
			} else {
				while(a[l++] != 0 && l < r);
				if(l < r) { a[l] = a[l - 1] - 1; }
				for(int i = l + 1; i < r; ++i) {
					a[i] = m;
				}
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		if(a[i] == 0) { a[i] = m; }

		cout << a[i] << ' ';
	}

	return 0;
}