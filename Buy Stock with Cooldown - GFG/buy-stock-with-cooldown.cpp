//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
    
        vector<vector<long long>>dp(n+2,vector<long long>(2,0));
        
        for(int i = n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                if(buy){
                    dp[i][buy] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else{
                    dp[i][buy] = max(prices[i] + dp[i+2][1] , dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends