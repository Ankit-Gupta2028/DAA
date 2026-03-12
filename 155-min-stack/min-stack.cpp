class MinStack {
private:
    stack<pair<int,int>> s1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty()){
            s1.push({val,val});
        }else{
            int min=s1.top().second;
            if(min>val){
                s1.push({val,val});
            }else{
                s1.push({val,min});
            }
        }
    }
    
    void pop() {
        if(s1.empty()){
        
        }else{
        s1.pop();
        }
    }
    
    int top() {
        if(s1.empty()){
      
        return -1;
        }
    return s1.top().first;

    }
    
    int getMin() {
        if(s1.empty()){
        return -1;
        }
        return s1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */