class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        if(nums.size()==0)return 0;
        int maxi=1;
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int ele = it;
               int cnt=1;
                while(s.find(ele+1)!=s.end()){
                    ele += 1;
                    cnt += 1;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
        
    }
};