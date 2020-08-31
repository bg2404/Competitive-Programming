#include<bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    string x = "codeforces", s = "";
    vector<unsigned long long> ans;
    unsigned long long r = 1, temp = 11;
    ans.push_back(0);
    ans.push_back(1);
    while(ans.back() < k) {
        ans.push_back((ans.back() * temp) / r);
        ++temp;
        ++r;
        s += x;
        // cout << ans.back() << ' ';
        // cout.flush();
    }
    if(ans.back() == k) {
        cout << s << x << endl;
        return 0;
    }
    // for(auto i: ans) {
    //     cout << i << ' ' ;
    // }
    int n = ans.size();
    unsigned long long d = ans[n-2] - ans[n-3];
    unsigned long long z = k - ans[n-2];
    unsigned long long num = (z + d - 1) / d;
    while(num--) {
        s += 's';
    }
    cout << s << endl;
    return 0;
}