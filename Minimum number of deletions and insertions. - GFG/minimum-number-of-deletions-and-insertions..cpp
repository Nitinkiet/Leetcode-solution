//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2] = 1 + f(ind1-1,ind2-1,s1,s2,dp);
    return dp[ind1][ind2] = max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return f(x-1,y-1,s1,s2,dp);
    }
	int minOperations(string s1, string s2) 
	{ 
	    int n = s1.length(),m = s2.length();
        
        return (n-lcs(n,m,s1,s2) + m-lcs(n,m,s1,s2));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends