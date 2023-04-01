class Solution {
public:
   bool isPalindrome(int low,int high,string &s){
        while(low<high){
            if(s[low++]!=s[high--]){
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
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