// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from 
// the root node down to the farthest leaf node.

class Solution {
	int max{0};
	vector<TreeNode*> nodes;
public:
    int maxDepth(TreeNode* root) {
    	if (root) {
    		nodes.push_back(root);
    	}    	    	
    	while (!nodes.empty()) {
    		max++;
    		vector<TreeNode*> newNodes;
    		for (auto tn : nodes) {
    			if (tn->left)  newNodes.push_back(tn->left);
    			if (tn->right)  newNodes.push_back(tn->right);
    		}
    		swap(nodes, newNodes);
    	}
    	return max;
    }
};