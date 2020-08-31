#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        int F[N], P[N];

        int cost[M];
        memset(cost, 0, sizeof(cost));

        for(int i = 0; i < N; ++i) {
            cin >> F[i];
        }

        for(int i = 0; i < N; ++i) {
            cin >> P[i];
            cost[F[i]-1] += P[i];   
        }

        int mini = 1000000000;
        for(int i = 0; i < N; ++i) {
            mini = min(mini, cost[F[i]-1]);
        }

        cout << mini << '\n';
    }
    return 0;
}