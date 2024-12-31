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
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==NULL) return root;
         if(root->val==key)
         return helper(root);
         TreeNode* temp= root;
         while(root){
            if(root->val>key){
                if(root->left!=NULL&& root->left->val==key) root->left= helper(root->left);
                else{
                    root= root->left;
                }

            }
            else{
                if(root->right!=NULL&&  root->right->val == key) root->right= helper(root->right);
                else root= root->right;
            }
         }
         return temp;}
         TreeNode* helper(TreeNode*root){
            if(root->left==NULL) return root->right;
            if(root->right==NULL) return root->left;
            TreeNode* rytchild= root->right;
            TreeNode* lastryt= findlastryt(root->left);
            lastryt->right= rytchild;
            return root->left;
         }
         TreeNode*findlastryt(TreeNode*root){
            if(root->right==NULL ) return root;
             return findlastryt(root->right);


         }
      
    
};