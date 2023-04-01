//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k, vector<int>& arr){
     
        vector<int>dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int len=0,maxi=INT_MIN,ans=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = (len*maxi) + dp[j+1];
            ans = max(ans,sum);
}
            dp[i] = ans;
}
return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends