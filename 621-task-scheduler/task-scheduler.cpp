class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }

       vector<int> arr(26);

        
        for(int i:tasks){
            arr[i-'A']+=1;
        }
        int max_feq=*max_element(arr.begin(),arr.end());
        int total_max_feq_ele=count(arr.begin(),arr.end(),max_feq);

        int freq=(max_feq-1)*(n+1 ) + total_max_feq_ele;

        return max(int(tasks.size()),freq);
    }
};