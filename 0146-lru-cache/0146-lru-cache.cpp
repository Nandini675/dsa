class LRUCache {
public:
// using doubly ll
class node{
    public:
 int key,  val;
 node* next;
 node* prev;
 node(int _key, int _val){
    key= _key;
    val=_val;
 }
};
 node* head= new node(-1,-1);
 node* tail= new node(-1,-1);
 int cap;
 unordered_map<int, node*>mpp;// key, node
    LRUCache(int capacity) {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }
    void insertnodeafterhead(node* temp){
         node *currafterhead= head->next;
         temp->next= currafterhead;
         temp->prev= head;
         head->next= temp;
         currafterhead->prev= temp;
    }
     void deletenode(node*temp){
         node* prevnode= temp->prev;
         node* delnext= temp->next;
         prevnode->next= delnext;
         delnext->prev= prevnode;
     }
    
    int get(int key) {
 if(mpp.find(key)!=mpp.end()){
    node* resnode= mpp[key];
    int res= resnode->val;
    mpp.erase(key);
    deletenode(resnode);
    insertnodeafterhead(resnode);
    mpp[key]= head->next;
    return res;
 }

 return -1;
    }
    
    void put(int key, int value) {
         if(mpp.find(key)!=mpp.end()){
             node* exist= mpp[key];//addres pta chl gya us node
             mpp.erase(key);
             deletenode(exist);
// map mai uski purana adress delte krke nya address dalenge
         } if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
         }
    insertnodeafterhead(new node(key,value));
         mpp[key]= head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */