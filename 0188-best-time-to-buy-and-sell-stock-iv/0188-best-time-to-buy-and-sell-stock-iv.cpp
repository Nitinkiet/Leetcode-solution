class Solution {
public:
    int f(int ind,int trans,int k, int n,vector<int>&price,vector<vector<int>>&dp){
        if(ind==n || trans==2*k)return 0;
        
        if(dp[ind][trans]!=-1)return dp[ind][trans];
        if(trans%2==0){
        return dp[ind][trans] = max(-price[ind] + f(ind+1,trans+1,k,n,price,dp) ,f(ind+1,trans,k,n,price,dp));
    }
    else{
     return dp[ind][trans] = max(price[ind] +f(ind+1,trans+1,k,n,price,dp), f(ind+1,trans,k,n,price,dp));
    }
    }


    int maxProfit(int k, vector<int>& price) {
         int n = price.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        
        return f(0,0,k,n,price,dp);
    }
};