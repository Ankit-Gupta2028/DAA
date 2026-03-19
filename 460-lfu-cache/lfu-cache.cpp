struct Node{
    int key,value,freq;
    Node* prev;
    Node* next;
    Node(int key1,int value1){
        key=key1;
        value=value1;
        freq=1;
        prev=NULL;
        next=NULL;
    }
};
class LFUCache {
private:
    int size,minfreq;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> m1;
    unordered_map<int,list<Node*>> freq_store;
public:
    LFUCache(int capacity) {
        size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m1.find(key) == m1.end()){
        return -1;
    }

    Node* newnode=m1[key];
    int freq=newnode->freq;

    freq_store[freq].remove(newnode);
    if(freq==minfreq && freq_store[freq].empty()){
        minfreq++;
    }
    newnode->freq++;
    freq_store[newnode->freq].push_back(newnode);
    return newnode->value;


        
    }
    
    void put(int key, int value) {

    if(m1.find(key)!=m1.end()){
        Node* node = m1[key];
        node->value=value;
        get(key);
        return;
    }
    if(m1.size()==size){
        Node* temp=freq_store[minfreq].front();
        freq_store[minfreq].pop_front();
        m1.erase(temp->key);
    }
    Node* newnode=new Node(key,value);
    m1[key]=newnode;
    freq_store[1].push_back(newnode);
    minfreq=1;

        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */