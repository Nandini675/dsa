/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parenttrack, TreeNode*&target){

queue<TreeNode*>q;
q.push(root);
while(!q.empty()){
    TreeNode* temp= q.front();
q.pop();
if(temp->left){
    parenttrack[temp->left]= temp;
    q.push(temp->left);
}
if(temp->right){
    parenttrack[temp->right]= temp;
    q.push(temp->right);
}

}

 }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       queue<TreeNode*>q;
       unordered_map<TreeNode*,TreeNode*>parenttrack;  
       markparent(root,parenttrack,target);
       unordered_map<TreeNode*, bool>visited;
        q.push(target);
        visited[target]= true;
        int cnt=0;
        while(!q.empty()){
            int size= q.size();
            if(cnt==k) break;
            cnt++;

for(int i=0;i<size;i++)
{
  TreeNode* temp= q.front();
  q.pop();
   if ((temp->left)&& !visited[temp->left]){
  q.push(temp->left);
  visited[temp->left]= true;

   }
   if ((temp->right)&& !visited[temp->right]){
  q.push(temp->right);
  visited[temp->right]= true;

   }
   if((parenttrack[temp])&& !visited[parenttrack[temp]]){
    q.push(parenttrack[temp]);
    visited[parenttrack[temp]]= true;
   }
}        
}
vector<int>res;
while(!q.empty()){
    TreeNode*temp= q.front();
    q.pop();
    res.push_back(temp->val);
}
return res;
    }
};