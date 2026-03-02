class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stack_operations;
        if(target.size()==0){
            return stack_operations;
        }
        int check_num=1;
        int index=0;

        

        while(index<target.size() && index<n){
            if(target[index] == check_num){
                stack_operations.push_back("Push");
                
                index+=1;
            }else{
                stack_operations.push_back("Push");
                stack_operations.push_back("Pop");
            }
            
            check_num+=1;
        }
        return stack_operations;
    }
};