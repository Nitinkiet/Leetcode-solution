//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 bool isPalindrome(int low,int high,string &s){
        while(low<high){
            if(s[low++]!=s[high--]){
                return false;
            }
        }
        return true;
    }
    int palindromicPartition(string s)
    {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    mini=min(mini,1+dp[j+1]);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    
   
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends