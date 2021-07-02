/*
    Bellman-Ford Algorithm
    ----------------------
    Time: O(n*m)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

class WeightedDirectedGraph final {
public:
    WeightedDirectedGraph(const unsigned& n, const unsigned& m) : distances(n, INT32_MAX), parents(n, -1), edgeList(m) {}
    void addEdge(const unsigned& source, const unsigned& destination, const int& weight) {
        Edge edge = { source, destination, weight };
        edgeList.emplace_back(edge);
    }
    auto BellmanFordAlgorithm(const unsigned& source) {
        // distances.assign(distances.size(), INT32_MAX);
        // parents.assign(distances.size(), -1);
        bool any;
        int vertex;
        distances[source] = 0;
        unsigned numIterations = distances.size();
        for (unsigned iteration = 0; iteration < numIterations; ++iteration) {
            any = false;
            vertex = -1;
            for (const auto& [source, destination, weight] : edgeList) {
                if (distances[source] < INT32_MAX && distances[destination] > distances[source] + weight) {
                    distances[destination] = std::max(INT32_MIN, distances[source] + weight);
                    parents[destination] = source;
                    vertex = destination;
                    any = true;
                }
            }
            if (any == false)
                break;
        }
        std::vector<unsigned> negativeCycle;
        if (vertex != -1) {
            for (unsigned i = 0; i < numIterations; ++i) {
                vertex = parents[vertex];
            }
            for (unsigned cur = vertex; cur != vertex || negativeCycle.size() < 2; cur = parents[cur]) {
                negativeCycle.emplace_back(cur);
            }
            std::reverse(negativeCycle.begin(), negativeCycle.end());
        }
        return std::make_pair(distances, negativeCycle);
    }

private:
    struct Edge {
        unsigned source, destination;
        int weight;
    };
    std::vector<int> distances;
    std::vector<int> parents;
    std::list<Edge> edgeList;
};

int main() {
    WeightedDirectedGraph graph(3, 3);
    graph.addEdge(0, 1, -1);
    graph.addEdge(1, 2, -2);
    graph.addEdge(2, 0, -3);
    auto [distances, negativeCycle] = graph.BellmanFordAlgorithm(0);
    if (negativeCycle.empty()) {
        for (const unsigned& distance : distances) {
            std::cout << distance << ' ';
        }
        std::cout << std::endl;
    } else {
        for (const unsigned& vertex : negativeCycle) {
            std::cout << vertex << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}