//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int f(vector<int>&arr,int i,int k,int curr,vector<vector<int>>&dp){
        if(i==0)return curr==k;
        if(dp[i][curr]!=-1)return dp[i][curr];
        
        int p = f(arr,i-1,k,curr^arr[i-1],dp);
        int np = f(arr,i-1,k,curr,dp);
        return dp[i][curr] = np + p;
    }
    int subsetXOR(vector<int> arr, int n, int k) {
    
        vector<vector<int>>dp(n+1,vector<int>(201,-1));
        return f(arr,n,k,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends