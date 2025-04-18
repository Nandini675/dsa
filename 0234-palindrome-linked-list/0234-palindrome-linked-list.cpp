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
ListNode*reversell(ListNode*head){
    ListNode*prev= NULL;
    ListNode* temp= head;
    while(temp!=NULL){
    ListNode* front= temp->next;
    temp->next= prev;
    prev= temp;
    temp= front;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast->next!=NULL&& fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* newhead= reversell(slow->next);
        ListNode*first= head;
        ListNode* sec= newhead;
        while(sec!=NULL){
            if(first->val!= sec->val){
                reversell(newhead);
                return false;
            }
            
            first= first->next;
            sec= sec->next;
        }
          reversell(newhead) ;
          return true;  
        }



    
};