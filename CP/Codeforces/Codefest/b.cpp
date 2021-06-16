#include<bits/stdc++.h>

using namespace std;

vector<int> app_f;
vector<int> app_b;

bool vec_se(vector<int> v, int k) {
    bool f = false;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] == k) {
            f = true;
            break;
        }
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int forw = n, back = -1;
    app_f.push_back(a[0]);
    for(int i = 1; i < n; ++i) {
        if(vec_se(app_f, a[i])) {
            forw = i;
            break;
        }
        app_f.push_back(a[i]);
    }

    app_b.push_back(a[n-1]);
    for(int i = n-2; i >= 0; --i) {
        if(vec_se(app_b, a[i])) {
            back = i;
            break;
        }
        app_b.push_back(a[i]);
    }

    if(forw == n && back == -1) {
        cout << 0 << '\n';
    } else if(forw < back) {
        cout << back - forw + 1 << '\n';
    } else {
        int a = min(min(n - forw, back + 1), forw - back + 1);
        cout << a << '\n';
    }

    cout << (((51^7)^(35^31))^((12^48)^(28^20))) << '\n';
    return 0;
}