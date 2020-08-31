#include<bits/stdc++.h>

using namespace std;

struct Infant {
    int idx;
    int a;
    int b;

    Infant(int x, int y, int z) {
        idx = x;
        a = y;
        b = z;
    }
};

vector<Infant> infant;
vector<map<int, int> > mp;
map<int, int> mr;

int main() {
    int n, q;
    cin >> n >> q;
    mp = vector<map<int, int> > (200010);
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        Infant inf(i+1, a, b);
        infant.push_back(inf);
        ++mp[b][a];
    }

    for(int i = 1; i < 200001; ++i) {
        if(mp[i].size() == 0) continue;
        int cmr = mp[i].rbegin()->first;
        mr[cmr]++;
    }
    for(int i = 0; i < q; ++i) {
        int c, d;
        cin >> c >> d;
        int ca = infant[c-1].b, cr = infant[c-1].a;
        if(mr.size() > 0 && mp[ca].size() > 0) {
            if(mr[mp[ca].rbegin()->first] == 1) {
                mr.erase(mp[ca].rbegin()->first);
            } else {
                --mr[mp[ca].rbegin()->first];
            }
        }
        if(mp[ca].size() > 0) {
            if(mp[ca][cr] > 1) {
                --mp[ca][cr];
            } else if(mp[ca][cr] == 1){
                mp[ca].erase(cr);
            }
        }
        if(mp[ca].size() > 0) {
            ++mr[mp[ca].rbegin()->first];
        }
        infant[c-1].b = d;
        if(mp[d].size() > 0 && mr.size() > 0) {
            if(mr[mp[d].rbegin()->first] == 1) {
                mr.erase(mp[d].rbegin()->first);
            } else {
                --mr[mp[d].rbegin()->first];
            }
        }
        mp[d][cr]++;
        if(mp[d].size() > 0) {
            ++mr[mp[d].rbegin()->first];
        }
        cout << mr.begin()->first << '\n';
    }

    return 0;
}

/*
6 3 8 1 6 2 9 3 1 1 2 2 1 3 4 3 2 1 1 2

2 2 4208 1234 3056 5678 1 2020 2 2020
*/