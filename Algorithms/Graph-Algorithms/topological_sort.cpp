/*
    Topological Sort
    ----------------
    Time: O(n+m)
    Space: O(n)
*/
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <stack>
#include <list>

class DAG final {
public:
    DAG(const unsigned& n) : visited(n), adjLists(n) {}
    void addEdge(const unsigned& source, const unsigned& destination) {
        adjLists[source].emplace(destination);
    }
    auto TopologicalSort() {
        // sorted.clear();
        for (unsigned vertex = 0; vertex < adjLists.size(); ++vertex) {
            if (visited[vertex] == false)
                DepthFirstSearch(vertex);
        }
        return sorted;
    }

private:
    void DepthFirstSearch(unsigned vertex) {
        // visited.assign(visited.size(), false);
        std::stack<unsigned> stack;
        stack.emplace(vertex);
        while (stack.empty() == false) {
            vertex = stack.top();
            stack.pop();
            visited[vertex] = true;
            sorted.emplace_front(vertex);
            for (const unsigned& next : adjLists[vertex]) {
                if (visited[next] == false)
                    stack.emplace(next);
            }
        }
    }
    std::vector<bool> visited;
    std::list<unsigned> sorted;
    std::unordered_map<unsigned, std::unordered_multiset<unsigned>> adjLists;
};

int main() {
    DAG graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto sorted = graph.TopologicalSort();
    for (const unsigned& vertex : sorted) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}