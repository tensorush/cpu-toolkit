/*
    Triangle Type By Angles
    --------------------------
    |    Sides    | Vertices |
    --------------------------
    | Time: O(1)  |   O(1)   |
    | Space: O(1) |   O(1)   |
    --------------------------
*/
#include <algorithm>
#include <iostream>
#include <vector>

enum TriangleType {
    Acute = 0, Right = 1, Obtuse = 2
};

struct Vertex {
    int x, y;
};

struct Vector {
    int x, y;
};

TriangleType TriangleTypeByAnglesForSides(const unsigned& A, const unsigned& B, const unsigned& C) {
    TriangleType triangleType = TriangleType::Right;
    std::vector<unsigned> sidesSortedAndSquared = { A, B, C };
    std::sort(sidesSortedAndSquared.begin(), sidesSortedAndSquared.end());
    for (unsigned& side : sidesSortedAndSquared) {
        side *= side;
    }
    if (sidesSortedAndSquared[2] < sidesSortedAndSquared[0] + sidesSortedAndSquared[1])
        triangleType = TriangleType::Acute;
    else if (sidesSortedAndSquared[2] > sidesSortedAndSquared[0] + sidesSortedAndSquared[1])
        triangleType = TriangleType::Obtuse;
    return triangleType;
}

TriangleType TriangleTypeByAnglesForVertices(const Vertex& A, const Vertex& B, const Vertex& C) {
    TriangleType triangleType = TriangleType::Right;
    Vector AB = { B.x - A.x, B.y - A.y }, AC = { C.x - A.x, C.y - A.y }, BC = { C.x - B.x, C.y - B.y };
    int dotProductA = AB.x * AC.x + AB.y * AC.y, dotProductB = -AB.x * BC.x - AB.y * BC.y, dotProductC = AC.x * BC.x + AC.y * BC.y;
    int dotProducts = dotProductA * dotProductB * dotProductC;
    if (dotProducts > 0)
        triangleType = TriangleType::Acute;
    else if (dotProducts < 0)
        triangleType = TriangleType::Obtuse;
    return triangleType;
}

int main() {
    unsigned side_1, side_2, side_3;
    std::cin >> side_1 >> side_2 >> side_3;
    std::cout << TriangleTypeByAnglesForSides(side_1, side_2, side_3) << std::endl;

    Vertex vertex_1, vertex_2, vertex_3;
    std::cin >> vertex_1.x >> vertex_1.y >> vertex_2.x >> vertex_2.y >> vertex_3.x >> vertex_3.y;
    std::cout << TriangleTypeByAnglesForVertices(vertex_1, vertex_2, vertex_3) << std::endl;

    return EXIT_SUCCESS;
}