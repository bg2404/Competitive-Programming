#include<bits/stdc++.h>

using namespace std;

int dfa[5][5] = {   {0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 1, 0, 1, 1},
                    {0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0}   };

int main() {
    int p, q;
    cin >> p >> q;
    vector<int> state(p, 0);
    while(q--) {
        string sd;
        int x;
        cin >> sd >> x;
        int s = sd[0] - 'A', d = sd[1] - 'A';
        --x;
        if(state[x] == s && dfa[s][d]) {
            state[x] = d;
        }
    }
    for(int i = 0; i < 5; ++i) {
        cout << (char)(i + 'A') << ' ';
        for(int j = 0; j < p; ++j) {
            if(state[j] == i) {
                cout << j+1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}