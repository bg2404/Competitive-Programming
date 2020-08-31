#include<bits/stdc++.h>
#define int long long
#define MOd 1000000007
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> x, y;
    x.push_back(a[0]);
    y.push_back(a[1]);

    bool pos = true;
    for(int i = 2; i < n; ++i) {
        y.push_back(a[i]);
        if(i > 2) {
            if(y[i-1] - y[i-2] != y[i-2] - y[i-3]) {
                pos = false;
                break;
            } else {
                y.push_back(a[i]);
            }
        }
    }
    if(!pos) {
        y.clear();
        int x_s = 1, y_s = 0;
        int p = 0;
        for(int i = 1; i < n; ++i) {
            x.push_back(a[i]);
            x_s++;
            // cout << i << '\n';
            for(int j = i + 1; j < n; ++j) {
                // cout << j << ' ' << a[j] << '\n';
                if(a[j] - x[x_s-1] == x[x_s-1] - x[x_s-2]) {
                    x.push_back(a[j]);
                    ++x_s;
                } else {
                    ++p;
                    if(y_s > 1) {
                        if(a[j] - y[y_s-1] == y[y_s-1] - y[y_s-2]) {
                            y.push_back(a[j]);
                            ++y_s;
                        } else {
                            ++p;
                        }
                    } else {
                        y.push_back(a[j]);
                            ++y_s;
                    }
                }
                if(p > 1) {
                    break;
                } else {
                    p = 0;
                }
            }
            if(p > 1) {
                p = 0;
                x.clear();
                y.clear();
                x_s = 1;
                y_s = 0;
                x.push_back(a[0]);
                for(int j = 1; j <= i; ++j) {
                    if(y_s < 2 ) {
                        y.push_back(a[j]);
                        ++y_s;
                    } else {
                        if(a[j] - y[y_s-1] == y[y_s-1] - y[y_s-2]) {
                            y.push_back(a[j]);
                            ++y_s;
                        } else {
                            pos = false;
                            p = 100;
                            break;
                        }
                    }
                }
                if(p == 100) {
                    pos = false;
                    break;
                }
            } else {
                cout << "Yes\n";
                // cout << i << " " << '\n';
                // for(int a = 0; a < x_s; ++a) {
                //     cout << x[a] << ' ';
                // }
                // cout << '\n';
                // for(int a = 0; a < y_s; ++a) {
                //     cout << y[a] << ' ';
                // }
                // cout << '\n';
                
                pos = true;
                break;
            }
        }
    } else {
        cout << "Yes\n";
    }

    if(!pos) {
        cout << "No\n";
    }

    return 0;
}