#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
#define R 1000000007
#define M 998244353

vector<vector<int> > v;
vector<int> li;

struct lib {
    int n, t, m, i, ts;
    vector<int> id;
    bool operator < (struct lib o) {
        int score = ((float)ts / n) * m / pow(t, 5);
        int score2 = ((float)o.ts / o.n) * o.m / pow(o.t, 5);
        return score > score2;
    }
};


vector<int> s;


bool comp(int a, int b)
{
    return s[a] > s[b];
}

int main()
{
    int b, l, d;
    cin >> b >> l >> d;
    vector<bool> exist(b, true);
    lib libs[l];
    s.resize(b);
    for(int i = 0; i < b; i++)
        cin >> s[i];
    

    vector<int> freq(b, 0);

    int L = l;
    for(int x = 0; x < l; ++x)
    {
        int n, t, m, q, ts = 0;
        cin >> n >> t >> m;
        vector<int> id;
        for(int i = 0; i < n; i++) {
            cin >> q;
            freq[q]++;
            ts += s[q];
            id.push_back(q);
        }

        sort(id.begin(), id.end(), comp);

        libs[x] = {n, t, m, x, ts, id};
    }


    for(int i = 0; i < l; ++i) {
        int ts = 0;
        for(int j = 0; j < libs[i].n; ++j) {
            ts += s[libs[i].id[j]]/freq[libs[i].id[j]];
        }
        libs[i].ts = ts;
    }

    sort(libs, libs + l);


    // int pres = 0;
    // while(l--) {
    //     int ts = 0;
    //     int cl = L-l-1;
    //     vector<int> zs;
    //     int count = 0;
    //     pres += libs[cl].t;
    //     for(int i = 0; i < libs[cl].n; i++) {
    //         if(count < libs[cl].m*(d-pres)) {
    //             if(exist[libs[cl].id[i]]) {
    //                 zs.push_back(libs[cl].id[i]);
    //                 exist[libs[cl].id[i]] = false;
    //                 ts += s[libs[cl].id[i]];
    //                 ++count;
    //             }
    //         } else {
    //             break;
    //         }
    //     }
    //     libs[cl].ts = ts;
    //     libs[cl].n = zs.size();
    //     libs[cl].id = zs;
    // }

    // sort(libs, libs + L);

    // exist.assign(b, true);
    int pre = 0;
    l = L;
    while(l--) {
        int cl = L-l-1;
        vector<int> z;
        int count = 0;
        pre += libs[cl].t;
        for(int i = 0; i < libs[cl].n; i++) {
            if(count < libs[cl].m*(d-pre)) {
                if(exist[libs[cl].id[i]]) {
                    z.push_back(libs[cl].id[i]);
                    exist[libs[cl].id[i]] = false;
                    ++count;
                }
            } else {
                break;
            }
        }
        if(z.size() > 0) {
            li.push_back(libs[cl].i);
            v.push_back(z);
        }
    }

    cout << li.size() << '\n';


    for(int i = 0; i < li.size(); ++i) {
        cout << li[i] << ' ' << v[i].size() << '\n';
        for(int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}