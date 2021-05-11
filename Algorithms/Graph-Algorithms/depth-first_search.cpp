/*
    Depth-First Search
    ------------------
    Time: O(n+m)
    Space: O(n)
*/
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <stack>
#include <list>

class Graph {
public:
    Graph(const size_t& n) : visited(n), adjLists(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto DepthFirstSearch(size_t vertex) {
        // dfs.clear();
        // visited.assign(visited.size(), false);
        std::stack<size_t> stack;
        stack.emplace(vertex);
        while (!stack.empty()) {
            vertex = stack.top();
            stack.pop();
            if (!visited[vertex]) dfs.emplace_back(vertex);
            visited[vertex] = true;
            for (const size_t& next : adjLists[vertex]) {
                if (!visited[next]) stack.emplace(next);
            }
        }
        return dfs;
    }
private:
    std::vector<size_t> dfs;
    std::vector<bool> visited;
    std::unordered_map<size_t, std::unordered_multiset<size_t>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto dfs = graph.DepthFirstSearch(2);
    for (const size_t& vertex : dfs) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    return 0;
}