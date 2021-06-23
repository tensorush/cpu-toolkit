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

class Graph final
{
public:
    Graph(const unsigned &n) : parents(n, -1), visited(n), adjLists(n) {}
    void addEdge(const unsigned &v_1, const unsigned &v_2)
    {
        adjLists[v_1].emplace(v_2);
        adjLists[v_2].emplace(v_1);
    }
    auto BreadthFirstSearch(unsigned vertex)
    {
        // bfs.clear();
        // visited.assign(visited.size(), false);
        std::queue<unsigned> queue;
        queue.emplace(vertex);
        visited[vertex] = true;
        while (queue.empty() == false)
        {
            vertex = queue.front();
            queue.pop();
            bfs.emplace_back(vertex);
            for (const unsigned &next : adjLists[vertex])
            {
                if (!visited[next])
                {
                    queue.emplace(next);
                    visited[next] = true;
                    parents[next] = vertex;
                }
            }
        }
        return bfs;
    }
    auto ShortestPath(const unsigned &source, const unsigned &destination)
    {
        // parents.assign(parents.size(), -1);
        std::list<unsigned> path;
        BreadthFirstSearch(source);
        for (int cur = destination; cur >= 0; cur = parents[cur])
        {
            path.emplace_front(cur);
        }
        return (path.front() == source) ? (std::make_pair(true, path)) : (std::make_pair(false, path));
    }

private:
    std::vector<int> parents;
    std::vector<bool> visited;
    std::vector<unsigned> bfs;
    std::unordered_map<unsigned, std::unordered_multiset<unsigned>> adjLists;
};

int main()
{
    Graph graph(4);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    auto bfs = graph.BreadthFirstSearch(2);
    for (const unsigned &vertex : bfs)
    {
        std::cout << vertex << ' ';
    }
    std::cout << std::endl;
    auto [exists, path] = graph.ShortestPath(0, 2);
    if (exists)
    {
        for (const unsigned &vertex : path)
        {
            std::cout << vertex << ' ';
        }
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}