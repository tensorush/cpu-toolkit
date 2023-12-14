/*
    Distance From Point To Segment
    ------------------------------
    Time: O(1)
    Space: O(1)
*/
#include <iostream>
#include <cmath>

struct Point2D {
    double x, y;
};

struct Point3D {
    double x, y, z;
};

struct Vector2D {
    double x, y;
};

struct Vector3D {
    double x, y, z;
};

double DistanceFromPointToSegmentIn2D(const Point2D& A, const Point2D& B, const Point2D& C) {
    Vector2D AB = { B.x - A.x, B.y - A.y }, CA = { A.x - C.x, A.y - C.y };
    double doubleTriangleArea = std::abs(AB.x * CA.y - CA.x * AB.y),
        distanceFromCToAB = doubleTriangleArea / std::hypot(AB.x, AB.y);
    return distanceFromCToAB;
}

double DistanceFromPointToSegmentIn3D(const Point3D& A, const Point3D& B, const Point3D& C) {
    Vector3D AB = { B.x - A.x, B.y - A.y, B.z - A.z }, AC = { C.x - A.x, C.y - A.y, C.z - A.z };
    Vector3D crossProduct = { AB.y * AC.z - AC.y * AB.z,
                              AB.x * AC.z - AC.x * AB.z,
                              AB.x * AC.y - AC.x * AB.y };
    double directedArea = std::hypot(crossProduct.x, crossProduct.y, crossProduct.z),
        distanceFromCToAB = directedArea / std::hypot(AB.x, AB.y, AB.z);
    return distanceFromCToAB;
}

int main() {
    Point2D A, B, point2D;
    std::cin >> A.x >> A.y >> B.x >> B.y >> point2D.x >> point2D.y;
    std::cout << DistanceFromPointToSegmentIn2D(A, B, point2D) << std::endl;
    Point3D C, D, point3D;
    std::cin >> C.x >> C.y >> C.z >> D.x >> D.y >> D.z >> point3D.x >> point3D.y >> point3D.z;
    std::cout << DistanceFromPointToSegmentIn3D(C, D, point3D) << std::endl;

    return EXIT_SUCCESS;
}