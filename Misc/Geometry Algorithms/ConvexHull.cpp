#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator<(const Point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

bool isRightTurn(Point p1, Point p2, Point p3) {
    return (p3.y - p2.y) * (p2.x - p1.x) < (p2.y - p1.y) * (p3.x - p2.x);
}

vector<Point> getConvexHull(vector<Point> &points) {
    int n = (int)points.size();
    if (n <= 3) {
        return points;
    } else {
        sort(points.begin(), points.end());
        //Upper half
        vector<Point> convex_hull({points[0], points[1]});
        int m = 2;
        for (int i = 2; i < n; ++i) {
            while (m > 1 && !isRightTurn(convex_hull[m - 2], convex_hull[m - 1], points[i])) {
                convex_hull.pop_back();
                --m;
            }
            convex_hull.push_back(points[i]);
            ++m;
        }
        // Lower half
        vector<Point> lower_half({points[n - 1], points[n - 2]});
        m = 2;
        for (int i = n - 3; i >= 0; --i) {
            while (m > 1 && !isRightTurn(lower_half[m - 2], lower_half[m - 1], points[i])) {
                lower_half.pop_back();
                --m;
            }
            lower_half.push_back(points[i]);
            ++m;
        }

        // Combining them
        convex_hull.insert(convex_hull.end(), lower_half.begin() + 1, lower_half.end() - 1);
        return convex_hull;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    vector<Point> convex_hull = getConvexHull(points);
    for (Point p : convex_hull) {
        printf("(%d, %d)\n", p.x, p.y);
    }
    return 0;
}