class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            m[nums[i]]++;
        }
        
        n = floor(n/3);
        
        for( auto it:m ) {
            if( it.second > n ) {
                ans.push_back(it.first);
            }
        }
        
        return ans; 
    }
};