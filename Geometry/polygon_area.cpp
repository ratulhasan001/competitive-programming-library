#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

// Shoelace formula; works for any simple polygon (convex or concave)
double polygonArea(vector<Point> &p) {
    int n = p.size();
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(area) / 2.0;
}

// even-odd (ray casting) point-in-polygon test
bool pointInPolygon(vector<Point> &poly, Point pt) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        bool intersects = ((poly[i].y > pt.y) != (poly[j].y > pt.y)) &&
            (pt.x < (poly[j].x - poly[i].x) * (pt.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x);
        if (intersects) inside = !inside;
    }
    return inside;
}

int32_t main() {
    int n;
    cin >> n;
    vector<Point> poly(n);
    for (auto &p : poly) cin >> p.x >> p.y;
    cout << "Area: " << polygonArea(poly) << endl;

    Point q;
    cin >> q.x >> q.y;
    cout << (pointInPolygon(poly, q) ? "Inside" : "Outside") << endl;
    return 0;
}
