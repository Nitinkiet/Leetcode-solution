class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        int n = v.size();
        for(int i=n-1;i>=0;i--){
            k--;
            if(k < 0){
                break;
            }
            else{
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};