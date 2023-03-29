class Solution {
public:
    int f(int ind,int cnt,vector<int>&s,vector<vector<int>>&dp){
        if(ind>=s.size())return 0;
       
       if(dp[ind][cnt]!=-1)return dp[ind][cnt];

        int notpick = f(ind+1,cnt,s,dp);
        int pick = (cnt+1)*s[ind] + f(ind+1,cnt+1,s,dp);

    return dp[ind][cnt] = max(pick,notpick); 
    }
    int maxSatisfaction(vector<int>& s) {
         sort(s.begin(),s.end());
         int n = s.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

         return f(0,0,s,dp);
    }
};