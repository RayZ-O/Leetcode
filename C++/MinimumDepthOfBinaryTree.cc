// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the 
// root node down to the nearest leaf node.

class Solution {
	int min{0};
	vector<TreeNode*> nodes;
public:
    int minDepth(TreeNode* root) {
    	if (root) {
    		nodes.push_back(root);
    	}    	    	
    	while (!nodes.empty()) {
    		min++;
    		vector<TreeNode*> newNodes;
    		for (auto tn : nodes) {
    			if (!tn->left && !tn->right) {
    				newNodes.clear();
    				break;
    			}    				
    			if (tn->left)  newNodes.push_back(tn->left);
    			if (tn->right)  newNodes.push_back(tn->right);
    		}
    		swap(nodes, newNodes);
    	}
    	return min;
    }
};