#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    long long cross(const Point &p) const { return x * p.y - y * p.x; }
};

long long cross_product(Point a, Point b, Point c) {
    return (b - a).cross(c - a);
}

// Andrew's monotone chain, returns hull points in counter-clockwise order
vector<Point> convex_hull(vector<Point> points) {
    int n = points.size();
    if (n <= 2) return points;
    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    int lower_hull_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)hull.size() > lower_hull_size &&
               cross_product(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

int32_t main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (auto &p : points) cin >> p.x >> p.y;
    vector<Point> hull = convex_hull(points);
    for (auto &p : hull) cout << p.x << " " << p.y << "\n";
    return 0;
}
