// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a
// pair of nodes), write a function to find the number of connected components in an
// undirected graph.

// Example 1:
//      0          3
//      |          |
//      1 --- 2    4
// Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

// Example 2:
//      0           4
//      |           |
//      1 --- 2 --- 3
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
// [0, 1] is the same as [1, 0] and thus will not appear together in edges.

class Solution {
    using Graph = unordered_map<int, vector<int>>;
    void bfs(Graph &graph, int node, vector<bool> &visited) {
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int v = q.front();
            visited[v] = true;
            q.pop();
            for (int u : graph[v]) {
                if (!visited[u]) {
                    q.push(u);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        Graph graph;
        for (int i = 0; i < n; i++) {
            graph[i] = vector<int>();
        }
        for (auto e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (auto g : graph) {
            if (!visited[g.first]) {
                count++;
                bfs(graph, g.first, visited);
            }
        }
        return count;
    }
};
