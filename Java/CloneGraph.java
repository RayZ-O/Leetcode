// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

public class CloneGraph {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null) {
            return null;
        }
        Map<UndirectedGraphNode, UndirectedGraphNode> nodeMap = new HashMap<>();
        Queue<UndirectedGraphNode> q = new LinkedList<>();
        q.add(node);
        UndirectedGraphNode clone = new UndirectedGraphNode(node.label);
        nodeMap.put(node, clone);
        while (!q.isEmpty()) {
            UndirectedGraphNode u = q.poll();
            for (UndirectedGraphNode v : u.neighbors) {
                if (!nodeMap.containsKey(v)) {
                    UndirectedGraphNode w = new UndirectedGraphNode(v.label);
                    nodeMap.put(v, w);
                    q.add(v);
                }
                nodeMap.get(u).neighbors.add(nodeMap.get(v));
            }
        }
        return clone;
    }
}
