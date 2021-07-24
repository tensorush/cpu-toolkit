/*
    Triangle Check
    --------------------------
    |   Segments  |  Points  |
    --------------------------
    | Time: O(1)  |   O(1)   |
    | Space: O(1) |   O(1)   |
    --------------------------
*/
#include <iostream>

struct Point {
    int x, y;
};

bool TriangleCheckForSegments(const unsigned& A, const unsigned& B, const unsigned& C) {
    bool isTriangle = false;
    if (A + B > C && A + C > B && B + C > A)
        isTriangle = true;
    return isTriangle;
}

bool TriangleCheckForPoints(const Point& A, const Point& B, const Point& C) {
    bool isTriangle = true;
    int crossProduct = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (crossProduct == 0)
        isTriangle = false;
    return isTriangle;
}

int main() {
    unsigned segment_1, segment_2, segment_3;
    std::cin >> segment_1 >> segment_2 >> segment_3;
    std::cout << std::boolalpha << TriangleCheckForSegments(segment_1, segment_2, segment_3) << std::endl;

    Point point_1, point_2, point_3;
    std::cin >> point_1.x >> point_1.y >> point_2.x >> point_2.y >> point_3.x >> point_3.y;
    std::cout << std::boolalpha << TriangleCheckForPoints(point_1, point_2, point_3) << std::endl;

    return EXIT_SUCCESS;
}