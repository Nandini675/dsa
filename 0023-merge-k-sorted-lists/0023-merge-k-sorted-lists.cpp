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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==0) return NULL;
         ListNode* dummy= new ListNode(-1);
          ListNode* temp= dummy;
         struct compare{
          bool operator()(ListNode* a, ListNode*b)
          {
             return (a->val> b->val);
          }
         };
          priority_queue<ListNode*,vector<ListNode*>,compare>pq;
          for(auto head: lists){
            if(head){
            pq.push(head);
            }
          }
           while(!pq.empty()){
            ListNode* minnode= pq.top();
            pq.pop();
             if(minnode->next!=NULL){
                pq.push(minnode->next);
             }
              temp->next= minnode;
              temp= temp->next;
           }
 return dummy->next;
    } 
};