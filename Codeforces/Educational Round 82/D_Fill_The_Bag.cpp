#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

vector<int> power_2;;

int32_t main() {
    int x = 1;
    while(x < 1000000000000000000) {
        power_2.push_back(x);
        x = x << 1;
    }
    int t;
    cin >> t;
    while(t--) {
        int n, m, k = 0;
        cin >> n >> m;
        int a[m], sum = 0;
        for(int i = 0; i < m; ++i) {
            cin >> a[i];
            if((a[i] & n) == a[i]) {
                n = n ^ a[i];
                continue;
            }
            a[k] = a[i];
            ++k;
            sum += a[i];
        }
        
        if(sum < n) {
            cout << -1 << '\n';
            continue;
        }

        map<int, int> count;
        for(int i = 0; i < k; ++i) {
            ++count[a[i]];
        }
        int num = 1;
        while(num <= n) {
            if((num & n) == num) {
                int temp = 0;
                while((1 << temp) <= num) {
                    if(count[temp]) {
                        int index = upper_bound(power_2.begin(), power_2.end(), temp >> 1) - power_2.begin();
                        if((1 << (index+temp)) > temp) {
                            
                        }
                    }
                    ++temp;
                }
            }
        }
    }
    return 0;
}