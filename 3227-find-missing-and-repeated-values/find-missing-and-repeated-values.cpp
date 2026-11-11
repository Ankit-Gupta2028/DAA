class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int o = grid.size();
        int p = grid[0].size();
        long long n = o*p;
        long long normal_sum = (n*(n+1))/2;
        long long normal_sum_squ = (n*(n+1)*(2*n+1))/6;

        long long nums_sum = 0;
        long long nums_sum_squ = 0;
        for(int i = 0;i<o;i++){
            for(int j=0;j<p;j++){
                nums_sum += grid[i][j];
                nums_sum_squ += 1LL * grid[i][j] * grid[i][j];
            }
           
        }
        // X - y 
        long long x = normal_sum - nums_sum;
        // X^2 - Y^2 
        long long y = normal_sum_squ - nums_sum_squ;
        // X + Y  = X^2 - Y^2  / X - y 
        // X + Y = (X + Y)(X-Y) / (X-Y)
        long long z = y / x;
        long long val1 = (z + x)/2;
        long long val2 = z - val1;

        return {(int)val2 , (int)val1};
    }
};