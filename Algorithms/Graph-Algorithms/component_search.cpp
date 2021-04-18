/*
    Component Search
    ----------------
    Time: O(n+m)
    Space: O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <list>

class Graph {
public:
    Graph(const size_t& n) : visited(n), adjLists(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace_back(v_2);
        adjLists[v_2].emplace_back(v_1);
    }
    auto ComponentSearch() {
        // components.clear();
        for (size_t vertex = 0; vertex < adjLists.size(); ++vertex) {
            if (!visited[vertex]) {
                std::list<size_t> component;
                DepthFirstSearch(vertex, component);
                components.emplace_back(component);
            }
        }
        return components;
    }
private:
    void DepthFirstSearch(size_t vertex, std::list<size_t>& component) {
        // visited.assign(visited.size(), false);
        std::stack<size_t> stack;
        stack.emplace(vertex);
        while (!stack.empty()) {
            vertex = stack.top();
            stack.pop();
            visited[vertex] = true;
            component.emplace_back(vertex);
            for (const size_t& next : adjLists[vertex]) {
                if (!visited[next]) stack.emplace(next);
            }
        }
    }
    std::vector<bool> visited;
    std::list<std::list<size_t>> components;
    std::vector<std::list<size_t>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    auto components = graph.ComponentSearch();
    for (const std::list<size_t>& component : components) {
        for (const size_t& v : component) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}