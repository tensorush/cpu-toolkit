/*
    Minkowski Distance
    ----------------------------------------------------------------
    | Manhattan Distance | Euclidean Distance | Chebyshev Distance |
    ----------------------------------------------------------------
    | Time: O(dimension) |    O(dimension)    |    O(dimension)    |
    | Space: O(1)        |        O(1)        |        O(1)        |
    ----------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <cmath>

enum class Norm {Manhattan = 1, Euclidean = 2, Chebyshev = 3};

struct Point {
    Point(const size_t& dimension) : coordinates(dimension) {};
    std::vector<double> coordinates;
};

double DistanceBetweenPoints(const Norm& norm, const Point& A, const Point& B) {
    double distance = 0;
    size_t dimension = A.coordinates.size();
    switch (norm) {
        case Norm::Manhattan:
            for (unsigned i = 0; i < dimension; ++i) {
                distance += abs(A.coordinates[i] - B.coordinates[i]);
            }
            break;
        case Norm::Euclidean:
            for (unsigned i = 0; i < dimension; ++i) {
                distance += pow(A.coordinates[i] - B.coordinates[i], 2);
            }
            distance = sqrt(distance);
            break;
        case Norm::Chebyshev:
            for (unsigned i = 0; i < dimension; ++i) {
                if (abs(A.coordinates[i] - B.coordinates[i]) > distance) distance = abs(A.coordinates[i] - B.coordinates[i]);
            }
    }
	return distance;
}

int main() {
    unsigned norm;
    size_t dimension;
    std::cin >> norm >> dimension;
    Point A(dimension), B(dimension);
    for (size_t i = 0; i < dimension; ++i) {
        std::cin >> A.coordinates[i];
    }
    for (size_t i = 0; i < dimension; ++i) {
        std::cin >> B.coordinates[i];
    }
    std::cout << DistanceBetweenPoints(static_cast<Norm>(norm), A, B) << std::endl;

    return EXIT_SUCCESS;
}