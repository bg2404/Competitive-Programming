#include<bits/stdc++.h>

using namespace std;

struct Point {
    long long x;
    long long y;
    long long idx;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

bool cmp_x(const Point &p1, const Point &p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool cmp_y(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

double dist(Point a, Point b) {
    return sqrt( (double)(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

pair<double, pair<long long, long long> > rec(vector<Point> &px, vector<Point> &py, long long l, long long r) {
    if(l + 1 == r) {
        return { dist(px[l], px[r]), {l, r} };
    }

    if(l + 2 == r) {
        double md = dist(px[l], px[l+1]);
        pair<long long, long long> cp = {l, l+1};
        double d = dist(px[l+1], px[r]);
        if(d < md) {
            md = d;
            cp = {l+1, r};
        }
        d = dist(px[l], px[r]);
        if(d < md) {
            md = d;
            cp = {l, r};
        }
        return {md, cp};
    }

    long long m = l +  (r-l)/2;

    vector<Point> pyl, pyr, qyl, qyr;
    for(Point p: py) {
        if(p.idx <= m) {
            pyl.push_back(p);
        } else {
            pyr.push_back(p);
        }
    }

    auto left = rec(px, pyl, l, m);
    auto right = rec(px, pyr, m+1, r);

    double md;
    pair<long long, long long> cp;
    if(left.first < right.first) {
        md = left.first;
        cp = left.second;
    } else {
        md = right.first;
        cp = right.second;
    }

    for(auto p: pyl) {
        if(px[m].x - p.x < md) {
            qyl.push_back(p);
        }
    }

    for(auto p: pyr) {
        if(p.x - px[m].x < md) {
            qyr.push_back(p);
        }
    }
    double d;
    long long j = 0;
    for(long long i = 0; i < qyl.size(); ++i) {
        while(j < qyr.size()) {
            if(qyr[j].y < qyl[i].y)
                ++j;
            else
                break;
        }
        for(long long k = -4; k < 4; ++k) {
            if(j + k >= 0 && j + k < qyr.size()) {
                d = dist(qyl[i], qyr[j+k]);
                if(d < md) {
                    md = d;
                    cp = {qyl[i].idx, qyr[j+k].idx};
                }
            }
        }
    }

    return {md, cp};
}

pair<long long, long long> closest_pair_of_points(vector<Point> &p) {
    if(p.size() == 2) {
        return {0, 1};
    }
    vector<Point> px = p, py;
    sort(px.begin(), px.end(), cmp_x);
    for(long long i = 0; i < px.size(); ++i) {
        px[i].idx = i;
    }
    py = px;
    sort(py.begin(), py.end(), cmp_y);
    auto ans = rec(px, py, 0, p.size()-1);
    Point p1 = px[ans.second.first], p2 = px[ans.second.second];
    long long a = -1, b = -1;
    for(long long i = 0; i < p.size(); ++i) {
        if(p1 == p[i]) {
            a = i;
        } else if(p2 == p[i]) {
            b = i;
        }
    }
    if(a > b) {
        swap(a, b);
    }
    return {a, b};
}

signed main() {
    long long n;
    cin >> n;
    if(n == 0) {
        return 0;
    }
    vector<Point> p(n);
    for(auto &i: p) {
        cin >> i.x >> i.y;
        i.idx = -1;
    }
    if(n == 1) {
        return 0;
    }
    pair<long long, long long> cp = closest_pair_of_points(p);
    int a = cp.first, b = cp.second;
    double c = dist(p[a], p[b]);
    cout << a << ' ' << b << ' ' << fixed << setprecision(6) << c << '\n';
    return 0;
}
/*
6
2 3
12 30
40 50
5 1
12 10
3 4

6 2 3 12 30 40 50 5 1 12 10 3 4

10
5000000 9000000
0 0
10000000 5000000
4000000 1000000
2000000 2000000
3000000 3000000
7000000 8000000
11000000 12000000
10000000 10000000
5000000 10000000
*/