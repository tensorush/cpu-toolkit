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

class Graph final {
public:
    Graph(const unsigned& n) : colours(n), parents(n, -1), adjLists(n) {}
    void addEdge(const unsigned& v_1, const unsigned& v_2) {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto CycleDetection(const unsigned& vertex) {
        // cycles.clear();
        // parents.assign(parents.size(), -1);
        // colours.assign(colours.size(), WHITE);
        DepthFirstSearch(vertex);
        return cycles;
    }

private:
    enum Colour {
        WHITE = 0, GRAY = 1, BLACK = 2
    };
    void DepthFirstSearch(const unsigned& vertex) {
        if (colours[vertex] == BLACK)
            return;
        if (colours[vertex] == GRAY) {
            std::vector<unsigned> cycle = { vertex };
            for (unsigned cur = parents[vertex]; cur != vertex; cur = parents[cur]) {
                cycle.emplace_back(cur);
            }
            cycles.emplace_back(cycle);
            return;
        }
        colours[vertex] = GRAY;
        for (const unsigned& next : adjLists[vertex]) {
            if (next == parents[vertex])
                continue;
            parents[next] = vertex;
            DepthFirstSearch(next);
        }
        colours[vertex] = BLACK;
    }
    std::vector<int> parents;
    std::vector<Colour> colours;
    std::vector<std::vector<unsigned>> cycles;
    std::unordered_map<unsigned, std::unordered_multiset<unsigned>> adjLists;
};

int main() {
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    auto cycles = graph.CycleDetection(0);
    if (cycles.size()) {
        for (const auto& cycle : cycles) {
            for (const unsigned& vertex : cycle) {
                std::cout << vertex << ' ';
            }
            std::cout << std::endl;
        }
    }

    return EXIT_SUCCESS;
}