#include <bits/stdc++.h>

using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

const int N = int(3e5) + 99;
const int INF = int(1e9) + 99;

int t, n;
int a[N], b[N];
vector<vector <int>> p;
int st[4 * N + 55];

int getMin(int v, int l, int r, int L, int R){
	if(L >= R) return INF;
	if(l == L && r == R)
		return st[v];

	int mid = (l + r) / 2;
	return min(getMin(v * 2 + 1, l, mid, L, min(R, mid)),
		getMin(v * 2 + 2, mid, r, max(mid, L), R));	
}

void upd(int v, int l, int r, int pos, int x){
	if(r - l == 1){
		st[v] = x;
		return;
	}

	int mid = (l + r) / 2;
	if(pos < mid) upd(v * 2 + 1, l, mid, pos, x);
	else upd(v * 2 + 2, mid, r, pos, x);
		
	st[v] = min(st[v * 2 + 1], st[v * 2 + 2]);
}

int main() {
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
        p = vector<vector<int> > (n);
		for(int i = 0; i < n; ++i)
			p[i].clear();					
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			--a[i];
			p[a[i]].push_back(i);	
		}	
		for(int i = 0; i < n; ++i){
			scanf("%d", b + i);	
			--b[i];		
		}


		for(int i = 0; i < 4 * n; ++i) st[i] = INF;
		for(int i = 0; i < n; ++i){
			reverse(p[i].begin(), p[i].end());
			if(!p[i].empty()) upd(0, 0, n, i, p[i].back());
		}

		bool ok = true;
		for(int i = 0; i < n; ++i){
			if(p[b[i]].empty()){
				ok = false;
				break;
			}

			int pos = p[b[i]].back();
			if(getMin(0, 0, n, 0, b[i]) < pos){
				ok = false;
				break;
			}

			p[b[i]].pop_back();
			upd(0, 0, n, b[i], p[b[i]].empty()? INF : p[b[i]].back());			
		}

		if(ok) puts("YES");
		else puts("NO");
	}	
	
	return 0;
}