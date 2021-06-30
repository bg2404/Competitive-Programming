#include<bits/stdc++.h>
#define BICARP "Bicarp"
#define MONOCARP "Monocarp"

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum_1 = 0, sum_2 = 0, num_1 = 0, num_2 = 0;
    for(int i = 0; i < n/2; ++i) {
        if(s[i] == '?') {
            num_1++;
        } else {
            sum_1 += s[i] - '0';
        }
    }
    for(int i = n/2+1; i < n; ++i) {
        if(s[i] == '?') {
            num_2++;
        } else {
            sum_2 += s[i] - '0';
        }
    }

    if(num_1 == num_2) {
        if(sum_1 == sum_2) {
            cout << BICARP << '\n';
        } else {
            cout << MONOCARP << '\n';
        }
    } else {
        if(num_1 > num_2) {
            if(sum_1 >= sum_2) {
                cout << MONOCARP << '\n';
            } else {
                
            }
        } else {
            if(sum_1 <= sum_2) {
                cout << MONOCARP << '\n';
            }
        }
    }
    return 0;
}