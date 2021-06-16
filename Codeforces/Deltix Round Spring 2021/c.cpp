#include <bits/stdc++.h>

using namespace std;

void print_item(vector<int> &v) {
    printf("%d", v[0]);
    for (int i = 1; i < v.size(); ++i) {
        printf(".%d", v[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m = -1;
        scanf("%d", &n);
        vector<int> a(n);
        for (int &i : a) {
            scanf("%d", &i);
        }
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (v.empty()) {
                v.push_back(a[i]);
                ++m;
            } else {
                if (a[i] == 1) {
                    v.push_back(1);
                    ++m;
                } else {
                    while (m >= 0 && a[i] != v[m] + 1) {
                        v.pop_back();
                        --m;
                    }
                    ++v[m];
                }
            }
            print_item(v);
        }
    }
    return 0;
}