/*
    Segments Intersection Check
    ---------------------------
    Time: O(1)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <string>

struct Point
{
    int x, y;
};

enum Orientation
{
    Clockwise = -1,
    Collinear = 0,
    Counterclockwise = 1
};

int SegmentsOrientation(const Point &A, const Point &B, const Point &C)
{
    int val = (B.y - A.y) * (C.x - B.x) - (C.y - B.y) * (B.x - A.x);
    return (val == 0) ? (Collinear) : ((val < 0) ? (Counterclockwise) : (Clockwise));
}

bool OnSegment(const Point &A, const Point &B, const Point &C)
{
    bool onSegment = (C.x >= std::min(A.x, B.x) && C.x <= std::max(A.x, B.x)) &&
                     (C.y >= std::min(A.y, B.y) && C.y <= std::max(A.y, B.y));
    return onSegment;
}

bool SegmentsIntersectionCheck(const Point &A, const Point &B, const Point &C, const Point &D)
{
    bool doIntersect = false;
    int orient_1 = SegmentsOrientation(A, B, C), orient_2 = SegmentsOrientation(A, B, D),
        orient_3 = SegmentsOrientation(C, D, A), orient_4 = SegmentsOrientation(C, D, B);
    if (orient_1 != orient_2 && orient_3 != orient_4 ||
        orient_1 == 0 && OnSegment(A, B, C) ||
        orient_2 == 0 && OnSegment(A, B, D) ||
        orient_3 == 0 && OnSegment(C, D, A) ||
        orient_4 == 0 && OnSegment(C, D, B))
        doIntersect = true;
    return doIntersect;
}

int main()
{
    Point A, B, C, D;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    std::cout << std::boolalpha << SegmentsIntersectionCheck(A, B, C, D) << std::endl;

    return EXIT_SUCCESS;
}