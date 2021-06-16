#include<bits/stdc++.h>

using namespace std;

int A[52][52];

bool checkType1(int i, int j) {
    if((A[i-1][j-1] && A[i-1][j]) && A[i][j-1]) {
        return true;
    }
    return false;
}

bool checkType2(int i, int j) {
    if((A[i-1][j] && A[i-1][j+1]) && A[i][j+1]) {
        return true;
    }
    return false;
}

bool checkType3(int i, int j) {
    if((A[i][j-1] && A[i+1][j-1]) && A[i+1][j]) {
        return true;
    }
    return false;
}

bool checkType4(int i, int j) {
    if((A[i+1][j] && A[i+1][j+1]) && A[i][j+1]) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j =1; j <= m; ++j) {
            cin >> A[i][j];
        }
    }

    vector<pair<int,int>> ans;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(A[i][j] == 1) {
                if(checkType1(i,j)) {
                    ans.push_back(make_pair(i-1,j-1));
                } else if(checkType2(i,j)) {
                    ans.push_back(make_pair(i-1,j));
                } else if(checkType3(i,j)) {
                    ans.push_back(make_pair(i,j-1));
                } else if(checkType4(i,j)) {
                    ans.push_back(make_pair(i,j));
                } else {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}