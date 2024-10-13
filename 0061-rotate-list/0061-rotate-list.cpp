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
    ListNode* rotateRight(ListNode* head, int k) {
       if( !head|| !head->next|| k==0)  return head;
       ListNode*temp= head;
       int l=1;
       while( temp->next!=NULL){
        l++;
        temp= temp->next;
       }
       temp->next= head;
       k= k%l;
     int   e= l-k;
       while(e--)
        temp= temp->next;

   head= temp->next;
  temp->next= NULL;
  
 return head;


    }
};