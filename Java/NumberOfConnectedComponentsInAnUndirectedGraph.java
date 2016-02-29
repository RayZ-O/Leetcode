// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
// write a function to find the number of connected components in an undirected graph.

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
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is 
// the same as [1, 0] and thus will not appear together in edges.

public class NumberOfConnectedComponentsInAnUndirectedGraph {
    void dfs(List<List<Integer>> graph, int i, boolean[] visited) {
        visited[i] = true;
        for (Integer u : graph.get(i)) {
            if (visited[u] == false) {
                dfs(graph, u, visited);
            }
        }
    }
    
    public int countComponents(int n, int[][] edges) {
        if (n < 1) {
            return 0;
        }
        
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<Integer>());
        }
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        boolean[] visited = new boolean[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(graph, i, visited);
                count++;
            }
        }
        return count;
    }
}
