// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},

//    1
//     \
//      2
//     /
//    3

// return [1,2,3].

// Note: Recursive solution is trivial, could you do it iteratively?

class Solution {
public:
	// recursive
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> output;
        preorderCollect(root, output);
        return output;
    }

    void preorderCollect(TreeNode* root, vector<int>& output) {
		if (root) {
			output.push_back(root->val);
			if(root->left) preorderCollect(root->left, output);
			if(root->right) preorderCollect(root->right, output);
		}
	}

    // iterative without pushing left child into stack
    vector<int> preorderTraversal2(TreeNode* root) {
    	vector<int> output;
    	vector<TreeNode*> nodes {nullptr};
    	while (root) {
    		output.push_back(root->val);    		
			if (root->left) {    	
				if(root->right) {
					nodes.push_back(root->right);
				}
    			root = root->left;
    		} else if(root->right) {
				root = root->right;
			} else if(!nodes.empty()){
    			root = nodes.back();
    			nodes.pop_back();
    		} 
    	}
    	return output;
    }
};