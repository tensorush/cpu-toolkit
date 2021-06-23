/*
    Interval Scheduling
    -------------------
    Time: O(n log(n))
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>

struct Interval
{
    unsigned start, end, value;
};

unsigned IntervalScheduling(std::vector<Interval> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const Interval &interval_1, const Interval &interval_2)
              { return (interval_1.end < interval_2.end) ? (true) : (false); });
    std::vector<unsigned> maxValues(intervals.size() + 1);
    for (size_t i = 0; i < intervals.size(); ++i)
    {
        // Leftmost binary search
        size_t low = 0, high = i;
        while (low < high)
        {
            size_t mid = low + (high - low) / 2;
            (intervals[mid].end < intervals[i].start) ? (low = mid + 1) : (high = mid);
        }
        maxValues[i + 1] = std::max(maxValues[i], maxValues[high] + intervals[i].value);
    }
    return maxValues.back();
}

int main()
{
    unsigned numIntervals;
    std::cin >> numIntervals;
    std::vector<Interval> intervals(numIntervals);
    for (Interval &interval : intervals)
    {
        std::cin >> interval.start >> interval.end >> interval.value;
    }
    std::cout << IntervalScheduling(intervals) << std::endl;

    return EXIT_SUCCESS;
}