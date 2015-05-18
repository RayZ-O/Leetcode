// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree {3,9,20,#,#,15,7},

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its level order traversal as:

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> output;
        list<TreeNode*> nodes{root, nullptr};
        while (!nodes.empty()) {
        	vector<int> v;
        	TreeNode* temp = nodes.front();
        	if(temp) {
        		do {
		        	v.push_back(temp->val);
		        	if (temp->left) {
		        		nodes.push_back(temp->left);
		        	}	        		
		        	if (temp->right) {
		        		nodes.push_back(temp->right);
		        	}	        		
		        	nodes.pop_front();
		        	temp = nodes.front();
	        	} while (temp);
        		nodes.push_back(nullptr);
        		output.push_back(v);  
        	}         	      	
        	nodes.pop_front();
        }
        return output;
    }
};