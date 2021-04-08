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
    Graph(const size_t& n) : adjLists(n), visited(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace_back(v_2);
        adjLists[v_2].emplace_back(v_1);
    }
    void DepthFirstSearch(size_t vertex, std::list<size_t>& component) {
        std::stack<size_t> stack;
        stack.push(vertex);
        while (!stack.empty()) {
            vertex = stack.top();
            stack.pop();
            visited[vertex] = true;
            component.emplace_back(vertex);
            for (const size_t& v : adjLists[vertex]) {
                if (!visited[v]) stack.push(v);
            }
        }
    }
    auto ComponentSearch() {
        components.clear();
        for (size_t v = 0; v < adjLists.size(); ++v) {
            if (!visited[v]) {
                std::list<size_t> component;
                DepthFirstSearch(v, component);
                components.emplace_back(component);
            }
        }
        return components;
    }
private:
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