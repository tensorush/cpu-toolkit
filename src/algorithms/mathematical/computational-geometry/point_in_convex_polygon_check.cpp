/*
    Point In Convex Polygon Check
    -----------------------------
    Time: O(log(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

enum Orientation {
    Clockwise = -1, Collinear = 0, Counterclockwise = 1
};

bool IsCounterclockwise(const Point& A, const Point& B, const Point& point) {
    int crossProduct = (B.y - A.y) * (point.x - B.x) - (point.y - B.y) * (B.x - A.x);
    Orientation orient = (crossProduct == 0) ? (Collinear) : ((crossProduct < 0) ? (Counterclockwise) : (Clockwise));
    bool isLeftOriented = (orient == Orientation::Collinear || orient == Orientation::Counterclockwise);
    return isLeftOriented;
}

bool IsInTriangle(const Point& A, const Point& B, const Point& C, const Point& point) {
    bool isInTriangle = (IsCounterclockwise(point, A, B) == IsCounterclockwise(point, B, C)
        && IsCounterclockwise(point, B, C) == IsCounterclockwise(point, C, A));
    return isInTriangle;
}

bool LeftmostBinarySearch(const Point& point, const std::vector<Point>& polygon, unsigned low, unsigned high) {
    while (low < high - 1) {
        unsigned mid = low + (high - low) / 2;
        (IsCounterclockwise(polygon.front(), polygon[mid], point)) ? (low) : (high) = mid;
    }
    return low;
}

bool PointInConvexPolygonCheck(const Point& point, const std::vector<Point>& polygon) {
    unsigned position = LeftmostBinarySearch(point, polygon, 1, polygon.size() - 1);
    bool isPointInConvexPolygon = IsInTriangle(polygon.front(), polygon[position], polygon[position + 1], point);
    return isPointInConvexPolygon;
}

int main() {
    Point point;
    unsigned numPolygonVertices;
    std::cin >> point.x >> point.y >> numPolygonVertices;
    std::vector<Point> polygon(numPolygonVertices);
    for (auto& [x, y] : polygon) {
        std::cin >> x >> y;
    }
    std::cout << std::boolalpha << PointInConvexPolygonCheck(point, polygon) << std::endl;

    return EXIT_SUCCESS;
}