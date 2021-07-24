/*
    Random Walk
    -----------------
    Time: O(numSteps)
    Space: O(1)
*/
#include <iostream>
#include <random>
#include <array>

constexpr unsigned NUM_DIRECTIONS = 4;
constexpr std::array<std::pair<int, int>, NUM_DIRECTIONS> directions = {
    std::make_pair(0, 1),
    std::make_pair(0, -1),
    std::make_pair(1, 0),
    std::make_pair(-1, 0)
};

void RandomWalk(int& x, int& y, const unsigned& numSteps, std::mt19937& generator, std::uniform_int_distribution<>& randomDirection) {
    unsigned directionIndex;
    for (unsigned i = 0; i < numSteps; ++i) {
        directionIndex = randomDirection(generator);
        x += directions[directionIndex].first;
        y += directions[directionIndex].second;
    }
}

int main() {
    int x, y;
    unsigned numSteps;
    std::cin >> x >> y >> numSteps;
    std::random_device seeder;
    std::mt19937 generator(seeder());
    std::uniform_int_distribution<> randomDirection(0, 3);
    RandomWalk(x, y, numSteps, generator, randomDirection);
    std::cout << x << ' ' << y << std::endl;

    return EXIT_SUCCESS;
}