/*
    Segment Intersection Check
    --------------------------
    Time: O(1)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>

struct Point {
    int x, y;
};

enum Orientation {
    Clockwise = -1, Collinear = 0, Counterclockwise = 1
};

Orientation SegmentOrientation(const Point& A, const Point& B, const Point& C) {
    int crossProduct = (B.y - A.y) * (C.x - B.x) - (C.y - B.y) * (B.x - A.x);
    return (crossProduct == 0) ? (Collinear) : ((crossProduct < 0) ? (Counterclockwise) : (Clockwise));
}

bool IsOnSegment(const Point& A, const Point& B, const Point& C) {
    bool isOnSegment = (C.x >= std::min(A.x, B.x) && C.x <= std::max(A.x, B.x)) &&
        (C.y >= std::min(A.y, B.y) && C.y <= std::max(A.y, B.y));
    return isOnSegment;
}

bool SegmentIntersectionCheck(const Point& A, const Point& B, const Point& C, const Point& D) {
    bool doIntersect = false;
    Orientation orient_1 = SegmentOrientation(A, B, C), orient_2 = SegmentOrientation(A, B, D),
        orient_3 = SegmentOrientation(C, D, A), orient_4 = SegmentOrientation(C, D, B);
    if (orient_1 != orient_2 && orient_3 != orient_4 ||
        orient_1 == Orientation::Collinear && IsOnSegment(A, B, C) ||
        orient_2 == Orientation::Collinear && IsOnSegment(A, B, D) ||
        orient_3 == Orientation::Collinear && IsOnSegment(C, D, A) ||
        orient_4 == Orientation::Collinear && IsOnSegment(C, D, B))
        doIntersect = true;
    return doIntersect;
}

int main() {
    Point A, B, C, D;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    std::cout << std::boolalpha << SegmentIntersectionCheck(A, B, C, D) << std::endl;

    return EXIT_SUCCESS;
}