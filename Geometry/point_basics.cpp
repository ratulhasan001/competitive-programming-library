#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    Point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    long long cross(const Point &p) const { return x * p.y - y * p.x; }
    long long dot(const Point &p) const { return x * p.x + y * p.y; }
};

// > 0 if a->b->c turns left (counter-clockwise), < 0 if right, 0 if collinear
long long cross_product(Point a, Point b, Point c) {
    return (b - a).cross(c - a);
}

int32_t main() {
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    cout << cross_product({ax, ay}, {bx, by}, {cx, cy}) << endl;
    return 0;
}
