class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int sum) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(sum-nums[i])!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[sum-nums[i]]);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return {-1};
    }
};