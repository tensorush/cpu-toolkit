/*
    Cycle Search
    -------------
    Time: O(n+m)
    Space: O(n+m)
*/
#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(const size_t& n) : colours(n), parents(n, -1), adjLists(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace_back(v_2);
        adjLists[v_2].emplace_back(v_1);
    }
    auto CycleSearch(const size_t& vertex) {
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
    std::vector<char> colours;
    std::list<std::list<size_t>> cycles;
    std::vector<std::list<size_t>> adjLists;
};

int main() {
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    auto cycles = graph.CycleSearch(0);
    if (cycles.size()) {
        for (const auto& cycle : cycles) {
            for (const size_t& v : cycle) {
                std::cout << v << ' ';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}