#include <bits/stdc++.h>
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;++i)
#define PII pair<int, int>
#define V vector
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define F first
#define mp make_pair
using namespace std;

void solve(){
    // 
    int n, k;
    cin >> n >> k;
    int a[n], c[n];
    memset(c, 0, sizeof(c));
    loop(i, 0, n) {
        cin >> a[i];
    }
    loop(i, 1, n-1) {
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            c[i] = c[i-1] + 1;
        } else {
            c[i] = c[i-1];
        }
    }
    c[n] = c[n-1];
    // cout << c << '\n';
    int ans = c[k-2]-c[0];
    PII seg = mp(0, k-1);
    loop(i, k, n) {
        int t = c[i-1] - c[i-k+1];
        if(t > ans) {
            ans = t;
            seg = mp(i-k+1, i);
        }
    }
    cout << ans + 1 << ' ' << seg.F+1 << '\n';
}

int main(){
    FAST;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}