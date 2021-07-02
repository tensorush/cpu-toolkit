/*
    Birthday Paradox
    ------------------
    Time: O(numPeople)
    Space: O(1)
*/
#include <iostream>
#include <iomanip>

double BirthdayParadox(unsigned numDays, unsigned numPeople) {
    double unoccupiedDays = numDays, noMatchProbability = 1;
    while (--numPeople)
        noMatchProbability *= --unoccupiedDays / numDays;
    double matchProbability = 1 - noMatchProbability;
    return matchProbability;
}

int main() {
    unsigned numDays, numPeople;
    std::cin >> numDays >> numPeople;
    std::cout << std::setprecision(3) << std::fixed
        << BirthdayParadox(numDays, numPeople) << std::endl;

    return EXIT_SUCCESS;
}