class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])cnt++;
        }
        return cnt<=1;
    }
};