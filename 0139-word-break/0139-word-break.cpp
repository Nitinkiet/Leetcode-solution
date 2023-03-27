class Solution {
public:
    bool f(int ind,string &s,set<string>&ans,vector<int>&dp){
        if(ind==s.length())return true;
        if(dp[ind]!=-1)return dp[ind];
        
        for(int i=ind+1;i<=s.length();i++){
            if(ans.find(s.substr(ind,i-ind)) != ans.end() && f(i,s,ans,dp))return dp[ind]=true;
        }
    return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& word) {
        set<string>ans(word.begin(),word.end());
        vector<int>dp(s.length(),-1);
        return f(0,s,ans,dp);
    }
};