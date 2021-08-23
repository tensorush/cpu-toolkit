/*
    Spatial Hashing
    ---------------
*/
#include <iostream>

int main() {
    int x, y, z, cellSize;
    std::cin >> x >> y >> z >> cellSize;

    // Hash function for permutation of 32-bit integers
    // Source: https://www.cs.ubc.ca/~rbridson/docs/schechter-sca08-turbulence.pdf
    constexpr unsigned long PRIME_1 = 2747636419, PRIME_2 = 2654435769, TWO_TO_POWER_OF_THIRTY_TWO = 1 << 32;
    int hash_1 = ((x ^ PRIME_1) * PRIME_2) % TWO_TO_POWER_OF_THIRTY_TWO;
    hash_1 = ((hash_1 ^ (hash_1 >> 16)) * PRIME_2) % TWO_TO_POWER_OF_THIRTY_TWO;
    hash_1 = ((hash_1 ^ (hash_1 >> 16)) * PRIME_2) % TWO_TO_POWER_OF_THIRTY_TWO;

    // Hash function for collision detection of deformable tetrahedral meshes
    // Source: http://www.beosil.com/download/CollisionDetectionHashing_VMV03.pdf
    constexpr long long PRIME_X = 73856093, PRIME_Y = 19349663, PRIME_Z = 83492791;
    int hash_2 = ((x / cellSize) * PRIME_X) ^ ((y / cellSize) * PRIME_Y) ^ ((z / cellSize) * PRIME_Z);

    return EXIT_SUCCESS;
}