/*
    Topological Sort
    ----------------
    Time: O(n+m)
    Space: O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <list>

class DAG {
public:
    DAG(const size_t& n) : visited(n), adjLists(n) {}
    void addEdge(const size_t& source, const size_t& destination) {
        adjLists[source].emplace_back(destination);
    }
    auto TopologicalSort() {
        // sorted.clear();
        for (size_t vertex = 0; vertex < adjLists.size(); ++vertex) {
            if (!visited[vertex]) DepthFirstSearch(vertex);
        }
        return sorted;
    }
private:
    void DepthFirstSearch(size_t vertex) {
        // visited.assign(visited.size(), false);
        std::stack<size_t> stack;
        stack.emplace(vertex);
        while (!stack.empty()) {
            vertex = stack.top();
            stack.pop();
            visited[vertex] = true;
            sorted.emplace_front(vertex);
            for (const size_t& next : adjLists[vertex]) {
                if (!visited[next]) stack.emplace(next);
            }
        }
    }
    std::list<size_t> sorted;
    std::vector<bool> visited;
    std::vector<std::vector<size_t>> adjLists;
};

int main() {
    DAG graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto sorted = graph.TopologicalSort();
    for (const size_t& v : sorted) {
        std::cout << v << ' ';
    }

    return 0;
}