class Solution {
public:
    bool f(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<int>>&dp){

        
        if(i==s1.size() && j==s2.size() && k==s3.size())return true;
        if(i>s1.size() || j>s2.size())return false;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k]) return dp[i][j] = f(i+1,j,k+1,s1,s2,s3,dp) || f(i,j+1,k+1,s1,s2,s3,dp);
        else if(s1[i]==s3[k]) return dp[i][j] = f(i+1,j,k+1,s1,s2,s3,dp);
        else if(s2[j]==s3[k])return dp[i][j] = f(i,j+1,k+1,s1,s2,s3,dp);
        else return dp[i][j] = false;
    
}
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),n2=s2.length(),n3=s3.length();
        vector<vector<int>>dp(n+1,vector<int>(n2+1,-1));
        
        return f(0,0,0,s1,s2,s3,dp);
    }
};