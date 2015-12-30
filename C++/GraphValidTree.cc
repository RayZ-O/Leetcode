// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge
// is a pair of nodes), write a function to check whether these edges make up a
// valid tree.

// For example:

// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

class Solution {
    using Graph = unordered_map<int, vector<int>>;
    bool hasCycle(Graph &graph, int node, vector<bool> &visited, int parent, int &count) {
        visited[node] = true;
        for (int adj : graph[node]) {
            if (visited[adj] && adj != parent) {
                return true;
            }
            if (!visited[adj] && hasCycle(graph, adj, visited, node, count)) {
                return true;
            }
        }
        count++;
        return false;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        Graph graph;
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        int count = 0;
        vector<bool> visited(n, false);
        return !hasCycle(graph, 0, visited, -1, count) && count == n;
    }
};
