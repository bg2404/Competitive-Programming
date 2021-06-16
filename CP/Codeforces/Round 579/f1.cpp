#include<bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>&a, const pair<int,int>&b) {
    return a.first + a.second > b.first + b.second;
}
int main() {
    int n, r;
    cin >> n >> r;

    vector< pair<int, int> > p(n), skipped;
    for(int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());

    bool possible = true;
    for(int i = 0; i < n; ++i) {
        if(p[i].second >= 0) {
            if(p[i].first <= r) {
                r += p[i].second;
            } else {
                possible = false;
                break;
            }
        } else {
            p[i].first = max(p[i].first, abs(p[i].second));
            skipped.push_back(p[i]);
        }
    }
    if(possible) {
        sort(skipped.begin(), skipped.end(), compare);
    }

    for(uint32_t i = 0; possible && i < skipped.size(); ++i) {
        if(p[i].first <= r) {
            r += p[i].second;
        } else {
            possible = false;
        }

        if(r < 0) {
            possible = false;
        }
    }

    if(possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}