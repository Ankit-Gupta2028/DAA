struct Node{
    int key,value;
    Node* next;
    Node* prev;
    Node(int key1,int data1){
        key=key1;
        value=data1;
        prev=NULL;
        next=NULL;
    }

};
class LRUCache {
private:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> m1;

        void insert_after_head( Node* newnode){

        Node* headnext=head->next;
        head->next=newnode;
        newnode->next=headnext;
        newnode->prev=head;
        headnext->prev=newnode;
    }

    void delete_node(Node* newnode){
        Node* keynext=newnode->next;
        Node* keyprev=newnode->prev;

        keynext->prev=keyprev;
        keyprev->next=keynext;
       

    }
public:
    LRUCache(int capacity) {
        size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m1.find(key)!=m1.end()){
        Node* node=m1[key];
        delete_node(node);
        insert_after_head(node);
        return node->value;
    }else{
        return -1;
    }
    }
    
    void put(int key, int value) {
        
    if(m1.find(key)!=m1.end()){

        Node* newnode1=m1[key];
        delete_node(newnode1);
        m1.erase(key);

    }
    if(size == m1.size()){
        m1.erase(tail->prev->key);
        delete_node(tail->prev);
          
        
    }    
    
    Node* newnode=new Node(key,value);
    insert_after_head(newnode);
    m1[key]=newnode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */