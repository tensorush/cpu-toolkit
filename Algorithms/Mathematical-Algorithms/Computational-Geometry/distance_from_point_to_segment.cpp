/*
    Distance From Point To Segment
    ------------------------------
    Time: O(1)
    Space: O(1)
*/
#include <iostream>
#include <cmath>

struct Point {
    double x, y, z;
};

struct Vector {
    double x, y, z;
};

double DistanceFromPointToSegment(const Point& A, const Point& B, const Point& C) {
    Vector AB = { B.x - A.x, B.y - A.y, B.z - A.z }, AC = { C.x - A.x, C.y - A.y, C.z - A.z };
    Vector crossProduct = { AB.y * AC.z - AC.y * AB.z,
                            AB.x * AC.z - AC.x * AB.z,
                            AB.x * AC.y - AC.x * AB.y };
    double directedArea = std::hypot(crossProduct.x, crossProduct.y, crossProduct.z),
        distanceFromCToAB = directedArea / std::hypot(AB.x, AB.y, AB.z);
    return distanceFromCToAB;
}

int main() {
    Point A, B, point;
    std::cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> point.x >> point.y >> point.z;
    std::cout << DistanceFromPointToSegment(A, B, point) << std::endl;

    return EXIT_SUCCESS;
}