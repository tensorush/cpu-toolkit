/*
    Interval Scheduling
    ---------------------------------------
    Time: O(numIntervals*log(numIntervals))
    Space: O(numIntervals)
*/
#include <algorithm>
#include <iostream>
#include <vector>

struct Interval {
    unsigned start, end, value;
};

unsigned IntervalScheduling(std::vector<Interval>& intervals) {
    unsigned numIntervals = intervals.size();
    std::sort(intervals.begin(), intervals.end(), [](const Interval& interval_1, const Interval& interval_2) {
        return (interval_1.end < interval_2.end);
    });
    std::vector<unsigned> maxValues(numIntervals + 1);
    for (unsigned i = 0; i < numIntervals; ++i) {
        // Leftmost binary search
        unsigned low = 0, high = i;
        while (low < high) {
            unsigned mid = low + (high - low) / 2;
            (intervals[mid].end < intervals[i].start) ? (low = mid + 1) : (high = mid);
        }
        maxValues[i + 1] = std::max(maxValues[i], maxValues[high] + intervals[i].value);
    }
    return maxValues.back();
}

int main() {
    unsigned numIntervals;
    std::cin >> numIntervals;
    std::vector<Interval> intervals(numIntervals);
    for (Interval& interval : intervals) {
        std::cin >> interval.start >> interval.end >> interval.value;
    }
    std::cout << IntervalScheduling(intervals) << std::endl;

    return EXIT_SUCCESS;
}