class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> m1;
   

        if(n % groupSize != 0){
            return false;
        }
        for(int i=0;i<n;i++){
            
 

            m1[hand[i]]+=1;
        }
        int prev=-1;
        int k=0;

        while(!m1.empty()){
            int curr=m1.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(m1.find(curr)==m1.end()){
                    return false;
                }
                m1[curr]--;
                if(m1[curr]==0){
                    m1.erase(curr);
                }
                curr=curr+1;
                
            }
        }
        return true ;
    }
};