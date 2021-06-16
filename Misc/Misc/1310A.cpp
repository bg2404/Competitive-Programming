#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Category {
    int count;
    int time;

    bool operator<(const Category &o) const {
        return count < o.count || (count == o.count && time < o.time);
    }
};

int main() {
    int n;
    cin >> n;
    vector<Category> category(n);
    for (int i = 0; i < n; ++i) {
        cin >> category[i].count;
    }
    for (int i = 0; i < n; ++i) {
        cin >> category[i].time;
    }
    sort(category.begin(), category.end());

    long long time = 0, ans = 0;
    priority_queue<int> pq;
    int i = 0, j;
    for (int i = 0; i < n; ++i) {
        pq.emplace(category[i].time);
        time += category[i].time;
        while (i + 1 < n && category[i + 1].count == category[i].count) {
            ++i;
            pq.emplace(category[i].time);
            time += category[i].time;
        }
        while (!pq.empty() && i + 1 < n && category[i].count + 1 <= category[i + 1].count) {
            time -= pq.top();
            ans += time;
            pq.pop();
            ++category[i].count;
        }
    }
    while (!pq.empty()) {
        time -= pq.top();
        ans += time;
        pq.pop();
    }
    cout << ans << '\n';
}