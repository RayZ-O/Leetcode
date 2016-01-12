// For a undirected graph with tree characteristics, we can choose any node as the root. The result
// graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called
// minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a
// list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a
// list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1]
// is the same as [1, 0] and thus will not appear together in edges.

// Example 1:

// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3
// return [1]

// Example 2:

// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5
// return [3, 4]

// Show Hint
// Note:

// (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two
// vertices are connected by exactly one path. In other words, any connected graph without simple cycles
// is a tree.”

// (2) The height of a rooted tree is the number of edges on the longest downward path between the root
// and a leaf.

class Solution {
    using adj_list = unordered_set<int>;
    using graph_t = vector<adj_list>;

    void findLeaf(graph_t& graph, queue<int>& leaf) {
        if (graph.size() == 1) {
            leaf.push(0);
            return;
        }
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 1) {
                leaf.push(i);
            }
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        graph_t graph(n);
        for (auto& e : edges) {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        queue<int> leaf;
        findLeaf(graph, leaf);
        while (n > 2) {
            int size = leaf.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int node = leaf.front();
                leaf.pop();
                int adj = *graph[node].begin(); // node has only one adj
                graph[adj].erase(node);
                if (graph[adj].size() == 1) {
                    leaf.push(adj);
                }
            }
        }
        vector<int> output;
        while (!leaf.empty()) {
            output.push_back(leaf.front());
            leaf.pop();
        }
        return output;
    }
};
