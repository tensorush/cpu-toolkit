/*
    Minimum Refueling Stops
    -----------------------
    Time: O(numStations)
    Space: O(1)
*/
#include <iostream>
#include <vector>

int MinimumRefuelingStops(const std::vector<unsigned>& locations, const unsigned& numStations, const unsigned& tankCapacity) {
    int numStops = 0;
    unsigned curStop = 0;
    while (curStop <= numStations) {
        unsigned lastStop = curStop;
        while (curStop <= numStations && locations[curStop + 1] - locations[lastStop] <= tankCapacity) ++curStop;
        if (curStop == lastStop) return -1; // Impossible
        if (curStop <= numStations) ++numStops;
    }
    return numStops;
}

int main() {
    unsigned numStations, tankCapacity, destination;
    std::cin >> numStations >> tankCapacity >> destination;
    std::vector<unsigned> locations(numStations + 2);
    locations[numStations + 1] = destination;
    for (unsigned i = 1; i <= numStations; ++i) {
        std::cin >> locations[i];
    }
    std::cout << MinimumRefuelingStops(locations, numStations, tankCapacity) << std::endl;

    return 0;
}