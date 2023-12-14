/*
    Component Detection
    -------------------
    Time: O(n+m)
    Space: O(n)
*/
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <stack>

class Graph final {
public:
    Graph(const unsigned& n) : visited(n), adjLists(n) {}
    void addEdge(const unsigned& v_1, const unsigned& v_2) {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto ComponentDetection() {
        // components.clear();
        for (unsigned vertex = 0; vertex < adjLists.size(); ++vertex) {
            if (visited[vertex] == false) {
                std::vector<unsigned> component;
                DepthFirstSearch(vertex, component);
                components.emplace_back(component);
            }
        }
        return components;
    }

private:
    void DepthFirstSearch(unsigned vertex, std::vector<unsigned>& component) {
        // visited.assign(visited.size(), false);
        std::stack<unsigned> stack;
        stack.emplace(vertex);
        while (stack.empty() == false) {
            vertex = stack.top();
            stack.pop();
            visited[vertex] = true;
            component.emplace_back(vertex);
            for (const unsigned& next : adjLists[vertex]) {
                if (visited[next] == false)
                    stack.emplace(next);
            }
        }
    }
    std::vector<bool> visited;
    std::vector<std::vector<unsigned>> components;
    std::unordered_map<unsigned, std::unordered_multiset<unsigned>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    auto components = graph.ComponentDetection();
    for (const auto& component : components) {
        for (const unsigned& vertex : component) {
            std::cout << vertex << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}