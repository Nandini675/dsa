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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        
         if(root==NULL) 
         return root;
q.push(root);
 bool flag=false;
 while(!q.empty()){
   vector<TreeNode*>ans;
     int size=  q.size();
      for(int i=0;i<size;i++){
         TreeNode*temp =   q.front();
         q.pop();
         ans.push_back(temp);
         if(temp->left) {q.push(temp->left);}
         if(temp->right){q.push(temp->right);}

      }
       if(flag){
int s=0; int e= (int)ans.size()-1;
while(s<=e){
    swap(ans[s++]->val, ans[e--]->val);
}
       }
        flag= !flag;
 }

return root;
    }
};