#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int binary_search(int a[], int n, int x) {
    int l = 0, r = n, m = (l+r)/2;
    while(l < r) {
        // cout << l << ' ' << r << ' ' << m << '\n';
        if(a[m]*a[m] == x) {
            return m+1;
        }
        if(a[m]*a[m] < x) {
            l = m+1;
        } else {
            r = m;
        }
        m = (l+r)/2;
    }
    return r;
}

bool comp(int a, int b) {
    return a*a < b*b;
}

template<typename T>
void printArray(T a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

map<int, bool> mapx, mapy;

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        mapx.clear();
        mapy.clear();
        int n, m;
        cin >> n >> m;
        int x[n], y[m];
        int x_z = -1, y_z = -1;
        for(int i = 0; i < n; ++i) {
            cin >> x[i];
            mapx[x[i]] = true;
            if(x[i] == 0) {
                x_z = i;
                --i;
                --n;
            }
        }
        for(int i = 0; i < m; ++i) {
            cin >> y[i];
            mapy[y[i]] = true;
            if(y[i] == 0) {
                y_z = i;
                --i;
                --m;
            }
        }

        sort(x, x+n);
        sort(y, y+m);
 
        int count = 0;
        for(int i = 0; i < n && x[i] < 0; ++i) {
            for(int j = n-1; j >= 0 && x[j] > 0; --j) {
                int z = sqrt(-x[i]*x[j]);
                if(z*z == -x[i]*x[j]) {
                    if(mapy[z]) {
                        ++count;
                        // printf("x: %lld %lld %lld\n", i, j, z);
                    }
                    if(mapy[-z]) {
                        ++count;
                        // printf("x: %lld %lld %lld\n", i, j, -z);
                    }
                }
            }
        }
        for(int i = 0; i < m && y[i] < 0; ++i) {
            for(int j = m-1; j >= 0 && y[j] > 0; --j) {
                int z = sqrt(-y[i]*y[j]);
                if(z*z == -y[i]*y[j]) {
                    if(mapx[z]) {
                        ++count;
                        // printf("y: %lld %lld %lld\n", i, j, z);
                    }
                    if(mapx[-z]) {
                        ++count;
                        // printf("y: %lld %lld %lld\n", i, j, -z);
                    }
                }
            }
        }
        if(x_z >= 0) {
            count += n*m;
        }
        if(y_z >= 0) {
            count += n*m;
        }
        cout << count << '\n';
    }

    return 0;
}