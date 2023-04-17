class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        for(int i=0;i<candies.size();i++){
            int mx = candies[i]+extraCandies;
            int ele = *max_element(candies.begin(),candies.end());
            if(mx>=ele){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};