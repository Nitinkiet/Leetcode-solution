class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,mx = INT_MIN;
        for(auto x:nums){
            sum += x;
            mx = max(mx,sum);
            if(sum<0)sum=0;
        }
        return mx;
    }
};