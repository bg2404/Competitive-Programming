#include<bits/stdc++.h>

using namespace std;

string s, t;
vector<pair<int, int> > ans;

int main() {
    int n;
    cin >> n;
    cin >> s >> t;
    int possible = true;
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'b' && t[i] == 'a') {
            int j = i+1;
            while(j < n) {
                if(s[j] == 'b' && t[j] == 'a') {    
                    ans.push_back(make_pair(i,j));
                    break;
                }
                j++;
            }
            if(j == n) {
                char temp = s[i];
                s[i] = t[i];
                t[i] = temp;
                ans.push_back(make_pair(i,i));
                break;
            }
            i = j;
        }
    }

    for(int i = 0; i < n; ++i) {
        if(s[i] == 'a' && t[i] == 'b') {
            int j = i+1;
            while(j < n) {
                if(s[j] == 'a' && t[j] == 'b') {
                    ans.push_back(make_pair(i,j));
                    break;
                }
                j++;
            }
            if(j == n) {
                possible = false;
                break;
            }
            i = j;
        }
    }
    if(!possible) {
        cout << -1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size() && possible; ++i) {
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
        }
    }   

    return 0;
}