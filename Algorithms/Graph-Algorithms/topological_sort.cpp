/*
    Topological Sort
    ----------------
    Time: O(n+m)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <list>

class DirectedGraph {
public:
    DirectedGraph(const size_t& n) : adjLists(n), visited(n) {}
    void addEdge(const size_t& source, const size_t& destination) {
        adjLists[source].emplace_back(destination);
    }
    void DepthFirstSearch(size_t vertex) {
        std::stack<size_t> stack;
        stack.push(vertex);
        while (!stack.empty()) {
            vertex = stack.top();
            stack.pop();
            visited[vertex] = true;
            sorted.emplace_back(vertex);
            for (const size_t& v : adjLists[vertex]) {
                if (!visited[v]) stack.push(v);
            }
        }
    }
    auto TopologicalSort() {
        sorted.clear();
        for (size_t v = 0; v < adjLists.size(); ++v) {
            if (!visited[v]) DepthFirstSearch(v);
        }
        std::reverse(sorted.begin(), sorted.end());
        return sorted;
    }
private:
    std::vector<bool> visited;
    std::vector<size_t> sorted;
    std::vector<std::vector<size_t>> adjLists;
};

int main() {
    DirectedGraph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto sorted = graph.TopologicalSort();
    for (const size_t& v : sorted) {
        std::cout << v << ' ';
    }

    return 0;
}