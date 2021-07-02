/*
    Optimal Binary Search Tree
    --------------------------
    Time: O(n^3)
    Space: O(n)
*/
#include <algorithm>
#include <iostream>
#include <vector>

void SortNodesAndFrequenciesByNodes(std::vector<unsigned>& nodes, std::vector<unsigned>& frequencies) {
    unsigned numNodes = nodes.size();
    std::vector<std::pair<unsigned, unsigned>> indices;
    for (unsigned i = 0; i < numNodes; ++i) {
        indices.emplace_back(std::make_pair(i, nodes[i]));
    }
    std::sort(indices.begin(), indices.end(), [](const std::pair<unsigned, unsigned>& a, const std::pair<unsigned, unsigned>& b) -> bool {
        return a.second < b.second;
    });
    std::vector<unsigned> sortedFrequencies;
    for (unsigned i = 0; i < numNodes; ++i) {
        sortedFrequencies.emplace_back(frequencies[indices[i].first]);
        nodes[i] = indices[i].second;
    }
    frequencies = sortedFrequencies;
}

unsigned OptimalBinarySearchTree(std::vector<unsigned>& nodes, std::vector<unsigned>& frequencies) {
    unsigned numNodes = nodes.size();
    SortNodesAndFrequenciesByNodes(nodes, frequencies);
    std::vector<std::vector<unsigned>> matrix(numNodes, std::vector<unsigned>(numNodes));
    for (unsigned i = 0; i < numNodes; ++i) {
        matrix[i][i] = frequencies[i];
    }
    unsigned col, frequencySum, minFound, newMin, leftCost, rightCost;
    for (unsigned cur = 2; cur <= numNodes; ++cur) {
        for (unsigned row = 0; row <= numNodes - cur; ++row) {
            frequencySum = 0;
            col = row + cur - 1;
            for (unsigned i = row; i <= col; ++i) {
                frequencySum += frequencies[i];
            }
            minFound = UINT32_MAX;
            for (unsigned i = row; i <= col; ++i) {
                leftCost = 0;
                rightCost = 0;
                if (i - 1 >= row)
                    leftCost = matrix[row][i - 1];
                if (i + 1 <= col)
                    rightCost = matrix[i + 1][col];
                newMin = frequencySum + leftCost + rightCost;
                if (newMin < minFound)
                    minFound = newMin;
            }
            matrix[row][col] = minFound;
        }
    }
    return matrix[0][numNodes - 1];
}

int main() {
    unsigned numNodes;
    std::cin >> numNodes;
    std::vector<unsigned> nodes, frequencies;
    for (unsigned& node : nodes) {
        std::cin >> node;
    }
    for (unsigned& frequency : frequencies) {
        std::cin >> frequency;
    }
    std::cout << OptimalBinarySearchTree(nodes, frequencies) << std::endl;

    return EXIT_SUCCESS;
}