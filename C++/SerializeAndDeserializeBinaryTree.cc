// Serialization is the process of converting a data structure or object into
// a sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in
// the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no
// restriction on how your serialization/deserialization algorithm should work.
// You just need to ensure that a binary tree can be serialized to a string and
// this string can be deserialized to the original tree structure.

// For example, you may serialize the following tree

//     1
//    / \
//   2   3
//      / \
//     4   5

class Codec {
    void treeToString(TreeNode* root, string& s) {
        if (!root) {
            s += "# ";
            return;
        }
        s += to_string(root->val) + " ";
        treeToString(root->left, s);
        treeToString(root->right, s);
    }

    TreeNode* buildTree(queue<string>& data) {
        string node = data.front();
        data.pop();
        if (node == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(node));
        root->left = buildTree(data);
        root->right = buildTree(data);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        treeToString(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string node;
        queue<string> nodes;
        while (ss >> node) {
            nodes.push(node);
        }
        return buildTree(nodes);
    }
};
