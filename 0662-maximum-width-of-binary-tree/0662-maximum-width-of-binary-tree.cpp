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
    int widthOfBinaryTree(TreeNode* root) {
         queue<pair<TreeNode*,long>>q;
          int ans =0;
           if(root==NULL) return 0;
            q.push({root,0});
            
            while(!q.empty()){
                int size = q.size();
                  int minim= q.front().second;
                  int s, e;
                   for(int i=0;i<size;i++){

                    long  id= q.front().second- minim;
                     TreeNode*temp =  q.front().first;
                     q.pop();
                      if(i==0) {s= id;}
                     if(i==size-1) {e= id;}
                     if(temp->left){q.push({temp->left,id*2+1});}
                     if(temp->right){q.push({temp->right,id*2+2});}
                    
                     
                   }
                    ans= max(ans,e-s+1);
            }
 return ans;
    }
};