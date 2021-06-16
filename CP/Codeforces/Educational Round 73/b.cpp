#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;
    string row[2];
    row[0] = "";
    row[1] = "";
    for(int i = 0 ; i < n; ++i) {
        (i & 1)? row[0] += "W": row[0] += "B";
    }
    for(int i = 0 ; i < n; ++i) {
        (i & 1)? row[1] += "B": row[1] += "W";
    }

    for(int i = 0; i < n; ++i) {
        cout << row[i&1] << '\n';
    }
    return 0;
}