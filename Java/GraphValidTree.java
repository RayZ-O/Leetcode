// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
// write a function to check whether these edges make up a valid tree.

// For example:

// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.


// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] 
// is the same as [1, 0] and thus will not appear together in edges.

public class GraphValidTree {
    public boolean validTree(int n, int[][] edges) {
        if (n != edges.length + 1) {
            return false;
        }
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            graph[edges[i][0]].add(edges[i][1]);
            graph[edges[i][1]].add(edges[i][0]);
        }
        boolean[] visited = new boolean[n];
        dfs(graph, visited, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                System.out.println(i);
                return false;
            }
        }
        return true;
    }

    void dfs(ArrayList<Integer>[] graph, boolean[] visited, int i) {
        visited[i] = true;
        for (Integer u : graph[i]) {
            if (!visited[u]) dfs(graph, visited, u);
        }
    }
}
