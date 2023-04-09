class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0,mn=INT_MAX;
        for(auto x:prices){
            mn = min(mn,x);
            mx = max(mx,x-mn);
        }
        return mx;
    }
};