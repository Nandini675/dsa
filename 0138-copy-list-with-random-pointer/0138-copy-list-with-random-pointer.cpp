/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 void insert(Node*  head){

     Node*temp= head;
     while(temp!=NULL){
     Node* copied= new Node(temp->val);
     
     copied->next= temp->next;
     temp->next= copied;
     temp= temp->next->next;
     }



     
 }
  void connectrandom(Node * head){
    Node * temp= head;

    while(temp!=NULL){
        Node* copied= temp->next;
        if(temp->random)
        copied->random= temp->random->next;
        else
        copied->random= NULL;

        temp= temp->next->next;
    }
  }

 Node *clone( Node* head){
    Node* temp= head;
   
    Node* dummy= new Node (-1);
    Node * res= dummy;

    while(temp!=NULL)
    {
        res->next= temp->next;
        res= res->next;
        temp->next= temp->next->next; 
        temp= temp->next;
    }
    return dummy->next;
 }
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        insert(head);
        connectrandom(head);
       
        return clone(head); 
    }
};