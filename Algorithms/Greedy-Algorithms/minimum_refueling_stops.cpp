/*
    Minimum Refueling Stops
    -----------------------
    Time: O(numStations)
    Space: O(1)
*/
#include <iostream>
#include <vector>

int MinimumRefuelingStops(const std::vector<size_t>& locations, const size_t& numStations, const size_t& tankCapacity) {
    int numStops = 0;
    size_t curStop = 0;
    while (curStop <= numStations) {
        size_t lastStop = curStop;
        while (curStop <= numStations && locations[curStop + 1] - locations[lastStop] <= tankCapacity) {
            ++curStop;
        }
        if (curStop == lastStop) return -1; // Impossible
        if (curStop <= numStations) ++numStops;
    }
    return numStops;
}

int main() {
    size_t numStations, tankCapacity, destination;
    std::cin >> numStations >> tankCapacity >> destination;
    std::vector<size_t> locations(numStations + 2);
    locations[numStations + 1] = destination;
    for (size_t i = 1; i <= numStations; ++i) {
        std::cin >> locations[i];
    }
    std::cout << MinimumRefuelingStops(locations, numStations, tankCapacity) << std::endl;

    return 0;
}