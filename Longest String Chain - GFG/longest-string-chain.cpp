//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     bool compare(string &s1,string &s2){
        if(s1.size()!=s2.size()+1)return false;
        
        int first=0,second=0;
        
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){first++;second++;}
            else first++;
        
        }
        if(first==s1.size() && second==s2.size())return true;
        else return false;

    }
    
    int longestChain(int n, vector<string>& nums) {
        sort(nums.begin(),nums.end(),[](const string &l, const string &r) { return l.size() < r.size(); });
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(nums[i], nums[prev]) && 1 + dp[prev]>dp[i]){
                    dp[i] = 1 + dp[prev];   
                }
            }  
          if(dp[i]>maxi)maxi = dp[i];
        
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends