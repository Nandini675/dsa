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
TreeNode* first;
TreeNode* prev;
TreeNode*middle ;
TreeNode* last;
 void inorder(TreeNode* root){
    if(root==NULL ) return;
    inorder(root->left);

    // the main check
    if(prev!=NULL && root->val < prev->val){
    // if it is a first violation
    if(first==NULL){
        first= prev;
        middle= root;
    }
    // if 2nd violation
    else{ last= root;}
    }
    prev= root;
     inorder(root->right);
 }
    void recoverTree(TreeNode* root) {
         first=middle= last= NULL;
         prev= new TreeNode(INT_MIN);
         // coz fisrt value of inoder if smaaler among allnode
          inorder(root);
          if(first && last) swap( first->val,last->val);
          else if( first && middle) swap( first->val, middle->val);
    }
};