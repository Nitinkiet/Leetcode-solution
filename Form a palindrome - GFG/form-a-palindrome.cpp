//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     int lcs(string s, string t){
        int n = s.size(); int m = t.size();
        vector<int>prev(m+1, 0); vector<int>cur(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j =1; j<=m; j++){
                if(s[i-1] == t[j-1]) cur[j] = 1+prev[j-1];
                else cur[j] = max(cur[j-1], prev[j]);
            }
            prev = cur;
        }
        return prev[m];
    }
    int lps(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(s, t);
    }
    int countMin(string str){
        int n = str.length();
        return n- lps(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends