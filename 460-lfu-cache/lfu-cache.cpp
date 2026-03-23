struct Node{
    int key,value,freq;
    Node* prev;
    Node* next;
    Node(int key1,int value1){
        key=key1;
        value=value1;
       
        prev=NULL;
        next=NULL;
        freq=1;
        
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }


    void insert_after_head( Node* newnode){

        Node* headnext=head->next;
        head->next=newnode;
        newnode->next=headnext;
        newnode->prev=head;
        headnext->prev=newnode;
        size++;
    }
    void delete_node(Node* newnode){
        Node* keynext=newnode->next;
        Node* keyprev=newnode->prev;

        keynext->prev=keyprev;
        keyprev->next=keynext;
        size--;
       

    }

};

class LFUCache {
private:
    unordered_map<int,Node*> m1;
    unordered_map<int,List*> freq_map;
    int max_LFU_size;
    int curr_size;
    int minfreq;
public:
    LFUCache(int capacity) {
    max_LFU_size=capacity;
    curr_size=0;
    minfreq=0;
    }
    void update_freq(Node* node){
    m1.erase(node->key);

    freq_map[node->freq]->delete_node(node);

    if(node->freq == minfreq && freq_map[node->freq]->size==0){
        minfreq++;
    }
    
    List* temp=new List{};

    if(freq_map.find(node->freq +1) != freq_map.end()){
        temp=freq_map[node->freq +1];
    }

    node->freq ++;
    temp->insert_after_head(node);

    freq_map[node->freq]=temp;
    m1[node->key]=node;

    }
    
    int get(int key) {
        if(m1.find(key)!= m1.end()){
            Node* node= m1[key];
            int val=node->value;
            update_freq(node);
            return val;
        }
        return -1;
    }



        
    
    
    void put(int key, int value) {
    if(m1.find(key)!= m1.end()){
        Node* node=m1[key];
        node->value=value;
        update_freq(node);
    }else{
        if(curr_size == max_LFU_size){
            List* temp=freq_map[minfreq];
            Node* node=temp->tail->prev;
            m1.erase(node->key);
            freq_map[minfreq]->delete_node(temp->tail->prev);
            curr_size--;

        }
        curr_size++;
        minfreq=1;
        List* temp1=new List();
        if(freq_map.find(minfreq)!= freq_map.end()){
            temp1=freq_map[minfreq];
        }
        Node* newnode=new Node(key,value);
        temp1->insert_after_head(newnode);

        m1[key]=newnode;
        freq_map[minfreq]=temp1;
    }
    
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */