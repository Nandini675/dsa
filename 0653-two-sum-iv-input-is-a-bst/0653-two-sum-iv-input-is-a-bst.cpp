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
 class bstiterator{
    // reverse->true->befor)desceinding order
    // reverse->false->next()
 bool reverse= true;// before
 stack<TreeNode*>s;
public: 
bstiterator( TreeNode* root,  bool isreverse){
    reverse= isreverse;
    pushALL(root);
}
 bool hasnext(TreeNode*root)
{
    return !s.empty();
}
int  next(){
     TreeNode* temp= s.top();
     s.pop();
     if(reverse){ pushALL(temp->left);}
     else{ pushALL(temp->right);}
     return temp->val;
}
private:  void pushALL(TreeNode*node){
 while(node){
    s.push(node);
     if(reverse){
       node= node->right; 
     }
     else{ node= node->left;}
 }
}

 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
         if(root==NULL) return false;
          bstiterator l(root,false);// making inorder
          bstiterator r(root,true);// making descenidng order
          int i= l.next();
          int j= r.next();
          while(i<j){
             if(i+j== k) return true;
             else if(i+j>k) j= r.next();
             else i= l.next();
          }
      return false;    
    }
};