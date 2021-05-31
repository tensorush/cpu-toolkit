/*
    Cycle Detection
    -------------
    Time: O(n+m)
    Space: O(n+m)
*/
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <list>

class Graph final {
public:
    Graph(const size_t& n) : colours(n), parents(n, -1), adjLists(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto CycleDetection(const size_t& vertex) {
        // cycles.clear();
        // parents.assign(parents.size(), -1);
        // colours.assign(colours.size(), WHITE);
        DepthFirstSearch(vertex);
        return cycles;
    }
private:
    enum Colour {WHITE, GRAY, BLACK};
    void DepthFirstSearch(const size_t& vertex) {
        if (colours[vertex] == BLACK) return ;
        if (colours[vertex] == GRAY) {
            std::list<size_t> cycle = {vertex};
            for (size_t cur = parents[vertex]; cur != vertex; cur = parents[cur]) {
                cycle.emplace_back(cur);
            }
            cycles.emplace_back(cycle);
            return ;
        }
        colours[vertex] = GRAY;
        for (const size_t& next : adjLists[vertex]) {
            if (next == parents[vertex]) continue ;
            parents[next] = vertex;
            DepthFirstSearch(next);
        }
        colours[vertex] = BLACK;
    }
    std::vector<int> parents;
    std::vector<unsigned> colours;
    std::list<std::list<size_t>> cycles;
    std::unordered_map<size_t, std::unordered_multiset<size_t>> adjLists;
};

int main() {
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    auto cycles = graph.CycleDetection(0);
    if (cycles.size()) {
        for (const auto& cycle : cycles) {
            for (const size_t& vertex : cycle) {
                std::cout << vertex << ' ';
            }
            std::cout << std::endl;
        }
    }

    return EXIT_SUCCESS;
}