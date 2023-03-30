//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int ind,int trans,int k, int n,int price[],vector<vector<int>>&dp){
        if(ind==n || trans==2*k)return 0;
        
        if(dp[ind][trans]!=-1)return dp[ind][trans];
        if(trans%2==0){
        return dp[ind][trans] = max(-price[ind] + f(ind+1,trans+1,k,n,price,dp) ,f(ind+1,trans,k,n,price,dp));
    }
    else{
     return dp[ind][trans] = max(price[ind] +f(ind+1,trans+1,k,n,price,dp), f(ind+1,trans,k,n,price,dp));
    }
    }

    int maxProfit(int k, int n, int A[]) {
         
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        
        return f(0,0,k,n,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends