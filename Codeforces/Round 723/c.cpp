#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    long long sum = 0;
    for (int x : a) {
        if (sum + x >= 0) {
            sum += x;
            pq.push(x);
        } else {
            if (!pq.empty() && pq.top() < x) {
                sum -= pq.top();
                sum += x;
                pq.pop();
                pq.push(x);
            }
        }
    }
    cout << pq.size() << endl;
    return 0;
}