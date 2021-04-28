/*
    Breadth-First Search
    --------------------
    Time: O(n+m)
    Space: O(n)
*/
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Graph {
public:
    Graph(const size_t& n) : parents(n, -1), visited(n), adjLists(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto BreadthFirstSearch(size_t vertex) {
        // bfs.clear();
        // visited.assign(visited.size(), false);
        std::queue<size_t> queue;
        queue.emplace(vertex);
        visited[vertex] = true;
        while (!queue.empty()) {
            vertex = queue.front();
            queue.pop();
            bfs.emplace_back(vertex);
            for (const size_t& next : adjLists[vertex]) {
                if (!visited[next]) {
                    queue.emplace(next);
                    visited[next] = true;
                    parents[next] = vertex;
                }
            }
        }
        return bfs;
    }
    auto ShortestPath(const size_t& source, const size_t& destination) {
        // parents.assign(parents.size(), -1);
        std::list<size_t> path;
        BreadthFirstSearch(source);
        for (int cur = destination; cur >= 0; cur = parents[cur]) {
            path.emplace_front(cur);
        }
        return (path.front() == source)?(std::make_pair(true, path)):(std::make_pair(false, path));
    }
private:
    std::vector<size_t> bfs;
    std::vector<int> parents;
    std::vector<bool> visited;
    std::unordered_map<size_t, std::unordered_multiset<size_t>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto bfs = graph.BreadthFirstSearch(2);
    for (const size_t& vertex : bfs) {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;
    auto [exists, path] = graph.ShortestPath(0, 2);
    if (exists) {
        for (const size_t& vertex : path) {
            std::cout << vertex << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}