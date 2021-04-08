/*
    Breadth-First Search
    --------------------
    Time: O(n+m)
    Space: O(n)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Graph {
public:
    Graph(const size_t& n) : adjLists(n), visited(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace_back(v_2);
        adjLists[v_2].emplace_back(v_1);
    }
    auto BreadthFirstSearch(size_t vertex) {
        bfs.clear();
        std::queue<size_t> queue;
        queue.push(vertex);
        visited[vertex] = true;
        while (!queue.empty()) {
            vertex = queue.front();
            queue.pop();
            bfs.emplace_back(vertex);
            for (const size_t& v : adjLists[vertex]) {
                if (!visited[v]) {
                    queue.push(v);
                    visited[v] = true;
                }
            }
        }
        return bfs;
    }
private:
    std::vector<size_t> bfs;
    std::vector<bool> visited;
    std::vector<std::list<size_t>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto bfs = graph.BreadthFirstSearch(2);
    for (const size_t& v : bfs) {
        std::cout << v << ' ';
    }

    return 0;
}