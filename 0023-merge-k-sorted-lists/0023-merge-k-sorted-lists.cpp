/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode * merge2list(ListNode* a, ListNode*b){
     if(a==NULL) return b;
     if(b==NULL) return a;
      if(a->val<=b->val){
a->next= merge2list(a->next,b);
return a;
      }
      else{
b->next= merge2list(a,b->next);
return b;
      }
 }
 
 ListNode* partitionmer(int s, int e, vector<ListNode*>& lists){
 if(s== e) return lists[s];
 if(s>e) return NULL;
 int mid= (s+e)/2;
  ListNode* l1=partitionmer(s,mid,lists);
  ListNode* l2=partitionmer(mid+1,e,lists);
  return merge2list(l1,l2);
  
 }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==NULL) return NULL;
         
          return partitionmer(0,lists.size()-1,lists);
    }
};