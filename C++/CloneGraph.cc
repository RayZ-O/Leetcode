// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return nullptr;
        }
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;

        q.push(node);
        UndirectedGraphNode* new_root = new UndirectedGraphNode(node->label);
        node_map.emplace(node, new_root);

        while (!q.empty()) {
            UndirectedGraphNode* old_node = q.front();
            UndirectedGraphNode* new_node = node_map[old_node];
            q.pop();
            for (auto n : old_node->neighbors) {
                if (node_map.find(n) == node_map.end()) {
                    UndirectedGraphNode* u = new UndirectedGraphNode(n->label);
                    q.push(n);
                    node_map.emplace(n, u);
                }
                new_node->neighbors.push_back(node_map[n]);
            }
        }
        return new_root;
    }
};
