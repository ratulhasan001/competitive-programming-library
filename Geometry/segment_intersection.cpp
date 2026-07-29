#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

double cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool onSegment(Point p, Point q, Point r) {
    return min(p.x, r.x) <= q.x && q.x <= max(p.x, r.x) &&
           min(p.y, r.y) <= q.y && q.y <= max(p.y, r.y);
}

int sign(double x) {
    if (x > 1e-9) return 1;
    if (x < -1e-9) return -1;
    return 0;
}

// true if segment p1p2 intersects segment p3p4 (including touching endpoints)
bool segmentsIntersect(Point p1, Point p2, Point p3, Point p4) {
    int d1 = sign(cross(p3, p4, p1));
    int d2 = sign(cross(p3, p4, p2));
    int d3 = sign(cross(p1, p2, p3));
    int d4 = sign(cross(p1, p2, p4));

    if (d1 != d2 && d3 != d4) return true;

    if (d1 == 0 && onSegment(p3, p1, p4)) return true;
    if (d2 == 0 && onSegment(p3, p2, p4)) return true;
    if (d3 == 0 && onSegment(p1, p3, p2)) return true;
    if (d4 == 0 && onSegment(p1, p4, p2)) return true;

    return false;
}

int32_t main() {
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << (segmentsIntersect(p1, p2, p3, p4) ? "Yes" : "No") << endl;
    return 0;
}
