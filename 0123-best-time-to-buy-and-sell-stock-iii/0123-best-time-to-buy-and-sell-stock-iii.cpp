class Solution {
public:
    int f(int ind,int trans,int n,vector<int>&price,vector<vector<int>>&dp){
        if(ind==n || trans>3)return 0;
        
        if(dp[ind][trans]!=-1)return dp[ind][trans];
        if(trans%2==0){
                        return dp[ind][trans] = max(-price[ind] + f(ind+1,trans+1,n,price,dp) ,f(ind+1,trans,n,price,dp));
    }
       else {
          return dp[ind][trans] = max(price[ind] +f(ind+1,trans+1,n,price,dp), f(ind+1,trans,n,price,dp));
}
        
        
    }
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<vector<int>>dp(n+1,vector<int>(5,-1));

//             for(int i=0;i<=3;i++){
//                 dp[n][i]=0;
//             }

//             for(int i=n-1;i>=0;i--){
//                 for(int trans = 0;trans<=3;trans++){
//                     if(trans%2==0){
//                         dp[i][trans] = max(-price[i] + dp[i+1][trans+1] , dp[i + 1 ][trans]);
//     }
//                     else {
//                          dp[i][trans] = max(price[i] + dp[i+1][trans+1] , dp[i + 1 ][trans]);
//     }
//     }
//     }
//             return dp[0][4];
        
        return f(0,0,n,price,dp);
        
    }
};