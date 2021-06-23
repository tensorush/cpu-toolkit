/*
    Strand Sort (stable)
    -------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(n)
*/
#include <iostream>
#include <list>

template <typename T>
auto StrandSort(std::list<T> &list)
{
    if (list.size() <= 1)
        return list;
    std::list<T> sortedList, sortedSublist;
    while (list.empty() == false)
    {
        sortedSublist.emplace_back(list.front());
        list.pop_front();
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (sortedSublist.back() <= *it)
            {
                sortedSublist.emplace_back(*it);
                it = list.erase(it);
                --it;
            }
        }
        sortedList.merge(sortedSublist);
    }
    return sortedList;
}

int main()
{
    int element;
    std::list<int> list;
    while (std::cin >> element)
        list.emplace_back(element);
    auto sortedList = StrandSort(list);
    for (const int &element : sortedList)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}