#include<bits/stdc++.h>

using namespace std;

struct Point {
    long long x;
    long long y;
    bool operator<(const Point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }

    bool operator<=(const Point &o) const {
        return x < o.x || (x == o.x && y <= o.y);
    }

    bool operator>(const Point &o) const {
        return x > o.x || (x == o.x && y > o.y);
    }

    bool operator>=(const Point &o) const {
        return x > o.x || (x == o.x && y >= o.y);
    }

    bool operator==(const Point &o) const {
        return x == o.x && y == o.y;
    }

    bool operator!=(const Point &o) const {
        return x != o.x || y != o.y;
    }
};

bool is_clockwise(Point a, Point b, Point c) {
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;
}

bool is_anticlockwise(Point a, Point b, Point c) {
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) > 0;
}

vector<Point> point;
set<Point> s;

long long convexHull() {
    vector<Point> s1, s2;
    Point A = point.front(), B = point.back();
    s1.push_back(A);
    s2.push_back(A);
    for(int i = 0; i < point.size(); ++i) {
        if(i + 1 == point.size() || is_clockwise(A, point[i], B)) {
            int sz = s1.size();
            while(sz > 1 && !is_clockwise(s1[sz-2], s1[sz-1], point[i])) {
                s1.pop_back();
                --sz;
            }
            s1.push_back(point[i]);
        }
        if(i + 1 == point.size() || is_anticlockwise(A, point[i], B)) {
            int sz = s2.size();
            while(sz > 1 && !is_anticlockwise(s2[sz-2], s2[sz-1], point[i])) {
                s2.pop_back();
                --sz;
            }
            s2.push_back(point[i]);
        }
    }
    long long ans = 0;
    for(int i = 1; i < s1.size(); ++i) {
        ans += max(abs(s1[i].y - s1[i-1].y), abs(s1[i].x - s1[i-1].x));
    }
    for(int i = 1; i < s2.size(); ++i) {
        ans += max(abs(s2[i].y - s2[i-1].y), abs(s2[i].x - s2[i-1].x));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        s.insert({x, y+1});
        s.insert({x, y-1});
        s.insert({x+1, y});
        s.insert({x-1, y});
    }
    while(s.size()) {
        point.push_back(*s.begin());
        s.erase(s.begin());
    }
    long long ans = convexHull();
    cout << ans << '\n';

    return 0;
}