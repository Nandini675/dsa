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
ListNode*findkth(ListNode *temp,int k){
            k-=1;
            while(temp!=NULL &&k>0){
                k--; temp= temp->next;

            }
            return temp;
        }
         ListNode*reversell(ListNode * head){
             ListNode* temp= head;
             ListNode* prevnode= NULL;
             while(temp!=NULL){
              ListNode* front=temp->next;
              temp->next= prevnode;
              prevnode= temp;
              temp= front;
              }
              return prevnode;
         }
    ListNode* reverseKGroup(ListNode* head, int k) {

        
       ListNode* temp= head;
      ListNode* prev= NULL;
       while(temp!=NULL){
       ListNode* kthnode = findkth(temp,k);
         if(kthnode==NULL){
            if(prev){
                prev->next= temp;
            }
            break;
         }
         ListNode* next= kthnode->next;
         kthnode->next= NULL;
         reversell(temp);
        if(temp==head) {
            head= kthnode;
        }
        else{
            prev->next= kthnode;
            
        }
prev= temp;
temp= next;
       } 
       return head; 
    }
};