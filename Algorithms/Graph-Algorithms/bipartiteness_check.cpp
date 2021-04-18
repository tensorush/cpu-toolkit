/*
    Bipartiteness Check
    -------------------
    Time: O(m)
    Space: O(n)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Graph {
public:
    Graph(const size_t& n) : colours(n, BLANK), adjLists(n) {}
    void addEdge(const size_t& v_1, const size_t& v_2) {
        adjLists[v_1].emplace_back(v_2);
        adjLists[v_2].emplace_back(v_1);
    }
    auto BipartitenessCheck() {
        // colours.assign(colours.size(), BLANK);
        bool isBipartite = true;
        for (size_t vertex = 0; vertex < adjLists.size(); ++vertex) {
            BreadthFirstSearch(vertex, isBipartite);
        }
        return std::make_pair(isBipartite, colours);
    }
private:
    enum Colour {BLANK = -1, RED = 0, BLUE = 1};
    void BreadthFirstSearch(size_t vertex, bool& isBipartite) {
        std::queue<size_t> queue;
        if (colours[vertex] == BLANK) {
            queue.emplace(vertex);
            colours[vertex] = RED;
            while (!queue.empty()) {
                vertex = queue.front();
                queue.pop();
                for (const size_t& next : adjLists[vertex]) {
                    if (colours[next] == BLANK) {
                        queue.emplace(next);
                        colours[next] = !colours[vertex];
                    } else {
                        isBipartite &= (colours[next] != colours[vertex]);
                    }
                }
            }
        }
    }
    std::vector<char> colours;
    std::vector<std::list<size_t>> adjLists;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    auto [IsBipartite, colours] = graph.BipartitenessCheck();
    if (IsBipartite) {
        for (const size_t& colour : colours) {
            std::cout << colour << ' ';
        }
    }

    return 0;
}