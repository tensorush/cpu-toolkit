/*
    Angle Between Vectors
    ---------------------
    Time: O(1)
    Space: O(1)
*/
#include <iostream>
#include <cmath>

struct Vector {
    double x, y, z;
};

double AngleBetweenVectors(const Vector& U, const Vector& V) {
    double dotProduct = U.x * V.x + U.y * V.y + U.z * V.z;
    Vector crossProduct = { U.y * V.z - V.y * U.z,
                            U.x * V.z - V.x * U.z,
                            U.x * V.y - V.x * U.y };
    double directedArea = std::hypot(crossProduct.x, crossProduct.y, crossProduct.z);
    return std::atan2(directedArea, dotProduct);
}

int main() {
    Vector U, V;
    std::cin >> U.x >> U.y >> U.z >> V.x >> V.y >> V.z;
    std::cout << AngleBetweenVectors(U, V) << std::endl;

    return EXIT_SUCCESS;
}