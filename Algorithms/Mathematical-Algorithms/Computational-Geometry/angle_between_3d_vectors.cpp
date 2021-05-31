/*
    Angle Between 3D Vectors
    ------------------------
    Time: O(1)
    Space: O(1)
*/
#include <iostream>
#include <cmath>

struct Vector {
    double x, y, z;
};

double AngleBetween3DVectors(const Vector& U, const Vector& V) {
    double dotProduct = U.x * V.x + U.y * V.y + U.z * V.z;
    Vector crossProduct;
    crossProduct.x = U.y * V.z - V.y * U.z;
    crossProduct.y = U.x * V.z - V.x * U.z;
    crossProduct.z = U.x * V.y - V.x * U.y;
    double directedArea = sqrt(pow(crossProduct.x, 2) +
                               pow(crossProduct.y, 2) +
                               pow(crossProduct.z, 2));
	return std::atan2(directedArea, dotProduct);
}

int main() {
    Vector U, V;
    std::cin >> U.x >> U.y >> U.z
             >> V.x >> V.y >> V.z;
    std::cout << AngleBetween3DVectors(U, V) << std::endl;

    return EXIT_SUCCESS;
}