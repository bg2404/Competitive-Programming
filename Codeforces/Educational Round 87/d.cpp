#include<bits/stdc++.h>

using namespace std;

vector<int> prevSmaller(const vector<int> &A) {
    stack<int> s;
    vector<int> ans(A.size(), -1);
    int n = A.size() - 1;
    s.push(n--);
    while(n >= 0) {
        if(s.empty() || A[s.top()] <= A[n]) {
            s.push(n--);
        } else {
            ans[s.top()] = n;
            s.pop();
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    vector<int> v = prevSmaller(a);
    for(int i: v) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}