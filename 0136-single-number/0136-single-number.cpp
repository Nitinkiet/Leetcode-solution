class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        
        int ans=0;
        for(auto x:mp){
            if(x.second==1)ans=x.first;
        }
        return ans;
    }
};