/*
    Random Walk
    -----------------
    Time: O(numSteps)
    Space: O(1)
*/
#include <iostream>
#include <random>
#include <array>

void RandomWalk(std::vector<int>& coordinates, const unsigned& numSteps) {
    std::random_device seeder;
    std::mt19937 generator(seeder());
    std::uniform_int_distribution<unsigned> randomDirection(0, 1);
    std::uniform_int_distribution<unsigned> randomAxis(0, coordinates.size() - 1);
    for (unsigned i = 0; i < numSteps; ++i) {
        coordinates[randomAxis(generator)] += (randomDirection(generator)) ? (-1) : (1);
    }
}

int main() {
    unsigned numAxis, numSteps;
    std::cin >> numAxis >> numSteps;
    std::vector<int> coordinates(numAxis);
    RandomWalk(coordinates, numSteps);
    for (const int& coordinate : coordinates) {
        std::cout << coordinate << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}