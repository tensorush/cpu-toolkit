/*
    Shoelace Algorithm
    ------------------
    Time: O(dimension)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
struct Point {
    T x, y;
};

template<typename T>
double ShoelaceAlgorithm(const std::vector<Point<T>>& polygon) {
    size_t dimension = polygon.size() - 1;
    double polygonArea = polygon[0].x * (polygon[1].y - polygon[dimension].y) +
                         polygon[dimension].x * (polygon[0].y - polygon[dimension - 1].y);
    for (size_t i = 1; i < dimension; ++i) {
        polygonArea += polygon[i].x * (polygon[i + 1].y - polygon[i - 1].y);
    }
	return abs(polygonArea) / 2;
}

int main() {
    size_t dimension;
    std::cin >> dimension;
    std::vector<Point<double>> polygon(dimension);
    for (size_t i = 0; i < dimension; ++i) {
        std::cin >> polygon[i].x >> polygon[i].y;
    }
    std::cout << ShoelaceAlgorithm(polygon) << std::endl;

    return EXIT_SUCCESS;
}