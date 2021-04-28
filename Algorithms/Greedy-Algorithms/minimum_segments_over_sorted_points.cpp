/*
    Minimum Segments Over Sorted Points
    -----------------------------------
    Time: O(numPoints)
    Space: O(1)
*/
#include <iostream>
#include <vector>

struct Segment {
    double left_end, right_end;
};

auto MinimumSegmentsOverSortedPoints(const std::vector<double>& points, const double& segmentLength) {
    size_t i = 0;
    Segment segment;
    std::vector<Segment> segments;
    while (i < points.size()) {
        segment.left_end = points[i];
        segment.right_end = points[i] + segmentLength;
        segments.emplace_back(segment);
        ++i;
        while (i < points.size() && points[i] <= segment.right_end) ++i;
    }
    return std::make_pair(segments.size(), segments);
}

int main() {
    unsigned numPoints;
    double segmentLength;
    std::cin >> numPoints >> segmentLength;
    std::vector<double> points(numPoints);
    for (double& point : points) {
        std::cin >> point;
    }
    auto [numSegments, segments] = MinimumSegmentsOverSortedPoints(points, segmentLength);
    std::cout << numSegments << std::endl;

    return 0;
}