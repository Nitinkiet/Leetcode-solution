class Solution {
public:
    
    int solve(string &w1,string &w2,int n1,int n2 ,vector<vector<int>> &dp){
        
        if(n1==0)return dp[n1][n2] = n2;
        if(n2==0)return dp[n1][n2] = n1;
        if(dp[n1][n2]!=-1)return dp[n1][n2];

        if(w1[n1-1]==w2[n2-1]){
            return dp[n1][n2] = solve(w1,w2,n1-1,n2-1,dp);
        }
        else{
            int Insert = solve(w1,w2,n1,n2-1,dp);
            int Delete = solve(w1,w2,n1-1,n2,dp);
            int Replace = solve(w1,w2,n1-1,n2-1,dp);

            return dp[n1][n2] = 1 + min({Insert,Delete,Replace});
        }
    }
    int minDistance(string w1, string w2) {
        int n1=w1.size(),n2=w2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(w1,w2,n1,n2,dp);
    }
};