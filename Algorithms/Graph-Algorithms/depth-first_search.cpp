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

class Graph final {
public:
    Graph(const unsigned& n) : visited(n), adjLists(n) {}
    void addEdge(const unsigned& v_1, const unsigned& v_2) {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto DepthFirstSearch(unsigned vertex) {
        // dfs.clear();
        // visited.assign(visited.size(), false);
        std::stack<unsigned> stack;
        stack.emplace(vertex);
        while (stack.empty() == false) {
            vertex = stack.top();
            stack.pop();
            if (visited[vertex] == false)
                dfs.emplace_back(vertex);
            visited[vertex] = true;
            for (const unsigned& next : adjLists[vertex]) {
                if (visited[next] == false)
                    stack.emplace(next);
            }
        }
        return dfs;
    }

private:
    std::vector<bool> visited;
    std::vector<unsigned> dfs;
    std::unordered_map<unsigned, std::unordered_multiset<unsigned>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto dfs = graph.DepthFirstSearch(2);
    for (const unsigned& vertex : dfs) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}