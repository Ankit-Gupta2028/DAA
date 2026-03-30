class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> p1;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
    for(int i=0;i<nums.size();i++){
        p1.push(nums[i]);
        if(p1.size()>k){
            p1.pop();
        }
    }

    }
    
    int add(int val) {
        int i=0;
        p1.push(val);
        if(p1.size()>K){
            p1.pop();
        }
        return p1.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */