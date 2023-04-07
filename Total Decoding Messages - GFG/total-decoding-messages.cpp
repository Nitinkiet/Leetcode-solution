//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	 int m = 1e9+7;
	  int f(int i,string&s, vector<int>&dp){
        int n = s.size();
        if(s[i]=='0')return 0;
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i]%m;
        int cnt=f(i+1,s,dp);
        if(i<n-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')){
            cnt += f(i+2,s,dp);
        }
    return dp[i] = cnt%m;
	  }
		int CountWays(string s){
		   int n = s.size();
       vector<int>dp(n+1,-1);
       return f(0,s,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends