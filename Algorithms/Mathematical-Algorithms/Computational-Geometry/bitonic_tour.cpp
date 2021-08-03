/*
    Bitonic Tour
    -------------
    Time: O(n^2)
    Space: O(n^2)
*/
#include <algorithm>
#include <iostream> 
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

double EuclideanDistance(const Point& A, const Point& B) {
    return std::hypot(A.x - B.x, A.y - B.y);
};

double BitonicTour(const std::vector<Point>& points) {
    // TODO: Fix implementation
    unsigned n = points.size();
    std::sort(points.begin(), points.end(), [](const Point& A, const Point& B) {
        return A.x < B.x;
    });
    std::vector<std::vector<double>> bitonicDistances(n, std::vector<double>(n, -1));
    bitonicDistances.front().front() = 0;
    for (unsigned i = 1; i < n; ++i) {
        bitonicDistances.front()[i] = bitonicDistances.front()[i - 1] + EuclideanDistance(points[i - 1], points[i]);
    }
    double min;
    for (unsigned i = 1; i < n; ++i) {
        for (unsigned j = i; j < n; ++j) {
            min = std::numeric_limits<double>::max();
            if (i == j || i == j - 1) {
                for (unsigned k = 0; k < i; ++k) {
                    min = std::min(min, bitonicDistances[k][i] + EuclideanDistance(points[k], points[j]));
                }
                bitonicDistances[i][j] = min;
            } else {
                bitonicDistances[i][j] = bitonicDistances[i][j - 1] + EuclideanDistance(points[j - 1], points[j]);
            }
        }
    }
    return bitonicDistances[n - 1][n - 1];
}

int main() {
    unsigned numPoints;
    std::vector<Point> points(numPoints);
    for (auto& [x, y] : points) {
        std::cin >> x >> y;
    }
    std::cout << BitonicTour(points) << std::endl;

    return EXIT_SUCCESS;
}