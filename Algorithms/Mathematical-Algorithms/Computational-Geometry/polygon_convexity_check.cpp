/*
    Polygon Convexity Check
    -----------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

bool PolygonConvexityCheck(const std::vector<Point>& polygon) {
    unsigned n = polygon.size();
    Point A = polygon[0], B = polygon[1], C = polygon[2];
    int crossProduct = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    bool isConvex = true, isClockwise = (crossProduct <= 0) ? (true) : (false);
    for (unsigned i = 3; i < n; ++i) {
        A = B, B = C, C = polygon[i];
        crossProduct = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
        if (isClockwise && crossProduct > 0 || isClockwise == false && crossProduct < 0) {
            isConvex = false;
            break;
        }
    }
    return isConvex;
}

int main() {
    unsigned numPolygonVertices;
    std::cin >> numPolygonVertices;
    std::vector<Point> polygon(numPolygonVertices);
    for (auto& [x, y] : polygon) {
        std::cin >> x >> y;
    }
    std::cout << std::boolalpha << PolygonConvexityCheck(polygon) << std::endl;

    return EXIT_SUCCESS;
}