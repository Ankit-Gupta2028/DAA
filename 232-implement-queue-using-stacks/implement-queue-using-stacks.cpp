class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        if(s2.empty()){
            cout<<"Underflow";
            return -1;
        }
        int popped= s2.top();
        s2.pop();
        return popped;
    }
    
    int peek() {
        if(s2.empty()){
            
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        if(s2.size()==0){
            cout<<"Queue is Empty";
            return -1;
        }
        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */