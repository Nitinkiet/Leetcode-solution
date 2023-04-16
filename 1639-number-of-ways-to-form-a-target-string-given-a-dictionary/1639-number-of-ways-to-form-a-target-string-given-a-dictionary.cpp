#define ll long long
class Solution {
    int md = 1e9+7;

    int solve(vector<string>& words, string &target,
     vector<vector<ll>> &ichar, int i, int j, vector<vector<ll>> &dp){
        if (j>=target.size())
            return 1;
        if (i>=words[0].size())
            return 0;
        if (dp[i][j]!=-1)
            return dp[i][j] ;

        ll inc = 0 , exc = 0;

        if (ichar[i][target[j]-'a'])
            inc = ( (ichar[i][target[j]-'a'])*(solve(words,target,ichar,i+1,j+1,dp)) )%md;
        
        exc = solve(words,target,ichar,i+1,j,dp) ;

        return dp[i][j] = (inc+exc)%md;
    }

public:
    int numWays(vector<string>& words, string target) {
        int N = words.size() , M = words[0].size() ;

        vector<vector<ll>> ichar(M,vector<ll>(26)) ;

        for (string &s : words){
            for (int i=0; i<M; i++)
                ichar[i][s[i]-'a']++;
        }

        vector<vector<ll>> dp(M+1,vector<ll>(target.size()+1,-1)) ;

        return solve(words,target,ichar,0,0,dp) ;
    }
};