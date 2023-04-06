class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int ans=INT_MIN,mx=1,mn=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0)swap(mx,mn);

            mx = max(mx*nums[i],nums[i]);
            mn = min(mn*nums[i],nums[i]);
            ans = max(ans,mx);
        }
        return ans;
    }
};