/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in the inorder traversal
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        // Call the recursive helper function to build the tree
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend,
                        vector<int>& inorder, int instart, int inend, map<int, int>& inmap) {
        // Base case: If there are no nodes to process
        if (prestart > preend || instart > inend) {
            return NULL;
        }

        // Create the root node with the current value in preorder traversal
        TreeNode* root = new TreeNode(preorder[prestart]);

        // Find the index of the root value in the inorder traversal
        int inroot = inmap[root->val];

        // Calculate the number of nodes in the left subtree
        int numsleft = inroot - instart;

        // Recursively build the left subtree
        root->left = buildTree(preorder, prestart + 1, prestart + numsleft,
                               inorder, instart, inroot - 1, inmap);

        // Recursively build the right subtree
        root->right = buildTree(preorder, prestart + numsleft + 1, preend,
                                inorder, inroot + 1, inend, inmap);

        // Return the root node
        return root;
    }
};
