#include<bits/stdc++.h>

using namespace std;

int power_2[30] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int input;
        vector<int> count(30,0);
        for(int i = 0; i < n; ++i) {
            cin >> input;
            for(int j = 0; j < 30; ++j) {
                if(power_2[j] == input) {
                    count[j]++;       
                    break;
                }
            }
        }

        for(int i = 1; i < 12; ++i) {
            count[i] += count[i-1]/2;
        }
        if(count[11]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}