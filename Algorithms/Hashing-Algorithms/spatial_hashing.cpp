/*
    Spatial Hashing
    ---------------
*/
#include <iostream>

int main() {
    int x, y, z, cellSize;
    std::cin >> x >> y >> z >> cellSize;

    // Hash function for collision detection of deformable tetrahedral meshes
    // Source: http://www.beosil.com/download/CollisionDetectionHashing_VMV03.pdf
    constexpr long long PRIME_X = 73856093, PRIME_Y = 19349663, PRIME_Z = 83492791;
    long long hash = ((x / cellSize) * PRIME_X) ^ ((y / cellSize) * PRIME_Y) ^ ((z / cellSize) * PRIME_Z);

    return EXIT_SUCCESS;
}