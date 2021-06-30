#include<bits/stdc++.h>

using namespace std;

int main() {
    long long T;
    cin >> T;
    while(T--) {
        long long N;
        cin >> N;
        long long A[N];
        
        vector<pair<long long,long long>> P;
        long long x = 0;
        P.push_back(make_pair(0,0));        
        for(long long i = 0; i < N; ++i) {
            cin >> A[i];
            x = x ^ A[i];
            P.push_back(make_pair(x, i + 1));
        }
        P.push_back(make_pair(2000000, 2000000));
        sort(P.begin(), P.end());
        long long len = 0;
        long long cnt = 0;
        for(unsigned long long i = 0; i < P.size() - 1; ++i) {
            len++;
            cnt += len * P[i].second;
            if(P[i+1].first != P[i].first) {
                for(long long j = 1; j <= len; ++j) {
                    cnt -= j * (P[i-j+1].second + 1);
                }
                cnt += len;
                len = 0;
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}