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
 int max_dia =0;
 int height(TreeNode* root){
 if (root==NULL) return 0;
   int rh= height(root->right);
   int lh= height(root->left);
    max_dia = max(max_dia, lh+rh);
     return max(lh,rh)+1;
 
 }
    int diameterOfBinaryTree(TreeNode* root) {
          height(root);
          return max_dia; 

    }
};